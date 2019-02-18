#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 1000005
using namespace std;

using namespace std;

typedef long long ll;
typedef pair < ll , ll > ii;

ll n, m, ans, a[N], b[N], say[N], fen[N];
ii git[N];
vector < ll > g;

void up(ll x, ll y){
	b[x] += y;
	for(; x < N; x += x&-x)
		fen[x] += y;
}

ll qu(ll x){
	ll ans = 0;
	for(; x > 0; x -= x&-x)
		ans += fen[x];
	return ans;
}

void oku(ll k){
	ll x;
	scanf("%lld",&x);
	if(x == 0){
		git[k].st = ++m;
		oku(m);
		git[k].nd = ++m;
		oku(m);
	} else
		a[k] = x;
}

void hazirla(ll node){
	if(a[node]){
		// cout << node << " = " << a[node] << endl;
		say[node] = 1;
		return;
	}
	// cout << node << " -> " << git[node].st << endl;
	// cout << node << " -> " << git[node].nd << endl;
	hazirla(git[node].st);
	hazirla(git[node].nd);
	say[node] += say[git[node].st] + say[git[node].nd];
}

void ekle(ll node){
	if(a[node]){
		g.pb(a[node]);
		up(a[node], -b[a[node]]);
		return;
	}
	ekle(git[node].st);
	ekle(git[node].nd);
}

void dfs(ll node){
	if(a[node]){
		up(a[node], 1);
		return;
	}
	if(say[git[node].st] > say[git[node].nd])
		swap(git[node].st, git[node].nd);
	// cout << node << " -> " << git[node].st << " " << git[node].nd << endl;
	dfs(git[node].st);

	g.clear();
	ekle(git[node].st);
	vector < ll > gg = g;

	dfs(git[node].nd);
	ll x = 0, y = 0;
	// cout << node << " -> " << endl;
	for(ll i = 0; i < gg.size(); i++){
		// cout << gg[i] << " ";
		ll kac = qu(gg[i]);
		x += kac;
		y += say[git[node].nd] - kac;
	}
	// cout << " = " << x << " " << y << endl;
	ans += min(x, y);
	for(ll i = 0; i < gg.size(); i++)
		up(gg[i], 1);
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%lld",&n);
	a[++m] = 0;
	oku(1);
	hazirla(1);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
