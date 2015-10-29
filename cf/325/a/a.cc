#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	int a[1010];

	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);	
	}

	int ans = n;
	int tmp = 0;
	int i = 1;
	for (; i <= n; i++) {
		if (a[i] == 1) 
			break;
		ans--;
	}
	for (; i <= n; i++) {
		if (a[i] == 0) {
			tmp++;	
		}
		if (a[i] == 1){
			if (tmp >= 2) {
				ans -= tmp;	
			}		
			tmp = 0;
		}
	}
	ans -= tmp;	

	printf("%d\n", ans);


	return 0;
}
