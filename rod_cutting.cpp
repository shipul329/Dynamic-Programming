#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define nn '\n'

// recursive approach 
int rod_cutting(int n, vector<int>&wt, vector<int>&val, int w)
{
    // base condition 
    if(n==0 || w==0)
    {
        return 0;
    }

    // choices 
    if(wt[n-1]<=w)
    {
        return max(rod_cutting(n-1, wt, val, w), val[n-1]+rod_cutting(n, wt, val, w-wt[n-1]));
    }
    
    else return rod_cutting(n-1, wt, val, w);
}

// top-down approach 
int rod_cutting2(int n, vector<int>&wt, vector<int>&val, int w)
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
    int n;
    cin >> n;
    
    vector<int>val(n), rod(n);
    
    for0(i, n)
    cin >> val[i];
    
    for0(i, n)
    rod[i]=i+1;
    
    int ans=rod_cutting(n, rod, val, n); // recursive approach 
    int ans2=rod_cutting2(n, rod, val, n); // top-down approach 
    
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
8
1 5 8 9 10 17 17 20
8
3 5 8 9 10 17 17 20 

output 
22 
24 
*/