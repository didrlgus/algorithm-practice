// 피자판매
#include<bits/stdc++.h>

using namespace std;

int k,n,m;
int a[1010],b[1010];
int pa[2010],pb[2010];
vector<int> v1,v2;

int main() {
    scanf("%d %d %d",&k,&n,&m);

    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);

    // 누적합 저장, 원형이기 때문에 2n까지 저장
    for(int i=1;i<=n;i++) pa[i]=pa[i-1]+a[i];
    for(int i=n+1;i<=2*n;i++) pa[i]=pa[n]+pa[i-n];  // 다시 처음부터 누적합
    
    for(int i=1;i<=m;i++) pb[i]=pb[i-1]+b[i];
    for(int i=m+1;i<=2*m;i++) pb[i]=pb[m]+pb[i-m];
    
    // n=5                 n           2n-2        2n
    // pa  0  2  4  5  12  14  16  18  19    26    28
    //                                 i
    // 누적합의 모든 경우 구하기
    for(int i=n-1;i<=2*n-2;i++) {
        for(int j=1;j<=n-1;j++) {                   // 모든 조각을 다 선택하는 경우는 결국 다 같은 경우므로 n이 아니라 n-1
            v1.push_back(pa[i]-pa[i-j]);
        }
    }

    for(int i=m-1;i<=2*m-2;i++) {
        for(int j=1;j<=m-1;j++) {
            v2.push_back(pb[i]-pb[i-j]);
        }
    }

    // 모든 조각을 선택하는 경우, 하나도 선택하지 않는 경우 별도 처리
    v1.push_back(0);
    v1.push_back(pa[n]);
    v2.push_back(0);
    v2.push_back(pb[m]);

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    
    int ans=0;
    for(int i=0;i<=k;i++){
        int c = upper_bound(v1.begin(),v1.end(),i) - lower_bound(v1.begin(),v1.end(),i);
        int w = upper_bound(v2.begin(),v2.end(),k-i) - lower_bound(v2.begin(),v2.end(),k-i);         
        ans+=c*w;
    }
    printf("%d\n",ans);

    return 0;
}