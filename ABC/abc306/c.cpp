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
  vector<int> a(3*n);
  rep(i,3*n) cin >> a[i];

  vector<int> cnt(n+1,0);  // index cnt
  vector<pair<int,int> > vec;  // index, value
  rep(i,3*n) {
    if(cnt[a[i]]==1) vec.push_back(make_pair(i,a[i])), cnt[a[i]]++;
    else cnt[a[i]]++;
  }
  sort(vec.begin(), vec.end());
  //cout << vec.size() << endl;
  rep(i,n) {
    if(i!=n) cout << vec[i].second << " ";
    else cout << vec[i].second;
  }
  cout << endl;
}