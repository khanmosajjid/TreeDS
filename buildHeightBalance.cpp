#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};struct node* root=NULL;


struct node* heightBalancedFromArray(int *a,int start,int end){
	if(start>end){
		return NULL;
	}
	int mid=(start+end)/2;
	struct node* root=new node();
	
	root->data=a[mid];
	root->left=heightBalancedFromArray(a,start,mid-1);
	root->right= heightBalancedFromArray(a,mid+1,end);
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
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	struct node*temp=heightBalancedFromArray(arr,0,n-1);
	printTree(temp);
}