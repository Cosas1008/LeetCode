/*
Input: [5, 2, 4, 3, 1, 6]
Output: 3
Explanation:
You can split this array into: [5, 2, 1], [4, 3], [6]. And there are 3 subsequences you get.
Or you can split it into [5, 4, 3], [2, 1], [6]. Also 3 subsequences.
But [5, 4, 3, 2, 1], [6] is not legal because [5, 4, 3, 2, 1] is not a subsuquence of the original array.

Assume: 1 <= A.size() <= 1e6

Challenge : Solve it in O(nlgn)
*/
class Solution {
public:
    int splitDecreasing(vector<int>& A){
        vector<int> container;
        container.push_back(A[0]);
        for(int i = 1; i < A.size(); ++i){
            auto it = upper_bound(container.begin(), container.end(), A[i]);
            if(it == container.end())
                container.push_back(A[i]);
            else
                *it = A[i];
        }
        return container.size();
    }
}
/*
Input: [5, 2, 4, 3, 1, 6]
Result:
Container: [5]
Container: [2]
Container: [2,4]
Container: [2,3]
Container: [1,3]
Container: [1,3,6]
*/