#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
int Q;
queue<int> que;
priority_queue<int,vector<int>,greater<int> > pq;
int main(void) {
  cin >> Q;
  rep(i,Q) {
    int c;
    cin >> c;
    if(c==1) {
      int x; cin >> x;
      que.push(x);
    } else if(c==2) {
      if(pq.size()!=0) {
        cout << pq.top() << endl;
        pq.pop();
      } else {
        cout << que.front() << endl;
        que.pop();
      }
    } else if(c==3) {
      while(!que.empty()) {
        pq.push(que.front());
        que.pop();
      }
    }
  }
}