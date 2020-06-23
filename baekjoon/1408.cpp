// 24
#include<bits/stdc++.h>
using namespace std;
int h1,h2,m1,m2,s1,s2;
int main() {
    scanf("%d:%d:%d",&h1,&m1,&s1);
    scanf("%d:%d:%d",&h2,&m2,&s2);
    int t1=h1*3600+m1*60+s1,t2=h2*3600+m2*60+s2;
    if(t1>t2) t2+=24*60*60;
    int ret=t2-t1;
    int h=ret/3600,m=ret%3600/60,s=ret%3600%60;
    printf("%02d:%02d:%02d\n",h,m,s);
    return 0;
}