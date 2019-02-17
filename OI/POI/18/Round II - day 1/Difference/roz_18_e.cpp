#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 1000005
using namespace std;

typedef long long ll;

int n, m, ans, son[3], pre[2][N], mx[N];
char s[N];
vector < int > g[30];

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	scanf("%d %s",&n ,s + 1);
	n = strlen(s + 1);

	for(int i = 1; i <= n; i++)
		g[s[i] - 'a'].pb(i);

	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++){
			if(i == j or g[i].empty() or g[j].empty())
				continue;
			m = 0;
			int i1 = 0, sz1 = g[i].size();
			int i2 = 0, sz2 = g[j].size();
			while(i1 < sz1 and i2 < sz2){
				if(g[i][i1] < g[j][i2]){
					s[++m] = 0;
					i1++;
				} else{
					s[++m] = 1;
					i2++;
				}
			}
			while(i1 < sz1){
				s[++m] = 0;
				i1++;
			}
			while(i2 < sz2){
				s[++m] = 1;
				i2++;
			}
			for(int i = 1; i <= m; i++){
				pre[0][i] = pre[0][i - 1] + (s[i] == 0);
				pre[1][i] = pre[1][i - 1] + (s[i] == 1);
				mx[i] = 0;
			}
			son[0] = son[1] = -1;
			for(int i = 1; i <= m; i++){
				son[s[i]] = i;
				mx[i] = max(mx[i - 1], pre[1][i] - pre[0][i]);
				if(s[i] == 1){
					ans = max(ans, pre[0][i] - pre[1][i] + mx[i - 1]);
				}
				if(s[i] == 0 and son[1] != -1){
					
				
					ans = max(ans, pre[0][i] - pre[1][i] + mx[son[1] - 1]);

				}
			}
		}

	printf("%d\n", ans);
	return 0;
}
