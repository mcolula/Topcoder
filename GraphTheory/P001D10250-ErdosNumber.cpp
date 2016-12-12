#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


class ErdosNumber {

  private:

  static const int A = 2501;

  typedef vector<int> vi;
  typedef vector< vi> vv;

  #define fst   first
  #define snd   second
  #define id(s) (si.find(s) != si.end() ? si[s] : si[s] = si.size())


  map<string, int> si;
  vv  graph ;
  int dis[A];

  void shortestPath(int s) {
    queue<int> q; q.push(s);
    fill(dis, dis + A,  -1);
    dis[s] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto & v: graph[u]) if (dis[v] < 0)
        dis[v] = 1 + dis[u], q.push(v);
    }
  }

  string distance(int i) {
    return dis[i] < 0 ? "" : " " + to_string(dis[i]);
  }

  public:

  vector<string> calculateNumbers(vector<string> data) {
    graph = vv(A);
    for (auto & s: data) {
      vector<int> people;
      stringstream ss(s);
      string name;
      while (ss >> name)
        people.push_back(id(name));
      for (auto & i: people)
        for (auto & j: people)
          graph[i].push_back(j);
    }
    shortestPath(id("ERDOS"));
    vector<string> ans;
    for (auto & i: si)
      ans.push_back(i.fst + distance(i.snd));
    return ans;
  }

};
