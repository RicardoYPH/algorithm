#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

char a[N], b[N];

int numa[N], numb[N];

int main() {
	scanf("%s%s", a, b);
	memset(numa, 0, sizeof(numa));
	memset(numb, 0, sizeof(numb));
	
	int e1 = strlen(a);
	int e2 = strlen(b);

	for (int i = 0; i < e1; i++) {
		numa[a[i]]++;
	}

	for (int i = 0; i < e2; i++) {
		numb[b[i]]++;
	}
	int tot1, tot2;
	tot1 = tot2 = 0;
	for (int i = 0; i < N; i++) {
		if (numa[i] < numb[i]) {
			tot1 += numb[i] - numa[i];
		}
		else {
			tot2 += numa[i] - numb[i];
		}
	}
	if (tot1 > 0) {
		printf("No %d\n", tot1);
	}
	else {
		printf("Yes %d\n", tot2);
	}


	return 0;
}
