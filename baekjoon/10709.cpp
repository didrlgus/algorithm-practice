// 기상캐스터
#include<bits/stdc++.h>
using namespace std;
int n,m,ret[105][105];
char arr[105][105];
int main() {
    fill(&ret[0][0],&ret[0][0]+105*105,-1);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        vector<int> v;
        for(int j=0;j<m;j++) {
            if(arr[i][j]=='c') v.push_back(j);
        }
        for(int j=0;j<(int)v.size()-1;j++) {
            int val=0;
            for(int k=v[j];k<v[j+1];k++) ret[i][k]=val++;
        }
        if((int)v.size()-1>=0) {
            int val=0;
            for(int k=v[(int)v.size()-1];k<m;k++) ret[i][k]=val++;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) printf("%d ",ret[i][j]);
        printf("\n");
    }
    return 0;
}