// 일곱난쟁이
#include<cstdio>
#include<vector>
#include <algorithm>

using namespace std;

int a[10];
vector<int> v;

int main() {

    int sum=0;
    bool flag = false;

    for(int i=1;i<=9;i++) {
        scanf("%d", &a[i]);
        sum+=a[i];
    }

    for(int i=1;i<=8;i++) {
        for(int j=i+1;j<=9;j++) {
            if(sum-a[i]-a[j]==100) {
                a[i]=-1;
                a[j]=-1;
                flag=true;
                break;
            }
        }

        if(flag) break;
    }

    for(int i=1;i<=9;i++) {
        if(a[i]!=-1) v.push_back(a[i]);
    }

    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++) {
        printf("%d\n", v[i]);
    }

    return 0;
}

/* 조합을 이용한 풀이
#include<bits/stdc++.h>

using namespace std;

vector<int> v1;
vector<int> v2;
int k=7;

void combi(int here, vector<int> &v2) {
    if(v2.size()==k) {
        int sum=0;
        for(int idx:v2) sum+=v1[idx];

        if(sum==100) {
            for(int idx:v2) printf("%d\n",v1[idx]);
            exit(0);
        }

        return;
    }
    for(int i=here+1;i<v1.size();i++) {
        v2.push_back(i);
        combi(i,v2);
        v2.pop_back();
    }
    return;
}

int main() {

    for(int i=0;i<9;i++) {
        int a;
        scanf("%d",&a);
        v1.push_back(a);
    }
    
    sort(v1.begin(),v1.end());
    
    // 9개중 7개 선택
    combi(-1,v2);

    return 0;
}
*/