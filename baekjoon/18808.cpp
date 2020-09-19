// 스티커 붙이기
#include<bits/stdc++.h>
using namespace std;
int n,m,k,arr[45][45],ret;
vector<vector<int>> v[105];
vector<vector<int>> _rotate(vector<vector<int>> key) {
    int n=(int)key.size(),m=(int)key[0].size();
    vector<vector<int>> temp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) temp[i][j]=key[n-j-1][i];
    }
    return temp;
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++) {
        int r,c;scanf("%d%d",&r,&c);
        v[i].resize(r,vector<int>(c,0));
        for(int a=0;a<r;a++) {
            for(int b=0;b<c;b++) scanf("%d",&v[i][a][b]);
        }
    }
    for(int t=0;t<k;t++) {
        vector<vector<int>> vv=v[t];
        bool flag2=false;
        int rot_cnt=0;
        while(!flag2&&rot_cnt<4) {
            vector<pair<int,int>> vvv;
            int r=(int)vv.size(),c=(int)vv[0].size();
            for(int i=0;i<r;i++) {
                for(int j=0;j<c;j++) if(vv[i][j]) vvv.push_back({i,j});
            }
            flag2=false;
            if(r<=n&&c<=m) {
                for(int i=0;i<=n-r;i++) {
                    for(int j=0;j<=m-c;j++) {
                        bool flag=false;
                        for(auto it:vvv) {
                            if(arr[it.first+i][it.second+j]) {
                                flag=true;
                                break;
                            }
                        }  
                        if(!flag) {
                            for(auto it:vvv) arr[it.first+i][it.second+j]=1;
                            flag2=true;
                            break;
                        }
                    }
                    if(flag2) break;
                }
            }
            vv=_rotate(vv);
            rot_cnt++;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) if(arr[i][j]) ret++;
    }
    printf("%d\n",ret);
    return 0;
}