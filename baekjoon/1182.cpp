// 1182. 부분 수열의 합
#include<cstdio>

int n,s;
int a[25];  

int cnt=0;

void dfs(int current, int sum) {
    if(current>=n) {
        if(sum==s) {
            cnt++;
        }
    } else {
        dfs(current+1, sum);
        dfs(current+1, sum+a[current]);
    }
}

int main() {

    scanf("%d %d",&n,&s);

    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    dfs(0,0);

    // 공집합 제외
    if(s==0) cnt--;

    printf("%d\n",cnt);

    return 0;
}