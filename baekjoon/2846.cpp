// 오르막길
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,arr[1005],e,ret=INF;
vector<int> v;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    e=arr[0];
    v.push_back(e);
    for(int i=1;i<n;i++) {
        if(e<arr[i]) {
            v.push_back(arr[i]);
            e=arr[i];
        } else {
            if((int)v.size()>1) ret=max(ret,v.back()-v.front());
            v.clear();
            e=arr[i];
            v.push_back(e);
        }
    }
    if((int)v.size()>1) ret=max(ret,v.back()-v.front());
    if(ret==INF) printf("0\n");
    else printf("%d\n",ret);
    return 0;
}