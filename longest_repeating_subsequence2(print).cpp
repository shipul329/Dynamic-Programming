#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

// recursive approach 
int lcs(string s, int n, int m)
{
    // base condition 
    if(n==0 || m==0)
    return 0;
    
    // choices 
    if(s[n-1]==s[m-1] && n!=m)
    {
        return 1+lcs(s, n-1, m-1);
    }
    
    else
    return max(lcs(s, n-1, m), lcs(s, n, m-1));
}

// top-down approach 
void lcs2(string s, int n, int m)
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
    
    // from choice diagram 
    for1(i, n)
    {
        for1(j, m)
        {
            if(s[i-1]==s[j-1] && i!=j)
            {
                dp[i][j]=1+dp[i-1][j-1];
            }

            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int ind=dp[n][m];
    
    if(ind==0)
    {
        return;
    }
    
    char ch[ind];
    
    int i=n, j=m;
    
    while(i>0 & j>0)
    {
        if(s[i-1]==s[j-1] && i!=j)
        {
            ch[ind-1]=s[i-1];
            i--, j--, ind--;
        }
        
        else{
            if(dp[i-1][j]>dp[i][j-1])
            i--;
            
            else j--;
        }
    }
    
    for(auto it:ch)
    cout << it;
    
    cout << nn;
}

void solve()
{
    string s;
    cin >> s;

    int n=s.size();

    int ans=lcs(s, n, n);
    cout << ans << nn;
    
    lcs2(s, n, n);
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
abac 
aaaaaaaa 
AGGTAB 
ABCDGH
AABEBCDD

output 
1
a
7
aaaaaaa
1
A
0
3
ABD 
*/