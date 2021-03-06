#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};



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

node* deletionBst(node *root,int data){
	if(root==NULL){
		return NULL;
	}
	else if(data<root->data){
		root->left=deletionBst(root->left,data);
		return root;
	}
	else if(data==root->data){
      //1 case. if data root is leaf root

		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}

		//case 2. if there is only 1 child

		if(root->left==NULL && root->right!=NULL){
			node *temp=root->right;
			delete root;
			return temp;
		}
		if(root->left!=NULL && root->right==NULL){
			node *temp=root->left;
			delete  root;
			return temp;
		}

		//case 3. if there is both the child...we replace root with inorder successor
		if(root->left!=NULL && root->right!=NULL){
			node *replace=root->right;

			while(replace->left!=NULL){
				replace=replace->left;
			}
			
			root->data=replace->data;
			root->right=deletionBst(root->right,replace->data);
			return root;
		}
	}
	else{
	    root->right=deletionBst(root->right,data);
		return root;	
	}
}

//to check whether the tree is binary search tree or not



bool _isBST(Node* root,int minV=INT_MIN,int maxV=INT_MAX){
    if(root==NULL){
        return true;
    }
    
    if(root->data >= minV && root->data <= maxV &&_isBST(root->left,minV,root->data)&&_isBST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}

int main(){
	node* root=build();
	inorder(root);
	cout<<endl;

	
	if(_isBST(root,INT_MIN,INT_MAX)){
		cout<<"BINARY SEARCH TREE"<<endl;
	}
	else{
		cout<<"not a binary search tree"<<endl;
	}
	return 0;
}