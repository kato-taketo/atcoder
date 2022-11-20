// AC

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i,N) cin >> a[i];
  sort(a.begin(), a.end());

  deque<int> deq;
  int r=0;
  rep(i,N) {
    if(deq.size()==0) deq.push_back(a[i]);
    else if(deq.back()!=a[i]) deq.push_back(a[i]);
    else r++;
  }

  //printf("r = %d\n", r);
  int res=0, cnt=0;
  while(!(deq.empty()&&r==0)) {
    if(res+1==deq.front()) res++, deq.pop_front();
    else if(r>0) {
      r--; cnt++;
      if(cnt==2) res++, cnt=0;
    } else {
      deq.pop_back(); cnt++;
      if(cnt==2) res++, cnt=0;
    }
    //printf("res = %d, deq.size()=%d, r=%d\n", res,(int)deq.size(), r);
  }
  //res += r/2;
  cout << res << endl;
}