
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL){
		return;
	}
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=new Node(a2);
			break;
			case 'R':root->right=new Node(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
void inorder(Node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int maxNodeLevel(Node *root1);
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t-->0)
	{
		int n;
		cin>>n;
		int m=n;
		Node *root1=NULL;
		while(n-->0){
			int a1,a2;
			cin>>a1>>a2;
			char lr;
			scanf(" %c",&lr);
			if(root1==NULL){
				root1=new Node(a1);
				switch(lr){
					case 'L':root1->left=new Node(a2);
					break;
					case 'R':root1->right=new Node(a2);
					break;
				}
			}
			else{
				insert(root1,a1,a2,lr);
			}
		}
			cout<<maxNodeLevel(root1)<<"
";
	}
}
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/

//my code for finding level for maximum number of node
int maxNodeLevel(Node *root)
{ queue<struct Node*> q;
  int max=0;
 q.push(root);
 q.push(NULL);
 int i=0;
 
 while(!q.empty()){
     struct Node *f=q.front();
     if(f==NULL){
         if(max<q.size()-1){
             max=q.size()-1;
             i++;
         }

    
       
       q.pop();
        if(!q.empty()){
             q.push(NULL);
         }
     }
     else{
         q.pop();
         if(f->left){
            q.push(f->left);
         } 
           if(f->right){
             q.push(f->right);
           }
     }
    
 }
 

 return i;
 
}