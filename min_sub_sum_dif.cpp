#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define nn '\n'

// recursive approach 
int min_dif(int n, vector<int>&v, int s1, int sum)
{
    // base condition 
    if(n<=0)
    return abs(sum-2*s1); // abs(s1-s2) or sum-(2*s1) same thing 
    
    
    // for every item of v[i] we have two choices 
    // i) we include it in first set 
    // ii) we do not include it in first set 
    
                          // s1                          // s2 
    return min(min_dif(n-1, v, s1+v[n-1], sum), min_dif(n-1, v, s1, sum));
}

// top-down approach 
int min_dif2(int n, vector<int>&v, int sum)
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
            if(v[i-1]<=j) // include or exclude 
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-v[i-1]];
            }
            
            else dp[i][j]=dp[i-1][j]; // no choice 
        }
    }
    
    int ans;
    
    for(int i=sum/2; i>=0; i--)
    {
        if(dp[n][i]==1)
        {
            ans=sum-2*i;
            break;
        }
    }
    
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int>v(n);
    
    for0(i, n)
    cin >> v[i];
    
    int sum=accumulate(all(v), 0);
    
    int ans=min_dif2(n, v, sum);
    
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
6
3 1 4 2 2 1
5
10 20 15 5 25 

output 
1 
5
*/