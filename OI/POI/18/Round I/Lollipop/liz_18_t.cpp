#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int N = 1e6 + 5;

ii ans[N * 2];
int n,q,a[N],l,r,sum;

void add_values(int l,int r,int sum) {
  if (l > r)
    return;
  ans[sum] = {l,r};
  if (a[l] == 2)
    add_values(l + 1,r,sum - 2);
  else if (a[r] == 2)
    add_values(l,r - 1,sum - 2);
  else
    add_values(l + 1,r - 1,sum - 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n >> q;
  for (int i = 1 ; i <= n ; i++) {
    char ch;
    cin >> ch;
    a[i] = 1;
    if (ch == 'T')
      a[i]++;
    if (a[i] == 1 && !l)
      l = i;
    if (a[i] == 1)
      r = i;
    sum += a[i];
  }
  add_values(1,n,sum);
  if (l) {
    if (l - 1 <= n - r)
      add_values(l + 1,n,sum - ((l - 1) * 2 + 1));
    else
      add_values(1,r - 1,sum - ((n - r) * 2 + 1));
  }
  while(q--) {
    int x;
    cin >> x;
    if (x > sum || ans[x].first == 0)
      cout << "NIE\n";
    else
      cout << ans[x].first << " " << ans[x].second << "\n";
  }
}