#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define orta ((bas+son)/2)
#define mod 1000000007
#define N 1000005
using namespace std;

typedef long long ll;

int n, a[N];
double b[N], c[N];

void sag(int bas, int son, int l, int r){
	if(bas > son)
		return;
	int mid = -1;
	for(int i = max(orta, l); i <= r; i++)
		if(sqrt(i - orta) + a[i] >= b[orta]){
			b[orta] = sqrt(i - orta) + a[i];
			mid = i;
		}
	// cout << orta << " -> " << mid << endl;
	sag(bas, orta - 1, l, mid);
	sag(orta + 1, son, mid, r);
}

void sol(int bas, int son, int l, int r){
	if(bas > son)
		return;
	int mid = -1;
	for(int i = l; i <= min(orta, r); i++)
		if(sqrt(orta - i) + a[i] >= c[orta]){
			c[orta] = sqrt(orta - i) + a[i];
			mid = i;
		}
	// cout << orta << " -> " << mid << endl;
	sol(bas, orta - 1, l, mid);
	sol(orta + 1, son, mid, r);
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",a + i);

	sag(1, n, 1, n);
	sol(1, n, 1, n);
	for(int i = 1; i <= n; i++){
		int x = (int)max(c[i], b[i]);
		if(x*1.0 != max(c[i], b[i]))
			x++;
		printf("%d\n", x - a[i] );
	}
	return 0;
}
