// 분수 합
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g;
int gcd(int a,int b) {
    while(1) {
        int atmp=a;
        int btmp=b;
        a=b;
        b=atmp%btmp;
        if(b==0) break;
    }
    return a;
}
int main() {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    e=b*d;
    f=a*d+c*b;
    g=gcd(e,f);
    printf("%d %d\n",f/g,e/g);
    return 0;
}