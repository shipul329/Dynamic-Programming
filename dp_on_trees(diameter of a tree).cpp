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
    
    int tmp=max(left, right)+1;
    int ans=max(tmp, 1+left+right); // induction 
    mx=max(mx, ans);
    
    return tmp;
}

void diameter (struct node* root)
{
    int mx=INT_MIN;
    
    solve(root, mx);
    
    cout << mx << nn; // 4
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

    struct node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    
    diameter(root);

    return 0;
}
