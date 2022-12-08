#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
//#define MOD 1000000007
#define mod 998244353
const int MAX = 510000;
//const int mod = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
ll pow_func(ll x, ll y) {
  // x^y
  ll res=1;
  while(y>0) {
    y--;
    res *= x;
    res %= mod;
  }
  return res;
}
ll func(ll x) {
  return x%mod;
}
// ax + by = gcd(a, b) となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
long long mod_func(long long a, long long m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod_func(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}
ll funcx(ll a, ll b, ll c, ll d, ll e) {
  ll res = 1;
  res *= a; res %= mod;
  res *= b; res %= mod;
  res *= c; res %= mod;
  res *= d; res %= mod;
  res *= e; res %= mod;
  return res;
}
int main(void) {
  COMinit();
  ll key = modinv(100, mod);
  int n,p;
  cin >> n >> p;

  ll res=0;
  ll even=0;
  for(int odd=n; odd>=0; odd-=2) {
    printf("odd = %d, even=%lld\n", odd,even);
    // odd is number of -1
    res += funcx(COM(odd+even,even), (odd+even), pow_func(100-p, odd), pow_func(p, even),     pow_func(key,odd+even));
    even++;
    if(odd==1) {
      odd=0;
      printf("odd = %d, even=%lld\n", odd,even);
      res += funcx(COM(odd+even,even), (odd+even), pow_func(100-p, odd), pow_func(p, even),     pow_func(key,odd+even));
    }
  }
  res %= mod;
  cout << res << endl;
  //cout << 229596204 << endl;
}