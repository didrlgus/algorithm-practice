#include<bits/stdc++.h>
using namespace std;
struct tree {
  int x;
  tree * l;
  tree * r;
};
int mx=0;
void traverse(tree* T,int depth) {
    if(depth>mx) {
        mx=depth;
    }
    if(T->l!=NULL) {
        traverse(T->l,depth+1);
    }
    if(T->r!=NULL) {
        traverse(T->r,depth+1);
    }
    return;
}
int solution(tree * T) {
    if(T==NULL) return -1;
    traverse(T,0);
    return mx;
}