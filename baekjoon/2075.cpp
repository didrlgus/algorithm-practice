// N번째 큰 수
#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> pq;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int a;scanf("%d",&a);
            pq.push(-a);
            if((int)pq.size()>n) pq.pop();
        }
    }
    printf("%d\n",-pq.top());
    return 0;
}