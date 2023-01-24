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

  ll res=0;
  for(ll i=1; i<=n; i*=10) {
    //cout << "i=" << i << endl;
    if(i*10<=n+1) res += 45*(i)*((n+1)/(i*10));
    //cout << "res=" << res << endl;
    ll tmp=((n+1)%(i*10))/(i);
    res += tmp*(tmp-1)*(i)/2;
    res += tmp*(((n+1)%(i*10))%(i));
    
  }
  cout << res << endl;
}