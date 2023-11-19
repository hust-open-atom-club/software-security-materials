#!/usr/bin/env python

from pwn import *

binary_path = "./vuln"

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
payload = b"A" * 64
p.sendline(payload)
print_lines(p)
