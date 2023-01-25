#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> mods(100,0);
  rep(i,n) mods[a[i]%100]++;
  ll res=0;
  for(int i=0; i<=50; i++) {
    if(i==0&&mods[i]>1) res += mods[i]*(mods[i]-1)/2;
    else if(i==50&&mods[i]>1) res += mods[i]*(mods[i]-1)/2;
    else if(i!=50 && i!= 0)res += mods[i]*(mods[100-i]);
  }

  cout << res << endl;
}