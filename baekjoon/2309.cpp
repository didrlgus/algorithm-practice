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