class Solution:
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        count = Counter([g % batchSize for g in groups])
        g = [count[i] for i in range(batchSize)]
        
        @lru_cache(None)
        def dp(sm, t):
            if max(t) == 0:
                return 0
            
            ans, arr = 0, list(t)
            
            for k in range(batchSize):
                if arr[k] == 0:
                    continue
                arr[k] -= 1
                ans = max(ans, dp((sm + k) % batchSize, tuple(arr)))
                arr[k] += 1
            return ans + (sm==0)
        
        return dp(0, tuple(g))