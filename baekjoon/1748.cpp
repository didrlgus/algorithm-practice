// 1748. 수 이어 쓰기1
#include<string>
#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int d[10];
    d[0]=9*1;

    for(int i=1;i<=7;i++) {
        d[i]=d[i-1]+9*pow(10,i)*(i+1);
    }

    int cnt=0;

    if(n<10) {
        cnt=n;
    } else if(n<100) {
        cnt=d[0]+2*(n-10+1);
    } else if(n<1000) {
        cnt=d[1]+3*(n-100+1);
    } else if(n<10000) {
        cnt=d[2]+4*(n-1000+1);
    } else if(n<100000) {
        cnt=d[3]+5*(n-10000+1);
    } else if(n<1000000) {
        cnt=d[4]+6*(n-100000+1);
    } else if(n<10000000) {
        cnt=d[5]+7*(n-1000000+1);
    } else if(n<100000000) {
        cnt=d[6]+8*(n-10000000+1);
    } else if(n==100000000) {
        cnt=d[7]+9*(n-100000000+1);
    }

    cout << cnt << endl;

    return 0;
}