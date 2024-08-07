#include <bits/stdc++.h>
using namespace std;
double x[233]; int mark[233];
void dfs(int u, int d, int v) {
	if (d < 5) dfs(u<<1, d+1, v), dfs(u<<1|1, d+1, v|1<<d);
	x[u] = d < 5 ? (x[u<<1] + x[u<<1|1]) / 2 : (u - 32) * 0.6;
	if (mark[u]) printf ("%d[label=\"%d\",pos=\"%.2lf,%d!\"]\n", u, v, x[u], - (d));
	if (d < 5) {
		if (mark[u] && mark[u<<1]) printf ("%d->%d\n", u, u<<1);
		if (mark[u] && mark[u<<1|1]) printf ("%d->%d\n", u, u<<1|1);
	}
}
int main() {
	for (int i=11; i<=21; i++) {
		int u = 1;
		for (int j=0; j<5; j++)
			mark[u] = 1, u = u << 1 | i >> j & 1; mark[u] = 1;
	}
	dfs(1, 0, 0);
}
