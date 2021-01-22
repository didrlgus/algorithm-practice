// 누울 자리를 찾아라
#include<bits/stdc++.h>
using namespace std;
int n,r_cnt,c_cnt;
char arr[105][105];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf(" %1c",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0;j<n;j++) {
            if(arr[i][j]=='.') cnt++;
            else {
                if(cnt>=2) r_cnt++;
                cnt=0;
            }
        }
        if(cnt>=2) r_cnt++;
    }
    for(int j=0;j<n;j++) {
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(arr[i][j]=='.') cnt++;
            else {
                if(cnt>=2) c_cnt++;
                cnt=0;
            }
        }
        if(cnt>=2) c_cnt++;
    }
    printf("%d %d\n",r_cnt,c_cnt);
    return 0;
}