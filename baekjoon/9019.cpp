// 9019. DSLR
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#define p pair<int, string>

using namespace std;

int n,a,b;
bool visited[10005];

void bfs(int current) {
    // 시작점 큐에 저장
    queue<p> q;
    visited[current]=true;
    q.push({current,""});

    while(!q.empty()) {
        int size=q.size();

        while(size--) {
            int f=q.front().first;
            string s=q.front().second;
            q.pop();
            
            if(f==b) {
                for(int i=0;i<s.size();i++) printf("%c",s.at(i));
                printf("\n");
                return;
            }

            // D
            int op1=(f*2)%10000;
            if(!visited[op1]) {
                visited[op1]=true;
                q.push({op1,s+"D"});
            }

            // S
            int op2=f-1<0?9999:f-1;
            if(!visited[op2]) {
                visited[op2]=true;
                q.push({op2,s+"S"});
            }

            // L
            int op3=(f%1000)*10 + (f/1000);
            if(!visited[op3]) {
                visited[op3]=true;
                q.push({op3,s+"L"});
            }

            // R
            int op4=(f%10)*1000 + (f/10);
            if(!visited[op4]) {
                visited[op4]=true;
                q.push({op4,s+"R"});
            }
        }
    }

}

int main() {

    scanf("%d",&n);

    while(n--) {
        memset(visited,0,sizeof(visited));
        
        scanf("%d %d",&a,&b);

        bfs(a);
    }

    return 0;
}