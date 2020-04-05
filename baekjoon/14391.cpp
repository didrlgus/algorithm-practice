// 14391. 종이 조각
#include<cstdio>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int n,m;
int a[10][10];
bool visited[70];

int max_=-1;

int getSum() {
    int sum=0,tmp=0;

    // 가로
    for (int i=0;i<n;i++) {
        tmp=0;
        for (int j=0;j<m;j++) {
            if (visited[i*m+j]) {
                tmp=tmp*10+a[i][j];
            } else {
                sum+=tmp;
                tmp=0;
            }
        }
        sum+=tmp;
    }

    // 세로
    for (int i=0;i<m;i++) {
        tmp=0;
        for(int j=0;j<n;j++) {
            if(!visited[j*m+i]) {
                tmp=tmp*10+a[j][i];
            } else {
                sum+=tmp;
                tmp=0;
            }
        }
        sum+=tmp;
    }

    return sum;
}

void dfs(int current) {
    if(current>=n*m) {
        int sum=getSum();

        max_=max(max_,sum);
    } else {
        // 가로
        visited[current]=true;
        dfs(current+1);

        // 세로
        visited[current]=false;
        dfs(current+1);
    }
}

int main() {

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) {
            a[i][j]=s.at(j)-'0';
        }
    }

    dfs(0);

    printf("%d\n",max_);

    return 0;
}