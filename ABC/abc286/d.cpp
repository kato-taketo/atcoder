#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,x;
  cin >> n >> x;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  vector<vector<bool> > dp(51, vector<bool>(10005,false));
  rep(i,51) dp[i][0]=true;
  for(int i=0; i<n; i++) {
    // a[i] is using now
    for(int j=0; j<x+1; j++) {
      // dp[i][j] is true or not
      for(int k=0; k<=b[i]; k++) {
        if(i==0) {
          if(a[i]*k>x) continue;
          dp[i][a[i]*k]=true;
        } else {
          if(j-a[i]*k>x || j-a[i]*k<0) continue;
          if(dp[i-1][j-a[i]*k]) dp[i][j]=true;
        }
      }
    }
  }

  rep(i,n) {
    if(dp[i][x]) {
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
}