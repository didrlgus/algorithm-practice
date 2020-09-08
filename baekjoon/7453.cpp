// 합이 0인 네 정수
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,arr[4010][4010];
ll ret;
vector<int> v;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<4;j++) scanf("%d",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        int a=arr[i][2];
        for(int j=0;j<n;j++) {
            int b=arr[j][3];
            v.push_back(a+b);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        int a=arr[i][0];
        for(int j=0;j<n;j++) {
            int b=arr[j][1];
            int sum=a+b;
            auto lo=lower_bound(v.begin(),v.end(),-sum);  
            auto hi=upper_bound(v.begin(),v.end(),-sum);
            if(*lo==-sum) ret+=hi-lo;
        }
    }
    printf("%lld\n",ret);
    return 0;
}