// 신규 아이디 추천
#include<bits/stdc++.h>
using namespace std;
string solution(string new_id) {
    string answer="";
    for(auto ch:new_id) {
        if(ch>='A'&&ch<='Z') {
            answer+=ch+32;
        } else answer+=ch;
    }
    string tmp="";
    for(auto ch:answer) {
        if(ch>='a'&&ch<='z') tmp+=ch;
        if(ch>='0'&&ch<='9') tmp+=ch;
        if(ch=='-'||ch=='_'||ch=='.') tmp+=ch;
    }
    answer=tmp;
    tmp=answer[0];
    for(int i=1;i<(int)answer.size();i++) {
        tmp+=answer[i];
        if(answer[i]=='.') {
            while(i<(int)answer.size()) {
                if(answer[++i]!='.') break;    
            }
            i--;
        }
    }
    answer=tmp;
    tmp="";
    while(answer.front()=='.'||answer.back()=='.') {
        if(answer.front()=='.') answer=answer.substr(1);
        if(answer.back()=='.') answer=answer.substr(0,(int)answer.size()-1);
    }
    if(answer=="") answer+="a";
    if((int)answer.size()>=16) {
        for(int i=0;i<=14;i++) tmp+=answer[i];
        answer=tmp;
    }
    if(answer.back()=='.') answer=answer.substr(0,(int)answer.size()-1);
    if((int)answer.size()<=2) {
        char ch=answer.back();
        while(answer.size()<3) answer+=ch;
    }
    return answer;
}
int main() {
    cout<<solution("z-+.^.")<<'\n';
    return 0;
}