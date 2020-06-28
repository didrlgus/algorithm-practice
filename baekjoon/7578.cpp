// 공장
#include<bits/stdc++.h>
using namespace std;
#define max_n 500001
typedef long long ll;
const int H = (int)ceil(log2(max_n));
const int tree_size = (1<<(H+1));
vector<ll> a(max_n,0);
vector<ll> tree(tree_size,0);
int n,tmp,idx[1000001];
ll ret;
void init(int node, int start,int end) {
	if(start==end) tree[node]=a[start];
	else {
		init(node*2,start,(start+end)/2);
		init(node*2+1,(start+end)/2+1,end);
		tree[node]=tree[node*2]+tree[node*2+1];
	}
}
ll query(int node, int start, int end, int i, int j) {
	if(j<start||end<i) return 0;
	if(i<=start&&end<=j) return tree[node];
	ll m1=query(node*2,start,(start+end)/2,i,j);
	ll m2=query(node*2+1,(start+end)/2+1,end,i,j);
	return m1+m2;
}
void update(int node,int start,int end,int index,int value) {
	if(index<start||end<index) return;
	if(start==end) {
		tree[node]=value;
		return;
	}
	update(node*2,start,(start+end)/2,index,value);
	update(node*2+1,(start+end)/2+1,end,index,value);
	tree[node]=tree[node*2]+tree[node*2+1];
}
int main() {
    scanf("%d",&n);
    init(1,1,n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&tmp);
        idx[tmp]=i;
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&tmp);
        tmp=idx[tmp];
        ret+=query(1,1,n,tmp,n);
        update(1,1,n,tmp,1);
    }
    printf("%lld\n",ret);
    return 0;
}