// 매직스타
#include<bits/stdc++.h>
using namespace std;
char arr[10][15];
bool visited[100];
vector<pair<int,int>> v;
int score(int y,int x) {
    return arr[y][x]-'A'+1;
}
bool check() {
    if(score(0,4)+score(1,3)+score(2,2)+score(3,1)!=26) return false;
    if(score(0,4)+score(1,5)+score(2,6)+score(3,7)!=26) return false;
    if(score(1,1)+score(1,3)+score(1,5)+score(1,7)!=26) return false;
    if(score(1,1)+score(2,2)+score(3,3)+score(4,4)!=26) return false;
    if(score(3,1)+score(3,3)+score(3,5)+score(3,7)!=26) return false;
    if(score(1,7)+score(2,6)+score(3,5)+score(4,4)!=26) return false;
    return true;
}
void dfs(int idx) {
    if(idx==(int)v.size()) {
        if(check()) {
            for(int i=0;i<5;i++) {
                for(int j=0;j<9;j++) printf("%c",arr[i][j]);
                printf("\n");
            }
            exit(0);
        }
        return;
    }
    for(int i=0;i<12;i++) {
        if(visited['A'+i]) continue;
        visited['A'+i]=true;
        arr[v[idx].first][v[idx].second]='A'+i;
        dfs(idx+1);
        arr[v[idx].first][v[idx].second]='x';
        visited['A'+i]=false;
    }
}
int main() {
    for(int i=0;i<5;i++) {
        for(int j=0;j<9;j++) {
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='x') v.push_back({i,j});
            if(arr[i][j]>='A'&&arr[i][j]<='L') visited[arr[i][j]]=true;
        }
    }
    dfs(0);
    return 0;
}