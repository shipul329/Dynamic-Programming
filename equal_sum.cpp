#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define nn '\n'

// recursive approach 
bool equal_sum(int n, vector<int>&v, int sum)
{
    if(sum==0) return true;
    
    if(n==0) return false;
    
    if(v[n-1]<=sum)
    {
        return equal_sum(n-1, v, sum-v[n-1]) || equal_sum(n-1, v, sum);
    }
    
    else return equal_sum(n-1, v, sum);
}

// top down approach 
bool equal_sum2(int n, vector<int>&v, int sum)
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
    int n;
    cin >> n;

    vector<int>v(n);

    for0(i, n) cin >> v[i];
    
    int sum=accumulate(all(v), 0);
    
    if(sum&1)
    {
        cout << "NO" << nn;
        return;
    }

    if(equal_sum(n, v, sum/2)) cout << "YES" << nn;

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
4
1 5 11 5
3
1 3 5

output 
YES
NO 
*/