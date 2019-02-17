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
#define inf 1000000000
#define MOD 1000000007
#define N 1000005	
#define M 1000003
#define LOG 19
#define KOK 750
using namespace std;

int n,ans;
char s[N];
int pre[26],mx[26][26],last[26][26];

int main() {

//	freopen("input.txt","r",stdin);
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n>>(s+1);

	for(int i=1;i<=n;i++) {

		int cur=s[i]-'a';

		if(pre[cur]) {

			for(int j=0;j<26;j++) {

				if(j!=cur) {

					umax(ans,pre[j]-pre[cur]+mx[j][cur]);

				}

			}

		}

		pre[cur]++;

		for(int j=0;j<26;j++) {

			umax(mx[j][cur],last[cur][j]);

		}

		for(int j=0;j<26;j++) {

			last[cur][j]=pre[cur]-pre[j];

		}

	}

	for(int i=0;i<26;i++) {

		int cur=i;

		if(!pre[cur]) continue ;

		for(int j=0;j<26;j++) {

			if(j!=cur) {

				umax(ans,pre[j]-pre[cur]+mx[j][cur]);

			}

		}

	}

	cout<<ans;

}
