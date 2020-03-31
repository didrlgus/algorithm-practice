// 10971. 외판원 순회 2
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int a[15][15];
int min_=987987987;

vector<int> v;

void func() {

    for(int i=1;i<n;i++) v.push_back(i);
    
    do {
        int sum=0;
        bool flag=false;

        for(int i=0;i<n-2;i++) {
            if(!a[v[i]][v[i+1]]) {
                flag=true;
                break;
            }

            sum+=a[v[i]][v[i+1]];
        }

        if(!flag) {
            if(a[0][v[0]] && a[v[n-2]][0]) {
                min_=min(min_,sum+a[0][v[0]]+a[v[n-2]][0]);
            }
        }
    } while (next_permutation(v.begin(),v.end()));
    

    printf("%d\n",min_);
}

int main() {

    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    }

    func();

    return 0;
}