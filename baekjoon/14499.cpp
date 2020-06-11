// 주사위 굴리기
#include<bits/stdc++.h>
using namespace std;
int n,m,y,x,k,arr[25][25],go[1010],dice[10];
int dy[]={0,0,0,-1,1};
int dx[]={0,1,-1,0,0};
int r[3][5]={{5,2,0,3},{5,4,0,1}};
int main() {
    scanf("%d %d %d %d %d",&n,&m,&y,&x,&k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }
    for(int i=0;i<k;i++) scanf("%d",&go[i]);
    int ny=y,nx=x;
    for(int i=0;i<k;i++) {
        int dir=go[i];
        ny+=dy[dir];nx+=dx[dir];
        if(ny<0||nx<0||ny>=n||nx>=m) {
            ny-=dy[dir];nx-=dx[dir];
            continue;
        }
        vector<int> v;
        if(dir==1) {
            for(int j=0;j<4;j++) v.push_back(dice[r[0][j]]);
            rotate(v.begin(),v.begin()+v.size()-1,v.end());
            for(int j=0;j<4;j++) dice[r[0][j]]=v[j];
        } else if(dir==2) {
            for(int j=0;j<4;j++) v.push_back(dice[r[0][j]]);
            rotate(v.begin(),v.begin()+1,v.end());
            for(int j=0;j<4;j++) dice[r[0][j]]=v[j];
        } else if(dir==3) {
            for(int j=0;j<4;j++) v.push_back(dice[r[1][j]]);
            rotate(v.begin(),v.begin()+1,v.end());
            for(int j=0;j<4;j++) dice[r[1][j]]=v[j];
        } else {
            for(int j=0;j<4;j++) v.push_back(dice[r[1][j]]);
            rotate(v.begin(),v.begin()+v.size()-1,v.end());
            for(int j=0;j<4;j++) dice[r[1][j]]=v[j];
        }
        if(arr[ny][nx]==0) {
            arr[ny][nx]=dice[0];
        } else {
            dice[0]=arr[ny][nx];
            arr[ny][nx]=0;
        }
        printf("%d\n",dice[5]);
    }
    return 0;
}