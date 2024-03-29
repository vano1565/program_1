#include <conio.h>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
 
const int Max = 1000;
const int MaxInt = 100000;
 
int n;
vvii G(Max);
vi D(Max, MaxInt);
 
void Dkstr(int s) {
  set<ii> Q;
  D[s] = 0;
  Q.insert(ii(0, s));
  while(!Q.empty()) {
    ii top = *Q.begin();
    Q.erase(Q.begin());
    int v = top.second;
    int d = top.first;
    for (vii::const_iterator it = G[v].begin(); it != G[v].end(); it++) {
      int v2 = it->first;
      int cost = it->second;
      if (D[v2] > D[v] + cost) {
        if (D[v2] != 1000000000) {
          Q.erase(Q.find(ii(D[v2], v2)));
        }
        D[v2] = D[v] + cost;
        Q.insert(ii(D[v2], v2));
      }
    }
  }
}
 
int main() {
  int m, s, t = 0;
  scanf("%d %d %d %d", &n, &m, &s, &t);    /// number of tops, archs, start top, end top
  for (int i = 0; i < m; i++) {
    int a, b, w = 0;
    scanf("%d %d %d", &a, &b, &w);
    G[a - 1].push_back(ii(b - 1, w));
    G[b - 1].push_back(ii(a - 1, w));
  }
  Dkstr(s - 1);
  printf("%d\n", D[t - 1]);       /// print
  _getch();
  return 0;
}