// 경비원
#include<bits/stdc++.h>
using namespace std;
int n,m,tc,ret;
vector<int> v;
int main() {
    scanf("%d%d%d",&n,&m,&tc);
    tc++;
    while(tc--) {
        int a,b;scanf("%d%d",&a,&b);
        if(a==2) b=n+m+n-b;
        else if(a==3) b=2*n+2*m-b;
        else if(a==4) b=n+b;
        v.push_back(b);
    }
    int standard=v.back();v.pop_back();
    for(auto it:v) {
        int dist=abs(standard-it);
        ret+=min(dist,2*n+2*m-dist);
    }
    printf("%d\n",ret);
    return 0;
}