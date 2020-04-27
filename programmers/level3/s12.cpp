// 단어 변환
#include<bits/stdc++.h>

using namespace std;

bool visited[60];
bool flag=false;
int min_=987987987;

bool check(string s1, string s2) {
    int cnt=0;

    for(int i=0;i<s1.size();i++) {
        if(s1.at(i)!=s2.at(i)) cnt++;
        if(cnt>=2) return false;
    }

    if(cnt<1) return false;

    return true;
}

void dfs(string begin,string target,vector<string> words,int cnt) {
    // base condition
    if(begin==target) {
        flag=true;
        if(min_>cnt) min_=cnt;
    } else {
        for(int i=0;i<words.size();i++) {
            if(!visited[i] && check(begin,words[i])) {
                visited[i]=true;
                dfs(words[i],target,words,cnt+1);
                visited[i]=false;
            } 
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    dfs(begin,target,words,0);

    if(flag) answer=min_; 

    return answer;
}

int main() {

    string begin="hit", target="cog";
    vector<string> words={"hot", "dot", "dog", "lot", "log", "cog"};

    int result=solution(begin,target,words);
    printf("%d\n",result);

    return 0;
}