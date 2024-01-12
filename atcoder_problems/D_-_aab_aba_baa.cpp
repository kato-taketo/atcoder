#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

ll A,B,K;
vector<vector<ll> > dp;
string find_kth(ll A, ll B, ll K) {
  if(A==0) return string(B,'b');
  if(B==0) return string(A,'a');
  if(K<=dp[A-1][B]) return string("a")+find_kth(A-1,B,K);
  if(K>dp[A-1][B]) return string("b")+find_kth(A,B-1,K-dp[A-1][B]);
}
int main(void) {
  cin >> A >> B >> K;
  dp.resize(A+1);
  rep(i,A+1) dp[i].resize(B+1);
  dp[0][0]=1;
  for(int i=0; i<=A; i++) {
    for(int j=0; j<=B; j++) {
      if(i>0) dp[i][j] += dp[i-1][j];
      if(j>0) dp[i][j] += dp[i][j-1];
    }
  }

  cout << find_kth(A,B,K) << endl;
  cout << dp[30][30] << endl;
}