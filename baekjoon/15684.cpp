// 사다리 조작
#include<bits/stdc++.h>

using namespace std;

bool arr[35][15];
int mn=987654321;
int m,n,h;

bool check() {
    for(int j=1;j<=m;j++) {
        int start=j;
        for(int i=1;i<=h;i++) {
            if(arr[i][start]) start++;
            else if(arr[i][start-1]) start--;
        }
        if(start!=j) return false;
    }
    return true;
}

void func(int here,int cnt) {
    if(cnt>3||cnt>=mn) return;
    if(check()) {
        mn=min(mn,cnt);
        return;
    }
    for(int i=here;i<=h;i++) {                                          // 사다리 하나씩 추가해보기
        for(int j=1;j<m;j++) {
            if(arr[i][j] || arr[i][j-1] || arr[i][j+1]) continue;       // 해당 공간, 인접한 양옆 공간이 차있으면 사다리 놓을 수 없음
            arr[i][j]=true;
            func(i,cnt+1);
            arr[i][j]=false;
        }
    }
}

int main() {

    scanf("%d %d %d",&m,&n,&h);

    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a][b]=true;
    }

    func(1,0);
    printf("%d\n",mn==987654321?-1:mn);

    return 0;
}