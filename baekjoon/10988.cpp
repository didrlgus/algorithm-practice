// 팰린드롬인지 확인하기
#include<bits/stdc++.h>
using namespace std;
string s;
bool flag;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	for(int i=0;i<(int)s.size();i++) if(s[i]!=s[(int)s.size()-1-i]) flag=true;
	printf("%d\n",flag?0:1);
	return 0;
}