#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
using P = pair<ll,ll>;

vector<P > prime_factorize(long long N) {
    vector<P > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back(P(a, ex));
    }

    // 最後に残った数について
    if (N != 1) res.push_back(P(N, 1));
    return res;
}
int main(void) {
  ll k;
  cin >> k;

  const auto &res = prime_factorize(k);
    //cout << k << ":";
    //for (auto p : res) {
    //    for (int i = 0; i < p.second; ++i) cout << " " << p.first;
    //}
    //cout << endl;

  ll ans=-1;
  for(auto p : res) {
    ll key=p.first;
    int cnt=0;
    for(ll i=0; i<p.second; i++) {
      cnt++;
      int value=i+1;
      while(value>0) {
        if(value%key==0) cnt++, value/=key;
        if(value%key!=0) break;
      }
      ans = max(ans, key*(i+1));
      if(cnt>=p.second) break;
    }
  }

  cout << ans << endl;
  
}