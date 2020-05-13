// 뮤탈리스크
#include<bits/stdc++.h>

using namespace std;

int n;
int arr[3];
int arr2[6][3]={{9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,9,3},{1,3,9}};
queue<pair<int,pair<int,int>>> q;

int visited[65][65][65];

int bfs(int a,int b,int c) {
    visited[a][b][c]=1;
    q.push({a,{b,c}});
    
    while(!q.empty()) {
        a=q.front().first, b=q.front().second.first, c=q.front().second.second;
        q.pop();

        if(a<=0 && b<=0 && c<=0) return visited[a][b][c]-1;

        for(int i=0;i<6;i++) {
            int na=max(0,a-arr2[i][0]),nb=max(0,b-arr2[i][1]),nc=max(0,c-arr2[i][2]);

            if(!visited[na][nb][nc]) {
                visited[na][nb][nc]=visited[a][b][c]+1;
                q.push({na,{nb,nc}});
            } 
        }
    }
    return -1;
}

int main() {

    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        arr[i]=a;
    }

    int result=bfs(arr[0],arr[1],arr[2]);
    printf("%d\n",result);

    return 0;
}