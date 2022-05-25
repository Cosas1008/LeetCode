#include<iostream>

using namespace std;

vector<int> helper(vector<int> ans, int sum, int mul, int k){
    if(sum * sum == mul) return ans;
    if(k == 0 ) return {};
    int add = 1;
    // how to iterate all posible pos/neg value?
}
int main(){
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ++ti){
        int n, k;
        cin >> n >> k;
        int tmp, sum, mul;
        sum = mul = 0;
        for(int i = 0; i < n; ++i){
            cin >> tmp;
            sum += tmp;
            mul = tmp*tmp;
        }
        int ans = 0;
        if(sum == mul){
            cout << "Case #" << ti+1 << ": " << ans << endl;
            continue;
        }
        vector<int> ans = helper(sum, mul, k);
        if(ans.size() == 0)
            cout << "Case #" << ti+1 << ": IMPOSSIBLE" << endl;
        else{
            cout << "Case #" << ti+1 << ": ";
            for(int i = 0; i < ans.size(); ++i){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}