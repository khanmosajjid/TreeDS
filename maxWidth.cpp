
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
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
     cout << getMaxWidth(root) << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*  Structure of a Binary Tree 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
/* Function to get the maximum width of a binary tree*/


//my function which return the maximum number of nodes
int getMaxWidth(Node* root)
{
   queue<struct Node*> q;
   int max=0;
   q.push(root);
   q.push(NULL);
   
   while(!q.empty()){
       struct Node *f=q.front();
       if(f==NULL){
           if(max<q.size()-1){
               max=q.size()-1;
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
   return max;
}