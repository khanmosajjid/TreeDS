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
		return root;
	}
	
	struct node *root=new node();
	root->data=d;
	root->left=buildTree();
	root->right=buildTree();
	return root;

}

void printTree(struct node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data;
	printTree(root->left);
	printTree(root->right);

}

int height(struct node *root){
	if(root==NULL){
		return 0;
	}
	int ls=height(root->left);
	int rs=height(root->right);
	return max(ls,rs)+1;
}

class HBpair{
public:
	int height;
	bool balance;
};

HBpair heightBalanced(struct node *root){
	HBpair p;
	if(root==NULL){
      p.height=0;
      p.balance=true;
      return p;
	}
	//recursive case for height balanced
	HBpair left=heightBalanced(root->left);
	HBpair right=heightBalanced(root->right);

     p.height=max(left.height,right.height)+1;

	if(abs(left.height-right.height)<=1 && left.balance && right.balance){
		p.balance=true;
	}
	else{
		p.balance=false;
	}
	return p;

}


int main(){
	struct node *temp=buildTree();
	printTree(temp);
	int h=height(temp);
	cout<<" height of tree is "<<h<<endl;

	if(heightBalanced(temp).balance){
		cout<<"balanced tree "<<endl;
	}
	else {
		cout<<" not balance tree "<<endl;
	}


}