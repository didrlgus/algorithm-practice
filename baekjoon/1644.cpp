// 1644. 소수의 연속합
#include<cstdio>
#include<vector>

using namespace std;

int n;

long long a[4000005];
vector<int> v;

int cnt=0;

//에라토스테네스의 체
void eratosthenes() {
    a[0]=a[1]=-1;

    for(long long i=2;i<4000000;i++) {
        a[i]=i;
    }

    for(long long i=2;i<4000000;i++) {
        if(a[i]==i) { 
            for(long long j=i*i; j<4000000; j+=i) {
                if (a[j]==j) a[j]=i;
            }
        }
    }
    for(int i=2;i<4000000;i++) {
        if(a[i]==i) v.push_back(i);
    }   
}

void func() {
    int low=0,high=0;
    int size=v.size();
    int sum=v[0];

    while(high<size && v[low]<=n) {
        if(sum<n) {
            sum+=v[++high];
        } else if(sum==n) {
            cnt++;
            sum+=v[++high];
        } else if(sum>n) {
            sum-=v[low++];

            if(low>high && low<size) {
                high=low;
                sum=v[high];
            }
        }
    }

    printf("%d\n",cnt);
}

int main() {

    scanf("%d",&n);

    eratosthenes();
    func();

    return 0;
}