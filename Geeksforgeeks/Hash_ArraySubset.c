#include <stdio.h>


int main()
{
    int npro;
    scanf("%d", &npro);
    for(int k =0; k < npro; k++){
        int n, m;
        scanf("%d %d", &n, &m);
        int a[n], b[m];
        for(int i=0; i < n; i++){
            scanf("%d", &a[i]);
        }
        for(int j=0;j < m; j++){
            scanf("%d", &b[j]);
        }
        // brute-force
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i]==b[j]){
                    count++;
                    break;
                }
            }
        }
        if(count == m){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
