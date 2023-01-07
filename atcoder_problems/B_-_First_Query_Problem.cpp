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
  int q;
  cin >> q;

  vector<int> res;
  rep(i,q) {
    int key;
    cin >> key;
    if(key==1) {
      int k,x;
      cin >> k >> x;
      a[k-1]=x;
    } else if(key==2) {
      int k;
      cin >> k;
      res.push_back(a[k-1]);
    }
  }

  rep(i,res.size()) cout << res[i] << endl;
}