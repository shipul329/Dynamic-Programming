#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define nn '\n'

// recursive approach 
int knapsack(int n, vector<int>&wt, vector<int>&val, int w)
{
    // base condition 
    if(n==0 || w==0)
    {
        return 0;
    }

    // choices 
    if(wt[n]<=w)
    {
        return max(knapsack(n-1, wt, val, w), val[n]+knapsack(n, wt, val, w-wt[n]));
    }
    
    else return knapsack(n-1, wt, val, w);
}

// top-down approach 
int knapsack2(int n, vector<int>&wt, vector<int>&val, int w)
{
    int dp[n+1][w+1];
    
    // base condition 
    
    for0(i, n+1)
    {
        for0(j, w+1)
        {
            if(i==0 || j==0) dp[i][j]=0;
        }
    }
    
    // choices 
    for1(i, n)
    {
        for1(j, w)
        {
            if(wt[i-1]<=j) // either include or exclude 
            {
                dp[i][j]=max(dp[i-1][j], val[i-1]+dp[i][j-wt[i-1]]);
            }
            
            else dp[i][j]=dp[i-1][j]; // no choice 
        }
    }
    
    return dp[n][w];
}

void solve()
{
    int n, w;
    cin >> n >> w;
    
    vector<int>wt(n), val(n);
    
    for0(i, n) 
    cin >> wt[i];
    
    for0(i, n)
    cin >> val[i];
    
    int ans=knapsack(n-1, wt, val, w); // recursive approach 
    int ans2=knapsack2(n, wt, val, w); // top-down approach 
    
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
3
4 10
1 3 4 5
1 4 5 7
3 4
4 5 1
1 2 3
3 3
4 5 6
1 2 3 

output 
14 
12 
0 
*/