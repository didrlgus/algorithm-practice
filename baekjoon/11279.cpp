// 최대 힙
#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> pq;
int main() {
    scanf("%d",&n);
    while(n--) {
        int a;scanf("%d",&a);
        if(a==0) {
            if(!pq.empty()) {
                printf("%d\n",pq.top());
                pq.pop();
            } else printf("0\n");
        } else {
            pq.push(a);
        }
    }
    return 0;
}