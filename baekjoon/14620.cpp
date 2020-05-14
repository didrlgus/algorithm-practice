// 꽃길
#include<bits/stdc++.h>

using namespace std;

int n;
int arr[15][15];
bool visited[15][15];
vector<pair<int,int>> v;
vector<int> v2;
int mn=987654321;

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

void combi(int here,vector<int> &v2) {
    if(v2.size()==3) {
        fill(&visited[0][0],&visited[0][0]+15*15,false);
        int sum=0;

        for(auto idx:v2) {
            int y=v[idx].first,x=v[idx].second;
            visited[y][x]=true;
            sum+=arr[y][x];

            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                if(!visited[ny][nx]) {
                    visited[ny][nx]=true;
                    sum+=arr[ny][nx];
                } else return;                      // 겹치는 부분이 있으면 해당 조합 불가, return
            }
        }

        mn=min(mn,sum);

        return;
    }
    for(int i=here+1;i<v.size();i++) {
        v2.push_back(i);
        combi(i,v2);
        v2.pop_back();
    }
}

int main() {

    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
            if(i>0 && i<n-1 && j>0 && j<n-1) v.push_back({i,j});    // 가장자리에는 꽃을 심을 수 없음
        }
    }
    
    combi(-1,v2);
    printf("%d\n",mn);

    return 0;
}