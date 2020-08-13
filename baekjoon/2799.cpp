// 블라인드
#include<bits/stdc++.h>
using namespace std;
int n,m,check[10];
char arr[1000][1000];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<5*n+1;i++) {
        for(int j=0;j<5*m+1;j++) scanf(" %1c",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        int row=1+5*i;
        for(int j=0;j<m;j++) {
            int col=1+5*j,cnt=0;
            for(int a=row;a<row+4;a++) {
                if(arr[a][col]=='*') cnt++;
            }
            check[cnt]++;
        }
    }
    for(int i=0;i<5;i++) printf("%d ",check[i]);
    return 0;
}