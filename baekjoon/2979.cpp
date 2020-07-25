// 트럭 주차
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int a,b,c,arr[105],lo=INF,hi=-INF,val[5],ret;
int main() {
	scanf("%d%d%d",&a,&b,&c);
	val[1]=a,val[2]=b*2,val[3]=c*3;
	for(int i=0;i<3;i++) {
		int s,e;scanf("%d%d",&s,&e);
		for(int i=s;i<e;i++) arr[i]++;
		lo=min(lo,s);hi=max(hi,e);
	}
	for(int i=lo;i<hi;i++) ret+=val[arr[i]];
	printf("%d\n",ret);
	return 0;
}