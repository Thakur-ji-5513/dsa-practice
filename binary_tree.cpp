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
int dia_t(node* tree){
    if (tree==NULL)
    {
        return 0;
    }
    int ht=height(tree->left);
    int hr=height(tree->right);
    int dia=hr+ht;
    int maxdia=max(dia_t(tree->left),dia_t(tree->right));
    return max(dia,maxdia);
}
bool id_tree(node* tree1, node* tree2){
    if (tree1==NULL && tree2==NULL)
    {
        return true;
    }

    if ((tree1==NULL && tree2!=NULL) ||(tree2==NULL && tree1!=NULL) )
    {
        return false;
    }

    if (tree1->data!=tree2->data)
    {
        return false;
    }
    if(!id_tree(tree1->right,tree2->right)){
        return false;
    }
    if(!id_tree(tree1->left,tree2->left)){
        return false;
    }
    return true;
}
void k_val(node* tree, int k){
    if (tree==NULL)
    {
        return;
    }
    
    if (k==1)
    {
        cout<<tree->data<<" ";
        return;
    }
    k_val(tree->left,k-1);
    k_val(tree->right,k-1);
    return;
}
int main(){
vector <int> rt={11,13,19,-1,-1,26,21,-1,-1,22,-1,-1,15,17,-1,-1,23,-1,25,-1,-1};
vector <int> preord = {1, 2, 4, -1, -1, 5, -1,  -1, 3, -1, 6, -1, -1};
node* root=build_tree(preord);
ind=-1;
node* root2=build_tree(rt);
/* cout<<" "<<root->data<<endl;
cout<<root->left->data<<" "<<root->right->data; */
print_tree(root);
int ans=0;
cout<<"\n total number of elements: "<<nt(root)<<endl;

cout<<"height is: "<<height(root)<<endl;
int sum=sum_node(root);
cout<<"the sum of node is: "<<sum<<endl;
cout<<"the diameter is: "<<dia_t(root)<<endl;
print_tree(root2);
cout<<"\nsecond binary tree has diameter of: "<<dia_t(root2)<<endl;
cout<<id_tree(root,root2)<<endl;
k_val(root,3);
return 0;
}