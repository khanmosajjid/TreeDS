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
  void levelOrder(struct node *root){
  	queue<struct node*> q;
  	if(root==NULL){
  		return;
  	}
  	q.push(root);
  	q.push(NULL);
  	while(!q.empty()){
  		struct node *temp=q.front();
  		if(temp==NULL){
  			cout<<""<<endl;
        q.pop();
  			if(!q.empty()){
  				q.push(NULL);
  			}
  		}
  		else{
  		cout<<temp->data<<" ";
  		q.pop();

  		if(temp->left!=NULL)
  			q.push(temp->left);
  		if(temp->right!=NULL)
  			q.push(temp->right);
  		temp=q.front();
  	}
  }
}

  // height of a tree

  int treeHeight(struct node *root){
  	if(root==NULL){
  		return 0;
     }

     int ls=treeHeight(root->left);
     int rs=treeHeight(root->right);
     
     return max(ls,rs)+1;
  }

  //replacing node with the sum of its children without changing the leaf node

  int sum(node *root){
    if(root==NULL){
      return 0;
    }
    if(root->left==NULL&&root->right==NULL){
      return root->data;
    }
    //recursive calling

    int temp=root->data;
    root->data=sum(root->left)+sum(root->right);
    return temp+root->data;
  }

int main(){
	root=buildTree();
	// cout<<" post order traversal is"<<endl;
	// printPostorder(root);
	// cout<<" in oredr traversal is"<<endl;
	// printInorder(root);
	// cout<<" print levelOrder is"<<endl;
	levelOrder(root);
  sum(root);
  levelOrder(root);
	// cout<<" height of tree is"<<treeHeight(root)<<endl;
}