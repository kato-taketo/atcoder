#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  char p,q;
  cin >> p >> q;
  string s = "ABCDEFG";
  //vector<int> vec(7);
  //vec[0] = 3;
  int vec[] = {0,3,1,4,1,5,9};
  for(int i=1; i<7; i++) {
    vec[i] = vec[i] + vec[i-1];
  }
  //swap(p,q);
  if(q-p<0) {char tmp; tmp = p; p = q; q = tmp; }
  cout << vec[q-'A'] - vec[p-'A'] << endl;
}