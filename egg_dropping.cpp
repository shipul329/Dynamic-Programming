#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back 
#define nn '\n'

// recursive approach 
int eggdrop(int e, int f)
{
    // base condition 
    if(e==0 || e==1)
    return f;
    
    if(f==0 || f==1)
    return 1;
    
    int ans=INT_MAX;
    
    // step 3 
    for(int i=1; i<=f; i++)
    {
        int tmp=1+max(eggdrop(e-1, i-1), eggdrop(e, f-i)); // use max cuz of wrost case
        ans=min(ans, tmp); // from all temp ans select final ans which is minimum 
    }
    
    return ans;
}


// bottom-up approach 

int dp[205][205];

int eggdrop2(int e, int f)
{
    if(e==0 || e==1)
    return f;
        
    if(f==0 || f==1)
    return f;
        
    if(dp[e][f]!=-1)
    return dp[e][f];
        
    int ans=INT_MAX;
        
    for(int k=1; k<=f; k++)
    {
        int tmp=1+max(eggdrop2(e-1, k-1), eggdrop2(e, f-k)); /// from wrost case 
            
        ans=min(ans, tmp); // from all temp ans select final ans which is minimum 
    }
        
    dp[e][f]=ans;
        
    return dp[e][f];
       
    return ans;
}

// binary search approach 
int eggdrop3(int e, int f, vector<vector<int> >&dp2)
{
    if(e==0 || e==1)
    return f;
    
    if(f==0 || f==1)
    return f;
    
    if(dp[e][f]!=-1)
    return dp[e][f];
    
    int l=1, r=f, tmp;
    
    int ans=INT_MAX;
    
    while(l<=r)
    {
        int mid=(l+r)/2;
        
        int left=eggdrop3(e-1, mid-1, dp2);
        int right=eggdrop3(e, f-mid, dp2);
        
        tmp=1+max(left, right);
        
        if(left<right)
        l=mid+1;
        
        else r=mid-1;
        
        ans=min(ans, tmp);
    }
    
    dp[e][f]=ans;
    
    return dp[e][f];
}

void solve()
{
    int e, f;
    cin >> e >> f;
    
    memset(dp, -1, sizeof(dp));
    
    int ans=eggdrop(e, f); // recursive 
    int ans2=eggdrop(e, f); // bottom-up 
    
    vector<vector<int> > dp2(e+1, vector<int>(f+1, -1));
    int ans3=eggdrop3(e, f, dp2); // binary search 
    
    cout << ans << " " << ans2 << " " << ans3 << nn;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}

/* 
input 
4
1 2
2 10
2 6
3 14

output 
2 2 2
4 4 4
3 3 3
4 4 4
*/