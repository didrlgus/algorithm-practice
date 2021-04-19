// 신규 아이디 추천
#include<bits/stdc++.h>
using namespace std;
string solution(string new_id) {
    string answer = "";
    transform(new_id.begin(),new_id.end(),new_id.begin(),::tolower);
    string tmp_str="";
    for(auto ch:new_id) {
        if(ch>='a'&&ch<='z') tmp_str+=ch;
        if(ch>='0'&&ch<='9') tmp_str+=ch;
        if(ch=='-'||ch=='_'||ch=='.') tmp_str+=ch;
    }
    new_id=tmp_str;
    tmp_str="";
    for(int i=0;i<(int)new_id.size();i++) {
        if(new_id[i]=='.') {
            tmp_str+=new_id[i];
            for(int j=i+1;j<(int)new_id.size();j++) {
                if(new_id[j]!='.') {
                    i=j-1;
                    break;
                }
                if(j==new_id.size()-1) i=j;
            }
        } else tmp_str+=new_id[i];
    }
    new_id=tmp_str;
    if(new_id.front()=='.') new_id=new_id.substr(1);
    if(new_id.back()=='.') new_id=new_id.substr(0,(int)new_id.size()-1);
    if(new_id=="") new_id+='a';
    if((int)new_id.size()>=16) new_id=new_id.substr(0,15);
    if(new_id.back()=='.') new_id=new_id.substr(0,(int)new_id.size()-1);
    if((int)new_id.size()<=2) {
        char last_ch=new_id.back();
        while(new_id.size()<3) new_id+=last_ch;
    }
    return new_id;
}

int main() {
    string new_id="...!@BaT#*..y.ab...b";
    cout<<solution(new_id)<<'\n';
    return 0;
}