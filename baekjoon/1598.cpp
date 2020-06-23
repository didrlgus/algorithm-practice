// 꼬리를 무는 숫자 나열
#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b,y1,x1,y2,x2;
    scanf("%d %d",&a,&b);
    y1=(a%4+3)%4,x1=a%4==0?a/4-1:a/4,y2=(b%4+3)%4,x2=b%4==0?b/4-1:b/4;
    printf("%d\n",abs(y1-y2)+abs(x1-x2));
    return 0;
}