class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # Top-Down Memorize
        cache = {}
        
        def dfs(i, j):
            
            if (i,j) in cache:
                return cache[(i,j)]
            
            if i >= len(s) and j >= len(p):
                return True
            if j >= len(p):
                return False
            
            match = i < len(s) and (s[i] == p[j] or p[j] == '.')
            
            if (j+1) < len(p) and (p[j+1] == '*'):
                cache[(i,j)] = ( dfs(i, j+2) or             # not to use *
                                (match and dfs(i+1, j)) )  # use *
                return cache[(i,j)]
            
            if match:
                return dfs(i+1, j+1)
            
            return False
        
        return dfs(0,0)

# Optimize
class Solution:
    def isMatch(self, text, pattern):
        if not pattern:
            return not text

        first_match = bool(text) and pattern[0] in {text[0], '.'}

        if len(pattern) >= 2 and pattern[1] == '*':
            return (self.isMatch(text, pattern[2:]) or
                    first_match and self.isMatch(text[1:], pattern))
        else:
            return first_match and self.isMatch(text[1:], pattern[1:])