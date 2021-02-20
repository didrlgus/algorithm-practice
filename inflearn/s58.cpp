// 이진트리 깊이우선탐색(DFS)
#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2,v3;
struct Node {
	int id;
	Node* left;
	Node* right;
};
void pre_order(Node* root) {
	if(root==NULL) return;
	v1.push_back(root->id);
	pre_order(root->left);
	pre_order(root->right);
}
void in_order(Node* root) {
	if(root==NULL) return;
	in_order(root->left);
	v2.push_back(root->id);
	in_order(root->right);
}
void post_order(Node* root) {
	if(root==NULL) return;
	post_order(root->left);
	post_order(root->right);
	v3.push_back(root->id);
}
int main() {
	vector<Node> nodes;
    for(int i=1;i<=7;i++) nodes.push_back({Node({i})});
	Node* root=&nodes[0];
	root->left=&nodes[1];
	root->right=&nodes[2];
	root->left->left=&nodes[3];
	root->left->right=&nodes[4];
	root->right->left=&nodes[5];
	root->right->right=&nodes[6];
	pre_order(root);
	for(auto it:v1) printf("%d ",it);
	printf("\n");
	in_order(root);
	for(auto it:v2) printf("%d ",it);
	printf("\n");
	post_order(root);
	for(auto it:v3) printf("%d ",it);
	printf("\n");
	return 0;
}