// 공
#include<bits/stdc++.h>
using namespace std;
int n,arr[]={0,1,2,3};
int main() {
	scanf("%d",&n);
	while(n--) {
		int a,b;
		scanf("%d %d",&a,&b);
		int tmp=arr[a];
		arr[a]=arr[b];
		arr[b]=tmp;
	}
	for(int i=1;i<=3;i++) if(arr[i]==1) printf("%d\n",i);
	return 0;
}