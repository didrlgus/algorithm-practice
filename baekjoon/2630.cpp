// 색종이 만들기
#include<bits/stdc++.h>
using namespace std;

int n,arr[150][150];
int dy[]={0,0,1,1};
int dx[]={0,1,0,1};
bool check(int y,int x,int size,int val) {
    for(int i=y;i<y+size;i++) {
        for(int j=x;j<x+size;j++) {
            if(arr[i][j]!=val) return false;
        }
    }
    return true;
}
pair<int,int> dfs(int y,int x,int size) {
    if(size==1) {
        if(check(y,x,size,0)) return {1,0};
        if(check(y,x,size,1)) return {0,1};
        return {0,0};
    }
    pair<int,int> p={0,0};
    if(check(y,x,size,0)) {
        p.first++;
        return p;
    } else if(check(y,x,size,1)) {
        p.second++;
        return p;
    }
    int next_size=size/2;
    pair<int,int> ret;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i]*next_size,nx=x+dx[i]*next_size;
        pair<int,int> tmp=dfs(ny,nx,next_size);
        ret.first+=tmp.first;ret.second+=tmp.second;
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
    }
    pair<int,int> rp=dfs(0,0,n);
    printf("%d\n%d\n",rp.first,rp.second);
    return 0;
}