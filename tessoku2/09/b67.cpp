// 17:14~
// 方針
// グラフを作成、各点はvectorの(node, cost)を保持する
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int N,M;
vector<int> a,b,c;
int main(void) {
  cin >> N >> M;  
  a.resize(M), b.resize(M), c.resize(M);
  rep(i,M) cin >> a[i] >> b[i] >> c[i];

}