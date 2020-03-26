// 14888. 연산자 끼워넣기
#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int a[15];
int o[4];
int result[25];

int max_=-987987987, min_=987987987;

void dfs(int current, int plus, int minus, int mul, int div, int sum) {
    // base condition
    if(current>=n) {
        max_=max(max_,sum);
        min_=min(min_,sum);
    } else {
        if(plus>0) dfs(current+1,plus-1,minus,mul,div,sum+a[current]);
        if(minus>0) dfs(current+1,plus,minus-1,mul,div,sum-a[current]);
        if(mul>0) dfs(current+1,plus,minus,mul-1,div,sum*a[current]);
        if(div>0) dfs(current+1,plus,minus,mul,div-1,sum/a[current]);
    }
}

int main() {

    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<4;i++) scanf("%d",&o[i]);

    dfs(1,o[0],o[1],o[2],o[3],a[0]);

    printf("%d\n", max_);
    printf("%d\n", min_);

    return 0;
}