/*
You have n binary tree nodes numbered from 0 to n - 1
return true if and only if all the given nodes form exactly one valid binary tree.
1. Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
2. Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
Output: false
*/
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>  degree(n, 0);
        int root = -1;
        // record node level and check if degree > 1 return false
        for(int i = 0; i < n; ++i){
            if(leftChild[i] != -1 && degree[leftChild[i]]++ == 1)
                return false;
            else if(rightChild[i] != -1 && degree[rightChild[i]]++ == 1)
                return false;
        }
        // find root and check multiple root
        for(int i = 0; i < n; ++i){
            if(degree[i] == 0){
                if(root == -1) root = i;
                else return false; // multiple root
            }
        }
        return countNode(leftChild, rightChild, root) == n;
    }
    int countNode(vector<int>& l, vector<int>& r, int root){
        if(root == -1) return 0;
        return 1 + countNode(l,r, l[root]) + countNode(l, r, r[root]);
    }
};
// Traverse
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        vector<bool> visited(n,false);
        visited[0]=true;                   	//Mark root as visited.
        for(int i=0;i<leftChild.size();i++)
        {
            //If 1. parent isn't visited or 2. Child has previously been visited return false.
            if(!visited[i] || 
                leftChild[i] != -1 && visited[leftChild[i]] || 
                rightChild[i]!= -1 && visited[rightChild[i]])	
                return false;
            if(leftChild[i] != -1)			//Mark left child as visited.
                visited[leftChild[i]] = true;
            if(rightChild[i] != -1)			//Mark right child as visited.
                visited[rightChild[i]] = true;
        }
        return true;
    }
};