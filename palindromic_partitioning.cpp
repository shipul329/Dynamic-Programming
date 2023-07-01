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

bool isPal(string s, int i, int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;
        
        i++, j--;
    }
    
    return true;
}

// recursive approach 
int pal_p(string s, int i, int j)
{
    // 2nd step -> base condition  
    if(i>j) return 0;
    
    if(isPal(s, i, j)) return 0;
    
    // 3rd step -> loop for K 
    int ans=INT_MAX;
    
    for(int k=i; k<j; k++) // 3rd step 
    {
        int tmp=pal_p(s, i, k) + pal_p(s, k+1, j) + 1;
        
        ans=min(ans, tmp); // 4th step 
    }
    
    return ans;
}

// memoization approach 

int dp[105][105];

int pal_p2(string s, int i, int j)
{
    // step 2 -> base condition 
    
    if(i>=j) return 0;
    
    if(isPal(s, i, j)) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    // step 3 
    
    int ans=INT_MAX;
    
    for(int k=i; k<j; k++)
    {
        int left, right;
        
        if(dp[i][k]!=-1)
        left=dp[i][k];
        
        else{
            left=pal_p2(s, i, k);
            dp[i][k]=left;
        }
        
        if(dp[k+1][j]!=-1)
        right=dp[k+1][j];
        
        else{
            right=pal_p2(s, k+1, j);
            
            dp[k+1][j]=right;
        }
        
        int tmp=left+right+1;
        
        ans=min(ans, tmp);
    }
    
    dp[i][j]=ans;
    
    return dp[i][j];
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    
    string s;
    cin >> s;
    
    // step 1 
    
    int i=0, j=s.size();
    
    int ans=pal_p(s, i, j-1); // i=0 ans j=size()-1 valid.. cuz s[0] and s[size()-1] have at least one item
    int ans2=pal_p2(s, i, j-1);
    
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
ababbbabbababa
aaabba

output 
3 
1 
*/