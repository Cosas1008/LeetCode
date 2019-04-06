class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
        {
           return 0; 
        }
        else
        {
            int count = 1;
            for(int i = 0; i< nums.size()-1; i++)
            {
                int current = nums[i];
                int next = nums[i+1];
                if(current < next)
                    count++;
                else{
                    compare(count);
                    count = 1;
                }
            }
            compare(count);
            return this->max;
        }
    }
private:
    int max = 0;
    void compare(int num)
    {
        if(num > this->max)
            this->max = num;
    }
};