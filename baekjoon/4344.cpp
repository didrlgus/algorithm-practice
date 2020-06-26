// 평균은 넘겠지
#include<bits/stdc++.h>
using namespace std;
int tc;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        int n;
        scanf("%d",&n);
        vector<int> v;
        for(int i=0;i<n;i++) {
            int a;
            scanf("%d",&a);
            v.push_back(a);
        }
        double avg=0.0;
        int sum=0,cnt=0;
        for(auto it:v) sum+=it;
        avg=(double)sum/n;
        for(auto it:v) if(it>avg) cnt++;
        double r=(double)cnt/n*100;
        printf("%0.3f%\n",r);
    }
    return 0;
}