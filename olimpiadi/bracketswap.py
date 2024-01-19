#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys

# uncomment the two following lines if you want to read/write from files
# sys.stdin = open('input.txt')
# sys.stdout = open('output.txt', 'w')

N = int(input().strip())

S = input().strip()

R = 0

A = []
B = []

for i in range(N):
    if S[i] == '(':
        A.append(i)
    else:
        B.append(i)

R = len(A) // 2

print(R)

for i in range(R):
    print(A[i], B[i])

sys.stdout.close()
