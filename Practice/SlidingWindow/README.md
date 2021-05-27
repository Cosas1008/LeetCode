- [ ] 3    Longest Substring Without Repeating Characters		  	  
- [ ] 76   Minimum Window Substring			  
- [ ] 159  Longest Substring with At Most Two Distinct Characters	  	  
- [ ] 239  Sliding Window Maximum			  
- [ ] 340  Longest Substring with At Most K Distinct Characters   
- [ ] 395  Longest Substring with At Least K Repeating Characters			  
- [ ] 424  Longest Repeating Character Replacement			   
- [ ] 480  Sliding Window Median			  
- [ ] 567  Permutation in String			    
- [ ] 727  Minimum Window Subsequence    
- [ ] 978  Longest Turbulent Subarray	  
- [x] 992  Subarrays with K Different Integers        
- [ ] 995	Minimum Number of K Consecutive Bit Flips			     
- [ ] 1004	Max Consecutive Ones III			  
- [ ] 1100	Find K-Length Substrings With No Repeated Characters	  
- [ ] 1151	Minimum Swaps to Group All 1's Together  
- [ ] 1040	Moving Stones Until Consecutive II		   
- [ ] 1052	Grumpy Bookstore Owner			  
- [ ] 1074	Number of Submatrices That Sum to Target			  
- [ ] 1176	Diet Plan Performance  
- [ ] 1208	Get Equal Substrings Within Budget	  		
- [ ] 1423	Maximum Points You Can Obtain from Cards   			
- [ ] 1438	Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit			  
- [ ] 1456	Maximum Number of Vowels in a Substring of Given Length			  
- [ ] 1498	Number of Subsequences That Satisfy the Given Sum Condition			  
- [ ] 1499	Max Value of Equation			  
- [ ] 1658	Minimum Operations to Reduce X to Zero
- [ ] 1358    Number of Substrings Containing All Three Characters
- [ ] Count Number of Nice Subarrays
- [ ] Replace the Substring for Balanced String
- [x] Subarrays with K Different Integers
- [ ] Fruit Into Baskets
- [ ] Shortest Subarray with Sum at Least K
- [ ] Minimum Size Subarray Sum


For 992. Subarrays with K Different Integers:
```
class Solution:
    def subarraysWithKDistinct(self, A: 'List[int]', K: 'int') -> 'int':
        return self.subarraysWithAtMostKDistinct(A, K) - self.subarraysWithAtMostKDistinct(A, K-1)
    
    def subarraysWithAtMostKDistinct(self, s, k):
        lookup = collections.defaultdict(int)
        l, r, counter, res = 0, 0, 0, 0
        while r < len(s):
            lookup[s[r]] += 1
            if lookup[s[r]] == 1:
                counter += 1
            r += 1   
            while l < r and counter > k:
                lookup[s[l]] -= 1
                if lookup[s[l]] == 0:
                    counter -= 1
                l += 1
            res += r - l 
        return res
```
For 3. Longest Substring Without Repeating Characters:
```
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lookup = collections.defaultdict(int)
        l, r, counter, res = 0, 0, 0, 0
        while r < len(s):
            lookup[s[r]] += 1
            if lookup[s[r]] == 1:
                counter += 1
            r += 1
            while l < r and counter < r - l:
                lookup[s[l]] -= 1
                if lookup[s[l]] == 0:
                    counter -= 1
                l += 1
            res = max(res, r - l)
        return res
```
For 159. Longest Substring with At Most Two Distinct Characters:
```
class Solution(object):
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        lookup = collections.defaultdict(int)
        l, r, counter, res = 0, 0, 0, 0
        while r < len(s):
            lookup[s[r]] += 1
            if lookup[s[r]] == 1:
                counter += 1
            r += 1   
            while l < r and counter > 2:
                lookup[s[l]] -= 1
                if lookup[s[l]] == 0:
                    counter -= 1
                l += 1
            res = max(res, r - l) 
        return res
```
For 340. Longest Substring with At Most K Distinct Characters:
```
class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        lookup = collections.defaultdict(int)
        l, r, counter, res = 0, 0, 0, 0
        while r < len(s):
            lookup[s[r]] += 1
            if lookup[s[r]] == 1:
                counter += 1
            r += 1   
            while l < r and counter > k:
                lookup[s[l]] -= 1
                if lookup[s[l]] == 0:
                    counter -= 1
                l += 1
            res = max(res, r - l) 
        return res
```