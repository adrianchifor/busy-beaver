Implementation of the Busy Beaver problem in C++.

http://en.wikipedia.org/wiki/Busy_beaver

Compile: g++ busy-beaver.cpp -o busy-beaver
Run: './busy-beaver x' where x is an integer number between 0 and 7.

Example: ./busy-beaver 3
--- 3 states ---
0
101
1111
111101
Finished in 14 steps.


1-state Busy Beaver:
	a0 -> h1r

2-state Busy Beaver:
	a0 -> b1r    a1 -> b1l
    b0 -> a1l    b1 -> h1r

3-state Busy Beaver:
	a0 -> b1r    a1 -> h1r
    b0 -> c0r    b1 -> b1r
    c0 -> c1l    c1 -> a1l

4-state Busy Beaver:
	a0 -> b1r    a1 -> b1l
    b0 -> a1l    b1 -> c0l
    c0 -> h1r    c1 -> d1l
    d0 -> d1r    d1 -> a0r

5-state Busy Beaver:
	a0 -> b1l    a1 -> a1l
    b0 -> c1r    b1 -> b1r
    c0 -> a1l    c1 -> d1r
    d0 -> a1l    d1 -> e1r
    e0 -> h1r    e1 -> c0r

6-state Busy Beaver:
	a0 -> b1r    a1 -> e0l
    b0 -> c1l    b1 -> a0r
    c0 -> d1l    c1 -> c0r
    d0 -> e1l    d1 -> f0l
    e0 -> a1l    e1 -> c1l
    f0 -> e1l    f1 -> h1r
    