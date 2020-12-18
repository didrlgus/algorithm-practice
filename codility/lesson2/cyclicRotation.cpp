#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> &v, int K) {
    while(K--) rotate(v.begin(),v.begin()+v.size()-1,v.end());
    return v;
}