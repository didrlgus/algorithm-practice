// 주몽
#include<bits/stdc++.h>

using namespace std;

vector<int> v1,v2;

int cnt=0;
int n,k;
void func(int here,vector<int> &v2) {
    if(v2.size()==2) {
        int sum=0;
        for(auto iter:v2) sum+=v1[iter];
        
        if(sum==k) cnt++;

        return;
    }
    for(int i=here+1;i<v1.size();i++) {
        v2.push_back(i);
        func(i,v2);
        v2.pop_back();
    }
}

int main() {

    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        v1.push_back(a);
    }

    func(-1,v2);
    printf("%d\n",cnt);

    return 0;
}