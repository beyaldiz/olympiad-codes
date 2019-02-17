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
#define inf 2000000000
#define MOD 1000000007
#define N 1000005	
#define M 1000003
#define LOG 19
#define KOK 750
using namespace std;

int n,ans;
int dp[N],a[N],b[N];

int main() {

//	freopen("input.txt","r",stdin);
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n;

	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];

	vector<int> da,db;
	
	a[n+1]=inf;
	b[n+1]=-inf;

	da.pb(n+1);
	db.pb(n+1);

	dp[n+1]=0;

	for(int i=n;i>=1;i--) {

		while(a[i]>=a[da.back()]) da.ppb();

		int posa=da.back();

		while(b[i]<=b[db.back()]) db.ppb();

		db.pb(i);
		da.pb(i);

		int posb=db[lower_bound(all(db),a[i],[&](int x,int y) {return b[x]<y;})-db.begin()-1];

		if(posb<posa) {

			dp[i]=posb-i;

		}
		else {

			dp[i]=dp[posa]+posa-i;

		}

		umax(ans,dp[i]);

	}

	cout<<ans;

}
