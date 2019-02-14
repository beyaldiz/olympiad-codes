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
typedef pair<lli, lli> ii;
typedef pair<ii, int> iii;
typedef pair<double, double> dd;
 
const int N = (int)(1e6 + 5);
const int LOG = (int)(20);
const lli mod = (lli)(1e9 + 7);
 
lli n, m, k, ans;
bool f1, f2;
pair<char, ii> p1[N], p2[N];
map<lli, lli> st;
 
lli fp(lli x, lli y) {
	if(y == 0)
		return 1;
	if(y == 1)
		return x;
	lli t = fp(x, y / 2);
	if(y % 2 == 0)
		return t * t % mod;
	else
		return (t * t % mod) * x % mod;
}
 
void calc(pair<char, ii> *p, bool *fl, lli x) {
	st.clear();
	for(int i = 1; i <= k; i++) {
		char a = p[i].fi;
		int b = p[i].se.fi, c = p[i].se.se;
		if(a == '+') {
			if(c % 2 == 0) {
				if(st[b] == 1) {
					*fl = true;
					break;
				}
				st[b] = 2;
			}
			else {
				if(st[b] == 2) {
					*fl = true;
					break;
				}
				st[b] = 1;
			}
		}
		else {
			if(c % 2 == 0) {
				if(st[b] == 2) {
					*fl = true;
					break;
				}
				st[b] = 1;
			}
			else {
				if(st[b] == 1) {
					*fl = true;
					break;
				}
				st[b] = 2;
			}
		}
	}
	if(*fl)
		return;
 
	ans += fp(2, x - st.size());
	ans %= mod;
}
 
int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++) {
		char a;
		int b, c;
		cin >> a >> b >> c;
		p1[i] = {a, {b, c}};
		p2[i] = {a, {c, b}};
	}
 
	calc(p1, &f1, n);
	calc(p2, &f2, m);
	if(!f1 && !f2) {
		if(k == 0)
			ans -= 2;
		else
			ans--;
	}
	cout << ans;
}