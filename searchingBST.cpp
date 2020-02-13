#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
     struct node *left;
     struct node *right;
};

node* insert(node *root,int data){
    if(root==NULL){
        node *t=new node();
        t->data=data;
        return t;
    }
    if(data<=root->data){
        root->left=insert(root->left,data);
    }else{
        root->right=insert(root->right,data);
    }
    return root;
}

node* buildTree(){
    int data;
    cin>>data;
    node *root=NULL;
    
    while(data!=-1){
       root=insert(root,data);
       cin>>data;
    }
    return root;
}

void inOrder(node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

bool searching(node *root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key<=root->data){
        searching(root->left,key);
    }else{
        searching(root->right,key);
    }
    
}


int main(){
    node *root=buildTree();
   
    int k;
    cin>>k;
    if(searching(root,k)){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
     inOrder(root);
    
    return 0;
}