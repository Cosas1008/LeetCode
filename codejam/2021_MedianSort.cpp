#include<iostream>
#include<vector>

using namespace std;

int ask(vector<int>& arr){
    int ret;
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    cin >> ret;
    return (ret == arr[0])? 0 : (ret == arr[1])? 1:2;
}

int main()
{
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++)
    {
        int n, q;
        cin >> n >> q;
        vector<int> sorted(n);
        for(int i = 0; i < n; i++){
            sorted[i] = i+1;
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    vector<int> query(3);
                    query[0] = i;
                    query[1] = j;
                    query[2] = k;
                    int idx = ask(query);
                    if(idx == 0){ // left is mid
                        swap(sorted[j], sorted[i]);
                    }else if(idx == 1){ // right is mid
                        swap(sorted[j], sorted[k]);
                    }
                }
            }
        }
        cout << "Case #" << ti+1 << ": ";
        for(int i = 0; i < n; i++){
            cout << sorted[i] << " ";
        }
        cout << endl;
    }
    return 0;
}