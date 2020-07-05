// 소트
#include<bits/stdc++.h>
using namespace std;
int n,arr[55],s;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&s);
    for(int i=0;i<n&&s;i++) {
        int mx=arr[i],mx_idx=i;
        for(int j=i+1;j<n&&j<=i+s;j++) {
            if(mx<arr[j]) {
                mx=arr[j];
                mx_idx=j;
            }
        }
        s-=mx_idx-i;
        while(mx_idx>i) {
            arr[mx_idx]=arr[mx_idx-1];
            mx_idx--; 
        }
        arr[i]=mx;
    }
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}