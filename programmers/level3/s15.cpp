// 여행경로
#include<bits/stdc++.h>

using namespace std;

bool visit[10010];
vector<string> answer;
bool dfs(string start, vector<vector<string>> tickets,int cnt) { 
    answer.push_back(start); 
    
    if (cnt==tickets.size()) return true; 
    
    for (int i=0;i<tickets.size();i++) { 
        if (!visit[i] && tickets[i][0]==start) { 
            visit[i]=true; 
            if(dfs(tickets[i][1],tickets,cnt+1)) return true; 
            visit[i]=false;
        } 
    } 
    answer.pop_back();  // dfs의 결과가 true가 아닌 경우. 즉, for문을 모두 수행하면서 모든 티켓을 다 이용하지 못한 경우
    return false; 
} 

vector<string> solution(vector<vector<string>> tickets) { 
    sort(tickets.begin(), tickets.end()); 
    dfs("ICN", tickets,0); 
    return answer; 
}

int main() {

    vector<vector<string>> tickets={{"ICN", "SFO"}, {"ICN", "TIA"}, {"TIA", "ICN"}};
    vector<string> result=solution(tickets);

    for(int i=0;i<result.size();i++) cout<<result[i]<<endl;

    return 0;
}