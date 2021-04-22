// 실패율
#include<bits/stdc++.h>
using namespace std;
int arr[510],sum;
vector<pair<int,double>> v;
bool cmp(pair<int,double> p1,pair<int,double> p2) {
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second>p2.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(auto it:stages) arr[it]++;
    for(int i=1;i<=N+1;i++) sum+=arr[i];
    for(int i=1;i<=N;i++) {
        if(arr[i]==0) v.push_back({i,0});
        else {
            v.push_back({i,(double)arr[i]/sum});
            sum-=arr[i];
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it:v) answer.push_back(it.first);
    return answer;
}
int main() {
    int N=5;
    vector<int> stages={2,1,2,6,2,4,3,3};
    vector<int> ret=solution(N,stages);
    for(auto it:ret) printf("%d ",it);
    return 0;
}