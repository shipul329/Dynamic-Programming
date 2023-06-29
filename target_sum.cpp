// this problem is almost similar with count minimum subset sum difference 
#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define nn '\n'

// recursive approach 
int target_sum(int n, vector<int>&v, int sum)
{
    // base condition 
    if(n==0)
    {
        if(sum==0) return 1;
        
        return 0;
    }

    int fs=target_sum(n-1, v, sum-v[n-1]);
    int sn=target_sum(n-1, v, sum+v[n-1]);
    
    return fs+sn;
}

// top-down approach 
int target_sum2(int n, vector<int>&v, int sum)
{
    int dp[n+1][sum+1];
    
    // base condition 
    
    for0(i, n+1)
    {
        for0(j, sum+1)
        {
            if(i==0) dp[i][j]=0;
            
            if(j==0) dp[i][j]=1;
        }
    }
    
    // choices 
    for1(i, n)
    {
        for0(j, sum+1) // be careful. use j=0 instead of 1 
        {
            if(v[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j] + dp[i-1][j-v[i-1]];
            }
            
            else dp[i][j]=dp[i-1][j]; // no choice 
        }
    }
    
    return dp[n][sum];
}

void solve()
{
    int n, target;
    cin >> n >> target;
    
    vector<int>v(n);
    
    for0(i, n)
    cin >> v[i];
    
    // for recursive approach 
    int ans=target_sum(n, v, target);
    
    // for top-down approach 
    
    int sum=accumulate(all(v), 0);
    
    int ans2;
    
    if((sum+target)&1 || sum<target)
    {
        ans2=0;
    }
    
    else{
        ans2=target_sum2(n, v, (sum+target)/2);
    }
    
    cout << ans << " " << ans2 << nn;
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
5 9
1 2 3 4 5 
5 3 
1 1 1 1 1
1 1
1
4 3
1 2 3 1 

output 
2 
5
1 
2 
*/