#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int num[N];
int flag[N];
vector <int> V;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", num + i);
	}
	int Max = num[1];
	memset(flag, 0, sizeof(flag));
	flag[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (num[i] >= Max) {
			Max = num[i];
			flag[i] = 1;
		}	
	}

	flag[n]++;
	int Min = num[n];
	for (int i = n - 1; i >= 1; i--) {
		if (num[i] <= Min) {
			Min = num[i];
			flag[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (flag[i] == 2) V.push_back(num[i]);
	}

	int e = V.size();
	sort(V.begin(), V.end());
	cout << e << endl;
	for (int i = 0; i < e; i++) {
		printf("%d%c", V[i], i == e - 1 ? '\0' : ' ');
	}
	cout << endl;


	return 0;
}
