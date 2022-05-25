#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ++ti){
        int p;
        cin >> p;
        vector<int> cake(p);
        for(int& it : cake)
            scanf("%d", &it);
        
        vector<int> left(p, 0), right(p, 0);

        int value = -1;
        for(int i = 0; i < p; ++i){
            left[i] = (i==0)? 1 : left[i-1] + (cake[i] >= value);
            value = max(value, cake[i]);
        }
        value = -1;
        for(int i = p-1; i >= 0; --i){
            right[i] = (i==p-1)? 1 : right[i+1] + (cake[i] >= value);
            value = max(value, cake[i]);
        }

        int ans = 0;
        for(int i = 0; i <= p; ++i)
            ans = max(ans, (i == 0? 0 : left[i-1]) + (i==p? 0 : right[i]));

        printf("Case #%d: %d\n", ti+1, ans);
    }
    return 0;
}