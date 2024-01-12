// 17:12~

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

ll N, res;
vector<ll> A;
int main(void) {
  cin >> N;
  A.resize(N);
  rep(i,N) cin >> A[i];

  res = 0;
  for(int i=N-1; i>=0; i--) {
    if(i!=N-1&&A[i]+1==A[i+1]) continue;
    else if(i!=0&&A[i]<=i&&A[i-1]>=A[i]-1) res += A[i];
    else if(i==0&&A[0]==0) continue;
    else {
      cout << -1 << endl; return 0;
    }
  }
  cout << res << endl;
}