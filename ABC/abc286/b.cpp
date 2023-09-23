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
  string s;
  cin >> s;

  int index=0;
  while(1) {
    //printf("index:%d\n", index);
    if(index!=s.length()-1 && s[index]=='n' && s[index+1]=='a') s=s.insert(index+1, "y"),index++;
    index++;
    if(index>=s.length()-1) break;
  }
  cout << s << endl;
}