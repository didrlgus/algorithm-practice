// 연산자 끼워넣기
#include<bits/stdc++.h>

using namespace std;

int n;
int arr[15];
vector<int> v;
int mx=-987654321,mn=987654321;
int main() {

    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        arr[i]=a;
    }

    for(int i=0;i<4;i++) {
        int a;
        scanf("%d",&a);

        for(int j=0;j<a;j++) v.push_back(i);        // 0->+, 1->-, 2->*, 3->/
    }

    do {
        int a=arr[0];
        for(int i=0;i<v.size();i++) {
            if(v[i]==0) a+=arr[i+1];
            else if(v[i]==1) a-=arr[i+1];
            else if(v[i]==2) a*=arr[i+1];
            else a/=arr[i+1];
        }
        mx=max(mx,a);
        mn=min(mn,a);
    } while(next_permutation(v.begin(),v.end()));

    printf("%d\n%d\n",mx,mn);

    return 0;
}