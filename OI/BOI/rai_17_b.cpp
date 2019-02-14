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
 
const int N = (int)(1e5 + 5);
const int LOG = (int)(20);
 
int n, m, k, dep[N], par[N][LOG];
set<int> in[N], ex[N];
vector<ii> v[N];
vector<int> ans;
 
void pre_dfs(int x = 1, int back = 0) {
	dep[x] = dep[back] + 1;
	par[x][0] = back;
	for(auto i : v[x])
		if(i.fi != back)
			pre_dfs(i.fi, x);
}
 
void build_lca() {
	for(int i = 1; i < LOG; i++)
		for(int j = 1; j <= n; j++)
			par[j][i] = par[par[j][i - 1]][i - 1]; 
}
 
int lca(int x, int y) {
	if(dep[x] < dep[y])
		swap(x, y);
	int dif = dep[x] - dep[y];
	for(int i = 0; i <= LOG; i++)
		if(dif & (1 << i))
			x = par[x][i];
	if(x == y)
		return x;
	for(int i = LOG - 1; i >= 0; i--)
		if(par[x][i] != par[y][i])
			x = par[x][i], y = par[y][i];
	return par[x][0];
}
 
void dfs(int x = 1, int back = 0) {
	for(auto i : v[x]) 
		if(i.fi != back)
			dfs(i.fi, x);
	for(auto i : v[x]) 
		if(i.fi != back) {
			if(in[i.fi].size() >= k)
				ans.pb(i.se);
			if(in[i.fi].size() > in[x].size())
				swap(in[i.fi], in[x]);
			for(auto j : in[i.fi])
				in[x].insert(j);
		}
	for(auto i : ex[x])
		in[x].erase(i);
}
 
void pre_calc() {
	pre_dfs();
	build_lca();
}
 
int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].pb({b, i});
		v[b].pb({a, i});
	}
 
	pre_calc();
	
	for(int i = 1; i <= m; i++) {
		int a, lc;
		cin >> a;
		for(int j = 1; j <= a; j++) {
			int b;
			cin >> b;
			in[b].insert(i);
			if(j == 1)
				lc = b;
			if(j >= 2) {
				lc = lca(lc, b);
			}
		}
		ex[lc].insert(i);
	}
 
	dfs();
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto i : ans)
		cout << i << spc;
}
