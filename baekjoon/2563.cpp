// 색종이
#include<bits/stdc++.h>
using namespace std;

int n;
bool arr[1010][1010];
int main() {
    scanf("%d",&n);
    int cnt=0;
    while(n--) {
        int y,x;
        scanf("%d %d",&y,&x);
        for(int i=y;i<y+10;i++) {
            for(int j=x;j<x+10;j++) {
                if(!arr[i][j]) {
                    arr[i][j]=true;
                    cnt++;
                } 
            }
        }    
    }
    printf("%d\n",cnt);
    return 0;
}