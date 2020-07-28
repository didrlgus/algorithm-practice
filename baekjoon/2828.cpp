// 사과 담기 게임
#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,e,ret;
int main() {
    scanf("%d%d%d",&n,&m,&k);
    s=0,e=m;
    for(int i=0;i<k;i++) {
        int a;scanf("%d",&a);
        if(a>e) {
            ret+=a-e;
            e=a;
            s=e-m;
        } else if(a<=s) {
            ret+=s-a+1;
            s=a-1;
            e=s+m;
        }        
    }
    printf("%d\n",ret);
    return 0;
}