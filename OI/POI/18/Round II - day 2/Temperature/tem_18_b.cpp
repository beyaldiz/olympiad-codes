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

int n, ans, tree[N << 2];
ii ar[N];

void build(int ind, int x, int y) {
	if(x == y) {
		tree[ind] = x;
		return;
	}
	build(left, x, mid);
	build(right, mid + 1, y);
	if(ar[tree[left]].fi <= ar[tree[right]].fi)
		tree[ind] = tree[right];
	else
		tree[ind] = tree[left];
}

int get(int ind, int x, int y, int a, int b) {
	if(y < a || b < x)
		return 0;
	if(a <= x && y <= b)
		return tree[ind];
	int l = get(left, x, mid, a, b), r = get(right, mid + 1, y, a, b);
	if(ar[l].fi <= ar[r].fi)
		return r;
	else
		return l;
}

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> ar[i].fi >> ar[i].se;
	ar[0].fi = INT_MIN;
	build(1, 1, n);

	int l = 0, r = 1, maxi = 1;
	while(l <= n && r <= n) {
		while(ar[maxi].fi <= ar[r].se && r < n) {
			if(ar[maxi].fi < ar[r].fi)
				maxi = r;
			r++;
		}
		ans = max(ans, r - l);
		l = maxi + 1;
		maxi = get(1, 1, n, l, r);
	}
	cout << ans;
}