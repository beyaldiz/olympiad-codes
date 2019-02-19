	
// ty Errichto
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
 
const int N = 1e5 + 5;

vector <int> ed[N],whe[N];

int n,m,start = -1;
bool on[N];
stack <int> st;
vector <vector <int> > ans;

void add_edge(int u,int v) {
  whe[u].push_back(ed[v].size());
  whe[v].push_back(ed[u].size());
  ed[u].push_back(v);
  ed[v].push_back(u);
}

void del_edge(int u) {
  int v = ed[u].back();
  int j = whe[u][ed[u].size() - 1];
  ed[u][ed[u].size() - 1] = -1;
  ed[v][j] = -1;
}

void dfs(int u) {
  st.push(u);
  on[u] = true;
  while(ed[u].empty() == false) {
    int v = ed[u].back();
    if (v == -1) {
      ed[u].pop_back();
      continue;
    }
    del_edge(u);
    ed[u].pop_back();
    if (on[v]) {
      start = v;
      ans.push_back({});
      ans.back().push_back(u);
      break;
    }
    else {
      dfs(v);
      ans.back().push_back(u);
      if (start == u)
        start = 0;
      else
        break;
    }
  }
  on[u] = false;
  st.pop();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1 ; i <= m ; i++) {
    int u,v,c1,c2;
    cin >> u >> v >> c1 >> c2;
    if (c1 ^ c2)
      add_edge(u,v);
  }

  for (int i = 1 ; i <= n ; i++) {
    if (ed[i].size() % 2 == 1) {
      cout << "NIE\n";
      return 0;
    }
  }

  for (int i = 1 ; i <= n ; i++)
    dfs(i);

  cout << ans.size() << "\n";

  for (auto i : ans) {
    cout << i.size() << " ";
    for (auto j : i)
      cout << j << " ";
    cout << i[0] << " ";
    cout << "\n";
  }

}
