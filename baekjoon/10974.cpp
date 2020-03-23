// 10974. 모든 순열
#include<cstdio>

bool check[15];
int result[15];

int n;

void func(int cnt) {
    // base condition
    if(cnt>=n) {
        for(int i=0;i<n;i++) printf("%d ", result[i]);
        printf("\n");
    } else {
        for(int i=1;i<=n;i++) {
            if(!check[i]) {
                check[i]=true;
                result[cnt]=i;

                func(cnt+1);

                check[i]=false;
            }
        }
    }
}

int main() {

    scanf("%d", &n);

    func(0);

    return 0;
}