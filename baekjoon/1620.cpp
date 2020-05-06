// 나는야 포켓몬 마스터 이다솜
#include<bits/stdc++.h>

using namespace std;

int n,m;
string arr[100010];
unordered_map<string,int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        arr[i]=s;
        mp[s]=i;
    }

    for(int i=0;i<m;i++) {
        string s;
        cin>>s;
        
        if(s[0]>='0' && s[0]<='9') {
            cout<<arr[atoi(s.c_str())]<<"\n";
        } else {
            cout<<mp[s]<<"\n";
        }
    }

    return 0;
}