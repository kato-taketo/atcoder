#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  string s,t;
  cin >> s >> t;

  vector<vector<int> > dp(2001, vector<int>(2001,0));
  for(int i=0; i<=s.length(); i++) {
    for(int j=0; j<=t.length(); j++) {
      if(i>=1&&j>=1&&s[i-1]==t[j-1]) {
        dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+1));
      } else if(i>=1&&j>=1) {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      } else if(i>=1) {
        dp[i][j]=dp[i-1][j];
      } else if(j>=1) {
        dp[i][j]=dp[i][j-1];
      }
    }
  }
  cout << dp[s.length()][t.length()] << endl;
}