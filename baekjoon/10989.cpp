// 수 정렬하기 3
#include<bits/stdc++.h>
using namespace std;
int n;
int arr[10005];
int main() {
    scanf("%d",&n);
    while(n--) {
        int val;scanf("%d",&val);
        arr[val]++;
    }
    for(int i=1;i<=10000;i++) {
        for(int j=0;j<arr[i];j++) printf("%d\n",i);
    }
    return 0;
}