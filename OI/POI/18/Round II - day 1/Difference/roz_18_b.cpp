#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mid ((x + y) / 2)
#define left (ind * 2)
#define right (ind * 2 + 1)
#define mp make_pair
#define timer ((double)clock() / CLOCKS_PER_SEC)
#define endl "\n"
#define spc " "
#define d1(x) cerr<<#x<<":"<<x<<endl
#define d2(x, y) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl
#define d3(x, y, z) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, double> dd;

const int N = (int)(1e6 + 5);
const int LOG = (int)(20);
const int inf = (int)(1e7);

int pre[N], n, mini, mind, ans;
char s[N];
vector<int> v[30];
set<char> used;

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n;
	cin >> s + 1;
	for(int i = 1; i <= n; i++)
		used.insert(s[i]);
	for(int i = 0; i < 26; i++)
		v[i].pb(0);
	for(int i = 1; i <= n; i++)
		v[s[i] - 'a'].pb(i);
	for(int i = 0; i < 26; i++)
		v[i].pb(n + 1);

	for(auto i : used) {
		for(int j = 1; j <= n; j++)
			pre[j] = pre[j - 1] + (s[j] == i);
		pre[n + 1] = pre[n];

		for(auto j : used) {
			if(i != j) {
				mini = inf;
				mind = 0;
				for(int k = 0; k < v[j - 'a'].size(); k++) {
					int idx = v[j - 'a'][k];
					ans = max(ans, pre[idx] - k - mini + (mind + 1 != k));
					if(mini > pre[idx] - k) {
						mini = pre[idx] - k;
						mind = k;	
					}
				}
			}
		}
	}
	cout << ans;
}