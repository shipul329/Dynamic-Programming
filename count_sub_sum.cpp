#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define nn '\n'

// recursive approach 
int count_sub_sum(int n, vector<int>&v, int sum)
{
    // base condition 
    
    if(n==0 && sum==0) return 1;
    
    if(n==0) return 0;
    
    // choices 
    if(v[n-1]<=sum && v[n-1]!=-1) // 2 choices include or exclude 
    return count_sub_sum(n-1, v, sum-v[n-1]) + count_sub_sum(n-1, v, sum);
    
    else return count_sub_sum(n-1, v, sum); // no choice 
}

// top-down approach 
int count_sub_sum2(int n, vector<int>&v, int sum)
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
        for0(j, sum+1)
        {
            if(v[i-1]<=j && v[i-1]!=-1) // include or exclude 
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
    int n, sum;
    cin >> n >> sum;
    
    vector<int>v(n);
    
    for0(i, n)
    cin >> v[i];
    
    int ans=count_sub_sum2(n, v, sum);
    
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
4
5 12
5 6 7 8 9
4 10 
9 5 7 3 
6 23 
9 5 7 2 5 1
10 31 
9 7 0 3 9 8 6 5 7 6

output 
1 
1 
2 
40
*/