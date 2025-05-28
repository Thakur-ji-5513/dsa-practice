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
node* insert_bst(node* root, int val) {
    if (root == nullptr) {
        return new node(val);  
    }

    if (val < root->data) {
        root->left = insert_bst(root->left, val);  
    } else {
        root->right = insert_bst(root->right, val);  
    }

    return root;  
}
void takeinput(node* &root){
    int value;
    cout<<"enter your element: "<<endl;
    cin>>value;
    while (value!=-1)
    {
        root=insert_bst(root,value);
        cin>>value;
    }
    return;
}
void print_tree(node* root){
    if (root==NULL)
    {
        return;
    }
    print_tree(root->left);
    cout<<root->data<<" ";
    print_tree(root->right);
}

bool search_bst(node* root, int k){
    if (root==NULL)
    {
        return false;
    }
    if (root->data==k)
    {
        return true;
    }
    if (root->data>k)
    {
        return search_bst(root->left,k);
    }
    else{
        return search_bst(root->right,k);
    }
}

node* del_node(node* root,int key){
    if (root==NULL)
    {
        return root;
    }
    else if (key<root->data)
    {
        root->left=del_node(root->left,key);
    }
    else if (key>root->data)
    {
        root->right=del_node(root->right,key);
    }
    else{
        node* temp=root;
        if (root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left==NULL && root->right!=NULL)
        {
            temp=root->right;
            delete root;
            return temp;
        }
        else if (root->left!=NULL && root->right==NULL)
        {
            temp=root->left;
            delete root;
            return temp;
        }
        else{
            temp=helper(root);
            root->data=temp->data;
            root->right=del_node(root->right,temp->data);
        }
        
    }
    
    
   return root; 
}

node* helper(node* root){
    while (root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

int main(){
    node* tree=NULL;
    takeinput(tree);
    print_tree(tree);
    cout<<endl;
    cout<<search_bst(tree,6);
    return 0;
}