#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N, H, W;
  cin >> N >> H >> W;
  vector<int> A(N), B(N);
  rep(i,N) cin >> A[i] >> B[i];

  int res=0;
  rep(i,N) res ^= A[i]-1, res ^= B[i]-1;
  if(res==0) cout << "Second" << endl;
  else cout << "First" << endl;
}