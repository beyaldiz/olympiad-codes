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

const int N = (int)(2e6 + 5);
const int LOG = (int)(20);

int n, m, ar[N], sum, fr, sc, pre[N];
char s[N];
ii p[N];

void f(int l, int r) {
	int sum = pre[r] - pre[l - 1];
	while(l <= r) {
		p[sum] = {l, r};
		if(ar[l] == 2)
			l++;
		else if(ar[r] == 2)
			r--;
		else {
			l++;
			r--;
		}
		sum -= 2;
	}
}

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n >> m;
	cin >> s + 1;
	for(int i = 1; i <= n; i++) {
		ar[i] = ((s[i] == 'T') ? 2 : 1);
		sum += ar[i];
		pre[i] = pre[i - 1] + ar[i];
	}

	f(1, n);

	fr = 1;
	sc = n;

	while(ar[fr] != 1 && fr <= n)
		fr++;
	while(ar[sc] != 1 && sc >= 1)
		sc--;

	if(fr != n + 1) {
		if(fr < n - sc + 1)
			f(fr + 1, n);
		else
			f(1, sc - 1);
	}
	for(int i = 1; i <= m; i++) {
		int a;
		cin >> a;
		if(p[a].fi != 0)
			cout << p[a].fi << spc << p[a].se << endl;
		else
			cout << "NIE" << endl;
	}
}
