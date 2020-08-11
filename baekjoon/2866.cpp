// 문자열 잘라내기
#include<bits/stdc++.h>
using namespace std;
int n,m,lo,hi,ret;
char arr[1005][1005];
bool check(int mid) {
    set<string> st;
    for(int j=0;j<m;j++) {
        string s="";
        for(int i=mid;i<n;i++) s+=arr[i][j];
        if(st.find(s)!=st.end()) return true;
        st.insert(s);
    }
    return false;
}
int main() {    
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    lo=0,hi=n-1;
    // 처음으로 중복이 시작되는 지점 찾기
    while(lo<=hi) {
        int mid=(lo+hi)/2;
        if(check(mid)) hi=mid-1;
        else lo=mid+1;
    }
    printf("%d\n",hi);
    return 0;
}