#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int func(int index, int n) {
  while(index<0 || index>=n) {
    if(index<0) index+=n;
    if(index>=n) index-=n;
  }
  return index;
}
int main(void) {
  int n,a,b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  ll cost=2e18;
  for(ll i=0; i<n; i++) {
    // i is start index
    ll tmp = a * i;
    for(ll j=0; j<n/2; j++) {
      if(s[func(i+j,n)] != s[func(n-1+i-j,n)]) tmp += b;
    }
    //if(i==0) printf("tmp = %lld\n", tmp);
    //if(i==1) printf("tmp = %lld\n", tmp);
    cost = min(cost, tmp);
  }

  cout << cost << endl;
}