# Leetcode

## Easy

Practice DSA as following:

#### data structure
1. LinkedList
2. Tree
3. Hashtable
4. Heap

### Algorithm
1. Dynamic Programming
2. Sort(w/ or w/o std)


### 7 Reverse Integer
kind of bit operation

### 13 Roman to Integer
map, unordered_map<char, int> is more better way without casing the char to string
```cpp

char c = string.at(i); // string to char
string s = string(1,c); // converted to string again
int i = c - '0';

```

this is better [Clean C++ solution](https://leetcode.com/problems/roman-to-integer/discuss/ "C++ clean solution")

### 88. Merge Sorted Array   
Given two sorted integer arrays nums1 and nums2, merge *nums2* into *nums1* as one sorted array.  
hint: [Min-Heap](http://yuweiichen.com/merge-two-array/ "MergeSortedArray")
 
### 301 Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

### 451. Sort Characters By Frequency  
Given a string, sort it in decreasing order based on the frequency of characters.  

### 461 Hamming Distance

### 476 Number Complement
solve it with vector<int>

### 412 Fizz Buzz
keyword : vector<string>  


### 463 Island Perimeter  
keyword : graph

### 387 First Unique Character in a String
solve it with min_element, <climits>  

### 392 Is Subsequence
keyword : dynamic programming, Memory Limit Exceeded

這寫得超棒 [Simple Solution](https://discuss.leetcode.com/topic/58078/simple-c-code-as-well-as-the-followup-solution)

### 557. Reverse Words in a String III  
keyword : use sstream lib, reverse and string basic sting operation  

### 575. Distribute Candies
Keyword: set of max different values

### 671 findSecondMinimumValue

keyword: Tree walk BFS or DFS

### 674.cpp

LeetCode Weekly Contest 49, simple Longest Continuous Increasing Subsequence question
also check question 673 Number of Longest Increasing Subsequence

## Medium

### WAP interview

dynamic programming for 
1. Largest Subset
2. the second question is to find whether it is possible to find a set of number that the sum of this set of numbers equals to target value
3. Similar to largest possible number problem in Leetcode