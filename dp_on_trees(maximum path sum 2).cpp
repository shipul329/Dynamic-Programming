// this one is from leaf node to leaf node 

#include<bits/stdc++.h>
using namespace std;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define nn '\n'

struct node{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data);

struct node* newNode(int data)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    
    return (node);
}

int solve(struct node* root, int &mx)
{
    if(root==NULL) return 0; // base condition 
    
    if(root && root->left==NULL && root->right==NULL)
    return root->data; 
    
    int left=solve(root->left, mx);
    int right=solve(root->right, mx);  // hypothesis 
    
    if(root->left && root->right)
    mx=max(mx, root->data+left+right); // induction 
    
    return root->data + (max(left, right));
}

void findMaxSum(struct node* root)
{
    int mx=INT_MIN;
    
    int tmp=solve(root, mx);
    
    if(root->left || root->right)
    mx=max(tmp, mx);
    
    cout << mx << nn; // 27 
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    struct node* root=newNode(-15);
    root->left=newNode(5);
    root->right=newNode(6);
    root->left->left=newNode(-8);
    root->left->right=newNode(1);
    root->left->left->left=newNode(2);
    root->left->left->right=newNode(-3);
    root->right->left=newNode(3);
    root->right->right=newNode(9);
    root->right->right->right=newNode(0);
    root->right->right->right->left=newNode(4);
    root->right->right->right->right=newNode(-1);
    root->right->right->right->right->left=newNode(10);
    
    findMaxSum(root);

    return 0;
}