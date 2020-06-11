// 톱니바퀴
#include<bits/stdc++.h>
using namespace std;
vector<char> v[5];
int n,ret;
void rot(int idx,int dir) {
    if(dir==1) {
        rotate(v[idx].begin(),v[idx].begin()+v[idx].size()-1,v[idx].end());
    } else {    
        rotate(v[idx].begin(),v[idx].begin()+1,v[idx].end());
    }
}
int main() {
    for(int i=1;i<=4;i++) {
        for(int j=0;j<8;j++) {
            int c;
            scanf(" %1c",&c);
            v[i].push_back(c);
        }
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        vector<pair<int,int>> vv;
        vv.push_back({a,b});
        int r=b;
        for(int j=a-1;j>=1;j--) {
            if(v[j+1][6]!=v[j][2]) {
                r*=-1;
                vv.push_back({j,r});
            } else break;
        }
        r=b;
        for(int j=a+1;j<=4;j++) {
            if(v[j-1][2]!=v[j][6]) {
                r*=-1;
                vv.push_back({j,r});
            } else break;
        }
        for(auto it:vv) rot(it.first,it.second);
    }
    for(int i=1;i<=4;i++) {
        int a=v[i][0]-'0';
        ret+=a*pow(2,i-1);
    }
    printf("%d\n",ret);
    return 0;
}