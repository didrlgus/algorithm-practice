// 2529. ???
#include<bits/stdc++.h>

using namespace std;

int n;
char c[15];
int result[15];
int check[15];
int result2[15];
int check2[15];
bool flag = false;
bool flag2 = false;

void func(int current) {
    if(flag) return;
    // base condition
    if(current>=n+1) {
        for(int i=0;i<=n;i++) printf("%d",result[i]);
        flag=true;
    } else {
        for(int i=9;i>=0;i--) {
            if(!check[i]) {
                if(current==0) {
                    check[i]=true;
                    result[current]=i;
                } else {
                    if(c[current]=='<') {
                        if(result[current-1] < i) {
                            check[i]=true;
                            result[current]=i;
                        } else continue;
                    } else {
                        if(result[current-1] > i) {
                            check[i]=true;
                            result[current]=i;
                        } else continue;
                    }
                }
                func(current+1);
                check[i]=false;
            }
        }
    }
}

void func2(int current) {
    if(flag2) return;
    // base condition
    if(current>=n+1) {
        for(int i=0;i<=n;i++) printf("%d",result2[i]);
        flag2=true;
    } else {
        for(int i=0;i<=9;i++) {
            if(!check2[i]) {
                if(current==0) {
                    check2[i]=true;
                    result2[current]=i;
                } else {
                    if(c[current]=='<') {
                        if(result2[current-1] < i) {
                            check2[i]=true;
                            result2[current]=i;
                        } else continue;
                    } else {
                        if(result2[current-1] > i) {
                            check2[i]=true;
                            result2[current]=i;
                        } else continue;
                    }
                }
                func2(current+1);
                check2[i]=false;
            }
        }
    }
}

int main() {
    
    scanf("%d",&n);

    for(int i=1;i<=n;i++) scanf(" %c", &c[i]);

    func(0);
    printf("\n");
    func2(0);

    return 0;
}