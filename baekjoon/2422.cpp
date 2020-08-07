// 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
#include<bits/stdc++.h>
using namespace std;
int n,m,check[205][205],ret;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b;scanf("%d%d",&a,&b);
        check[a][b]=true;
        check[b][a]=true;
    }
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(check[i][j]) continue;
            for(int k=j+1;k<=n;k++) {
                if(check[i][k]||check[j][k]) continue;
                ret++;
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}