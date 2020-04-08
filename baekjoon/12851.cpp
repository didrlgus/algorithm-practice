// 12851. 숨바꼭질 2
#include<cstdio>
#include<queue>

using namespace std;

int n,k;

struct p {
    int c;
    int l;    
};

queue<p> q;
bool visited[100005];

int cnt=0;
int min_=0;

void bfs(int current,int level) {
    visited[current]=true;
    q.push({current,level});

    level++;

    while(!q.empty()) {
        int size=q.size();

        while(size--) {
            int c=q.front().c;
            int l=q.front().l;

            q.pop();
            visited[c]=true;

            // 첫 발견 후 최단거리 경우 추가
            if(min_ && c==k && l==min_) cnt++;
            
            // 최단거리 경우 첫 발견
            if(!min_ && c==k) {
                cnt++;
                min_=l;
            }

            if(c-1>=0 && !visited[c-1]) {
                q.push({c-1,level});
            }

            if(c+1<=100000 && !visited[c+1]) {
                q.push({c+1,level});
            }

            if(c*2<=100000 && !visited[c*2]) {
                q.push({c*2,level});
            }
        }
        level++;
    }

    printf("%d\n%d\n",min_,cnt);
}

int main() {

    scanf("%d %d",&n,&k);

    bfs(n,0);

    return 0;
}