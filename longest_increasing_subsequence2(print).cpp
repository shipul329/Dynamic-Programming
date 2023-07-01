#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

// recursive approach 
int lcs(vector<int>&v, vector<int>&v2, int n, int m)
{
    // base condition 
    if(n==0 || m==0) return 0;
    
    // choices 
    if(v[n-1]==v2[m-1])
    return 1+lcs(v, v2, n-1, m-1);
    
    else
    return max(lcs(v, v2, n-1, m), lcs(v, v2, n, m-1));
}

// top-down approach 
void lcs2(vector<int>&v, vector<int>&v2, int n, int m)
{
    int dp[n+1][m+1];
    
    // base condition 
    
    for0(i, n+1)
    {
        for0(j, m+1)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
        }
    }
    
    // choices
    
    for1(i, n)
    {
        for1(j, m)
        {
            if(v[i-1]==v2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int ind=dp[n][m];
    
    vector<int>ans(ind);
    
    int i=n, j=m;
    
    while(i>0 && j>0)
    {
        if(v[i-1]==v2[j-1])
        {
            ans[ind-1]=v[i-1];
            i--, j--, ind--;
        }
        
        else{
            if(dp[i-1][j] > dp[i][j-1])
            i--;
            
            else j--;
        }
    }
    
    for(auto it:ans)
    cout << it << " ";
    
    cout << nn;
}

// binary search approach 
int lis(vector<int>&v, int n)
{
    int tmp=1;
    
    vector<int>v2;
    v2.pb(v[0]);
    
    for(int i=1; i<n; i++)
    {
        if(v[i]>v2.back())
        {
            v2.pb(v[i]);
            tmp++;
        }
        
        else{
            int j=lower_bound(all(v2), v[i])-v2.begin();
            v2[j]=v[i];
        }
    }
    
    return tmp;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int>v(n);
    
    for0(i, n)
    cin >> v[i];
    
    set<int>st(all(v));
    vector<int>v2(all(st));
    
    int m=v2.size();
    
    int ans=lis(v, n);
    cout << ans << nn;
    
    lcs2(v, v2, n, m);
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
5
16 
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6 
5 8 3 7 9 1
8
10 9 2 5 3 7 101 18
6
0 1 0 3 2 3
7
7 7 7 7 7 7 7

output 
6
0 2 6 9 11 15 
3
3 7 9 
4
2 3 7 18 
4
0 1 2 3 
1
7 
*/