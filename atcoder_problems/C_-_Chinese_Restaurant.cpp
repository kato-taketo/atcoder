#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N;
int f(int x) {
  if(x >= N) x -= N;
  else if(x < 0) x += N;
  return x;
}
int main(void) {
  
  cin >> N;
  vector<int> p(N);
  rep(i,N) cin >> p[i];
  map<int,int> mp;  // 料理番号, 初期場所
  rep(i,N) mp.insert(make_pair(p[i],i));

  // 料理目線で回転数0,1,2,3,..,N-1におけるカウンティングを行う
  vector<int> cnt(N,0);
  rep(i,N) {
    //料理iに関して考える
    int index=mp[i];  // 料理iの初期場所
    cnt[f(i-1-index)]++; cnt[f(i-index)]++; cnt[f(i+1-index)]++;
  }
  int res=0;
  rep(i,N) {
    res = max(res, cnt[i]);
  }
  cout << res << endl;
}