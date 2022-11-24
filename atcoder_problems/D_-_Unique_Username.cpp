#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

void func() {
  int res=0;
  for(int stop=8; stop>=1; stop--) {
    int tmp=1;
    for(int i=8; i>=stop; i--) {
      tmp *= i;
    }
    res += tmp;
  }
  cout << res << endl;
  //return res;
}
int main(void) {
  func();
  int N,M;
  cin >> N >> M;
  vector<string> S(N);
  rep(i,N) cin >> S[i];
  vector<string> T(N);
  rep(i,N) cin >> T[i];

  // 文字の並べ方は、
}