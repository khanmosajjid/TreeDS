
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
  	while(!q.empty()){
  		struct node *temp=q.front();
  		cout<<temp->data<<" ";
  		q.pop();

  		if(temp->left!=NULL)
  			q.push(temp->left);
  		if(temp->right!=NULL)
  			q.push(temp->right);
  		
  	}
  }

  // height of a tree

  int treeHeight( node *root){
  	if(root==NULL){
  		return 0;
     }

     int ls=treeHeight(root->left);
     int rs=treeHeight(root->right);
     
     return max(ls,rs)+1;
  }

  


  //print level through recursive call
  void Klevel(node *root,int k){
  	if(root==NULL){
  		return;
  	}
  	if(k==1){
  		cout<<root->data<<" ";
  		return;
  	}
  	Klevel(root->left,k-1);
  	Klevel(root->right,k-1);
  }

     //printing  all level

    void allLevelPrint(node *root){
  	int h=treeHeight(root);
  	for(int i=1;i<=h;i++){
  		Klevel(root,i);
  		cout<<""<<endl;
  	}
  }

int main(){
	root=buildTree();
	// cout<<" post order traversal is"<<endl;
	// printPostorder(root);
	// cout<<" in oredr traversal is"<<endl;
	// printInorder(root);
	// cout<<" print levelOrder is"<<endl;
	// levelOrder(root);
	cout<<" height of tree is"<<endl;
	treeHeight(root);
	allLevelPrint(root);
	
	
	
}