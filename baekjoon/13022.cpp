// 늑대와 올바른 단어
#include<bits/stdc++.h>
using namespace std;
string str;
bool flag;
int main() {
    cin>>str;
    if(str.size()<4) {
        cout<<0<<'\n';
        return 0;
    }
    for(int i=0;i<(int)str.size();) {
        char ch=str[i];
        if(ch!='w') {
            flag=true;
            break;
        }
        int w_cnt=1;
        int idx=-1;
        for(int j=i+1;j<(int)str.size();j++) {
            char c=str[j];
            if(str[j]=='w') w_cnt++;
            else {
                idx=j;
                break;
            }
        }
        string tmp="";
        for(int j=0;j<w_cnt;j++) tmp+='o';
        for(int j=0;j<w_cnt;j++) tmp+='l';
        for(int j=0;j<w_cnt;j++) tmp+='f';
        int tmp_idx=0;
        for(int j=0;j<(int)tmp.size();j++) {
            if(str[idx++]!=tmp[j]) {
                flag=true;
                break;
            }
        }
        if(flag) break;
        i=idx;
    }
    cout<<!flag<<'\n';
    return 0;
}