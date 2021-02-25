class Solution{
public:
    vector<vector<int>> insert(vector<vector>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> ret;
        int insert_position = 0;
        for(auto interval : intervals)
        {
            if(interval[1] < newInterval[0]){
                // increase position
                ret.push_back(interval);
                insert_position++;
            }else if(interval[0] > newInterval[1]){
                ret.push_back(interval);
            }else{
                // merge newInterval
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        ret.insert(ret.begin() + insert_position, newInterval);
        return ret;
    }
}