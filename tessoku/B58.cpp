#include <iostream>
#include <algorithm>
using namespace std;

class SegmentTree {
  public:
    int dat[300000], siz = 1;
    void init(int N) {
      siz = 1;
      while(siz < N) siz *= 2;
      for (int i=1; i<siz*2; i++) dat[i] = 0;
    }
    void update(int pos, int x) {
      pos = pos + siz - 1;
      dat[pos] = x;
      while(pos >= 2) {
        pos /= 2;
        dat[pos] = min(dat[pos*2],dat[pos*2+1]);
      }
    }
    int query(int l, int r, int a, int b, int u) {
      if (r <= a || b <= l) return 1000000000;
      if (l <= a && b <= r) return dat[u];
      int m = (a + b) / 2;
      int AnswerL = query(l, r, a, m, u * 2);
      int AnswerR = query(l ,r, m, b, u * 2 + 1);
      return min(AnswerL, AnswerR);
    }
};

int N, L, R, X[10009];
int dp[100009];
SegmentTree Z;

int main() {
  cin >> N >> L >> R;
  for (int i=1; i<=N; i++) cin >> X[i];

  Z.init(N);
  dp[1] = 0;
  Z.update(1, 0);

  for (int i = 2; i <= N; i++) {
    int posL = lower_bound(X+1,X+N+1,X[i]-R)-X;
    int posR = lower_bound(X+1,X+N+1,X[i]-L+1)-X-1;
    dp[i] = Z.query(posL, posR+1, 1, Z.siz+1, 1) + 1;
    Z.update(i, dp[i]);
  }

  cout << dp[N] << endl;
  return 0;
}