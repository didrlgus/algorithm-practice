#include<bits/stdc++.h>
using namespace std;
char arr[]={'A','C','G','T'};
map<char,int> mp;
vector<int> ret;
vector<int> solution(string &s, vector<int> &p, vector<int> &q) {
    vector<int> v[4];
    mp['A']=0;mp['C']=1;mp['G']=2;mp['T']=3;
    for(int i=0;i<4;i++) v[i].push_back(0);
    for(int i=1;i<=(int)s.size();i++) {
        char ch=s[i-1];
        for(int j=0;j<4;j++) {
            if(ch==arr[j]) {
                vector<int> &cur_vec=v[mp[ch]];
                cur_vec.push_back(cur_vec[i-1]+1);
            } else {
                vector<int> &cur_vec=v[mp[arr[j]]];
                cur_vec.push_back(cur_vec[i-1]);
            }
        }
    }
    for(int i=0;i<(int)p.size();i++) {
        int start=p[i]+1,end=q[i]+1;
        for(int j=0;j<4;j++) {
            if(v[j][end]-v[j][start-1]>0) {
                ret.push_back(j+1);
                break;
            }
        }
    }
    return ret;
}