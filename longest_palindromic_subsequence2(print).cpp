#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

// recursive approach 
int lcs(string s, string s2, int n, int m)
{
    // base condition 
    if(n==0 || m==0)
    return 0;
    
    // choices 
    if(s[n-1]==s2[m-1])
    {
        return 1+lcs(s, s2, n-1, m-1);
    }
    
    else
    return max(lcs(s, s2, n-1, m), lcs(s, s2, n, m-1));
}

// top-down approach 
void lcs2(string s, string s2, int n, int m)
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
            if(s[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }

            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int i=n, j=m;
    
    int ind=dp[n][m];
    
    char ch[ind];
    
    while(i>0 && j>0)
    {
        if(s[i-1]==s2[j-1])
        {
            ch[ind-1]=s[i-1];
            i--, j--, ind--;
        }
        
        else{
            if(dp[i-1][j] > dp[i][j-1])
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
    
    string s2=s;
    reverse(all(s2));

    int n=s.size(), m=s2.size();
    
    int ans=lcs(s, s2, n, m);
    cout << ans << nn;

    lcs2(s, s2, n, m);
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
bbbab 
cbbd 
heap
geeksforgeeks

output 
4
bbbb
2
bb
1
p
5
eegee
*/