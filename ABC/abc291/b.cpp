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
  vector<int> x(5*n);
  rep(i,5*n) cin >> x[i];
  sort(x.begin(), x.end());
  double sum=0;
  for(int i=n; i<5*n-n; i++) sum+=x[i];
  sum /= (3.0*n);
  printf("%.6f\n", sum);
}