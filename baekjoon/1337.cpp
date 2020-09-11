// 올바른 배열
#include <bits/stdc++.h>
using namespace std;
int n,arr[10005],lo,hi,ret=5;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
	while(hi<n){
		if(arr[hi]<=arr[lo]+4){
			int num=hi-lo+1;
			ret=min(ret,5-num);
			hi++;
		} else lo++;
	}
	printf("%d\n",ret);
    return 0;
}