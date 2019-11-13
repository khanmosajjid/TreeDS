#include<bits/stdc++.h>
using namespace std;

//building a tree from preorder and inOrder array

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
int i=0;

struct node* createTreeFromTrav(int *inOrder,int *pre,int s,int e){
	
	if(s>e){
		return NULL;
	}
	int index=-1;
	struct node *root=new node();
	root->data=pre[i];

	for(int j=s;s<=e;j++){
		if(inOrder[j]==pre[i]){
			index=j;
			break;
		}
	}
	i++;
	root->left=createTreeFromTrav(inOrder,pre,s,index-1);
	root->right=createTreeFromTrav(inOrder,pre,index+1,e);
	return root;
}

void printTree(struct node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printTree(root->left);
	printTree(root->right);
}


int main(){
	int preOrder[]={1,2,3,4,8,5,6,7};
	int inOrder[]={3,2,8,4,1,6,7,5};
	int n=sizeof(inOrder)/sizeof(int);
	struct node* temp=createTreeFromTrav(inOrder,preOrder,0,n-1);
	printTree(temp);
   return 0;
}