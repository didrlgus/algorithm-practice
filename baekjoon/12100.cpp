// 2048 (Easy)
#include<bits/stdc++.h>

using namespace std;

int n;
int arr[25][25];
int tmp[25][25];
int mx=-987654321;
vector<int> v;

void go(int type) {
    queue<int> q;
    if(type==0) {                               // 오른쪽
        for(int i=0;i<n;i++) {
            for(int j=n-1;j>=0;j--) {
                if(tmp[i][j]>0) {
                    q.push(tmp[i][j]);
                    tmp[i][j]=0;
                }
            }
            int idx=n-1;
            while(!q.empty()) {
                int f=q.front(); q.pop();
                if(tmp[i][idx]==0) {
                    mx=max(mx,f);
                    tmp[i][idx]=f;
                } else if(tmp[i][idx]==f) {
                    mx=max(mx,f*2);
                    tmp[i][idx--]*=2;
                } else {
                    mx=max(mx,f);
                    tmp[i][--idx]=f;
                }
            }
        }
    } else if(type==1) {                        // 왼쪽
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(tmp[i][j]>0) {
                    q.push(tmp[i][j]);
                    tmp[i][j]=0;
                }
            }
            int idx=0;
            while(!q.empty()) {
                int f=q.front(); q.pop();
                if(tmp[i][idx]==0) {
                    mx=max(mx,f);
                    tmp[i][idx]=f;
                } else if(tmp[i][idx]==f) {
                    mx=max(mx,f*2);
                    tmp[i][idx++]*=2;
                } else {
                    mx=max(mx,f);
                    tmp[i][++idx]=f;
                }
            }
        }
    } else if(type==2) {                        // 위쪽
        for(int j=0;j<n;j++) {
            for(int i=0;i<n;i++) {
                if(tmp[i][j]>0) {
                    q.push(tmp[i][j]);
                    tmp[i][j]=0;
                }
            }
            int idx=0;
            while(!q.empty()) {
                int f=q.front(); q.pop();
                if(tmp[idx][j]==0) {
                    mx=max(mx,f);
                    tmp[idx][j]=f;
                } else if(tmp[idx][j]==f) {
                    mx=max(mx,f*2);
                    tmp[idx++][j]*=2;
                } else {
                    mx=max(mx,f);
                    tmp[++idx][j]=f;
                }
            }
        }
    } else {
        for(int j=0;j<n;j++) {
            for(int i=n-1;i>=0;i--) {
                if(tmp[i][j]>0) {
                    q.push(tmp[i][j]);
                    tmp[i][j]=0;
                }
            }
            int idx=n-1;
            while(!q.empty()) {
                int f=q.front(); q.pop();
                if(tmp[idx][j]==0) {
                    mx=max(mx,f);
                    tmp[idx][j]=f;
                } else if(tmp[idx][j]==f) {
                    mx=max(mx,f*2);
                    tmp[idx--][j]*=2;
                } else {
                    mx=max(mx,f);
                    tmp[--idx][j]=f;
                }
            }
        }
    }
}

void permu() {
    if(v.size()>=5) {
        memcpy(tmp,arr,sizeof(tmp));
        for(int i=0;i<v.size();i++) go(v[i]);
        
        return;
    }
    for(int i=0;i<4;i++) {      // 0->오른쪽, 1->왼쪽, 2->위쪽, 3->아래쪽
        v.push_back(i);
        permu();
        v.pop_back();
    }
}

int main() {
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
    }

    permu();
    printf("%d\n",mx);

    return 0;
}