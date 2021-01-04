// A+B - 6
#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin>>n;
    while(n--) {
        string s;cin>>s;
        cout<<(s[0]-'0')+(s[2]-'0')<<'\n';
    }
    return 0;
}