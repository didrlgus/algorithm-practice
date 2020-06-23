// 피시방 알바
#include<bits/stdc++.h>
using namespace std;
int n,ret;
bool arr[105];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        if(arr[a]) ret++;
        else arr[a]=true;
    }
    printf("%d\n",ret);
    return 0;
}