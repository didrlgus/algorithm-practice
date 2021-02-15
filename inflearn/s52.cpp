// Ugly Numbers
#include<bits/stdc++.h>
using namespace std;
int n,p2=1,p3=1,p5=1;
vector<int> v;
int main() {
	v.push_back(0);
	v.push_back(1);
	scanf("%d",&n);
	while(true) {
		int a=v[p2]*2,b=v[p3]*3,c=v[p5]*5;
		int mn;
		mn=min(a,min(b,c));
		v.push_back(mn);
		if(a==mn) p2++;		
		if(b==mn) p3++;
		if(c==mn) p5++;
		if((int)v.size()==n+1) break;
	}
	printf("%d\n",v.back());
	return 0;
}