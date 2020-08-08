// 베스트앨범
#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
map<string,vector<pair<int,int>>> mp2;
vector<pair<string,int>> v;
bool cmp(pair<string,int> p1,pair<string,int> p2) {
    return p1.second>p2.second;
}
bool cmp2(pair<int,int> p1,pair<int,int> p2) {
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first>p2.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<(int)genres.size();i++) {
        mp[genres[i]]+=plays[i];
        mp2[genres[i]].push_back({plays[i],i});
    }
    for(auto it:mp) v.push_back({it.first,it.second});
    sort(v.begin(),v.end(),cmp);
    for(auto it:v) {
        vector<pair<int,int>> tmp=mp2[it.first];
        if((int)tmp.size()==1) {
            answer.push_back(tmp.front().second);
            continue;
        }
        sort(tmp.begin(),tmp.end(),cmp2);
        answer.push_back(tmp[0].second),answer.push_back(tmp[1].second);
    }
    return answer;
}
int main() {
    vector<string> genres={"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays={500, 600, 150, 800, 2500};
    vector<int> answer=solution(genres,plays);
    for(auto it:answer) printf("%d ",it);
    return 0;
}