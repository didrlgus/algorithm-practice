// 게리맨더링
#include<bits/stdc++.h>

using namespace std;

int n;
int people[15];
vector<int> graph[15];

bool visited[15],visited2[15];
int mn=987654321;

void dfs(int current) {
    for(int i=0;i<graph[current].size();i++) {
        int y=graph[current][i];

        if(visited[y]) {
            visited[y]=false;
            dfs(y);
        }
    }
}

void combi(int here,vector<int> &v1,int a) {
    if(v1.size()==a) {
        fill(&visited[0],&visited[0]+15,false);
        for(int i=1;i<v1.size();i++) visited[v1[i]]=true;           // 1팀 색칠 (시작점 제외)
        dfs(v1[0]);

        for(int i=1;i<=n;i++) if(visited[i]) return;
        
        vector<int> v2;
        for(int i=1;i<=n;i++) v2.push_back(i);
        for(int i=0;i<v1.size();i++) {
            for(int j=0;j<v2.size();j++) {
                if(v1[i]==v2[j]) v2.erase(v2.begin()+j);
            }
        }
        fill(&visited[0],&visited[0]+15,false);
        
        for(int i=1;i<v2.size();i++) visited[v2[i]]=true;           // 2팀 색칠 (시작점 제외)
        dfs(v2[0]);

        for(int i=1;i<=n;i++) if(visited[i]) return;

        int people1=0,people2=0;
        for(int i=0;i<v1.size();i++) people1+=people[v1[i]];
        for(int i=0;i<v2.size();i++) people2+=people[v2[i]];

        mn=min(mn,abs(people1-people2));

        return;
    }
    for(int i=here+1;i<=n;i++) {        // 1부터 n까지 조합
        v1.push_back(i);
        combi(i,v1,a);
        v1.pop_back();
    }
}

int main() {
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&people[i]);

    for(int i=1;i<=n;i++) {              
        int a;
        scanf("%d",&a);
        for(int j=0;j<a;j++) {
            int b;
            scanf("%d",&b);
            graph[i].push_back(b);
        }
    }

    for(int i=1;i<=n/2;i++) {             // nCr 과 nCn-r은 동일, 절반 까지의 조합만 구하면 됨
        vector<int> v1;
        combi(0,v1,i);
    }

    if(mn==987654321) printf("-1\n");
    else printf("%d\n",mn);

    return 0;
}