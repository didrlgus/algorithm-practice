// 알파벳 개수
#include<bits/stdc++.h>

using namespace std;
string s;
int a[30];

int main() {

    cin>>s;

    for(int i=0;i<s.size();i++) a[s.at(i)-'a']++;
    for(int i=0;i<26;i++) printf("%d ",a[i]);
}