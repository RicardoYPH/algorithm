#include <bits/stdc++.h>

using namespace std;

string s[11];
int n, cnt;
int fzero[30];
int H[30];
int ma;

int main() {


	while (~scanf("%d", &n)) {

		memset(fzero, false, sizeof(fzero));
		cnt = 0;
		memset(H, 0, sizeof(H));
		ma = 0;
		for (int i = 0; i < n; i++) 
			s[i].clear();


		for (int i = 0; i < n; i++) 
			cin >> s[i];

		for (int i = 0; i < n; i++) {
			fzero[s[i][0]] = true;
			ma = max((int)s[i].size(), ma);
		}

		for (int i = 0; i < n; i++) 
			reverse(s[i].begin(), s[i].end());
		
		for (int i = 0; i < ma; i++) {
			for (int j = 0; i < n; i++) {
				if (s[j][i] == 0) {
					continue;
				}
				if (H[s[j][i] - 'A'] == 1) continue;
				k[cnt++] = s[i][j];
				H[s[j][i] - 'A'] = 1;
			}
		}

	}
	return 0;
}
