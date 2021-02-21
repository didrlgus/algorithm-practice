// 메뉴 리뉴얼
#include<bits/stdc++.h>
using namespace std;
struct Data {
    string keyword;
    int cnt;
};
map<string,int> mp;
string s,tmp_s;
bool cmp(Data& d1,Data& d2) {
    return d1.cnt>d2.cnt;
}
void combi(int here,int n) {
    if((int)tmp_s.size()==n) {
        string key=tmp_s;
        sort(key.begin(),key.end());
        mp[key]++;
        return;
    }
    for(int i=here+1;i<(int)s.size();i++) {
        tmp_s+=s[i];
        combi(i,n);
        tmp_s.pop_back();
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto it:course) {
        int len=it;
        for(auto order:orders) {
            s=order;
            tmp_s="";
            if((int)order.size()<len) continue;
            combi(-1,len);
        }
        vector<Data> v;
        for(auto pa:mp) v.push_back({pa.first,pa.second});
        mp.clear();
        if((int)v.size()==0) continue;
        sort(v.begin(),v.end(),cmp);
        int mx=v[0].cnt;
        for(auto data:v) {
            if(mx>data.cnt) break;
            if(data.cnt>1) answer.push_back(data.keyword);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
int main() {
    vector<string> orders={"XYZ", "XWY", "WXA"};
    vector<int> course={2,3,4};
    vector<string> ret=solution(orders,course);
    for(auto it:ret) cout<<it<<' ';
    return 0;
}