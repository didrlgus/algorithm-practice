// 부분집합(DFS)
#include<bits/stdc++.h>
using namespace std;
int n;
bool check[15];
void func(int x) {
	if(x==n+1) {
		bool flag=false;
		for(int i=1;i<=n;i++) {
			if(check[i]) {
				flag=true;
				printf("%d ",i);
			}
		}
		if(flag) printf("\n");
		return;
	}	
	check[x]=true;
	func(x+1);
	check[x]=false;
	func(x+1);
}
int main() {
	scanf("%d",&n);
	func(1);
	return 0;
}