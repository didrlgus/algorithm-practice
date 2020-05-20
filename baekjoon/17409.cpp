// 배열 돌리기 4
#include<bits/stdc++.h>

using namespace std;

int n,m,k;
int arr[55][55];
int tmp[55][55];

vector<pair<pair<int,int>,int>> v;
vector<int> v_idx;
vector<pair<int,int>> vv;

int sy,sx,ey,ex,dir;
int mn=987654321;

int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};

void go(int y,int x) {
    int ny=y+dy[dir]; 
	int nx=x+dx[dir];

    if(ny==sy&&nx==ex) dir++;
	if(ny==ey&&nx==ex) dir++;
	if(ny==ey&&nx==sx) dir++; 
	
    if(ny==sy&&nx==sx) return;
	vv.push_back({ny,nx});
	go(ny,nx);
}

void func() {
    for(int i=0;i<(int)v_idx.size();i++) {            
        int y=v[v_idx[i]].first.first,x=v[v_idx[i]].first.second,s=v[v_idx[i]].second;   // y,x는 중점
        for(int j=1;j<=s;j++) {                                     // 각 가장자리
            sy=y-j;sx=x-j;
            ey=y+j;ex=x+j;
            dir=0;
            vv.clear();

            vv.push_back({sy,sx});
            go(sy,sx);

            vector<int> vvv;
            for(auto iter:vv) vvv.push_back(tmp[iter.first][iter.second]);

            // 82352393 -> 38235239로 회전
            rotate(vvv.begin(),vvv.begin()+vvv.size()-1,vvv.end());

            for(int k=0;k<(int)vv.size();k++) {
                tmp[vv[k].first][vv[k].second]=vvv[k];
            }
        }
    }

    for(int i=0;i<n;i++) {
        int sum=0;
        for(int j=0;j<m;j++) sum+=tmp[i][j];
        mn=min(mn,sum);
    }
}

int main() {

    scanf("%d %d %d",&n,&m,&k);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }

    for(int i=0;i<k;i++) {
        int y,x,s;
        scanf("%d %d %d",&y,&x,&s);
        y--;x--;
        v.push_back({{y,x},s});
        v_idx.push_back(i);
    }

    do {
        memcpy(tmp,arr,sizeof(arr));
        func();
    } while(next_permutation(v_idx.begin(),v_idx.end()));
    printf("%d\n",mn);

    return 0;
}