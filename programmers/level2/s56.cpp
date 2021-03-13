// 이진 변환 반복하기
#include<bits/stdc++.h>
using namespace std;
int turn,cnt;
string bin;
string remove_zero(string s) {
    string tmp="";
    int sum=0;
    for(auto ch:s) {
        if(ch=='1') tmp+=ch;
        else sum++;
    }
    cnt+=sum;
    return tmp;
}
void tobin(int x) {
    if(x==0) return;
    tobin(x/2);
    bin+=to_string(x%2);
}
vector<int> solution(string s) {
    vector<int> answer;
    while(s!="1") {
        s=remove_zero(s);
        bin.clear();
        tobin((int)s.size());
        s=bin;
        turn++;
    }
    answer.push_back(turn);
    answer.push_back(cnt);
    return answer;
}
int main() {
    string s="110010101001";
    vector<int> ret=solution(s);
    for(auto it:ret) printf("%d ",it);
    return 0;
}