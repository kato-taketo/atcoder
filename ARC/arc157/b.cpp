#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int n,k;string s;
bool check(int x) {
  int num_x=0;
  for(int i=0; i<x; i++) {
    if(s[i]=='X') num_x++;
  }
  for(int i=0; i+x-1<n; i++) {
    if(i!=0) {
      if(s[i-1]=='X') num_x--;
      if(s[i+x-1]=='X') num_x++;
    }
    if(num_x <= k && k <= n-x+num_x) return true;
  }
  return false;
}
int main(void) {
  
  cin >> n >> k;
  cin >> s;

  int left=0, right=n+1;
  while(right-left>1) {
    int middle = left + (right-left)/2;
    if(check(middle)) left = middle;
    else right = middle;
    printf("%d %d\n",left, right);
  }
  if(left==0) cout << 0 << endl;
  else cout << left-1 << endl;
}