#!/usr/bin/env python
import sys

mod=1000000007

def powr(a,b):
	if b==1:
		return a%mod
	ans=1

	k=powr(a,b/2)
	ans=(k*k)%mod
	if b%2 == 1:
		ans=(ans*a)%mod

	return ans
			

def even(n,c):
	p=powr(powr(c,n/2) ,(5*n)/2)
	ans=(powr(p,4)+powr(p,2)+2*p)%mod
	ans=ans/4
	return ans

def odd(n,c):
	a=powr(c,(n-1)/2)
	b=powr(c,n)
	ans=powr(b,5*n) + (powr(b,(2*n)+1)*powr(a,n-1)) + 2*c*powr(b,n)*powr(a,(n+1)/2)
	ans=ans/4
	return ans

t=raw_input()
while t:
	n=raw_input()
	c=raw_input()
	if n%2==0:
		print even(n,c)
	else:
		print odd(n,c)
	t=t-1