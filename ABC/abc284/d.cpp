#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back(make_pair(a, ex));
    }

    // 最後に残った数について
    if (N != 1) res.push_back(make_pair(N, 1));
    return res;
}
ll my_pow(ll x, ll y) {
  ll res=1;
  rep(i,y) res *= x;
  return res;
}
int main(void) {
  int t;
  cin >> t;

  vector<bool> primes(1e7,true);
  primes[0]=false, primes[1]=false;
  for(ll i=2; i<1e7; i++) {
    if(primes[i]==false) continue;
    for(ll j=i*2; j<1e7; j+=i) primes[j]=false;
  }
  vector<ll> vecs;
  rep(i,1e7) if(primes[i])vecs.push_back(i);

  vector<pair<ll,ll> > ans;
  rep(i,t) {
    ll n;
    cin >> n;
    ll p=1,q=1;
    rep(j,vecs.size()) {
      if(n%vecs[j]==0) {
        if(n%(vecs[j]*vecs[j])==0) p*=vecs[j], n/=(vecs[j]*vecs[j]);
        else q*=vecs[j],n/=vecs[j];
      }
    }
    //printf("n = %lld\n", n);
    const auto &res=prime_factorize(n);
    for (auto x: res) {
      if(x.second%2!=0) q *= my_pow(x.first,x.second);
      else p *= my_pow(x.first, x.second/2);
    }
    ans.push_back(make_pair(p,q));
  }

  rep(i,ans.size()) printf("%lld %lld\n", ans[i].first, ans[i].second);
}