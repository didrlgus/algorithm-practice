// 사탕 게임
#include<bits/stdc++.h>
using namespace std;

int n;
char arr[55][55],tmp[55][55];
vector<pair<int,int>> v;
vector<int> v2;
int ret=-987654321;
bool check(int y1,int x1,int y2,int x2) {
    if(y1==y2&&abs(x1-x2)==1) return true;
    if(x1==x2&&abs(y1-y2)==1) return true;
    return false;
}
int go(int y,int x) {
    int cnt1=1,cnt2=1;
    char ch=tmp[y][x];
    for(int i=y+1;i<n;i++) {
        if(ch!=tmp[i][x]) break;
        cnt1++;
    }
    for(int j=x+1;j<n;j++) {
        if(ch!=tmp[y][j]) break;
        cnt2++;
    }
    return max(cnt1,cnt2);
}
void combi(int here,vector<int>& v2) {
    if((int)v2.size()==2) {
        int y1=v[v2[0]].first,x1=v[v2[0]].second,y2=v[v2[1]].first,x2=v[v2[1]].second;
        if(!check(y1,x1,y2,x2)) return;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) tmp[i][j]=arr[i][j];
        }
        char temp=tmp[y1][x1];
        tmp[y1][x1]=tmp[y2][x2];
        tmp[y2][x2]=temp;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) ret=max(ret,go(i,j));
        }
        return;
    }
    for(int i=here+1;i<(int)v.size();i++) {
        v2.push_back(i);
        combi(i,v2);
        v2.pop_back();
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %1c",&arr[i][j]);
            v.push_back({i,j});
        }
    }
    combi(-1,v2);
    printf("%d\n",ret);
    return 0;
}