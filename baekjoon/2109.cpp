// 순회강연
#include<bits/stdc++.h>
using namespace std;
int n,ret;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<>> pq;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int p,d;scanf("%d%d",&p,&d);
        v.push_back({d,p});
    }
    sort(v.begin(),v.end());
    for(auto it:v) {
        ret+=it.second;
        pq.push(it.second);
        if((int)pq.size()>it.first) {
            ret-=pq.top();
            pq.pop();
        }
    }
    printf("%d\n",ret);
    return 0;
}