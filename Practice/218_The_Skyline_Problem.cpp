/*
The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti   is the x coordinate of the left edge of the ith building.
righti  is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int,int>> chkpoint;
        pair<int,int> curr({0,0});
        vector<vector<int>> ans;
        for(auto building : buildings){
            chkpoint.emplace(building[0], -building[2]);
            chkpoint.emplace(building[1], building[2]);
        }
        multiset<int> height({0});
        for(auto p : chkpoint){
            if(p.second < 0)
                height.insert(-p.second);
            else
                height.erase(height.find(p.second));
            if(*height.rbegin() != curr.second){
                curr.first = p.first;
                curr.second = *height.rbegin();
                ans.push_back({curr.first, curr.second});
            }
        }
        return ans;
    }
};