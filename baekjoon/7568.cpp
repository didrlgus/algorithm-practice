// 7568. 덩치
#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> v;
int main() {

    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);

        v.push_back({a,b});
    }

    for(int i=0;i<v.size();i++) {           // 내 몸무게
        int cnt=0;
        for(int j=0;j<v.size();j++) {       // 상대 몸무게
            if(i==j) continue;
            
            int x=v[i].first,y=v[i].second,p=v[j].first,q=v[j].second;

            if(x<p && y<q) cnt++;
        }
        printf("%d ",++cnt);
    }

    return 0;
}