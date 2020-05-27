// 방번호
#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    cnt.resize(10);
    for(int i=0;i<s.size();i++) {
        if(s[i]=='6') cnt[9]++;
        else cnt[s[i]-'0']++;
    }
    if(cnt[9]%2==0) cnt[9]/=2;
    else cnt[9]=cnt[9]/2+1;
    sort(cnt.begin(),cnt.end());
    printf("%d\n",cnt[9]);
    return 0;
}