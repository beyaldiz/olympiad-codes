#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define pw(x) (1ll<<(x))
#define inf 2000000000000000
#define MOD 1000000007
#define N 300005
#define M 1000003
#define LOG 25
#define KOK 580
using namespace std;

struct query {

	int l,r,x;

} ;

int n,m,q;
int flag[N],ex[N];
ll f[N];
ii ans[N];
vector<int> may[N],own[N];
vector<query> qu;

ll get(int x) {

	ll res=0;

	for(int i=x;i>=1;i-=i&-i) res+=f[i];

	return res;

}

void up(int x,int y) {

	for(int i=x;i<=m;i+=i&-i) f[i]+=y;

}

void update(int l,int r,int val) {

	up(l,val);
	up(r+1,-val);

}

void solve() {

	for(int i=0;i<q;i++) may[i].clear();

	for(int i=1;i<=m;i++) f[i]=0;

	for(int i=1;i<=n;i++) {

		if(!flag[i]) {
		
			may[(ans[i].st+ans[i].nd)>>1].pb(i);
		
		}

	}

	for(int i=0;i<q;i++) {

		if(qu[i].l>qu[i].r) {

			update(qu[i].l,m,qu[i].x);
			update(1,qu[i].r,qu[i].x);

		}
		else {

			update(qu[i].l,qu[i].r,qu[i].x);

		}

		for(int cur:may[i]) {

			ll sum=0;

			for(int who:own[cur]) {

				sum+=get(who);

				if(sum>=ex[cur]) break ;

			}

			if(sum>=ex[cur]) {

				ans[cur].nd=i-1;

			}
			else {

				ans[cur].st=i+1;

			}

		}

	}

}

int main() {

//	freopen("input.txt","r",stdin);
 	
 	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n>>m;

	for(int i=1;i<=m;i++) {
	
		int x;

		cin>>x;

		own[x].pb(i);
	
	}

	for(int i=1;i<=n;i++) cin>>ex[i];

	cin>>q;

	for(int i=1;i<=q;i++) {

		int l,r,x;

		cin>>l>>r>>x;
		
		qu.pb({l,r,x});

	}

	for(int i=1;i<=n;i++) ans[i]={0,q-1};

	int cnt=n;

	while(cnt) {

		solve();

		for(int i=1;i<=n;i++) {

			if(!flag[i] && ans[i].st>ans[i].nd) {

				cnt-=(flag[i]=1);

			}

		}

	}

	for(int i=1;i<=n;i++) {

		if(ans[i].st<q) cout<<ans[i].st+1<<"\n";
		else cout<<"NIE\n";

	}

}
