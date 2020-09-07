// 절댓값 힙
#include<bits/stdc++.h>
using namespace std;
int n;
struct p{
    int y,x;
};
struct cmp{
    bool operator()(p a, p b){
        if(a.y==b.y) return a.x>b.x;
        return a.y>b.y;
    }
};
priority_queue<p,vector<p>,cmp> pq;
int main() {
    scanf("%d",&n);
    while(n--) {
        int a;scanf("%d",&a);
        if(a==0) {
            if(pq.empty()) printf("0\n");
            else {
                p cur=pq.top();pq.pop();
                if(cur.y==pq.top().y) printf("%d\n",cur.x);
                else printf("%d\n",cur.x);
            }
        } else {
            int b=abs(a);
            pq.push({b,a});
        }
    }
    return 0;
}