// 치킨 배달
#include<bits/stdc++.h>

using namespace std;

int n,m;
int arr[55][55];

vector<pair<int,int>> v1,v2;    // 모든 치킨집 좌표, 집 좌표
vector<int> v3;                 // 선택한 치킨집 좌표
int result=987654321;

int getDis(int y1,int x1,int y2,int x2) {
    int dis=0;
    dis=abs(y1-y2)+abs(x1-x2);
    return dis;
}

void func(int here,vector<int>& v3) {
    if(v3.size()==m) {
        int ret=0;
        for(int i=0;i<v2.size();i++) {
            int mn=987654321;            
            int hy=v2[i].first,hx=v2[i].second;

            for(auto iter:v3) {      // m개 선택한 치킨집의 좌표
                int cy=v1[iter].first,cx=v1[iter].second;
                mn=min(mn,getDis(hy,hx,cy,cx));
            }
            ret+=mn;
        }
        result=min(result,ret);
    }
    for(int i=here+1;i<v1.size();i++) {
        v3.push_back(i);
        func(i,v3);
        v3.pop_back();
    }
}

int main() {
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);

            if(arr[i][j]==2) v1.push_back({i,j});
            if(arr[i][j]==1) v2.push_back({i,j});
        }
    }

    func(-1,v3);
    printf("%d\n",result);

    return 0;
}