#include <iostream>
using namespace std;

string s_add(string s, string t) {
  string res;
  int flag = 0;
  int m = s.size(), n = t.size();
  int first = 0, second = 0, sum = 0;
  char c;
  string remain;
  for (int i = 0; i < min(m,n); i++) {
    first = int(s[m - 1 - i] - '0');
    second = int(t[n - 1 - i] - '0');
    sum = first + second + flag;
    if (sum >= 10) {
      sum -= 10;
      flag = 1;
    } else {
      flag = 0;
    }
    c = char('0' + sum);
    res = c + res;
  }
  c = char('0' + flag);
  if (m > n) {
    remain = s.substr(0, m-n);
  } else if (m < n) {
    remain = t.substr(0, n-m);
  } else {
    if (c == '1') {
      res = c + res;
      return res;
    } else {
      return res;
    }
  }
  int i = remain.size()-1, temp, temp_r;
  while (flag) {
    if (i < 0) {
      remain = '1' + remain;
      break;
    }
    temp = remain[i] - '0';
    temp_r = temp + flag;
    if (temp_r >= 10) {
      flag = 1;
      remain[i] = '0';
    } else {
      flag = 0;
      remain[i] = char('0' + temp_r);
    }
    i--;
  }
  res = remain + res;
  return res;
}
int main() {
  string t;
  getline(cin, t);
  int times = stoi(t, nullptr);
  while(times--) {
    string total, sub;
    getline(cin, total);
    getline(cin, sub);
    int m = int(total.size()), n = int(sub.size());
    if (n == 0) {
      cout << 0 << endl;
      continue;
    }
    if (m == 0) {
      cout << 0 << endl;
      continue;
    }
    string table[2][n+1];

    for (int i = 0; i <= n; i++) {
      table[0][i] = "0";
    }

    for (int i = 0; i < 2; i++) {
      table[i][0] = "1";
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (total[i-1] == sub[j-1]){
          // table[1][j] = table[0][j-1] + table[0][j];
          table[1][j] = s_add(table[0][j-1], table[0][j]);
        } else {
          table[1][j] = table[0][j];
        }
      }
      for (int p = 0; p <= n; p++) {
        table[0][p] = table[1][p];
      }
    }
    cout << table[1][n] << endl;
  }
  return 0;
}