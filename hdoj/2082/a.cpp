#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define LEN 60

using namespace std;

int main() {

	int a[LEN], b[LEN];

	int t;
	int num;

	scanf("%d", &t);

	while (t--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		a[0] = 1;
		for (int i = 1; i <= 26; i++) {
			scanf("%d", &num);		
			if (num == 0) 
				continue;
			for (int j = 0; j <= 50; j++) {
				for (int k = 0; k <= num && k * i + j <= 50; k++) {
					b[k * i + j] += a[j];	
				}	
			}
			for (int j = 0; j <= 50; j++) {
				a[j] = b[j];	
				b[j] = 0;
			}
		}		

		int ans = 0;

		for (int i = 1; i <= 50; i++) {
			ans += a[i];	
		}
		printf("%d\n", ans);
	
	}



	return 0;
}
