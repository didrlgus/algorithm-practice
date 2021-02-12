// 순위 검색
#include<bits/stdc++.h>
using namespace std;
string s[4],num;
unordered_map<string,vector<int>> mp;
vector<string> v;
void combi(int score,int cnt) {
    if(cnt==4) {
        string key=v[0]+v[1]+v[2]+v[3];
        mp[key].push_back(score);
        return;
    }
    for(int i=0;i<2;i++) {
        if(i==0) v.push_back(s[cnt]);
        else v.push_back("-");
        combi(score,cnt+1);
        v.pop_back();
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(auto it:info) {
        stringstream ss(it);
        ss>>s[0]>>s[1]>>s[2]>>s[3]>>num;
        v.clear();
        combi(stoi(num),0);
    }
    for(auto it=mp.begin();it!=mp.end();it++) sort(it->second.begin(),it->second.end());
    for(auto it:query) {
        stringstream ss(it);
        ss>>s[0]>>num>>s[1]>>num>>s[2]>>num>>s[3]>>num;
        string key=s[0]+s[1]+s[2]+s[3];
        vector<int> vv=mp[key];
        int score=stoi(num);
        if((int)vv.size()>0) {
            int val=vv.end()-lower_bound(vv.begin(),vv.end(),score);
            answer.push_back(val);
        } else answer.push_back(0);
    }
    return answer;
}
int main() {
    vector<string> info={"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query={"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    vector<int> ret=solution(info,query);
    for(auto it:ret) printf("%d ",it);
    printf("\n");
    return 0;
}