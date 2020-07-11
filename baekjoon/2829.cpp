// 아름다운 행렬
#include<bits/stdc++.h>
using namespace std;
int n,arr[405][405],p_sum1[405][405],p_sum2[405][405],ret;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) scanf("%d",&arr[i][j]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            p_sum1[i][j]=p_sum1[i-1][j-1]+arr[i][j];
            p_sum2[i][j]=p_sum2[i-1][j+1]+arr[i][j];
        }
    }
    for(int s=2;s<=n;s++) {
        for(int i=1;i<=n-s+1;i++) {
            for(int j=1;j<=n-s+1;j++) {
                ret=max(ret,(p_sum1[i+s-1][j+s-1]-p_sum1[i-1][j-1])-(p_sum2[i+s-1][j]-p_sum2[i-1][j+s]));
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}