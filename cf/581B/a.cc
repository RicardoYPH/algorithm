#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N];
int m[N];
int flag[N];

int main() {

	int n;

	scanf("%d", &n);

	memset(a, 0, sizeof(a));
	memset(m, 0, sizeof(m));
	memset(flag, 0, sizeof(flag));

	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	m[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > m[i + 1]) {
			m[i] = 	a[i];
			flag[i] = 1;
		}
		else if (a[i] == m[i + 1]) {
			m[i] = a[i];
		}
		else 
			m[i] = m[i + 1];
			
	}
	for (int i = 0; i < n - 1; i++) {
		if (flag[i] == 1) {
			printf("0 ");	
		}	
		else {
			printf("%d ", m[i] - a[i] + 1);	
		}
	}

	printf("0\n");
	


	return 0;
}
