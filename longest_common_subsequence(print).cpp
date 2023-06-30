#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

// top-down approach 
void print_lcs(string s, string s2, int n, int m)
{
    int dp[n+1][m+1];

    // base condition 
    for0(i, n)
    {
        for0(j, m)
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

    int ind=dp[n][m];

    char ch[ind]; 

    int i=n, j=m;

    while(i>0 && j>0)
    {
        if(s[i-1]==s2[j-1])
        {
            ch[ind-1]=s[i-1];

            i--, j--;
            ind--;
        }

        else{
            if(dp[i-1][j] > dp[i][j-1])
            {
                i--;
            }

            else j--;
        }
    }

    for(auto it:ch)
    cout << it;

    cout << nn;
}

void solve()
{
    string s, s2;
    cin >> s >> s2;

    int n=s.size(), m=s2.size();

    print_lcs(s, s2, n, m);
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
AGGTAB GXTXAYB
ABCDGH AEDFHR

output 
GTAB
ADH
*/