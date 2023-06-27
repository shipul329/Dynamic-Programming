#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define nn '\n'

// recursive approach 
int knapsack(int n, vector<int>&wt, vector<int>&val, int W)
{
    // base condition 
    
    if(n==0 || W==0) return 0;
    
    // choice 
    
    if(wt[n-1]<=W)
    return max(knapsack(n-1, wt, val, W), val[n-1]+knapsack(n-1, wt, val, W-wt[n-1]));
    
    else return knapsack(n-1, wt, val, W);
}

// top down approach 
int knapsack2(int n, vector<int>&wt, vector<int>&val, int W)
{
    int dp[n+1][W+1];

    /// base condition, think of the smallest valid input 
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<W+1; j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
        }
    }

    /// choices
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<W+1; j++)
        {
            if(wt[i-1]<=j)
            dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);

            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][W];
}

void solve()
{
    int n, W;
    cin >> n >> W;

    vector<int>wt(n), val(n);

    for0(i, n) cin >> wt[i];

    for0(i, n) cin >> val[i];

    int ans=knapsack(n, wt, val, W); // recursive 
    int ans2=knapsack2(n, wt, val, W); // top down 

    cout << ans << nn;
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
2
3 4
4 5 1
1 2 3
3 3
4 5 6
1 2 3

output
3 
0
*/