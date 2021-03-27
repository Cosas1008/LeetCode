#include <iostream>
#include <vector>

using namespace std;

// Recursive
int reverSort(int i, vector<int> arr, int iter){
    if(i == arr.size()-1) return iter;
    if(arr[i] == i+1) return reverSort(i+1, arr, iter+1);
    int j = arr.size() - 1;
    for(; j >= 0; j--){
        if(arr[j] == i+1) break;
    }
    int count = j - i + 1;
    int t = i;
    while(j > t){
        swap(arr[j--], arr[t++]);
    }
    return reverSort(i+1, arr, iter+count);
};

int main()
{
    int t, n;
    cin >> t;

    for(int ti = 0; ti < t; ti++){
        cin >> n;
        vector<int> arr(n, 0);
        for(int ni = 0; ni < n; ni++){
            cin >> arr[ni];
        }
        cout << "Case #" << ti+1 << ": " << reverSort(0, arr, 0) << endl;
    }
    return 0;
}