// 최솟값
#include<bits/stdc++.h>
using namespace std;
#define max_n 100001
typedef long long ll;
const int H = (int)ceil(log2(max_n));
const int tree_size = (1<<(H+1));
vector<ll> a(max_n,0);
vector<ll> tree(tree_size,0);
int n,m;
void init(int node, int start,int end) {
	if(start==end) tree[node]=start;
	else {
		init(node*2,start,(start+end)/2);
		init(node*2+1,(start+end)/2+1,end);
		ll l=tree[node*2],r=tree[node*2+1];
		if(a[l]<a[r]) tree[node] = l; 
        else tree[node] = r;
	}
}
ll query(int node, int start, int end, int i, int j) {			
	if(j<start||end<i) return -1;
	if(i<=start&&end<=j) return tree[node];
	ll m1=query(node*2,start,(start+end)/2,i,j);
	ll m2=query(node*2+1,(start+end)/2+1,end,i,j);
	if(m1==-1) return m2;
	else if(m2==-1) return m1;
	else {
		if(a[m1]<a[m2]) return m1;
		return m2;
	}
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	init(1,1,n);
	for(int i=1;i<=m;i++) {
		int s,e;
		scanf("%d %d",&s,&e);
		int idx=query(1,1,n,s,e);
		printf("%lld\n",a[idx]);
	}
	return 0;
}