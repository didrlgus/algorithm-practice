// 1644. 소수의 연속합
#include<bits/stdc++.h>
using namespace std;
int n,ret,s,e,sum;
bool arr[4000005];
vector<int> v;
int main() {
	scanf("%d",&n);
	for(int i=0;i<=n;i++) arr[i]=true;  
	for(int i=2;i<=n;i++) {
		if(arr[i]) {
			for(int j=2;j<=n/i;j++){
				if(arr[i*j]) arr[i*j]=false;
			}
		}
	}
	for(int i=2;i<=n;i++) if(arr[i]) v.push_back(i);
	while(true) {
		if(sum>=n) sum-=v[s++];
		else if((int)v.size()==e) break;
		else sum+=v[e++];
		if(sum==n) ret++;
	}
	printf("%d\n",ret);
	return 0;
}