#include<bits/stdc++.h>
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
	struct node *root=new node();
	root->data=d;
	root->left=buildTree();
	root->right=buildTree();
	return root;
}

int height(node *root){
	if(root==NULL){
		return 0;
	}
	return max(height(root->left),height(root->right))+1;
}

void print(node *root){
	if(root==NULL){
		return ;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

int diameter(node *root){
	if(root==NULL){
		return 0;
	}
	int h1=height(root->left);
	int h2=height(root->right);
	int opt1=h1+h2;
	int o2=diameter(root->left);
	int o3=diameter(root->right);
	return max(o3,max(o2,opt1));
}

int main(){
	root=NULL;
	root=buildTree();
	cout<<"height of tree is"<<height(root)<<endl;
	print(root);
	cout<<" diamter of tree is"<<diameter(root)<<endl;
}