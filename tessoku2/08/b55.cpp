// 17:56~
// 方針
// 毎回sortして追加するとo(nlogn n)
// 毎回二分探索を行うとo(1/2 n logn)

// 方針2
// 一度query処理を全て行い、sortする。
// 逆順に削除を行なって、二分探索する
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int Q;
vector<int> vec;
int main(void) {
  cin >> Q;
  rep(i,Q) {
    int key, x;
    cin >> key >> x;
    if(key==1) 
  }
}