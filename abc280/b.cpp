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
  vector<int> s(n);
  rep(i,n) cin >> s[i];

  vector<int> a(n);
  a[0]=s[0];
  for(int i=1; i<n; i++) {
    a[i] = s[i] - s[i-1];
  }
  rep(i,n) {
    if(i==n-1) printf("%d\n", a[i]);
    else printf("%d ", a[i]);
  }
}