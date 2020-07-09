// 신입 사원
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int tc,n;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d",&n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            pq.push({a,b});
        }
        int e=INF,ret=0;
        while(!pq.empty()) {
            if(e>pq.top().second) {
                e=pq.top().second;
                ret++;
            }
            pq.pop();
        }
        printf("%d\n",ret);
    }
    return 0;
}