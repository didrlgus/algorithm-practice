// 문자열 압축
#include<bits/stdc++.h>
using namespace std;
int n;
int solution(string s) {
    int answer = 0;
    n=(int)s.size();
    answer=n;
    for(int i=1;i<=n/2;i++) {
        int idx=0,num=0;
        string str="";
        string prev_str=s.substr(idx,i);
        idx+=i;
        num++;
        for(int j=idx;j<n;j+=i) {
            string cur_str=s.substr(j,i);
            if(prev_str==cur_str) {
                num++;
            } else {
                if(num>1) str+=to_string(num)+prev_str;
                else str+=prev_str;
                prev_str=cur_str;
                num=1;
            }
        }
        if(num>1) str+=to_string(num)+prev_str;
        else str+=prev_str;
        answer=min(answer,(int)str.size());
    }
    return answer;
}
int main() {
    string s="abcabcabcabcdededededede";
    printf("%d\n",solution(s));
    return 0;
}