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
#define N 3000005
#define M 1000003
#define LOG 19
#define KOK 750
using namespace std;

int k;
int last[55];
vector<ii> l;
vector<iii> vn;

void print(vector<int> v) {

	for(int i=0;i<3;i++) cout<<vn[v[i]].st<<" "<<vn[v[i]].nd.nd<<" ";

	exit(0);

}

int main() {

//	freopen("input.txt","r",stdin);
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>k;

	for(int i=1;i<=k;i++) {

		int c;

		cin>>c;

		for(int j=1;j<=c;j++) {

			int x;

			cin>>x;

			l.pb({x,i});

		}


	}

	sort(all(l));

	for(int i=0;i<sz(l);i++) {

		int tut=i;

		while(i+1<sz(l) && l[i].nd==l[i+1].nd) i++;

		vn.pb({l[i].nd,{l[tut].st,l[i].st}});

	}

	for(int i=1;i<=k;i++) last[i]=sz(vn);

	last[vn.back().st]=sz(vn)-1;

	for(int i=sz(vn)-2;i>=0;i--) {

		int no1=vn[i].st,no2=vn[i+1].st;
		int mn=sz(vn);

		for(int j=1;j<=k;j++) {

			if(j!=no1 && j!=no2) {

				umin(mn,last[j]);

			}

		}

		if(mn<sz(vn) && vn[i].nd.nd+vn[i+1].nd.nd>vn[mn].nd.st) {

			swap(vn[mn].nd.st,vn[mn].nd.nd);

			print({i,i+1,mn});

		}

		last[vn[i].st]=i;

	}

	cout<<"NIE";

}
