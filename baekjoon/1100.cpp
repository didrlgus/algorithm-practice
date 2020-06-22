// 하얀 칸
#include<bits/stdc++.h>
using namespace std;
int ret;
char arr[10][10];
int main() {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) scanf(" %1c",&arr[i][j]);
    }
    for(int i=0;i<8;i++) {
        if(i&1) {
            for(int j=1;j<8;j+=2) if(arr[i][j]=='F') ret++;
        } else {
            for(int j=0;j<8;j+=2) if(arr[i][j]=='F') ret++;
        }
    }
    printf("%d\n",ret);
    return 0;
}