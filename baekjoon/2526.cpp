// 싸이클
#include<bits/stdc++.h>

using namespace std;

int arr[1000010];
int n,p;

int main() {

    scanf("%d %d",&n,&p);

    //      67 31
    // a 25 
    int a=n;
    int st=0;
    while(true) {
        a=(a*n)%p;

        if(!arr[a]) {
            arr[a]=true;
        } else {
            st=a;
            break;
        }
    }

    int b=st;
    int cnt=0;
    do {
        cnt++;
        b=(b*n)%p;
    } while(b!=st);

    printf("%d\n",cnt);

    return 0;
}