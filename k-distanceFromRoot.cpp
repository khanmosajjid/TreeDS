
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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
void printKdistance(struct Node *root, int k);
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
     int n,k;
     scanf("%d%d",&n,&k);
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
     printKdistance(root,k);
     cout << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
// function should print the nodes at k distance from root
void printKdistance(Node *root, int k)
{
  queue<Node*>q;
  int i=1;
  q.push(root);
  q.push(NULL);
  if(k==0){
      cout<<root->data;
      return;
  }
  
  while(!q.empty()){
      struct Node *f=q.front();
      
      if(f==NULL){
          if(i==k){
            //   cout<<"i is "<<i<<" and k is "<<k;
            //   cout<<"top of queue is "<<q.front()<<endl;
              q.pop();
            //   cout<<" size of queue after poping element"<<q.size()<<endl;
              while(!q.empty()){
                  f=q.front();
                //   cout<<"after getting i =k  element is"<<q.front()<<endl;
                  
                  cout<<f->data<<" ";
                  q.pop();
                //   cout<<" after poping element"<<endl;
              }
              return ;
          }
          q.pop();
          if(!q.empty()){
              q.push(NULL);
          }
          i++;
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
}