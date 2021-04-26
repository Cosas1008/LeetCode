from typing import List
from collections import Counter
from functools import lru_cache

class Solution:
    def maxHappyGroups(self, batch_size: int, groups: List[int]) -> int:
        # 1.    Create new list only of groups that are not of batch_size multiplication  
        groups_remainders   = [x % batch_size for x in groups if x % batch_size != 0]
        # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Case 1 - Start ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        # 2.    The groups that are of batch_size multiplication are by definition happy
        #       when such group arrives we can create a multiplication of batch_size donuts for them
        happy               = len(groups) - len(groups_remainders)
        # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Case 1 - End   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        # 3.    Create a counter for the groups_remainders   
        counter             = Counter(groups_remainders)
        # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Case 2 - Start ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        # 4.    When looking at two groups that have reminders (k, batch_size-k) - we can put them in the same day and make one of them happy
        for k in counter.keys():
            if k == batch_size-k:
                if counter[k] >= 2:
                    common                       = counter[k] // 2
                    counter[k]                  -= common*2
                    happy                       += common
            else:
                if counter[k] > 0 and counter[batch_size - k] > 0:
                    common                       = min(counter[k], counter[batch_size - k])
                    counter[k]                  -= common
                    counter[batch_size - k]     -= common
                    happy                       += common
        # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Case 2 - End   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Case 3 - Start ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        # 5.    The remaining groups from the previous steps have to be arranged
        #       in a such way that maximal amount from them are happy
        #       This part is solved in a backtracking way and using memoization to prevent reoccurring computations;
        #       Going over all options of arrangement and finding the optimal one
        @lru_cache(maxsize=None)
        def solve_remaining_groups(groups_by_batch_remainder, remaining):
            # If the sum of reminders is 0 - we can put all the remaining groups on the same day
            if 0 == sum(groups_by_batch_remainder):
                return 0
            # Going over all options of selecting a group with a given reminder as the group for current day
            # This loop finds the optimal arrangement without one of the groups
            happy_groups_current        = 0
            groups_by_batch_remainder   = list(groups_by_batch_remainder)
            for group_reminder in range(batch_size):
                if groups_by_batch_remainder[group_reminder]:
                    # Choosing a group for current day
                    groups_by_batch_remainder[group_reminder]   -= 1
                    happy_groups_current            = max(happy_groups_current, solve_remaining_groups(tuple(groups_by_batch_remainder), (remaining + group_reminder) % batch_size))
                    # Backtracking the chosen group for current day
                    groups_by_batch_remainder[group_reminder]   += 1
            # When arrived to this function, we had a `remaining` parameter
            # if it was 0 it means that whatever group we have choosen for today - they were not given previous remaining donuts 
            # the answer is therefore; 
            return (1 if not remaining else 0) + happy_groups_current
        remaining_happy_groups = solve_remaining_groups(tuple([counter[i] for i in range(batch_size)]), 0)
        # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Case 3 - End   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        return happy+remaining_happy_groups

s = Solution()
a = s.maxHappyGroups(4,[1,3,2,5,2,2,1,6])
print(a)