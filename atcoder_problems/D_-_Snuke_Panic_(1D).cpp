// wa だめだ。。。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define inf -2e9

vector<vector<ll> > dp(1e5+1,vector<ll>(5,inf));
ll check(int i, int j, int x, ll a) {
  if(j<0 || j>=5) return inf;
  if(dp[i][j]==inf) return inf;
  if(x==-1||x!=j) return dp[i][j];
  if(x==j) return max(a,dp[i][j] + a);
}

int main(void) {
  int N;
  cin >> N;
  vector<ll> T(N),X(N),A(N);
  rep(i,N) cin >> T[i] >> X[i] >> A[i];

  //vector<vector<ll> > dp(1e5+1,vector<ll>(5,-1));
  int move[3]={-1,0,1};
  dp[0][0]=0;
  int index=0;
  for(int i=1; i<=T[N-1]; i++) {
    int x=-1,a=-1;
    if(T[index]==i) x=X[index], a=A[index], index++;
    for(int j=0; j<=4; j++) {
     for(int k=0; k<3; k++) {
        dp[i][j] = max(dp[i][j], check(i-1,j-move[k],x,a));
        }
      }
    }
    ll res=-1;
  rep(i,5) {
    res = max(res, dp[T[N-1]][i]);
  }
  cout << res << endl;
}