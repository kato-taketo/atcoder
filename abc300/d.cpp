#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  ll n;
  cin >> n;

  vector<bool> prime(1000000, true);
  prime[0]=false, prime[1]=false;
  for(int i=2; i<1000000; i++) {
    if(!prime[i]) continue;
    for(int j=i+i; j<1000000; j+=i) prime[j]=false;
  }
  vector<ll> primes;
  rep(i,1000000) if(prime[i]) primes.push_back(i);
  int primes_len=primes.size();
  //cout << "primes_len" << primes_len << endl;
  //rep(i,10) cout << primes[i] << " ";
  //cout << endl;

  ll cnt=0;
  //rep(a,primes_len) {
  //  ll a2=primes[a]*primes[a];
  //  if(primes[a]>1000) break;
  //  if(a2>n) break;
  //  for(int b=a+1; b<primes_len; b++) {
  //    if(a2*primes[b]>n) {break; }
  //    for(int c=b+1; c<primes_len; c++) {
  //      ll c2=primes[c]*primes[c];
  //      if(a2*primes[b]*c2<=n) {cnt++; } 
  //      else {break; }
  //    }
  //  }
  //}
  ll a,b,c;
  rep(a_index,primes_len) {
    a = primes[a_index];
    if(a>1000 || a>n) break;

    rep2(c_index, a_index+1, primes_len) {
      c = primes[c_index];
      if(a*a*c*c>n) break;
      ll b_max=n/(a*a*c*c);
      if(b_max<a) break;
      b_max = min(b_max, c);
      if(b_max==c) b_max--;
      // aより大きくn_max以下の数をカウント
      ll index=upper_bound(primes.begin(), primes.end(), b_max)-primes.begin();
      ll tmp=index-a_index-1;
      if(tmp>0) cnt += tmp;
    }
  }
  cout << cnt << endl;
}