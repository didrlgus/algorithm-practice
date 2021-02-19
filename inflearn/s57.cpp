// 재귀함수 이진수 출력
#include<bits/stdc++.h>
using namespace std;
int n;
string ret;
void func(int x) {
	if(x/2==0) {
		ret+=to_string(x%2);
		return;
	}
	func(x/2);
	ret+=to_string(x%2);
}
int main() {
	scanf("%d",&n);
	func(n);
	cout<<ret<<'\n';
	return 0;
}