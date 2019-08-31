#include<bits/stdc++.h>
using namespace std;

// struct node{
// 	int data;
// 	struct node *left;
// 	struct node *right;
// };
  
//   struct node *root;

// int main(){
// 	int n,a;
// 	root->data=1;
// 	root->left=root->right=NULL;
// 	struct node *ptr=root;

// 	while(1){
// 		cout<<"press 1 enter the elements in binary search tree"<<endl;
// 		cout<<"press 2 to print the elements in binary search tree"<<endl;
// 		cout<<"press 3 to exit"<<endl;
// 		cin>>n;
// 		if(n==1){
// 			cin>>a;
			
// 			if(root==NULL){
// 				root=new node();
// 				root->data=a;
// 				root->left=root->right=NULL;
// 			}
// 			else if(a>root->data){
//                 struct node *R=new node();
//                 R->data=a;
//                 root->right=R;
//                 root=R;
// 			}
// 			else{
// 				struct node *L=new node();
// 				L->data=a;
// 				root->left=L;
// 				root=L;
// 			}
// 		}

// 		if(n==2){
// 			while(ptr!=NULL){
// 				if(root==NULL){
// 					return 0;
// 				}

// 				cout<<ptr->data<<"->";
// 				ptr=ptr->left;

// 			}
// 		}
// 		if(n==3){
// 			break;
// 		}

// 	}
// 	return 0;
// }