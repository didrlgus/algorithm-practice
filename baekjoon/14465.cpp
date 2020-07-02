// 소가 길을 건너간 이유 5
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,k,b,ret=INF,broken;
bool arr[100005];
int main() {
    scanf("%d %d %d",&n,&k,&b);
    for(int i=0;i<b;i++) {
        int a;
        scanf("%d",&a);
        arr[a]=true;    
    }
    for(int i=1;i<=k;i++) if(arr[i]) broken++;
    for(int i=k+1;i<=n;i++) {
        if(arr[i-k]) broken--;
        if(arr[i]) broken++;
        ret=min(ret,broken);
    }
    printf("%d\n",ret);
    return 0;
}