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
  deque<int> a;
  rep(i,n) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  rep(i,k) {
    a.pop_front();
    a.push_back(0);
  }
  rep(i,n) {
    if(i==n-1) printf("%d\n", a[i]);
    else printf("%d ", a[i]);
  }
}