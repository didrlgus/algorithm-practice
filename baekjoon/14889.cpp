// 스타트와 링크
#include<bits/stdc++.h>

using namespace std;

int n;
int arr[25][25];
bool check[25];
vector<int> v;

int mn=987654321;

void combi(int here,vector<int> &v) {
    if(v.size()==n/2) {
        vector<int> team2;
        for(int i=1;i<=n;i++) {
            if(!check[i]) team2.push_back(i);
        }
        
        int sum1=0,sum2=0;
        for(int i=0;i<v.size()-1;i++) {
            for(int j=i+1;j<v.size();j++) {
                sum1+=arr[v[i]][v[j]]+arr[v[j]][v[i]];
                sum2+=arr[team2[i]][team2[j]]+arr[team2[j]][team2[i]];
            }
        }

        mn=min(mn,abs(sum1-sum2));

        return;
    }
    for(int i=here+1;i<=n;i++) {
        check[i]=true;
        v.push_back(i);
        combi(i,v);
        check[i]=false;
        v.pop_back();
    }
}

int main() {

    scanf("%d",&n);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) scanf("%d",&arr[i][j]);
    }

    combi(0,v);
    printf("%d\n",mn);

    return 0;
}