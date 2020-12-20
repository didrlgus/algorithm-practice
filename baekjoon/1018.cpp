#include<bits/stdc++.h>
using namespace std;
int n,m,ret=987654321;
char arr[55][55];
string s1,s2;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=8;i++) {
        if(i&1) {
            s1+='W';
            s2+='B';
        } else {
            s1+='B';
            s2+='W';
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    for(int r=0;r<=n-8;r++) {
        for(int c=0;c<=m-8;c++) {
            int cnt1=0,cnt2=0;
            for(int i=0;i<8;i++) {
                if(i&1) {
                    for(int j=0;j<8;j++) {
                        if(s2[j]!=arr[i+r][j+c]) cnt1++;
                        if(s1[j]!=arr[i+r][j+c]) cnt2++;
                    }
                } else {
                    for(int j=0;j<8;j++) {
                        if(s1[j]!=arr[i+r][j+c]) cnt1++;
                        if(s2[j]!=arr[i+r][j+c]) cnt2++;
                    }
                }
            }
            ret=min(ret,min(cnt1,cnt2));
        }
    }
    printf("%d\n",ret);
    return 0;
}