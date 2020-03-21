// 날짜 계산
#include<cstdio>

int main() {

    int a,b,c;
    int e=1,s=1,m=1;
    int cnt=1;

    scanf("%d %d %d", &a,&b,&c);

    while(1) {
        if(a==e && b==s && c==m) break;

        e++;
        s++;
        m++;
        cnt++;

        if(e>=16) e=1;
        if(s>=29) s=1;
        if(m>=20) m=1;
    }

    printf("%d\n", cnt);

    return 0;
}