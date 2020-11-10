// 나이순 정렬
#include<bits/stdc++.h>
using namespace std;
struct people {
    int age;
    string name;
    int order;
};
bool cmp(people p1,people p2) {
    if(p1.age==p2.age) return p1.order<p2.order;
    return p1.age<p2.age;
}
int n;
vector<people> v;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        int age;string name;
        cin>>age>>name;
        v.push_back({age,name,i});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it:v) cout<<it.age<<" "<<it.name<<"\n";
    return 0;
}