// 원판 돌리기
#include<bits/stdc++.h>

using namespace std;

int n,m,t;
vector<deque<int>> v;
struct p {
    int x,d,k;
};
vector<p> v2;

int main() {

    scanf("%d %d %d",&n,&m,&t);

    for(int i=0;i<n;i++) {
        deque<int> dq;
        for(int j=0;j<m;j++) {
            int a; scanf("%d",&a);
            dq.push_back(a);
        }
        v.push_back(dq);
    }

    for(int i=0;i<t;i++) {
        int x,d,k;
        scanf("%d %d %d",&x,&d,&k);
        v2.push_back({x,d,k});
    }
    
    for(int i=0;i<v2.size();i++) {
        int x=v2[i].x,d=v2[i].d,k=v2[i].k;              // 배수, 방향, 회전 수
        // 회전
        int idx=0;
        while(true) {
            idx++;
            if(x*idx>n) break;
            
            int di=x*idx-1;
            if(d==0) {                                  // 시계방향
                for(int a=0;a<k;a++) {
                    int f=v[di].back();
                    v[di].pop_back();
                    v[di].push_front(f);
                }
            } else {                                    // 반시계방향
                for(int a=0;a<k;a++) {
                    int b=v[di].front();
                    v[di].pop_front();
                    v[di].push_back(b);
                }
            }
        }

        // 인접 요소 찾기
        set<pair<int,int>> set_;
        for(int a=0;a<n;a++) {
            for(int b=0;b<m;b++) {
                if(b==m-1) {
                    if(v[a][b]==v[a][0] && v[a][b]!=0) {
                        set_.insert({a,b});
                        set_.insert({a,0});
                    }
                    break;    
                }
                if(v[a][b]==v[a][b+1] && v[a][b]!=0) {
                    set_.insert({a,b});
                    set_.insert({a,b+1});
                }
            }
        }

        for(int b=0;b<m;b++) {
            for(int a=0;a<n-1;a++) {
                if(v[a][b]==v[a+1][b] && v[a][b]!=0) {
                    set_.insert({a,b});
                    set_.insert({a+1,b});
                }
            }
        }

        if(!set_.empty()) {
            for(pair<int,int> iter:set_) {
                v[iter.first][iter.second]=0;      // 지우기
            }
        } else {
            int cnt=0,sum=0;
            for(int a=0;a<v.size();a++) {
                for(int b=0;b<v[a].size();b++) {
                    if(v[a][b]>0) {
                        sum+=v[a][b];
                        cnt++;
                    }
                }
            }
            double avg=(double)sum/cnt;
            for(int a=0;a<v.size();a++) {
                for(int b=0;b<v[a].size();b++) {
                    if(v[a][b]>0) {
                        if(v[a][b]>avg) {
                            v[a][b]--;
                        } else if(v[a][b]<avg) v[a][b]++;
                    }
                }
            }
        }
    }
    int ret=0;
    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v[i].size();j++) ret+=v[i][j];
    }
    printf("%d\n",ret);

    return 0;
}