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

  for(int i=0; i<n-1; i++) {
    if(i==0) printf("%d ", a[i]);
    if(a[i]<a[i+1]) {
      for(int j=a[i]+1; j<=a[i+1]; j++) {
        printf("%d ", j);
      }
    } else {
      for(int j=a[i]-1; j>=a[i+1]; j--) {
        printf("%d ", j);
      }
    }
  }
  cout << endl;
}