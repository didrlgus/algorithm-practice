// 알파벳 개수
#include<bits/stdc++.h>
using namespace std;
int arr[30];
string s;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	for(auto c:s) arr[c-'a']++;
	for(int i=0;i<26;i++) printf("%d ",arr[i]);
	return 0;
}