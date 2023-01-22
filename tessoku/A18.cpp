#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,s;
  cin >> n >> s;
  vector<int> a(n+1);
  rep2(i,1,n+1) cin >> a[i];

  vector<vector<bool> > dp(n+1, vector<bool>(s+1,false));
  dp[0][0]=true;
  rep2(i,1,n+1) {
    rep2(j,0,s+1) {
      if(j==0) dp[i][j]=true;
      if(dp[i-1][j]) dp[i][j]=true;
      if(j-a[i]>=0&&dp[i-1][j-a[i]]) dp[i][j]=true;
    }
  }
  if(dp[n][s]) cout << "Yes" << endl;
  else cout << "No" << endl;
}