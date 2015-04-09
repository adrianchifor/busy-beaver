# Implementation of the Busy Beaver problem in C++

http://en.wikipedia.org/wiki/Busy_beaver

Compile: g++ busy-beaver.cpp -o busy-beaver<br>
Run: './busy-beaver x' where x is an integer number between 0 and 7.

Example: ./busy-beaver 3<br>
--- 3 states ---<br>
0<br>
101<br>
1111<br>
111101<br>
Finished in 14 steps.
<br><br><br>
1-state Busy Beaver:<br>
a0 -> h1r

2-state Busy Beaver:<br>
a0 -> b1r&nbsp;&nbsp;&nbsp;&nbsp;a1 -> b1l<br>
b0 -> a1l&nbsp;&nbsp;&nbsp;&nbsp;b1 -> h1r

3-state Busy Beaver:<br>
a0 -> b1r&nbsp;&nbsp;&nbsp;&nbsp;a1 -> h1r<br>
b0 -> c0r&nbsp;&nbsp;&nbsp;&nbsp;b1 -> b1r<br>
c0 -> c1l&nbsp;&nbsp;&nbsp;&nbsp;c1 -> a1l

4-state Busy Beaver:<br>
a0 -> b1r&nbsp;&nbsp;&nbsp;&nbsp;a1 -> b1l<br>
b0 -> a1l&nbsp;&nbsp;&nbsp;&nbsp;b1 -> c0l<br>
c0 -> h1r&nbsp;&nbsp;&nbsp;&nbsp;c1 -> d1l<br>
d0 -> d1r&nbsp;&nbsp;&nbsp;&nbsp;d1 -> a0r

5-state Busy Beaver:<br>
a0 -> b1l&nbsp;&nbsp;&nbsp;&nbsp;a1 -> a1l<br>
b0 -> c1r&nbsp;&nbsp;&nbsp;&nbsp;b1 -> b1r<br>
c0 -> a1l&nbsp;&nbsp;&nbsp;&nbsp;c1 -> d1r<br>
d0 -> a1l&nbsp;&nbsp;&nbsp;&nbsp;d1 -> e1r<br>
e0 -> h1r&nbsp;&nbsp;&nbsp;&nbsp;e1 -> c0r

6-state Busy Beaver:<br>
a0 -> b1r&nbsp;&nbsp;&nbsp;&nbsp;a1 -> e0l<br>
b0 -> c1l&nbsp;&nbsp;&nbsp;&nbsp;b1 -> a0r<br>
c0 -> d1l&nbsp;&nbsp;&nbsp;&nbsp;c1 -> c0r<br>
d0 -> e1l&nbsp;&nbsp;&nbsp;&nbsp;d1 -> f0l<br>
e0 -> a1l&nbsp;&nbsp;&nbsp;&nbsp;e1 -> c1l<br>
f0 -> e1l&nbsp;&nbsp;&nbsp;&nbsp;f1 -> h1r<br>
    