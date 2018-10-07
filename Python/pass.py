#!/usr/bin/env python3
from random import shuffle, randint
import crypt


char_set = [ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
			 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
			 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a',
			 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
			 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
			 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '@',
			 '#', '$', '%', '^', '&', '*', '(', ')', '-',
			 '+', '=', '[', ']', '?', '.', ',', '_', '~',
			 '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' ]

shuffle( x=char_set)

max_choices = len(char_set)
passwd = ""

for i in range(8):
	rand = randint(0, max_choices)
	passwd += char_set[rand]

print(passwd)

salt = crypt.mksalt( method=crypt.METHOD_SHA512)
enc_passwd = crypt.crypt( word=passwd, salt=salt)

print(enc_passwd)
