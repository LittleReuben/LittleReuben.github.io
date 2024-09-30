#include <bits/stdc++.h>
using namespace std;
int p[10], c[10]; basic_string <int> v[8];
int main() {
	for (int n=2; n<=10000; n++) {
		int m = 0, t = n;
		for (int j=2; j*j<=t; j++)
			if (! (t % j)) {
				p[++m] = j, c[m] = 0;
				while (! (t % j)) c[m] ++, t /= j;
			}
		if (t > 1)
			p[++m] = t, c[m] = 1;
		if (m != 3 || c[1] + c[2] + c[3] != 3)
			continue;
		bool fqr = (p[3] - 1) % p[2], fpr = (p[3] - 1) % p[1], fpq = (p[2] - 1) % p[1];
		v[!fqr<<2|!fpr<<1|!fpq] += n;
/*		if (m != 2 || c[1] + c[2] != 3)
			continue;
		if (n == 12)
			v[1] += n;
		else {
			int p = :: p[1], q = :: p[2];
			if (c[1] == 1) swap(p, q);
			if (! ((q - 1) % p) && (q - 1) % (p * p)) v[2] += n;
			else if (! ((q - 1) % (p * p))) v[3] += n;
			else if (q == 2) v[4] += n;
			else if (! ((p + 1) % q)) v[5] += n;
			else if (! ((p - 1) % q)) v[6] += n;
			else v[0] += n;
		} */
	}
	for (int i=0; i<8; i++, puts(""))
		for (int j : v[i])
			printf ("%d ", j);
}
