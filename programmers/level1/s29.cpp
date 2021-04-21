#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v1,v2;
string ret="";
void get_bin(int num) {
    if(num==0) return;
    get_bin(num/2);
    ret+=to_string(num%2);
}
void func(int n,vector<int> &arr,vector<vector<int>> &v) {
    for(auto it:arr) {
        ret="";
        get_bin(it);
        while((int)ret.size()<n) ret="0"+ret;
        vector<int> ret_v;
        for(auto ch:ret) {
            if(ch=='0') ret_v.push_back(0);
            else ret_v.push_back(1);
        }
        v.push_back(ret_v);
    }    
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    func(n,arr1,v1);
    func(n,arr2,v2);

    for(int i=0;i<n;i++) {
        string str="";
        for(int j=0;j<n;j++) {
            int v1_val=v1[i][j],v2_val=v2[i][j];
            if(v1_val==1||v2_val==1) str+="#";
            else str+=" ";
        }
        answer.push_back(str);
    }
    return answer;
}
int main() {
    int n=1;
    vector<int> arr1={1},arr2={0};
    vector<string> ret=solution(n,arr1,arr2);
    for(auto it:ret) cout<<it<<'\n';
    return 0;
}