#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  // kよりXが大きかれば反転させる。
  int cnt=0;
  rep(i,n) if(s[i]=='X') cnt++;
  if(cnt<k) {
    k=n-k;
    rep(i,n) if(s[i]=='X') s[i]='Y'; else s[i]='X';
  }

  // sの調査 
  int tmp=0;
  vector<int> vec;  // x..xy...yx...xy...y
  if(s[0]=='Y') vec.push_back(0);
  rep(i,n) {
    if(i!=0) {
      if(s[i]!=s[i-1]) vec.push_back(tmp), tmp=0;
    }
    tmp++;
  }
  vec.push_back(tmp);
  //rep(i,vec.size()) if(i==vec.size()-1) printf("%d\n", vec[i]); else printf("%d ", vec[i]);

  // change x -> y
  int res=0;
  rep(i,vec.size()) {
    if(i%2==1) res += max(0, vec[i]-1);
  }
  vector<int> vec_in_x;  // yxyのようなx
  rep(i,vec.size()) {
    // xの該当箇所
    if(i%2==0) {
      // 先頭のxは無視
      if(i==0) continue;
      // lastのxは無視
      else if(i==vec.size()-1) continue;
      else vec_in_x.push_back(vec[i]);
    }
  }
  sort(vec_in_x.begin(), vec_in_x.end());
  rep(i,vec_in_x.size()) {
    if(k>=vec_in_x[i]) res+=vec_in_x[i]+1, k-=vec_in_x[i];
    else {
      res += k; k=0;
      break;
    }
  }
  if(k>0) res += k;
  cout << res << endl;
}