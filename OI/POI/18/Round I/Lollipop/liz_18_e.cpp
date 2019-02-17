#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 1000005
using namespace std;

typedef long long ll;
typedef pair < int , int > ii;

int n, m, mn = N, mx = 0, top, ind = 1, f, a[N];
ii b[N], c[N];
char ch;

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d %d",&n ,&m);
	for(int i = 1; i <= n; i++){
		scanf(" %c",&ch);
		if(ch == 'W'){
			mn = min(mn, i);
			mx = i;
			a[i] = 1;
		} else
			a[i] = 2;
	}
	if(!mx){
		for(int i = 1; i <= m; i++){
			int x;
			scanf("%d",&x);
			if(x%2 or x/2 > n)
				printf("NIE\n");
			else
				printf("1 %d\n",x/2);
		}
		return 0;
	}
	if(mn > n - mx + 1){
		mn = n - mx + 1;
		f = 1;
		reverse(a + 1, a + n + 1);
		// cout << "CEVIRILDI" << endl;
	}
	// for(int i = 1; i <= n; i++)cout << a[i] << " ";
	for(int i = 1; i <= m; i++){
		scanf("%d",&b[i].st);
		b[i].nd = i;
	}
	sort(b + 1, b + m + 1);
	for(int i = mn; i <= n; i++){
		top += a[i];

		while(ind <= m and top - 1 == b[ind].st){
			if(!f)
				c[b[ind].nd] = mp(mn + 1, i);
			else
				c[b[ind].nd] = mp(n - i + 1, n - mn);
			ind++;
		}

		while(ind <= m and top == b[ind].st){
			if(!f)
				c[b[ind].nd] = mp(mn, i);
			else
				c[b[ind].nd] = mp(n - i + 1, n - mn + 1);
			ind++;
		}
		
	}
	for(int i = mn - 1; i >= 1; i--){
		top += a[i];
		while(ind <= m and top - 1 == b[ind].st)
			ind++;
		while(ind <= m and top == b[ind].st){

			if(!f)
				c[b[ind].nd] = mp(i, n);
			else
				c[b[ind].nd] = mp(1, n - i + 1);

			// c[b[ind].nd] = mp(i, n);
			ind++;
		}
	}
	for(int i = 1; i <= m; i++){
		if(!c[i].st)
			printf("NIE\n");
		else
			printf("%d %d\n", c[i].st ,c[i].nd);
	}
	return 0;
}
