// official answer

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

struct PQ {
  priority_queue<int> q, dq;
  void push(int x) { q.push(x);}
  int top() {
    while(dq.size() && q.top() == dq.top()) {
      q.pop(); dq.pop();
    }
    return q.top();
  }
  void pop() { top(); q.pop();}
  void erase(int x) {dq.push(x); }
  int size() const {return q.size() - dq.size();}
};
struct DS {
  int k;
  ll sum;
  multiset<int> ls, rs;
  DS(int k=0): k(k), sum(0) {}
  void ladd(int x) {
    sum += x;
    ls.insert(x);
  }
  void lerase(multiset<int>::iterator it) {
    sum -= *it;
    ls.erase(it);
  }
  void add(int x) {
    ladd(x);
    if (int(ls.size()) <= k) return;
    auto it = ls.end(); it--;
    rs.insert(*it);
    lerase(it);
  }
  void erase(int x) {
    if (*ls.rbegin() < x) {
      rs.erase(rs.find(x));
    } else {
      lerase(ls.find(x));
      auto it = rs.begin();
      ladd(*it);
      rs.erase(it);
    }
  }
};

int main(void) {
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  DS d(k);
  rep(i,m) d.add(a[i]);
  cout << d.sum << '\n';
  rep(i,n-m) {
    d.add(a[i+m]);
    d.erase(a[i]);
    cout << d.sum << '\n';
  }
}