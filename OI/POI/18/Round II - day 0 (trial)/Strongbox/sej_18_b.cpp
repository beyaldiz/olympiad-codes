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

lli n, k, ar[N];
vector<lli> divn, dv, pr;
map<lli, bool> mpx;

void f(lli x) {
	if(mpx[x])
		return;
	mpx[x] = true;
	for(auto i : pr)
		if(x % i == 0)
			f(x / i);
}

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n >> k;
	for(int i = 1; i <= k; i++) {
		cin >> ar[i];
		if(ar[i] == 0) {
			ar[i] = n;
			continue;
		}
		ar[i] = __gcd(ar[i], n);
	}

	for(lli i = 1; i * i <= ar[k]; i++) {
		if(ar[k] % i == 0) {
			dv.pb(i);
			if(i * i != ar[k])
				dv.pb(ar[k] / i);
		}
	}
	sort(dv.begin(), dv.end());

	lli t = n;
	for(lli i = 2; i * i <= n; i++) {
		bool fl = false;
		while(t % i == 0) {
			fl = true;
			t /= i;
		}
		if(fl)
			pr.pb(i);
	}

	for(lli i = 1; i <= k - 1; i++)
		f(ar[i]);

	for(auto i : dv) {
		if(mpx[i] == 0) {
			cout << n / i;
			return 0;
		}
	}
}