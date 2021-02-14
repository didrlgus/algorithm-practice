// 블록의 최댓값
#include<bits/stdc++.h>
using namespace std;
int n,arr[15][15],ret;
vector<int> v1,v2;
int main() {
	scanf("%d",&n);
	for(int j=0;j<n;j++) {
		int val;scanf("%d",&val);
		v1.push_back(val);
	}
	for(int j=0;j<n;j++) {
		int val;scanf("%d",&val);
		v2.push_back(val);
	}
	for(int j=0;j<n;j++) {
		for(int i=0;i<n;i++) arr[i][j]=v1[j];
	}
	for(int i=0;i<n;i++) {
		int mx=v2[n-i-1];
		for(int j=0;j<n;j++) {
			if(arr[i][j]>mx) arr[i][j]=mx;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) ret+=arr[i][j];
	}
	printf("%d\n",ret);
	return 0;
}