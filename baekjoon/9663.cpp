#include<bits/stdc++.h>
using namespace std;
int n;
bool cross1[65],cross2[65],col[20];
int go(int row) {
    if(row==n) return 1;
    int ret=0;
    for(int j=0;j<n;j++) {
        if(cross1[row+j]||cross2[row-j+n-1]||col[j]) continue;
        cross1[row+j]=true;
        cross2[row-j+n-1]=true;
        col[j]=true;
        ret+=go(row+1);
        cross1[row+j]=false;            
        cross2[row-j+n-1]=false;
        col[j]=false;
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    printf("%d\n",go(0));
    return 0;
}