// this one is from any node to any node 

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
    
    int left=solve(root->left, mx);
    int right=solve(root->right, mx);  // hypothesis 
    
    int tmp=max(root->data, root->data+max(left, right));
    int ans=max(tmp, root->data+left+right);   
    mx=max(mx, ans); // induction 
    
    return tmp;
}

void findMaxSum(struct node* root)
{
    int mx=INT_MIN;
    
    solve(root, mx);
    
    cout << mx << nn; // 42 
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

    struct node* root=newNode(10);
    root->left=newNode(2);
    root->right=newNode(10);
    root->left->left=newNode(20);
    root->left->right=newNode(1);
    root->right->right=newNode(-25);
    root->right->right->left=newNode(3);
    root->right->right->right=newNode(4);
    
    findMaxSum(root);

    return 0;
}
