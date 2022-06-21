/*
A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.
A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
*/
class Solution {
public:
    // Hash
    int longestWPI(vector<int>& hours) {
        int days = 0, ans = 0;
        unordered_map<int,int> seen; // store the first time we see the day on ith day
        for(int i = 0; i < hours.size(); i++){
            days += hours[i] > 8? 1 : -1;
            if(days > 0)
                ans = i + 1;
            else{
                if(seen.find(days) == seen.end()) // record the earliest seen days
                    seen[days] = i;
                if(seen.find(days - 1) != seen.end()) // we want the first occurence of days - 1
                    ans = max(ans, i - seen[days - 1]);
            }
        }
        return ans;
    }
    // brute-force (TLE)
    int longestWPI(vector<int>& hours) {
        int result = 0;
        for(int i = 0; i < hours.size(); i++){
            hours[i] = hours[i] > 8 ? 1 : -1;
        }
        for(int i = 0; i < hours.size(); i++){
            int sum = 0;
            for(int j = i; j < hours.size(); j++){
                sum += hours[j];
                if(sum > 0) result = max(result, j - i + 1);
            }
        }
        return result; 
    }
};