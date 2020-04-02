// 1759. 암호 만들기
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

int l,c;

vector<char> v;

void dfs(int current,int idx,int m,int j,string s) {
    if(current>=l) {
        if(m>=1 && j>=2) cout << s << endl;
    } else {
        for(int i=idx;i<c;i++) {
            if(v[i]=='a' || v[i]=='i' || v[i]=='o' || v[i]=='u' || v[i]=='e') {
                dfs(current+1,i+1,m+1,j,s+v[i]);
            } else {
                dfs(current+1,i+1,m,j+1,s+v[i]);
            }
        }
    }
}

int main() {

    scanf("%d %d",&l,&c);

    for(int i=0;i<c;i++) {
        char ch;
        scanf(" %c",&ch);
        v.push_back(ch);
    }

    sort(v.begin(),v.end());

    dfs(0,0,0,0,"");

    return 0;
}