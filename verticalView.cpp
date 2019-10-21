#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

struct node* buildTree(){
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

void print(struct node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	print(root->left);
	
	print(root->right);
}

void getVerticalOrder(node *root,int hd,map<int,vector<int>>&m){
	if(root==NULL){
		return;
	}
	m[hd].push_back(root->data);
	getVerticalOrder(root->left,hd-1,m);
	getVerticalOrder(root->right,hd+1,m);
}

//print vertical order using map

void printVerticalOreder(struct node *root){
	map<int,vector<int>>m;
	int hd=0;
	getVerticalOrder(root,hd,m);

	map<int,vector<int>> :: iterator it;

	for(it=m.begin();it!=m.end();it++){
		for(int i=0;i<it->second.size();++i){
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	root=buildTree();
	// print(root);
	printVerticalOreder(root);
     
}

