#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define nn '\n'

bool subset_sum(int n, vector<int>&v, int sum)
{
    int dp[n+1][sum+1];

    /// base condition
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(i==0) dp[i][j]=0;

            if(j==0) dp[i][j]=1;
        }
    }

    /// choices
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<sum+1; j++)
        {
            if(v[i-1]<=j)
            dp[i][j]=dp[i-1][j-v[i-1]] || dp[i-1][j];

            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][sum];
}

void solve()
{
    int n, sum;
    cin >> n >> sum;

    vector<int>v(n);

    for0(i, n) cin >> v[i];

    if(subset_sum(n, v, sum)) cout << "YES" << nn;

    else cout << "NO" << nn;
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
6 9
3 34 4 12 5 2
6 30
3 34 4 5 12 2
*/