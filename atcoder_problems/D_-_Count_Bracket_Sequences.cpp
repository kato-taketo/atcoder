// 22:43~22:58 15:05~

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define mod 998244353
string S;
ll len,cnt;
vector<vector<ll> > dp;
int main(void) {
  cin >> S;
  len = S.length();
  dp.resize(len+1);
  rep(i,len+1) dp[i].resize(len+1,0);
  dp[0][0]=1;
  rep(i,len) {
    rep(j,len) {
      if(S[i]!=')') dp[i+1][j+1] += dp[i][j], dp[i+1][j+1]%=mod;
      if(j!=0&&S[i]!='(') dp[i+1][j-1] += dp[i][j], dp[i+1][j-1]%=mod;
    } 
  }
  cout << dp[len][0] << endl;
}