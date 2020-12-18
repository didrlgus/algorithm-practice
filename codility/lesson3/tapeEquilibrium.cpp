#include<bits/stdc++.h>
using namespace std;
int sum,diff;
int solution(vector<int> &v) {
    for(auto it:v) sum+=it;
    int p1=v[0],p2=sum-v[0];
    diff=abs(p1-p2);
    for(int i=1;i<(int)v.size()-1;i++) {
        p1+=v[i];p2-=v[i];
        diff=min(diff,abs(p1-p2));
    }
    return diff;
}