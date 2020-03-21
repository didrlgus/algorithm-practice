// 리모컨
#include<iostream>
#include<cmath>

bool a[10];

int check(int c) {
    if(c==0) {
        if(a[c]) return 0;
        else return 1;
    }

    int cnt=0;

    while(c>0) {
        if(a[c%10]) return 0;
        c/=10;
        cnt++;
    }

    return cnt;
}

int main() {
    int n,m;
    scanf("%d\n", &n);
    scanf("%d\n", &m);

    for(int i=0;i<m;i++) {
        int b;
        scanf("%d", &b);
        a[b]=true;
    }

    int result = abs(n-100);

    for(int i=0;i<=1000000;i++) {
        int l = check(i);
        int d = abs(n-i);
        
        if(l>0 && result > l+d) result = l+d;
    }

    printf("%d\n", result);
}