// 2003. 수들의 합2
#include<cstdio>

using namespace std;

int n,m;
int a[10010];

int high=0,low=0;
int cnt=0;

// 투 포인터 알고리즘
// (배열의 연속합 구하는데 사용)
void func() {
    int sum=a[0];

    while(high<n) {
        if(sum<m) {
            sum+=a[++high];
        } else if(sum==m) {
            cnt++;
            sum+=a[++high];
        } else if(sum>m) {
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

    printf("%d\n",cnt);


    return 0;
}