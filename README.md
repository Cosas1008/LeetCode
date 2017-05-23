# Leetcode

## 88. Merge Sorted Array   
Given two sorted integer arrays nums1 and nums2, merge *nums2* into *nums1* as one sorted array.  
hint: [Min-Heap](http://yuweiichen.com/merge-two-array/ "MergeSortedArray")
 
## 301 Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

## 451. Sort Characters By Frequency  
Given a string, sort it in decreasing order based on the frequency of characters.  

## 461 Hamming Distance

## 476 Number Complement
solve it with vector<int>

## 412 Fizz Buzz
keyword : vector<string>  


## 463 Island Perimeter  
keyword : graph


## 387 First Unique Character in a String
solve it with min_element, <climits>  

## 557. Reverse Words in a String III  
keyword : use sstream lib, reverse and string basic sting operation  


## 575. Distribute Candies
Keyword: set of max different values

## WAP interview
the first problem is to find the swap k in n sequence 1,2,3...n.
for starter, you will have to int number n and k, n means how many in order sequence and k means the number of swap. The output is how many possible combination with exactly k swaps.
for example:

----------

```cpp
4 1 \\ which stands for n = 4, k = 1
\\so the possible combinations are  :  
\\ | means swap take place
\\[1, 3, 2 ,4]  
\\ ---|  |  
\\[2, 1, 3, 4]  
\\ |  |  
\\[1, 2, 4, 3]  
\\ ------|  |  
```  
therefore, you should output # of possible combination, which is 3 in this (4, 1) case

----------

the second question is to find whether it is possible to find a set of number that the sum of this set of numbers equals to target value


------------

outcome ==20%== for the first and ==90%== for the second question
