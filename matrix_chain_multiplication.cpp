// to solve mcm pattern problems follow these 4 steps 
// i) find value of i & j 
// ii) base condition 
// iii) find loop for K 
// iv) function for temporary ans(min, max) 

#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

// recursive approach 
int mcm(vector<int>&v, int i, int j)
{
    // base condition  
    if(i>=j)   // 2nd step 
    return 0;
    
    // loop for K 
    int ans=INT_MAX;
    
    for(int k=i; k<j; k++) // 3rd step 
    {
        int tmp=mcm(v, i, k) + mcm(v, k+1, j) + (v[i-1]*v[k]*v[j]);
        
        ans=min(ans, tmp); // 4th step 
    }
    
    return ans;
}

// memoization approach 
int dp[105][105];
int mcm2(vector<int>&v, int i, int j)
{
    // base condition 
    
    if(i>=j) // step 2 
    return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans=INT_MAX;
    
    // step 3 
    for(int k=i; k<j; k++)
    {
        int tmp=mcm(v, i, k) + mcm(v, k+1, j) + (v[i-1]*v[k]*v[j]);
        
        ans=min(ans, tmp);
    }
    
    dp[i][j]=ans;
    
    return dp[i][j];
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    
    int n;
    cin >> n; 
    
    vector<int>v(n);
    
    for0(i, n)
    cin >> v[i];
    
    // i=1 and j=n-1 ...... 1st step 
    int ans=mcm(v, 1, n-1); // 1 instead of 0 because arr[0-1] not valid but v[1-1] is valid
    
    int ans2=mcm2(v, 1, n-1);
    
    cout << ans << " " << ans2 << nn;
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
2
5 
40 20 30 10 30 
4
10 30 5 60 

output 
26000
4500 
*/