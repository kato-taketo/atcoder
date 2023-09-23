#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,p,q,r,s;
  cin >> n >> p >> q >> r >> s;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int tmp,index=r-1;
  for(int i=p-1; i<q; i++) {
    tmp = a[i];
    a[i] = a[index];
    a[index] = tmp;
    index++;
  }

  rep(i,n) {
    if(i!=n-1) printf("%d ", a[i]);
    else cout << a[i] << endl;
  }
}