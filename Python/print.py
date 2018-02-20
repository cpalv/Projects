#!/usr/bin/python

#Print shit in reverse 
A = [ 1, 2, 3, 4 , 5]
# decrement shit by 1
print(A[::-1])
# increment counter by 1
print(A[::1])

# *vars like __VARGS__ in C
# allows for many arguments
def foo(q, *vars):
	print(q)
	for var in ( *vars):
		print(var)

foo(1, 2, 3, 4, 5, 6)
#function to iterate over list

