// 10972. 이전 순열
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int n;
vector<int> v;

int main() {
  
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }

    if (prev_permutation(v.begin(),v.end())) {
        for (int i=0; i<n; i++) {
            cout << v[i] << ' ';
        }
    } else {
        cout << "-1";
    }

    return 0;
}