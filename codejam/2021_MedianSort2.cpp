// Brute-Force (TLE)
#include<iostream>
#include<vector>

using namespace std;

int ask(vector<int>& arr){
    int ret;
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    cin >> ret;
    return (ret == arr[0])? 0 : (ret == arr[1])? 1:2;
};

bool checkAnswer(vector<int> ans)
{
    int result;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    cin  >> result;
    return (result == 1);
};
int main()
{
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++)
    {
        int n, q;
        cin >> n >> q;
        vector<int> sorted(n, -1);
        
        while(checkAns(sorted)){

        }
    }
    return 0;
}