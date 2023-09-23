#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007

int n;
string S, T;
bool search(string str) {
  int len=str.length();
  for(int i=0; i+len-1<n; i++) {
    // start index is i
    bool key=true;
    for(int j=0; j<len&&i+j<n; j++) {
      if(str[j]!=T[i+j]) {
        key=false; break;
      }
    }
    if(key) return true;
  }
  return false;
}
int main(void) {
  
  cin >> n;
  
  cin >> S >> T;

  string abc="abcdefghijklmnopqrstuvwxyz";
  vector<int> abcnum(abc.length(), 0);
  rep(i,n) {
    abcnum[S[i]-'a']++; abcnum[T[i]-'a']--;
  }
  rep(i,abc.length()) {
    if(abcnum[i]!=0) {
      cout << -1 << endl; return 0;
    }
  }

  int left=0, right=n+1;  //left is ok, right is no
  while(right-left>1) {
    int middle = left + (right - left)/2;
    string str;
    str=S.substr(n-middle);
    //cout << str << " " << search(str) << endl;
    if(search(str)) left=middle;
    else right=middle;
  }
  //cout << left << endl;
  cout << n-left << endl;
}