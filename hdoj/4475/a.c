#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long ll;

int main() {
	
	srand(time(NULL));
	int t = 100;
	printf("%d\n", t);

	ll tmp;

	for (int i = 1; i <= t; i++) {
		tmp = rand() % 10003 + 1;
		printf("%lld\n", tmp);
	}
		
	return 0;


}
