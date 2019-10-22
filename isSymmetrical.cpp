#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
bool isSymmetric(struct Node* root);
void inorder(struct Node *root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->key<<' ';
    inorder(root->right);
}
int main()
{
  int t;
  struct Node *child;
  cin>>t;
  while (t--)
  {
     int N1, N2;
     cin>>N1>>N2;
     struct Node *root1 = NULL;
     struct Node *root2 = NULL;
     struct Node *root = NULL;
     map<int, Node*> m;
     while (N1--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        cin>>n1>>n2>>lr;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root1 == NULL)
             root1 = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     m.clear();
     while (N2--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        cin>>n1>>n2>>lr;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root2 == NULL)
             root2 = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int N;
     cin>>N;
     root = new Node(N);
     root->left=root1;
     root->right=root2;
     //inorder(root);
     if(isSymmetric(root))cout<<"True"<<endl;
     else cout<<"False"<<endl;
  }
  return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of the tree is as
struct Node
{
	int key;
	struct Node* left, *right;
};
*/
// complete this function
// return true/false if the is Symmetric or not

vector<int>a,b;
void lt(struct Node *root){
    if(root==NULL){
        return;
    }
    a.push_back(root->key);
   
    lt(root->left);
    lt(root->right);

}

void rt(struct Node *root){
    if(root==NULL){
        return ;
    }
    b.push_back(root->key);
   
    rt(root->right);
    rt(root->left);
}

bool isSymmetric(struct Node* root)
{  lt(root);
   rt(root);
   
   for(int i=0;i<a.size();i++){
       if(a[i]!=b[i]){
           a.clear();
           b.clear();
           return false;
       }
       
     
   }
    a.clear();
    b.clear();
   return true;
   
}