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

lli n, h[N];
double dp[N], ans[N];

void f(lli x, lli y, lli optl, lli optr) {
	if(x > y)
		return;
	lli opt = optl;
	for(lli i = optl; i <= optr; i++) {
		double t = (double)h[i] - (double)h[mid] + sqrt(mid - i);
		if(dp[mid] < t) {
			opt = i;
			dp[mid] = t;
		}
	}
	f(x, mid - 1, optl, opt);
	f(mid + 1, y, opt, optr);
}

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> h[i];

	f(1, n, 1, n);
	for(int i = 1; i <= n; i++)
		ans[i] = max(ans[i], dp[i]);
	memset(dp, 0, sizeof dp);
	reverse(h + 1, h + n + 1);
	f(1, n, 1, n);
	for(int i = 1; i <= n; i++)
		ans[i] = max(ans[i], dp[n - i + 1]);
	for(int i = 1; i <= n; i++)
		cout << (lli)ceil(ans[i]) << endl;
}