// 먹을 것인가 먹힐 것인가
#include<bits/stdc++.h>
using namespace std;
int tc;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        int n,m;
        scanf("%d %d",&n,&m);
        vector<int> v1,v2;
        for(int i=0;i<n;i++) {
            int a;scanf("%d",&a);
            v1.push_back(a);
        }
        for(int i=0;i<m;i++) {
            int a;scanf("%d",&a);
            v2.push_back(a);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int ret=0;
        for(auto it:v2) ret+=(int)(v1.end()-upper_bound(v1.begin(),v1.end(),it));
        printf("%d\n",ret);
    }
    return 0;
}