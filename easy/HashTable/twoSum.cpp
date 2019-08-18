#include <unordered_map>

using namespace std;
class Solution
{
public:
    // brute-force
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> returnVector(2);
        int length = nums.size();
        int remains;
        for (int i = 0; i < length; i++)
        {
            remains = target - nums[i];
            //find the next couple value
            for (int j = length - 1; j >= 0; j--)
            {
                if (nums[j] == remains && i != j)
                {
                    returnVector[0] = i;
                    returnVector[1] = j;
                    return returnVector;
                }
            }
        }
    };
    // hash table
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> ht;
        vector<int> result;
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     ht.insert(make_pair(nums[i], i));
        // }
        for (int i = 0; i < nums.size(); ++i)
        {
            auto search = ht.find(target - nums[i]);
            if (search != ht.end())
            {
                result.push_back(search->second);
                result.push_back(i);
                return result;
            }
            ht[nums[i]] = i;
        }
        return result;
    }
};