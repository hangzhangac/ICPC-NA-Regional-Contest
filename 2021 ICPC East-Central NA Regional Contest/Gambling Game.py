#!/usr/bin/env python3
import math

l = list(map(int, input().split()))
m,n,p = l
#n=4
#p=3
if n==0 and p==0:
	print("1/1")
	exit(0)
if(n!=0 and p==0):
	print("0/1")
	exit(0)

def comb(n,m):
	return math.factorial(n)//(math.factorial(n-m)*math.factorial(m))
def perm(n,m):
	return math.factorial(n)//math.factorial(n-m)
#from scipy.special import comb, perm
	
#comb(3,2)
ans=0
a = [1]
for x in range(1,20):
	a.append(a[x-1]*2)
#print(a)
	
for x in range(0,n):
	#print(x)
	if p-(n+x)>=0 and p-(n+x)<=m-2*n:
		t = comb(n-1,x)*a[n-1-x]*comb(m-2*n,p-(n+x))
		ans+=t
#print(ans)
#print(comb(m,p))
def gcd(x,y):
	if y==0:
		return x
	return gcd(y,x%y)
x = ans*2*n
y = comb(m,p)*p
g = gcd(x, y)
x//=g
y//=g
print(str(x)+'/'+str(y))