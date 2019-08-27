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

	struct node *root=new node();
	root->data=d;
	root->left=buildTree();
	root->right=buildTree();
	return root;
}
//postOrder printing of tree
void printPostorder(node *root){
	if(root==NULL){
		return;
	}
	//postoreder traversal of tree
	printPostorder(root->left);

	printPostorder(root->right);
   cout<<root->data<<" ";
}
void printInorder(node *root){
	if(root==NULL){
		return;
	}
	//postoreder traversal of tree
	printInorder(root->left);
     cout<<root->data<<" ";
	printInorder(root->right);
   
}

int main(){
	root=buildTree();
	cout<<" post order traversal is"<<endl;
	printPostorder(root);
	cout<<" in oredr traversal is"<<ednl;
	printInorder(root);
}