#include<iostream>
#include<vector>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=right=NULL;
    }
};
static int ind=-1;
node* build_tree(vector <int>pre){
    ind++;
    if (pre[ind]==-1)
    {
        return NULL;
    }
    node* root= new node(pre[ind]);
    root->left=build_tree(pre);
    root->right=build_tree(pre);
    return root;    
}
void print_tree(node* tree){
    if(tree==NULL){
        return;
    }
    cout<<tree->data<<" ";
    print_tree(tree->left);
    print_tree(tree->right);
}
int nt(node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + nt(root->left) + nt(root->right);
}
int height(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+(max(height(root->right), height(root->left)));
}
int sum_node(node* root){
    if (root==NULL)
    {
        return 0;
    }

    return(root->data)+sum_node(root->left)+sum_node(root->right);
}
int main(){
vector <int> preord = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
node* root=build_tree(preord);
/* cout<<" "<<root->data<<endl;
cout<<root->left->data<<" "<<root->right->data; */
print_tree(root);
int ans=0;
cout<<"total number of elements: "<<nt(root)<<endl;

cout<<"height is: "<<height(root)<<endl;
int sum=sum_node(root);
cout<<"the sum of node is: "<<sum<<endl;
return 0;
}