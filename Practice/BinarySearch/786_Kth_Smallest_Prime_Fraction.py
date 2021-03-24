# https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85170/on-from-paper-yes-orows
def kthSmallestPrimeFraction(self, A, K):
    class Row(int):
        def __getitem__(self, j):
            return float(self) / A[~j], [int(self), A[~j]]
    return self.kthSmallest(map(Row, A), K)[1]