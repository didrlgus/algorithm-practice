// 퍼레이드
#include<bits/stdc++.h>
using namespace std;
int v,e,p[3005],in[3005],ret;
int uf_find(int a){
    if(p[a]<0) return a; 
    return p[a]=uf_find(p[a]);
}
void uf_merge(int a,int b){
    a=uf_find(a);
    b=uf_find(b);
    if(a==b) return;  
    p[b]=a; 
    return;
}
int main() {
    scanf("%d%d",&v,&e);
    memset(p,-1,sizeof(p));
    for(int i=1;i<=e;i++) {
        int a,b;scanf("%d%d",&a,&b);
        uf_merge(a,b);
        in[a]++;in[b]++;
    }
    for(int i=1;i<=v;i++) {     // 차수가 홀수인 정점 카운트
        if(in[i]&1) ret++;
    }
    int root=uf_find(1);
    for(int i=2;i<=v;i++) {
        if(root!=uf_find(i)) {
            ret=3;
            break;
        }
    }
    // 오일러회로 : 모든 정점이 연결된 상태이고 차수가 홀수인 정점이 0개 또는 2개면 한붓그리기 가능
    if(ret==0||ret==2) printf("YES\n");
    else printf("NO\n");
    return 0;
}