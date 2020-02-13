#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

// class node{
// 	int data;
// 	node*left;
// 	node*right;

// 	node(int data){
// 		left=NULL;
// 		right=NULL;
// 	}
// };

node* insert(node *root,int data){
	if(root==NULL){
		node* t=new node();
		t->data=data;
		return t;
	}
	
	if(data<=root->data){
		
		root->left=insert(root->left,data);
	}
	else{
		
		root->right=insert(root->right,data);
	}
	return root;
}

node* build(){
	int d;
	cin>>d;
	node* root=NULL;
	while(d!=-1){
		root=insert(root,d);
		cin>>d;

	}
	return root;
}

//inorder printing tree

void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	node* root=build();
	inorder(root);
}