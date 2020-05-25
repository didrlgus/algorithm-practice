// 나무 재테크
#include<bits/stdc++.h>

using namespace std;

int n,m,k;
int map_[15][15],arr[15][15];
vector<int> tree[15][15];

int dy[]={0,0,1,-1,1,1,-1,-1};
int dx[]={1,-1,0,0,1,-1,1,-1};

int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
            map_[i][j]=5;
        }
    }
    for(int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        a--;b--;
        tree[a][b].push_back(c);
    }
    while(k--) {
        // 봄,여름
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if((int)tree[i][j].size()==0) continue;
                int dead_tree=0;
                vector<int> tmp;
                sort(tree[i][j].begin(),tree[i][j].end());
                for(int age:tree[i][j]) {
                    if(map_[i][j]>=age) {
                        map_[i][j]-=age;
                        tmp.push_back(age+1);
                    } else {
                        dead_tree+=age/2;
                    }
                }
                // tree[i][j].clear();
                tree[i][j]=tmp;
                map_[i][j]+=dead_tree;
            }
        }
        // 가을
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(tree[i][j].size()==0) continue;
                for(int age:tree[i][j]) {
                    if(age%5==0) {
                        for(int d=0;d<8;d++) {
                            int ny=i+dy[d],nx=j+dx[d];
                            if(ny<0||nx<0||ny>=n||nx>=n) continue;
                            tree[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
        // 겨울
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) map_[i][j]+=arr[i][j];
        }
    }
    int ret=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ret+=(int)tree[i][j].size();
        }
    }
    printf("%d\n",ret);
    return 0;
}