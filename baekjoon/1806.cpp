// 1806. 부분합
#include<cstdio>
#include<algorithm>

using namespace std;

int n,m;
int a[100005];
int low=0,high=0;

int min_=987987987;

// 투포인터 알고리즘
void func() {
    int sum=a[0];

    while(high<n) {
        if(sum<m) {
            sum+=a[++high];
        } else if(sum==m) {
            int len=high-low+1;
            min_=min(min_,len);

            sum+=a[++high];
        } else if(sum>m) {
            int len=high-low+1;
            min_=min(min_,len);

            sum-=a[low++];

            if(low>high && low<n) {
                high=low;
                sum=a[high];
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    func();

    if(min_==987987987) printf("0\n");
    else printf("%d\n",min_);

    return 0;
}