// 톱니바퀴 (2)
#include<bits/stdc++.h>

using namespace std;

int n,k;

vector<deque<int>> arr;
vector<pair<int,int>> rot;
int main() {
    
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        deque<int> dq;
        for(int j=0;j<8;j++) {
            int a;
            scanf("%1d",&a);
            dq.push_back(a);
        }
        arr.push_back(dq);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        rot.push_back({a-1,b});
    }

    for(int i=0;i<k;i++) {
        int wheel=rot[i].first;
        int dir=rot[i].second;

        vector<pair<int,int>> v;
        v.push_back({wheel,dir});

        for(int j=wheel+1;j<n;j++) {
            if(arr[j-1][2]==arr[j][6]) break;
            dir*=-1;
            v.push_back({j,dir});
        }

        dir=rot[i].second;
        for(int j=wheel;j>0;j--) {
            if(arr[j][6]==arr[j-1][2]) break;
            dir*=-1;
            v.push_back({j-1,dir});
        }

        for(int j=0;j<v.size();j++) {
            int idx=v[j].first;
            if(v[j].second==1) {    // 시계 방향
                int bk=arr[idx].back();
                arr[idx].pop_back();
                arr[idx].push_front(bk);
            } else {                // 반시계 방향
                int ft=arr[idx].front();
                arr[idx].pop_front();
                arr[idx].push_back(ft);
            }
        }
    }

    int cnt=0;
    for(int i=0;i<arr.size();i++) {
        if(arr[i][0]==1) cnt++;
    }

    printf("%d\n",cnt);

    return 0;
}