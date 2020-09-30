// 카드2
#include<bits/stdc++.h>
using namespace std;
int n;
deque<int> dq;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) dq.push_back(i);
    while(dq.size()>1) {
        dq.pop_front();
        int a=dq.front();
        dq.pop_front();
        dq.push_back(a);
    }
    printf("%d\n",dq.front());
    return 0;
}