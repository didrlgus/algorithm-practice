// 좋은 단어
#include<bits/stdc++.h>

using namespace std;

int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    scanf("%d",&n);

    int cnt=0;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;

        stack<char> st;
        for(int j=0;j<s.size();j++) {
            if(!st.empty() && st.top()==s[j]) st.pop();
            else st.push(s[j]);
        }

        if(st.empty()) cnt++;
    }

    printf("%d\n",cnt);

    return 0;
}