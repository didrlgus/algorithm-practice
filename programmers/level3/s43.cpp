// 길 찾기 게임
#include<bits/stdc++.h>
using namespace std;
int n;
struct Node {
    int id,x,y;
    Node* left;
    Node* right;
};
vector<Node> nodes;
bool cmp(Node& n1,Node& n2) {
    if(n1.y==n2.y) return n1.x<n2.x;
    return n1.y>n2.y;
}
void insertNode(Node* root,Node* child) {
    if(root->x>child->x) {
        if(root->left==NULL) root->left=child;
        else insertNode(root->left,child);
    } else {
        if(root->right==NULL) root->right=child;
        else insertNode(root->right,child);
    }
}
void pre_order(vector<int>& answer,Node* root) {
    if(root==NULL) return;
    answer.push_back(root->id);
    pre_order(answer,root->left);
    pre_order(answer,root->right);
}
void post_order(vector<int>& answer,Node* root) {
    if(root==NULL) return;
    post_order(answer,root->left);
    post_order(answer,root->right);
    answer.push_back(root->id);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer={{},{}};
    n=(int)nodeinfo.size();
    for(int i=0;i<n;i++) nodes.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1]});
    sort(nodes.begin(),nodes.end(),cmp);
    Node* root=&nodes[0];
    for(int i=1;i<n;i++) insertNode(root,&nodes[i]);
    pre_order(answer[0],root);
    post_order(answer[1],root);
    return answer;
}
int main() {
    vector<vector<int>> nodeinfo={{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
    vector<vector<int>> ret=solution(nodeinfo);
    for(auto v:ret) {
        printf("{");
        for(auto it:v) {
            printf("%d ",it);
        }
        printf("}\n");
    }
    return 0;
}