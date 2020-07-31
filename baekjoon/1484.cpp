// 다이어트
#include<bits/stdc++.h>
using namespace std;
int g,lo,hi;
vector<int> ret;
int main() {
    scanf("%d",&g);
    lo=1,hi=1;
    while(true) {
        int val=lo*lo-hi*hi;
        if(val<=g) {
            if(val==g) ret.push_back(lo);
            lo++;
        } else if(lo-1==hi) break;
        else hi++;
    }
    if((int)ret.size()) {
        for(auto it:ret) printf("%d\n",it);
    } else printf("-1\n");
    return 0;
}