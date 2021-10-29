#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TrieNode{
    TrieNode* left, *right;
    bool isEnd;
    int val;
    TrieNode(int val) : val(val), isEnd(false), left(nullptr), right(nullptr);
}

void buildTree(TrieNode* root, vector<string>& s){
    for(int i = 0; i < s.size(); ++i){
        TrieNode* cur = root;
        int j = 0, len = s[i].length();
        while(j < len){
            if(s[i][j] == '0'){
                if(!cur->left)
                    cur->left = new TrieNode(len-j);
                else
                    cur->left->val = max(cur->left->val, len-j); 
                cur = cur->left;
            }else{
                if(!cur->right)
                    cur->right = new TrieNode(len-j);
                else
                    cur->right->val = max(cur->right->val, len-j);
                cur = cur->right;
            }
            j++;
        }
        cur->isEnd = true;
    }
    return;
}

// BFS
int maxDistance(vector<string> &s){
    int maxDist = 0;
    TrieNode* root = new TrieNode(0);
    buildTree(root, s);
    queue<TrieNode*> q;
    q.push(root);
    while(!q.empty()){
        TrieNode* cur = q.front(); q.pop();
        if(cur->left || cur->right){
            if(cur->left && cur->right)
                maxDist = max(maxDist, cur->left->val + cur->right->val);
            else if(cur->isEnd) // if the node is end, 
                maxDist = max(maxDist, cur->left? cur->left->val : cur->right->val);
        }
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    return maxDist;
}


// Main function
int main(){
    int n;
    scanf("%d",&n);
    vector<string>nums;
    nums.resize(n);
    for(int i=0;i<n;i++){
        //scanf("%s",&nums[i]);
        cin>>nums[i];
    }
    int max_distance=maxDistance(nums);
    printf("%d\n",max_distance);
    getchar();
    return 0;
}