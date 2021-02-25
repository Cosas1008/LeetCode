/*  This case shows function stack FILO */
#include<iostream>

using namespace std;
int call;

int fibonacci(int N){
    cout << "Call: " << call++ << " / N " << N << endl;
    if(N == 1 || N == 2) return 1;
    return fibonacci(N-1) + fibonacci(N-2);
}

int main(){
    fibonacci(5);
    return 0;
}