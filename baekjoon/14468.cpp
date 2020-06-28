// 소가 길을 건너간 이유 2
#include<bits/stdc++.h>
using namespace std;
int ret;
string s;
pair<int,int> arr[30];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    for(int i=0;i<52;i++) {
        int idx=s[i]-'A';
        if(arr[idx].first) arr[idx].second=i+1;
        else arr[idx].first=i+1;
    }
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            if(i==j) continue;
            int s1,e1,s2,e2;
            s1=arr[i].first;
            e1=arr[i].second;
            s2=arr[j].first;
            e2=arr[j].second;
            if(s1<s2&&s2<e1&&e1<e2) ret++;
        }
    }
    cout<<ret<<'\n';
    return 0;
}