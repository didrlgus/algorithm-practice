// 프린터 큐
#include<bits/stdc++.h>
using namespace std;
int tc,ret;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        queue<pair<int,bool>> q;
        priority_queue<int> pq;
        ret=0;
        int n,m;scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) {
            int val;scanf("%d",&val);
            if(i==m) q.push({val,true});
            else q.push({val,false});
            pq.push(val);
        }
        while(!q.empty()) {
            int q_front=(int)q.front().first,pq_front=(int)pq.top();
            bool flag=q.front().second;
            if(q_front==pq_front) {
                q.pop();pq.pop();
                ret++;
                if(flag) break;
            } else {
                q.pop();q.push({q_front,flag});
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}