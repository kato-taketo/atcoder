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
  vector<vector<int> > a(n+1, vector<int>(n+1));
  rep2(i,1,n+1) rep2(j,1,n+1) cin >> a[i][j];
  int q;
  cin >> q;
  vector<int> gyou(n+1);
  vector<int> res;
  rep2(i,1,n+1) gyou[i]=i;
  rep(i,q) {
    int key,x,y;
    cin >> key >> x >> y;
    if(key==1) swap(gyou[x],gyou[y]);
    else if(key==2) res.push_back(a[gyou[x]][y]);
  }

  rep(i,res.size()) cout << res[i] << endl;
}