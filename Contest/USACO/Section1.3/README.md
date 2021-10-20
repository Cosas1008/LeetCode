- [x] PROGRAM NAME: milk

Goal:
To calculate the minimum amount of money that Merry Milk Makers must spend to meet their daily need for milk.
### Input

```c
100 5 // MMM wants 100 units of milk from 5 farmers
5 20 // Farmer 1 says, "I can sell you 20 units at 5 cents per unit"
9 40 etc.
3 10 // Farmer 3 says, "I can sell you 10 units at 3 cents per unit"
8 80 etc.
6 30 // Farmer 5 says, "I can sell you 30 units at 6 cents per unit"
```
### Output

A single line with a single integer that is the minimum cost that Merry Milk Makers must pay for one day's milk.

-------------
- [x] PROGRAM NAME: barn1

INPUT | FORMAT
------------ | -------------
Line 1:|	M, S, and C (space separated)
Lines 2-C+1:|Each line contains one integer, the number of an occupied stall.

#### Sample Input (file barn1.in)
```c
4 50 18
3
4
6
8
14
15
16
17
21
25
26
27
30
31
40
41
42
43
```
####  Sample Output (file barn1.out)
25

-------------
- [x] PROGRAM NAME: crypt1

#### Input Format:
INPUT | FORMAT
------------ | -------------
Line 1:	 | N, the number of digits that will be used
Line 2:	 | N space separated digits with which to solve the cryptarithm
#### Sample Input (file crypt1.in)
5
2 3 4 6 8

####  Explain 
A single line with the total number of unique solutions. Here is the solution for the sample input:
```c
      2 2 2
    x   2 2
     ------
      4 4 4
    4 4 4
    -------
    4 8 8 4
```
####  Sample Output (file crypt1.out)  
1  

-------------
- [x] PROGRAM NAME: combo


#### Input Format:
Input  | Format
------------| -------------
Line 1: | The integer N.
Line 2: | Three space-separated integers, specifying Farmer John's combination.
Line 3: | Three space-separated integers, specifying the master combination (possibly the same as Farmer John's combination).
```
50
1 2 3
5 6 7
```
####  Sample Output (file combo.out):
249

-------------

- [ ] PROGRAM NAME: wormhole

#### Input Format:
Input  | Format
------------| -------------
Line 1 | The number of wormholes, N.
Lines 2..1+N | Each line contains two space-separated integers describing the (x,y) coordinates of a single wormhole. Each coordinate is in the range 0..1,000,000,000.

#### Sample Input (file wormhole.in):
```
4
0 0
1 0
1 1
0 1
```
#### Output Format:
Line 1:	The number of distinct pairings of wormholes such that Bessie could conceivably get stuck in a cycle walking from some starting point in the +x direction.
####  Sample Output (file wormhole.out):
2
#### Thought:

This is much alike a permuation problem with a little bit pruning

refer to permuation.cpp

-------------