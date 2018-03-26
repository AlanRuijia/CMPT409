#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
int search(int l[25][25], vector<int> res, int visited[21], const int next, const int t) {
  if (next == t) {
    for (int re : res) {
      cout << re << " ";
    }
    cout << t << endl;
    return 1;
  }
  res.push_back(next);
  visited[next] = 1;
  int s = 0;
  for (int i = 0; i < 22; i++) {
    if (!l[next][i])
      continue;
    if (visited[i])
      continue;
    s += search(l, res, visited, i, t);
  }
  visited[next] = 0;
  return s;
}
bool bfs(int l[25][25], int visited[25], int c, int t) {
  queue<int> q;
  q.push(c);
  visited[c] = 1;
  while(!q.empty()) {
    int n = q.front();
    q.pop();
    if (n == t)
      return true;
    for (int i = 0; i < 22; i++) {
      if (!l[n][i])
        continue;
      if (visited[i])
        continue;
      q.push(i);
      visited[i] = 1;
    }
  }
  return false;
}
int main() {
  int count = 1;
  int dest;
  while (scanf("%d", &dest) == 1) {
    if (dest == 0)
      break;
    int l[25][25];
    memset(l, 0, sizeof(l));
    do {
      int first, second;
      scanf("%d %d", &first, &second);
      if (!first && !second) {
        break;
      }
      l[first][second] = 1;
      l[second][first] = 1;
    } while(true);
    vector<int> res;
    int visited[25];
    memset(visited, 0, sizeof(visited));
    cout << "CASE " << count << ":" <<endl;
    int s = 0;
    int v[25];
    memset(v, 0, sizeof(v));
    if (bfs(l, v, 1, dest))
      s = search(l, res, visited, 1, dest);
    cout << "There are " << s << " routes from the firestation to streetcorner " << dest << "." << endl;
    count++;
  }
  return 0;
}