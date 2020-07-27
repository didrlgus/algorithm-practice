// 싸이클
#include<bits/stdc++.h>
using namespace std;
int n,p,ret;
bool check[105];
vector<int> v;
int main() {
	scanf("%d%d",&n,&p);
	int a=n*n%p;
	while(!check[a]) {
		check[a]=true;
		v.push_back(a);
		a=a*n%p;
	}
	int idx=0;
	for(int i=0;i<(int)v.size();i++) {
		if(v[i]==a) idx=i;
	}
	printf("%d\n",(int)v.size()-idx);
	return 0;
}
