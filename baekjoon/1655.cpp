// 가운데를 말해요
#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> max_heap;
priority_queue<int,vector<int>,greater<int>> min_heap;
int main() {
    scanf("%d",&n);
    while(n--) {
        int a;scanf("%d",&a);
        if((int)max_heap.size()==(int)min_heap.size()) max_heap.push(a);
        else min_heap.push(a);
        if(!max_heap.empty()&&!min_heap.empty()&&max_heap.top()>min_heap.top()) {
            int mx=max_heap.top(),mn=min_heap.top();
            max_heap.pop(),min_heap.pop();
            max_heap.push(mn),min_heap.push(mx);
        }
        printf("%d\n",max_heap.top());
    }
    return 0;
}