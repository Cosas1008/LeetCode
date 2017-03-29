#include <iostream>
#include <cstdio>

using namespace std;
double factorial(int num){
    int i;
    double fact =1;
    for(i=1;i<=num;i++)
    {
        fact=fact*i;
    }
    return fact;
}
int solve(int n, int k) {
    int count = 0;
    for(int i =0; i < k; i ++){
        if( k -i >= 1){
            double numerator = factorial(n-1);
            double fact_k = factorial(k-i);
            double denum = factorial(n-1-k+i);
            count += numerator/fact_k/denum;
        }else{
            break;
        }
    }
    return count;

}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n", solve(n, k));
	return 0;
}