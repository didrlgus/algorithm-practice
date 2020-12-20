#include<bits/stdc++.h>
using namespace std;
int n,half;
map<int,int> count_mp,idx_mp;
vector<int> numbers;
vector<pair<int,int>> v;
map<int,bool> check;
bool cmp(pair<int,int> p1,pair<int,int> p2) {
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second>p2.second;
}
int solution(vector<int> &A) {
    n=(int)A.size();
    half=n/2;
    if(n==0) return -1;
    if(n==1) return 0;
    for(int i=1;i<=(int)A.size();i++) {
        int el=A[i-1];
        count_mp[el]++;
        if(!idx_mp[el]) idx_mp[el]=i;
        if(!check[el]) {
            numbers.push_back(el);
            check[el]=true;
        }
    }
    for(auto it:numbers) {
        int cnt=count_mp[it];
        v.push_back({it,cnt});
    }
    sort(v.begin(),v.end(),cmp);
    pair<int,int> one=v[0],two=v[1];
    if(one.second==two.second) return -1;
    if(one.second<=half) return -1; 
    return idx_mp[one.first]-1;
}