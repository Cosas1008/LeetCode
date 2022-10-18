### Contest

Geneous Collection
* 1402 Reducing Dishes ( One-Pass )
* 1943 Describe the Painting ( Meeting Rooms II )
* 1986 Min Number of Work Session to Finish the Tasks (classic TSP) 
* 1987 Number of Unique Good Subsequence

- [ ]  Unique Paths II
- [ ]  Lowest Common Ancester
- [ ]  523 Continuous Subarray Sum
- [ ]  713.
- [ ]  Subarray Product Less Than K
- [ ]  2155. All Divisions With the Highest Score of a Binary Array
- [ ]  Combinations
### TODO List
- [x] 8    String to Integer (atoi)
- [x] 23   Merge K Sorted Lists
- [x] 25   Reverse Nodes in k-Group ( Hard )
- [x] 28   Implement strStr()
- [x] 34   Find First and Last Position of Element in Sorted Array
- [x] 41   First Missing Positive
- [x] 54   Spiral Matrix
- [x] 57   Insert Interval
- [x] 77   Combinations
- [x] 85   Maximal Rectangle
- [x] 88   Merge Sorted Array
- [x] 92   Reverse Linked List II
- [x] 123  Best Time to Buy and Sell Stock III
- [ ] 126  Word Ladder II
- [x] 127  Word Ladder ( Same as 433)
- [x] 149  Max Points on a Line
- [x] 166  Fraction to Recurring Decimal
- [x] 204  Count Primes
- [x] 241  Different Ways to Add Parentheses
- [x] 253  Meeting Rooms II
- [x] 264  Ugly Number II
- [x] 304  Range Sum Query 2D - Immutable
- [x] 324  Wiggle Sort II ( genius )
- [x] 329  Longest Increasing Path in a Matrix ( DFS )
- [ ] 343  Integer Break
- [x] 433  Min Gentic Mutation
- [x] 468  Validate IP Address
- [x] 548  Split Array with Equal Sum
- [ ] 564  Find the Closest Palindrome
- [x] 581  Shortest Unsorted Continuous Subarray ( 3 ways )
- [x] 720  Longest Word in Dictionary
- [x] 763  Partition Labels
- [x] 777  Swap Adjacent in LR String
- [ ] 786  K-th Smallest Prime Fraction
- [x] 826  Most Profit Assigning Work
- [x] 835  Image Overlap ( Smart )
- [x] 838  Push Dominoes
- [x] 885  Spiral Matrix III
- [x] 905  Sort Array by Parity
- [x] 931  Min Falling Path Sum
- [ ] 949  Largest Time for Given Digits
- [ ] 963  Min Area Rectangle II
- [x] 973  K Closest Points to Origin
- [x] 974  Subarray Sums Divisible by K
- [x] 1042 Flower Planting With No Adjacent ( Greedy )
- [x] 1087 Brace Expansion
- [x] 1139 Largest 1-Bordered Square
- [x] 1230 Toss Strange Coins ( kind of DP )
- [ ] 1289 Min Falling Path Sum II
- [x] 1314 Matrix Block Sum
- [x] 1402 Reducing Dishes
- [x] 1546 Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
- [x] 1567 Max Length of Subarray With Positive Product
- [x] 1583 Count Unhappy Friends ( need to think again)
- [x] 1630 Arithmetic Subarrays
- [x] 1674 Minimum Moves to Make Array Complementary ( Hard )
- [x] 1713 Minimum Operations to Make a Subsequence (Longest Increasing Subsequence)
- [x] 1980 Find Unique Binary String
- [x] 1943 Describe the Painting
- [x] 1995 Count Special Quadruplets
- [x] 2025 Maximum Number of Ways to Partition an Array ( Prefix Suffix )
- [ ] 2030 Smallest K-Length Subsequence with Occurrence of a Letter
- [x] 2091 Removeing Min and Max From Array
- [x] 2092 Find All People With Secret
- [x] 2095 Delete the Middle Node of a Linked List

