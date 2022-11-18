// snuke answer
// 1e9は大きいので、mapによって一部の配列のみを持つ
// local 環境だと [&]がerrorが返されるのでc++環境変えるべき  "https://qiita.com/DaikiSuyama/items/09f5aa399aad37783146"
// 4方向をfで省略して記述するのはなかなか難しい

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int h,w,si,sj,n;
  cin >> h >> w >> si >> sj >> n;
  using MP = map<int,vector<int> >;
  MP mpL, mpR, mpU, mpD;
  rep(ni, n) {
    int i, j;
    cin >> i >> j;
    mpR[i].push_back(j);
    mpL[i].push_back(-j);
    mpD[j].push_back(i);
    mpU[j].push_back(-i);
  }

  auto init = [&](MP& mp, int r) {
    for (auto& p : mp) {
      sort(p.second.begin(), p.second.end());
      p.second.push_back(r);
    }
  };
  init(mpR, w+1);
  init(mpL, 0);
  init(mpD, h+1);
  init(mpU, 0);

  auto f = [&](MP& mp, int i, int j, int l, int r) {
    auto it = mp.find(i);
    if(it == mp.end()) return min(j+l,r-1);
    auto& is = it->second;
    int wi = *lower_bound(is.begin(), is.end(), j);
    return min(j+l, wi-1);
  };
  int q;
  cin >> q;
  rep(qi, q) {
    char d; int l;
    cin >> d >> l;
    if (d == 'R') sj = f(mpR, si,sj,l,w+1);
    if (d == 'L') sj = -f(mpL,si,-sj,l,0);
    if (d == 'D') si = f(mpD, sj,si,l,h+1);
    if (d == 'U') si = -f(mpU,sj,-si,l,0);
    printf("%d %d\n", si,sj);
  }
}