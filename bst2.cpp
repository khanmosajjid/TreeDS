#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

node *buildTree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node* root=new node();
	root->data=d;
	 root->left=buildTree();
	 root->right=buildTree();
	 return root;

}

void print(node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}


int main(){
	root=buildTree();
	print(root);

	
}