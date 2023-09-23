#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;

  int left=1,right=n;
  int key=1;
  while(right-left>1) {
    int middle = (right+left)/2;
    cout << "? " << middle << endl;
    int s;
    cin >> s;
    if(s==0) left=middle, key=middle;
    else right=middle, key=middle-1;
  }

  cout << "! " << key << endl;
}