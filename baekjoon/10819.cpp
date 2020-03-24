// 10819. 차이를 최대로
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int n;
int a[15];
int result[15];
bool check[15];

int max_=-987987987;

void func(int current) {
    if(current>=n) {
        int sum=0;

        for(int i=1;i<n;i++) {
            sum+=abs(result[i-1]-result[i]);
        }

        if(max_<sum) max_=sum;
    } else {
        for(int i=0;i<n;i++) {
            if(!check[i]) {
                check[i]=true;
                result[current]=a[i];

                func(current+1);

                check[i]=false;
            }
        }
    }
}

int main() {

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }

    func(0);

    printf("%d\n", max_);

    return 0;
}