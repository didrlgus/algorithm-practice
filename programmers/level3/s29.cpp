// 불량 사용자
#include<bits/stdc++.h>

using namespace std;

int bannSize;
bool visited[15];
set<string> set_;

bool check(string s1, string s2) {
    if(s1.size()!=s2.size()) return false;

    for(int i=0;i<s2.size();i++) {
        if(s2[i]=='*') continue;
        if(s1[i]!=s2[i]) return false;
    }
    return true;
}

// bann의 모든 요소를 돌면서 user_id에 매칭되는 모든 경우를 구한다
void dfs(vector<string> user_id, vector<string> banned_id, int current) {
    if(current==bannSize) {     // base condition
        string s;

        for(int i=0;i<user_id.size();i++) {
            if(visited[i]) s+=to_string(i);
        }
        set_.insert(s);

        return;
    }
    for(int i=0;i<user_id.size();i++) {
        string s1=user_id[i],s2=banned_id[current];
        if(!visited[i] && check(s1,s2)) {
            visited[i]=true;
            dfs(user_id,banned_id,current+1);
            visited[i]=false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    bannSize=banned_id.size();

    dfs(user_id,banned_id,0);
    answer=set_.size();

    return answer;
}

int main() {

    vector<string> user_id={"frodo", "fradi", "crodo", "abc123", "frodoc"}, 
            banner_id={"fr*d*", "*rodo", "******", "******"};

    int result=solution(user_id,banner_id);
    printf("%d\n",result);

    return 0;
}