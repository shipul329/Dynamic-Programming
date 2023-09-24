#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back 
#define nn '\n'

// recursive approach 
int edit_dis(string s, string s2, int n, int m)
{
    // base condition 
    if(n==0) return m;
    
    if(m==0) return n;
    
    if(s[n-1]==s2[m-1]) // last characters are same so ignore them and recur for remaining string  
    return edit_dis(s, s2, n-1, m-1);
    
    else return 1+min({edit_dis(s, s2, n-1, m-1), edit_dis(s, s2, n-1, m), edit_dis(s, s2, n, m-1)});
                       // replace                  // delete                         // insert 
}

int editD(string s, string s2, int n, int m)
{
    int dp[n+1][m+1];
    
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<m+1; j++)
        {
            if(i==0)
            dp[i][j]=j; // if first string is empty then minimum j operations needed 
            
            if(j==0)
            dp[i][j]=i; // if second string is empty then minimum i operations needed 
        }
    }
    
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<m+1; j++)
        {
            if(s[i-1]==s2[j-1])
            dp[i][j]=dp[i-1][j-1]; // last characters are same 
            
            else 
            dp[i][j]=1+min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                           // replace     // insert    // remove 
        }
    }
    
    return dp[n][m];
}

void solve()
{
    string s, s2;
    cin >> s >> s2;
    
    int n=s.size();
    int m=s2.size();
    
    int ans=edit_dis(s, s2, n, m);
    int ans2=editD(s, s2, n, m);
    
    cout << ans2 << nn;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    solve();
    
    return 0;
}

/*
input 
3
sunday saturday 
abc dc 
whgtdwhgtdg aswcfg

output 
3
2
9
*/