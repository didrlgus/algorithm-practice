// 큐빙
#include<bits/stdc++.h>
using namespace std;
int tc;
vector<char> v;
vector<int> u={20,19,18,38,37,36,29,28,27,47,46,45},d={24,25,26,51,52,53,33,34,35,42,43,44},
f={6,7,8,45,48,51,11,10,9,44,41,38},b={2,1,0,36,39,42,15,16,17,53,50,47},
l={0,3,6,18,21,24,9,12,15,35,32,29},r={8,5,2,27,30,33,17,14,11,26,23,20};
vector<int> uu={0,1,2,5,8,7,6,3},dd={9,10,11,14,17,16,15,12},ff={18,19,20,23,26,25,24,21},
bb={27,28,29,32,35,34,33,30},ll={36,37,38,41,44,43,42,39},rr={45,46,47,50,53,52,51,48};
void init() {
    v.clear();
    for(int i=0;i<9;i++) v.push_back('w');
    for(int i=9;i<18;i++) v.push_back('y');
    for(int i=18;i<27;i++) v.push_back('r');
    for(int i=27;i<36;i++) v.push_back('o');
    for(int i=36;i<45;i++) v.push_back('g');
    for(int i=45;i<54;i++) v.push_back('b');
}
void func(int dir,int start,int end,vector<int> vv,vector<int> vvv) {
    vector<char> rv,fv;
    for(auto iter:vv) rv.push_back(v[iter]);
    for(int i=0;i<3;i++) {
        if(dir==0) rotate(rv.begin(),rv.begin()+rv.size()-1,rv.end());
        else rotate(rv.begin(),rv.begin()+1,rv.end());
    }
    int idx=0;
    for(auto iter:vv) v[iter]=rv[idx++];
    for(auto iter:vvv) fv.push_back(v[iter]);
    for(int i=0;i<2;i++) {
        if(dir==0) rotate(fv.begin(),fv.begin()+fv.size()-1,fv.end());
        else rotate(fv.begin(),fv.begin()+1,fv.end());
    }
    idx=0;
    for(auto iter:vvv) v[iter]=fv[idx++];
}
void go(string s) {
    if(s=="U+") func(0,0,9,u,uu);
    else if(s=="U-") func(1,0,9,u,uu);
    else if(s=="D+") func(0,9,18,d,dd);
    else if(s=="D-") func(1,9,18,d,dd);
    else if(s=="F+") func(0,18,27,f,ff);
    else if(s=="F-") func(1,18,27,f,ff);
    else if(s=="B+") func(0,27,36,b,bb);
    else if(s=="B-") func(1,27,36,b,bb);
    else if(s=="L+") func(0,36,45,l,ll);
    else if(s=="L-") func(1,36,45,l,ll);
    else if(s=="R+") func(0,45,54,r,rr);
    else func(1,45,54,r,rr);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>tc;
    while(tc--) {
        init();
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
            string s;
            cin>>s;
            go(s);
        }
        for(int i=0;i<9;i++) {
            cout<<v[i];
            if(i%3==2) cout<<'\n';
        }
    }
    return 0;
}