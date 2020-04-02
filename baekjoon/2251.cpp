// 2251. 물통
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int A,B,C;
bool check[205][205][205];

struct p{
    int x;
    int y;
    int z;
};

queue<p> q;
vector<int> v;

void bfs() {
    // 시작점 큐에 삽입
    check[0][0][C]=true;
    q.push({0,0,C});

    while (!q.empty()) {
        int a=q.front().x;
        int b=q.front().y;
        int c=q.front().z;

        q.pop();

        //조건 충족 시
        if (a==0) v.push_back(c);
        
        // 1. a->b
        if(a+b>B) {
            if(!check[a+b-B][B][c]) {
                check[a+b-B][B][c]=true;
                q.push({a+b-B,B,c});
            }
        } else {
            if(!check[0][a+b][c]) {
                check[0][a+b][c]=true;
                q.push({0,a+b,c});
            }
        }

        // 2. a->c
        if(a+c>C) {
            if(!check[a+c-C][b][C]) {
                check[a+c-C][b][C]=true;
                q.push({a+c-C,b,C});
            }
        } else {
            if(!check[0][b][a+c]) {
                check[0][b][a+c]=true;
                q.push({0,b,a+c});
            }
        }

        // 3. b->a
        if(b+a>A) {
            if(!check[A][b+a-A][c]) {
                check[A][b+a-A][c]=true;
                q.push({A,b+a-A,c});
            }
        } else {
            if(!check[b+a][0][c]) {
                check[b+a][0][c]=true;
                q.push({b+a,0,c});
            }
        }

        // 4. b->c
        if(b+c>C) {
            if(!check[a][b+c-C][C]) {
                check[a][b+c-C][C]=true;
                q.push({a,b+c-C,C});
            }
        } else {
            if(!check[a][0][b+c]) {
                check[a][0][b+c]=true;
                q.push({a,0,b+c});
            }
        }

        // 5. c->a
        if(c+a>A) {
            if(!check[A][b][c+a-A]) {
                check[A][b][c+a-A]=true;
                q.push({A,b,c+a-A});
            }
        } else {
            if(!check[c+a][b][0]) {
                check[c+a][b][0]=true;
                q.push({c+a,b,0});
            }
        }

        // 6. c->b
        if(c+b>B) {
            if(!check[a][B][c+b-B]) {
                check[a][B][c+b-B]=true;
                q.push({a,B,c+b-B});
            }
        } else {
            if(!check[a][c+b][0]) {
                check[a][c+b][0]=true;
                q.push({a,c+b,0});
            }
        }
    }

    sort(v.begin(),v.end());

    for (int i=0; i<v.size(); i++) printf("%d ",v[i]);
}

int main() {

    scanf("%d %d %d",&A,&B,&C);
    bfs();

    return 0;
}