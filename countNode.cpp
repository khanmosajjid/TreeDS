#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

node *buildTree(){
	int c;
	cin>>c;
	if(c==-1)
		return NULL;
	else{
		node *root=new node();
		root->data=c;
		root->left=buildTree();
		root->right=buildTree();
	}
}
void print(node *root){ 
	if(root==NULL){
		return;
	}
	cout<<root->data<<" "; //print the root data first followed by subtree
	print(root->left);
	print(root->right);
}

int sum(node *root){
	if(root==NULL){
		return 0;
	}
	return root->data+sum(root->left)+sum(root->right);
}

int count(node *root){
	if(root==NULL){
		return 0;
	}
	return 1+count(root->left)+count(root->right);
}

int main(){
	root=buildTree();
    print(root);
    cout<<"number of nodes are->"<<count(root)<<endl;
    cout<<"sum of tree is ->"<<sum(root)<<endl;

}