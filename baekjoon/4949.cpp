// 균형잡힌 세상
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        string s;
        getline(cin,s);
        stack<char> st;

        if(s==".") break;

        for(int i=0;i<s.size();i++) {
            if(!st.empty() && s[i]==')') {
                if(st.top()=='(') st.pop();
                else {
                    st.push(')');
                    break;
                }
            } else if(st.empty() && s[i]==')') {
                st.push(')');
                break;
            } else if(!st.empty() && s[i]==']') {
                if(st.top()=='[') st.pop();
                else {
                    st.push(']');
                    break;
                }
            } else if(st.empty() && s[i]==']') {
                st.push(']');
                break;
            }
            
            if(s[i]=='(' || s[i]=='[') {
                if(s[i]=='(') st.push('(');
                else st.push('[');
            }
        }

        if(st.empty()) cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
    }

    return 0;
}