### Practice

0. Google OA
[link](https://leetcode.com/discuss/interview-question/352460/Google-Online-Assessment-Questions)


1. Practice 1801 will use the concept of transforming long long int to output correct answer by adding module 10^9+7    
```
    (ans)%(10^9+7)
```
2. Test number 65 in Java shows design pattern to solve problem properly for SWE


### Heap (Generally hard problem )
`tips: solved by priority_queue`   
- [x] 436 Find Right Interval ( practice lower_bound)
- [x] 1705 Maximum Number of Eaten Apples
- [x] 857 Minimum Cost to Hire K Workers
- [x] 871 Minimum Number of Refueling Stops
- [x] 1834 Single Threaded CPU
- [x] 1882 Process Tasks Using Servers

### Union Find
- [x] 737 Sentence Similarity II


### 13 Roman to Integer
map, unordered_map<char, int> is more better way without casing the char to string
[Clean C++ solution](https://leetcode.com/problems/roman-to-integer/discuss/ "C++ clean solution")

### 92 Reverse Linked List II
Hint : To make a dummy head at front   


### Stock Series
- [x] 121 Best Time to Buy and Sell Stock      (simple 1 transaction)    
- [x] 122 Best Time to Buy and Sell Stock II   (n transactions)    
- [x] 123 Best Time to Buy and Sell Stock III  (at most 2 transactions)    
- [x] 309 Best Time to Buy and Sell Stock with Cooldown    (transactions with cooldown)    
- [x] 714 Best Time to Buy and Sell Stock with Transaction Fee

### 300 Longest Increasing Subsequence

Classic Question
Just Like 334. Increasing Triplet Subsequence

### 412 Fizz Buzz
keyword : vector<string>  

### 440. K-th Smallest in Lexicographical Order (TODO 9/17)
Solve 316 and 1081 later


### 451. Sort Characters By Frequency  
Given a string, sort it in decreasing order based on the frequency of characters.  

### 461 Hamming Distance

### 463 Island Perimeter  
keyword : graph

### 476 Number Complement
solve it with vector<int>

### 387 First Unique Character in a String
solve it with min_element, <climits>  

### 392 Is Subsequence
keyword : dynamic programming, Memory Limit Exceeded

這寫得超棒 [Simple Solution](https://discuss.leetcode.com/topic/58078/simple-c-code-as-well-as-the-followup-solution)

### 528. Random Pick with Weight

How to make weighted random probability   
Similar to :   
- [x] 380 Insert Delete GetRandom O(1)   
- [x] 382 Linked List Random Node     
- [x] 710 Random Pick with Blacklist  (Hard)     
Follow up:

What if the linked list is extremely large and its length is unknown to you?
Could you solve this efficiently without using extra space?    

### 556. Next Greater Element III
[Wiki](https://www.wikiwand.com/en/Permutation#/Generation_in_lexicographic_order) Introduce Generation in lexicographic order for permutation, it goes:   
1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.    
2. Find the largest index l greater than k such that a[k] < a[l].    
3. Swap the value of a[k] with that of a[l].    
4. Reverse the sequence from a[k + 1] up to and including the final element a[n].    

### 557. Reverse Words in a String III  
keyword : use sstream lib, reverse and string basic sting operation  

### 575. Distribute Candies
Keyword: set of max different values

### 671 findSecondMinimumValue

keyword: Tree walk BFS or DFS

### 674

LeetCode Weekly Contest 49, simple Longest Continuous Increasing Subsequence question
also check question 673 Number of Longest Increasing Subsequence

### 657. Judge Route Circle

Basic C type string char operation

### 1671. Minimum Number of Removals to Make Mountain Array

Hint : 300.LIS

dynamic programming for 
1. Largest Subset
2. the second question is to find whether it is possible to find a set of number that the sum of this set of numbers equals to target value
3. Similar to largest possible number problem in Leetcode

### 1994 Count Special Quadruplets
Hint: 2Sum, 3Sum, 4Sum