#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define mod 998244353

int main(void) {
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;

  // make a min
  rep(i,n) {
    if(a[i]>b[i]) {
      char tmp;
      tmp = a[i];
      a[i] = b[i]; b[i] = tmp;
    }
  }

  int cnt=0,r;
  cnt = n/10;
  r = n%10;
  ll va=0,vb=0;
  ll tmp=0, tmp2=0, key;
  key = 10000000000LL%mod;
  //printf("key = %lld\n", key);
  //printf("key^2 = %lld\n", key*key%mod);
  for(int i=0; i<r; i++) {
    va = va*10 + (a[i]-'0');
    vb = vb*10+(b[i]-'0');
  }
  va %= mod;
  vb %= mod;
  rep(i,cnt) va *= key, va %= mod, vb *= key, vb %= mod;
  int count=0;
  for(int i=r; i<n; i++) {
    tmp = tmp*10+(a[i]-'0');
    tmp2=tmp2*10+(b[i]-'0');
    count++;
    if(count==10) {
      //printf("tmp = %lld\n", tmp);
      //printf("tmp2 = %lld\n", tmp2);
      count = 0;
      tmp %= mod, tmp2 %= mod;
      --cnt;
      rep(i,cnt) tmp *= key, tmp %= mod, tmp2 *= key, tmp2 %= mod;
      va += tmp, vb += tmp2, va %= mod, vb %= mod;
      tmp = 0; tmp2 = 0;
      //printf("va = %lld, vb = %lld\n", va,vb);
    }
  }
  cout << va*vb%mod << endl;



}