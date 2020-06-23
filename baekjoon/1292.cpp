// 쉽게 푸는 문제
#include<bits/stdc++.h>
using namespace std;
int s,e,ret;
vector<int> v;
int main() {
    scanf("%d %d",&s,&e);
    int idx=1;
    while((int)v.size()<1005) {
        for(int i=0;i<idx;i++) v.push_back(idx);
        idx++;
    }
    for(int i=s-1;i<e;i++) ret+=v[i];
    printf("%d\n",ret);
    return 0;
}