class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

       vector<int> outarray;
        if(n == 0){
            for(int j=0;j<m;j++)
                outarray.push_back(nums1[j]);
        }else if(m == 0){
            for(int i=0;i<n;i++)
                outarray.push_back(nums2[i]);
        }else{
            for(int i=0, j =0; i < n || j<m;){
                if(nums1[j] < nums2[i] && nums1[j] != 0){
                    outarray.push_back(nums1[j]);
                    j++;
                }else if(nums2[i] != 0){
                    outarray.push_back(nums2[i]);
                    i++;
                }
            }
        }
        nums1.clear();
        for(int k =0; k < m+n;k++){
            nums1.push_back(outarray[k]);
        }
    }
};
//optimized two
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(n == 0){
            return;
        }else if(m == 0){
            nums1.clear();
            for(int i=0;i<n;i++)
                nums1.push_back(nums2[i]);
        }else{
            for(int i=0, j =0; i < n || j < m;){
                if(nums1[j] < nums2[i] && nums1[j] != 0){
                    nums1.push_back(nums1[j]);
                    j++;
                }else if(nums1[j] > nums2[i] && nums2[i] != 0){
                    nums1.push_back(nums2[i]);
                    i++;
                }
            }
        }
    }
};
//Accepted solution
struct comparator {
    bool operator()(int i, int j) {
        return i > j;
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        priority_queue<int, std::vector<int>, comparator> minHeap;
        for(int i = 0; i < m; i++)
            minHeap.push(nums1[i]);
        for(int i = 0; i < n; i++)
            minHeap.push(nums2[i]);
        nums1.clear();
        for(int i = 0; i < m + n; i++) {
            nums1.push_back(minHeap.top());
            minHeap.pop();
        }

    }   
};