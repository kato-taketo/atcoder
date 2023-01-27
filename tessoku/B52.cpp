#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n,x;
  cin >> n >> x;
  string a;
  cin >> a;

  queue<int> que;
  que.push(x-1);
  a[x-1]='@';
  while(!que.empty()) {
    int pos = que.front();
    if(a[pos-1]=='.') a[pos-1]='@', que.push(pos-1);
    if(a[pos+1]=='.') a[pos+1]='@', que.push(pos+1);
    que.pop();
  }
  cout << a << endl;
}