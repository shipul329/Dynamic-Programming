#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define nn '\n'

// recursive approach 
int coin_change(int n, vector<int>&coins, int sum)
{
    // base condition 
    if(sum==0) return 1;
    
    if(n==0) return 0;

    // choices 
    if(coins[n-1]<=sum)
    {
        return coin_change(n-1, coins, sum) + coin_change(n, coins, sum-coins[n-1]);
    }
    
    else return coin_change(n-1, coins, sum);
}

// top-down approach 
int coin_change2(int n, vector<int>&coins, int sum)
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
        for1(j, sum)
        {
            if(coins[i-1]<=j) // either include or exclude 
            {
                dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
            }
            
            else dp[i][j]=dp[i-1][j]; // no choice 
        }
    }
    
    return dp[n][sum];
}

void solve()
{
    int n, sum;
    cin >> n >> sum;
    
    vector<int>coins(n);
    
    for0(i, n)
    cin >> coins[i];
    
    int ans=coin_change(n, coins, sum); // recursive approach 
    int ans2=coin_change2(n, coins, sum); // top-down approach 
    
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
2
3 4 
1 2 3
4 10
2 5 3 6

output 
4
5
*/