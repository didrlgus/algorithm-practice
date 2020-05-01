// 베스트앨범
#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<string,int> p1,pair<string,int> p2) {
    return p1.second>p2.second;
}

bool cmp2(pair<int,int> p1,pair<int,int> p2) {
    return p1.first>p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> mp;
    vector<pair<string, int>> v;

    for(int i=0;i<genres.size();i++) {
        mp[genres[i]]+=plays[i];
    }

    for(auto iter:mp) {
        v.push_back({iter.first,iter.second});
    }

    sort(v.begin(),v.end(),cmp);    // second 기준 내림차순

    for(int i=0;i<v.size();i++) {   // 장르
        vector<pair<int,int>> v2;   // <plays,index>

        for(int j=0;j<genres.size();j++) {
            if(v[i].first==genres[j]) v2.push_back({plays[j],j});
        }

        sort(v2.begin(),v2.end(),cmp2);     // first 기준 내림차순

        if(v2.size()<2) answer.push_back(v2[0].second);
        else {
            answer.push_back(v2[0].second);
            answer.push_back(v2[1].second);
        }
    }

    return answer;
}

int main() {

    vector<string> genres={"classic", "pop", "classic", "classic", "pop"}; 
    vector<int> plays={500, 600, 150, 800, 2500};

    vector<int> result=solution(genres,plays);

    for(auto iter:result) printf("%d ",iter);

    return 0;
}