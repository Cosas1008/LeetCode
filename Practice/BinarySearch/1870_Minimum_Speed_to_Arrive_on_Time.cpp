class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour < (double)(N-1)){
            return -1;
        }
        int lo = 1, hi = 1e7, mi;
        while(lo < hi){
            mi = (lo + hi) / 2;
            if(canReach(dist, hour, mi))
                hi = mi;
            else
                lo = mi+1;
        }
        return hi;
    }
private:
    bool canReach(vector<int>& dist, double hour, int speed){
        double time = 0;
        for(int i = 0; i < dist.size() - 1; i++){
            time += (dist[i] + speed - 1) / speed;
        }
        time += ((double) dist.back() / speed);
        return time <= hour;
    }
};