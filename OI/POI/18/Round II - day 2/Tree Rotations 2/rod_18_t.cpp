#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int N = 1e6 + 5;

int n,tim,sub[N * 3],l[N * 3],r[N * 3],val[N * 3],fen[N];
ll ans;
vector <int> v;

void update(int x,int val) {
  for (int i = x ; i <= n ; i += i & (-i))
    fen[i] += val;
}

int query(int x) {
  int res = 0;
  for (int i = x ; i ; i -= i & (-i))
    res += fen[i];
  return res;
}

int read() {
  int cur = ++tim;
  cin >> val[cur];
  if (val[cur] == 0) {
    l[cur] = read();
    r[cur] = read();
    if (sub[l[cur]] > sub[r[cur]])
      swap(l[cur],r[cur]);
    sub[cur] = sub[l[cur]] + sub[r[cur]];
  }
  else
    sub[cur] = 1;
  return cur;
}

void del(int cur) {
  if (val[cur]) {
    update(val[cur],-1);
    v.push_back(val[cur]);
    return;
  }
  del(l[cur]);
  del(r[cur]);
}

void solve(int cur) {
  if (val[cur]) {
    update(val[cur],1);
    return;
  }
  solve(l[cur]);
  v.clear();
  del(l[cur]);
  vector <int> temp;
  swap(temp,v);
  v.clear();
  solve(r[cur]);
  ll res = 0;
  for (auto i : temp)
    res += query(i);
  ans += min(res,(ll)sub[l[cur]] * sub[r[cur]] - res);
  for (auto i : temp)
    update(i,1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  read();
  solve(1);
  cout << ans << endl;
}
