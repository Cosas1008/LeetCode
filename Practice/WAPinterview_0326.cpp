#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> void printVector(const vector<T> &integers){
    typename vector<T>::const_iterator constIterator;
    for(constIterator = integers.begin(); constIterator != integers.end(); ++constIterator)
        cout << *constIterator << " ";
}

string tell(vector<double> n_vec , double m){
    sort(n_vec.begin(), n_vec.end());
    int length = n_vec.size();
    string reply;
    // we want to find m in the n_vec first
    for(int i =0; i < length; i++){
        if((fmod(n_vec[i],m)) == 0){
            reply = "Yes";
            break;
        }else{
            //deal with compliment
            if((fmod(n_vec[i],m)) == m){    // means the m is small than stored number
                n_vec[i] -= fmod(m,n_vec[i]);
            }else{  //means the stored number can have mod(m) value
                m -= fmod(n_vec[i],m);
            }
            reply = "No"; // go on for searching
        }
    }
    return reply;
}

int main() {
    int length;
    double sum;
    cin >> length >> sum;
    vector<double> arr(length);
    for(int i=0; i < length; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << tell(arr, sum );
    return 0;
}