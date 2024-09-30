#include <bits/stdc++.h>
using namespace std;
int a[16][16], b[16][16], f[16], v[16];
void dfs(int t) {
	if (t == 16) {
		bool ok = 1;
		for (int i=0; i<16; i++)
			for (int j=0; j<16; j++)
				if (f[a[i][j]] != b[f[i]][f[j]])
					{ ok = 0; goto E; }
		E : if (! ok) return ;
		puts ("iso");
		for (int i=0; i<16; i++)
			cerr << f[i] << ' ';
		exit(0);
	}
	for (int i=0; i<16; i++)
		if (! v[i]) {
			f[t] = i, v[i] = 1;
			bool ok = 1;
			for (int j=0; j<=t; j++)
				if (! (f[a[t][j]] == - 1 && ! v[b[f[t]][f[j]]]) && f[a[t][j]] != b[f[t]][f[j]] || 
					! (f[a[j][t]] == - 1 && ! v[b[f[j]][f[t]]]) && f[a[j][t]] != b[f[j]][f[t]])
					{ ok = 0; break; }
			if (ok) dfs(t + 1);
			f[t] = - 1, v[i] = 0;
		}
}
int main() {
	for (int i=0; i<16; i++)
		for (int j=0; j<16; j++) {
			int k = i, t = j >> 2;
			if (k & 1) {
				(k += t << 2) &= 15;
				k ^= (t & 1) << 1;
			} else (k += t << 2) &= 15;
			k ^= (j >> 1 & 1) << 1;
			k ^= j & 1;
			a[i][j] = k;
		}
	for (int i=0; i<16; i++)
		for (int j=0; j<16; j++) {
			int k = i, t = j >> 2;
			if (k & 1) {
				(k += t * 3 << 2) &= 15;
				k ^= (t & 1) << 1;
			} else (k += t << 2) &= 15;
			k ^= (j >> 1 & 1) << 1;
			k ^= j & 1;
			b[i][j] = k;
		}
	memset (f, - 1, sizeof f), dfs(0);
}
