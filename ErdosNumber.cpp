#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#define MAX 100000
using namespace std;

int main() {
  int scenario;
  cin >> scenario;
  for (int s = 0; s < scenario; s++) {
    int lines, names;
    cin >> lines >> names;
    if (lines == 0){
      cout << "Scenario " << s+1 << endl;
      continue;
    }
    string line;
    getline(cin, line);
    vector< vector<string> > relation;
    for (int p = 0; p < lines; p++) {
      string line;
      getline(cin, line);
      vector<string> temp;
      int head = 0, tail = 0, flag = 0;
      while(line[tail] != ':' && tail < line.size()) {
        while (line[tail] != ':'){
          if (line[tail] == ',') {
            flag++;
            if (flag == 2)
              break;
          }
          tail++;
        }
        string res;
        res = line.substr(head, tail - head);
        if (res[0] == ' ')
          res = res.substr(1);
        if (res[res.size()-1] == ' ')
          res = res.substr(0, res.size()-1);
        temp.push_back(res);
        if (line[tail] == ':')
          break;
        head = ++tail;
        flag = 0;
      }
      relation.push_back(temp);
    }
    map<string, set<string> > graph;
    vector<string> name_needed;

    for (int i = 0; i < names; i++) {
      string name;
      getline(cin, name);
      name_needed.push_back(name);
    }

    set<string> temp;
    set<string> name_string;
    graph.insert(pair<string, set<string> >(string("Erdos, P."), temp));
    for (int i = 0; i < relation.size(); i++) {
      for (int j = 0; j < relation[i].size(); j++) {
        set<string>::iterator it = name_string.find(relation[i][j]);
        if (it == name_string.end()) {
          name_string.insert(relation[i][j]);
          graph.insert(pair<string, set<string> >(relation[i][j], temp));
        }
      }
    }

    for (int i = 0; i < relation.size(); i++) {
      for (int j = 0; j < relation[i].size(); j++) {
        for (int k = j+1; k < relation[i].size(); k++) {
          graph[relation[i][j]].insert(relation[i][k]);
          graph[relation[i][k]].insert(relation[i][j]);
        }
      }
    }
    map<string, int> name_op;
    for (set<string>::iterator it = name_string.begin(); it != name_string.end(); it++) {
      if (*it == string("Erdos, P."))
        name_op[string("Erdos, P.")] = 0;
      else
        name_op[*it] = MAX;
    }

    deque<string> name_queue;
    name_queue.push_back(string("Erdos, P."));
    int dist = 0;
    while(!name_queue.empty()) {
      string temp_name = name_queue.front();
      name_queue.pop_front();
      set<string> name_set = graph[temp_name];
      for (set<string>::iterator it = name_set.begin(); it != name_set.end(); it++) {
        if (name_op[*it] > name_op[temp_name]) {
          name_op[*it] = name_op[temp_name] + 1;
          name_queue.push_back(*it);
        }
      }
    }
    cout << "Scenario " << s+1 << endl;
    for (int f = 0; f < name_needed.size(); f++) {
      cout << name_needed[f] << " ";
      if (name_op[name_needed[f]] == MAX || name_op[name_needed[f]] == 0) {
        cout << "infinity";
      } else {
        cout << name_op[name_needed[f]];
      }
      cout << endl;
    }
  }
}