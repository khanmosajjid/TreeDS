#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
Node* insert(Node* node, int data) 
{
    
    if(node == NULL) return(new Node(data)); 
    else
    {
        if (data <= node->data)node->left = insert(node->left, data);
        else node->right = insert(node->right, data);
        return node; 
    }
}
int minValue(Node* root);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, tmp;
        cin>>n>>tmp;
        Node* root = NULL;
        root = insert(root, tmp);
        n--;
        while(n--){
            cin>>tmp;
            insert(root, tmp);
        }
        cout<<minValue(root)<<endl;
    }
    return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of the binary search tree is as
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
// your task is to complete the below function

int minValue(Node* root)
{
   queue<struct Node*>q;
   q.push(root);
   int k=INT_MAX;
   while(!q.empty()){
       struct Node *f=q.front();
       if(f->data<k){
           k=f->data;
       }
       q.pop();
       if(f->left){
           q.push(f->left);
       }
       if(f->right){
           q.push(f->right);
       }
   }
   return k;
}

