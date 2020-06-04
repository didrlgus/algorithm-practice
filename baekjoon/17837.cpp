// 새로운 게임 2
#include<bits/stdc++.h>
using namespace std;
int n,k,arr[15][15],ret;
struct p {
    int y,x,dir;
};
vector<int> horse[15][15];
vector<p> v;
int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};
int change(int dir) {
    if(dir==0) return 1;
    else if(dir==1) return 0;
    else if(dir==2) return 3;
    else return 2;    
}
void go(int y,int x,int dir,int idx) {
    int ny=y+dy[dir],nx=x+dx[dir];
    if(ny<0||nx<0||ny>=n||nx>=n||arr[ny][nx]==2) {
        dir=change(dir);
        v[idx].dir=dir;
        ny=y+dy[dir];nx=x+dx[dir];
        if(ny<0||nx<0||ny>=n||nx>=n||arr[ny][nx]==2) return;
    }
    vector<int>& tmp=horse[y][x];
    auto it=find(tmp.begin(),tmp.end(),idx);
    vector<int> bak;
    for(auto i=it;i<tmp.end();i++) {
        v[*i].y=ny;
        v[*i].x=nx;
        bak.push_back(*i);
    }
    tmp.erase(it,tmp.end());
    if(arr[ny][nx]==1) reverse(bak.begin(),bak.end());
    for(auto it:bak) horse[ny][nx].push_back(it); 
    if(horse[ny][nx].size()>=4) {
        printf("%d\n",ret);
        exit(0);
    }
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
    }
    for(int i=0;i<k;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        a--;b--;c--;
        horse[a][b].push_back(i);
        v.push_back({a,b,c});
    }
    while(ret<=1000) {
        ret++;
        for(int i=0;i<k;i++) go(v[i].y,v[i].x,v[i].dir,i);
    }
    printf("-1\n");
    return 0;
}