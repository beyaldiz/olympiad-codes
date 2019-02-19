#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int N = 55;

int n,l[N],mx[N];
vector <ii> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1 ; i <= n ; i++) {
    int x,y;
    cin >> x;
    while(x--) {
      cin >> y;
      v.push_back({y,i});
    }
  }
  sort(v.begin(),v.end());
  v.resize(unique(v.begin(),v.end()) - v.begin());
  for (int i = 0 ; i < v.size() - 1 ; i++) {
    mx[v[i].second] = v[i].first;
    if (v[i].second == v[i + 1].second)
      continue;
    for (int j = 1 ; j <= n ; j++) {
      if (mx[j] == 0 || j == v[i].second | j == v[i + 1].second) continue;
      if (mx[j] + v[i].first > v[i + 1].first) {
        cout << j << " " << mx[j] << " " << v[i].second << " " << v[i].first << " " << v[i + 1].second << " " << v[i + 1].first;
        return 0;
      }
    }
  }
  cout << "NIE\n";
}
