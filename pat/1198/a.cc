#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N], b[N];
int tmp[N];
int n;
int flag;
bool cmp() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

void change(int r) {
	if (r >= flag) return;
	if (r * 2 < flag && r * 2 + 1 < flag) {
		if (b[r * 2] > b[r * 2 + 1]) {
			if (b[r * 2] > b[r]) {
				int tmp = b[r];
				b[r] = b[r * 2];
				b[r * 2] = tmp;
			}
		}
		else {
			if (b[r * 2 + 1] > b[r]) {
				int tmp = b[r];
				b[r] = b[r * 2 + 1];
				b[r * 2 + 1] = tmp;
			}
		}
	}
	else if (r * 2 < flag) {
		if (b[r * 2] > b[r]) {
			int tmp = b[r];
			b[r] = b[r * 2];
			b[r * 2] = tmp;
		}
	}
	change(r * 2);
	change(r * 2 + 1);
}

int main() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) scanf("%d", a + i);
	for (i = 1; i <= n; i++) scanf("%d", b + i);

	for (i = 1; i <= n; i++) {
		sort(a + 1, a + i + 1);
		if (cmp()) {
			break;
		}
	}
	if (i > n) {
		int tmp = b[1];
		int j;
		for (j = 2; j <= n; j++) {
			if (b[j] > tmp) {
				b[1] = b[j - 1];
				b[j - 1] = tmp;
				break;
			}
		}
		flag = j - 1;
		change(1);
		cout << "Heap Sort" << endl;
		printf("%d", b[1]);
		for (int i = 2; i <= n; i++) {
			printf(" %d", b[i]);
		}
		puts("");
	}
	else {
		cout << "Insertion Sort" << endl;
		if (i != n) {
			for (; i <= n; i++) {
				sort(a + 1, a + i + 2);
				if (cmp() != true) 
					break;
			}
		}
		printf("%d", a[1]);
		for (int i = 2; i <= n; i++) {
			printf(" %d", a[i]);		
		}
		puts("");
	}
	
	return 0;
}
