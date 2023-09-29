#include<bits/stdc++.h>

using namespace std;

#define for0 for(int i=0; i<n; i++)
#define for1 for(int i=1; i<=n; i++) 
#define all(v) v.begin(), v.end()
#define pb push_back 
#define nn '\n'

int lcs(string s, string s2, int n, int m, int cnt)
{
    // base condition 
    if(n==0 || m==0)
    return cnt; 
    
    // choices 
    if(s[n-1]==s2[m-1])
    cnt=lcs(s, s2, n-1, m-1, cnt+1);
    
    cnt=max(cnt, max(lcs(s, s2, n, m-1, 0), lcs(s, s2, n-1, m, 0)));
    
    return cnt;
}

void lcs2(string s, string s2, int n, int m)
{
   // top-down approach 
   int dp[n+1][m+1];

   // base condition 
   for(int i=0; i<n+1; i++)
   {
       for(int j=0; j<m+1; j++)
       {
           if(i==0 || j==0)
           dp[i][j]=0;
       }
   }

   // chioces 

  int mx=INT_MIN;
  
  int row, col;

   for(int i=1; i<n+1; i++)
   {
      for(int j=1; j<m+1; j++)
      {
          if(s[i-1]==s2[j-1])
          {
              dp[i][j]=1+dp[i-1][j-1];
              
              if(mx<dp[i][j])
              {
                  mx=dp[i][j];
                  row=i;
                  col=j;
              }
          }

          else dp[i][j]=0;
      }
    
    }
   
    string ans="";

   while(dp[row][col]!=0)
   {
      ans+=s[row-1];
      row--;
      col--;
   }
   
   reverse(all(ans));
   
   cout << "size is " << mx << nn;

   cout << ans << nn;
}

void solve()
{
    string s, s2;
    cin >> s >> s2; 

    int n=s.size(), m=s2.size();

    int ans=lcs(s, s2, n, m, 0);
    
    cout << ans << nn;
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
abcjklp acjkp 
wasdijkl wsdjkl
tyfg cvbnuty

output 
3
3
2  
*/