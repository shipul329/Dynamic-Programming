// minimum number of coins to make the given sum 

#include<bits/stdc++.h> 

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

int min_coin(int n, vector<int>&v, int sum)
{
    int dp[n+1][sum+1];

    // base condition

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(i==0) dp[i][j]=INT_MAX-1;

            if(j==0) dp[i][j]=0;
        }
    }

    // for second row

    for(int i=1; i<=1; i++)
    {
        for(int j=1; j<sum+1; j++)
        {
            if(j%v[0]==0)
                dp[i][j]=j/v[0];

            else dp[i][j]=INT_MAX-1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(v[i-1]<=j)
                dp[i][j]=min(dp[i-1][j], 1+dp[i][j-v[i-1]]);

            else dp[i][j]=dp[i-1][j];
        }
    }

    if(dp[n][sum]==INT_MAX-1)
        return -1;

    else return dp[n][sum];
}

void solve()
{
    int n, sum;
    cin >> n >> sum;

    vector<int>coins(n);

    for0(i, n)
    cin >> coins[i];

    int ans=min_coin(n, coins, sum);

    cout << ans << nn;
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
3 30
25 10 5
4 11 
9 6 5 1
3 11 
1 2 5
1 3
2

output 
2 
2 
3 
-1 
*/