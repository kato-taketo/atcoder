// 理解度50%

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  string N;
  cin >> N;
  ll ans=0;
  for(int s=1; s<=9*14; s++) {
    //vector<vector<vector<vector<int> > > > dp;
    //dp.resize(N.size()+1);
    //rep(i,N.size()+1) dp[i].resize(s+1);
    //rep(i,N.size()+1) rep(j,s+1) dp[i][j].resize(s);
    //rep(i,N.size()+1) rep(j,s+1) rep(k,s) dp[i][j][k].resize(2, 0LL);
    vector dp(N.size()+1, vector(s+1,vector(s,vector(2,0LL))));
    dp[0][0][0][1] = 1;
    rep(d,N.size()) rep(i,s+1) rep(j,s) rep(f,2) rep(t,10) {
      if(i+t>s) continue;
      if(f and N[d]-'0' < t) continue;
      dp[d+1][i+t][(j*10+t)%s][f and N[d]-'0'==t] += dp[d][i][j][f];
    }
    ans += dp[N.size()][s][0][0] + dp[N.size()][s][0][1];
  }
  cout << ans << endl;
}