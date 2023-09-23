#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  rep(i,n) {
    int tmp=a[i]+x;
    int index = lower_bound(a.begin(),a.end(),tmp)-a.begin();
    if(index<n&&a[index]==tmp) {
      cout << "Yes" << endl; return 0;
    }
    tmp=a[i]-x;
    index = lower_bound(a.begin(),a.end(),tmp)-a.begin();
    if(index<n&&a[index]==tmp) {
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
}