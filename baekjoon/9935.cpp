// 문자열 폭발
#include<bits/stdc++.h>
using namespace std;
string s,bomb,ret;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>s>>bomb;
    int bs=(int)bomb.size();
    for(auto c:s) {
        ret+=c;
        int rs=(int)ret.size();
        if(rs>=bs&&c==bomb[bs-1]) {
            bool flag=false;
            int b_idx=bs-1;
            for(int i=rs-1;i>=rs-bs;i--) {
                if(ret[i]!=bomb[b_idx--]) {
                    flag=true;
                    break;
                }
            }
            if(!flag) {
                for(int i=0;i<bs;i++) ret.pop_back();   // 여기서 substr 사용 시 시간초과
            }
        }
    }
    if((int)ret.size()==0) cout<<"FRULA"<<"\n";
    else cout<<ret<<"\n";
    return 0;
}