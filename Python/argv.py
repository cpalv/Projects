#!/usr/bin/python3

import sys # gives us argv
import codecs # lets us encode things
import struct # make stuff C like

RET_ADDR = 0x08048dba

# feels like bad practice but for quick use
# we've assigned argv[1] to s
s = sys.argv[1]
print (s)
# s.encode() converts 'str' to 'bytes'
# codecs.encode( b'str', 'hex') converts bytes to hex
x = codecs.encode(s.encode(), 'hex')
print(x)

y = int.from_bytes(x,'little')
print(y)
print( hex(y))

print("An address that we might want to return to")
goto = struct.pack("I", RET_ADDR)
# thankfully struct.pack appears to print them in little endian format!
print(goto)
