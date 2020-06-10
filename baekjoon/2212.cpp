// 센서
#include<bits/stdc++.h>
using namespace std;
int n,k,ret;
vector<int> v,diff;
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++) diff.push_back(v[i]-v[i-1]);
    sort(diff.begin(),diff.end());
    // n보다 k가 작으면 n-k만큼의 영역(인접좌표의 차이)을 추가로 담당해야 한다.
    for(int i=0;i<n-k;i++) ret+=diff[i];
    printf("%d\n",ret);
    return 0;
}