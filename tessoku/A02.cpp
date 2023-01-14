#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N,X;
  cin >> N >> X;
  vector<int> A(N);
  rep(i,N) cin >> A[i];

  bool key=false;
  rep(i,N) if(A[i]==X) key=true;
  if(key) cout << "Yes" << endl;
  else cout << "No" << endl;
}