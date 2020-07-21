// 등산
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
string s;
int n,m,t,d,arr[30][30],dy[]={0,0,1,-1},dx[]={1,-1,0,0},dist[3000][3000],ret;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>t>>d;
    for(int i=0;i<n;i++) {
        cin>>s;
        for(int j=0;j<(int)s.size();j++) {
            if(s[j]>='a') arr[i][j]=s[j]-'a'+26;
            else arr[i][j]=s[j]-'A';
        }
    }
    ret=arr[0][0];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) v.push_back(i*100+j);      // 좌표압축, 2차원 y,x를 하나로 합칠 수 있다. (y,x의 범위가 모두 100미만 이므로 100으로 설정)
    }
    fill(&dist[0][0],&dist[0][0]+3000*3000,INF);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<4;k++) {
                int ny=i+dy[k],nx=j+dx[k];
                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                int diff=abs(arr[i][j]-arr[ny][nx]);
                if(diff<=t) {                           // 이동할 수 있는 산일 경우, dist 값(시간) 설정
                    if(arr[i][j]<arr[ny][nx]) dist[i*100+j][ny*100+nx]=diff*diff;   // 오르막
                    else dist[i*100+j][ny*100+nx]=1;
                }
            }
        }
    }
    for(int k:v) {
        for(int i:v) {
            for(int j:v) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
    for(int j:v) {
        if(dist[0][j]+dist[j][0]<=d) ret=max(ret,arr[j/100][j%100]);
    }
    cout<<ret<<'\n';
    return 0;
}