// 슈퍼 마리오
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
    for(int i=0;i<10;i++) {
        int val;scanf("%d",&val);
        v.push_back(val);
    }
    int sum=v[0];
    for(int j=1;j<10;j++) {
        if(abs(sum+v[j]-100)<=abs(sum-100)) {
            sum+=v[j];
        } else break;
    }
    printf("%d\n",sum);
    return 0;
}