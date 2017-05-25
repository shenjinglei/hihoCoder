#1074 : Typeface Design
Time Limit:10000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
 You are helping somebody design a new typeface for Chinese characters on Linux.

 ![图片](http://media.hihocoder.com//problem_images/20141109/14154980323967.png)

14154980323967.png

To reduce the size of characters, some points' positions need to be anchored while the others' can be interpolated by the anchored points(IUP).

Given a sequence a of n elements, we define an item ax can be interpolated by al and ar if and only if:

There exist l < x < r, which satisfied al ≤ ax ≤ ar or al ≥ ax ≥ ar.

Find the minimum number of selected elements, so that every unselected element can be interpolated by the nearest selected elements.

Input
The first line contains an integer n - the number of elements of the sequence (1 ≤ n ≤ 105).

The second line contains n integers - a1, a2, ..., an (1 ≤ ai ≤ 109).All ai are distinctive.

Output
The first line contains an integer ans - the minimum number of the selected elements. The second line contains ans integers in increasing order - the index of each selected elements.

Hint
Another Sample：

Sample Input	Sample Output
7
1 2 3 10 5 6 4	3
1 4 7
Sample Input
8
3 4 2 1 8 5 7 6
Sample Output
7
1 2 4 5 6 7 8 