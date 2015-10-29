#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {

	ll data[70];
	data[1] = 0;
	for (int i = 2; i < 70; i++) {
		data[i] = (data[i - 1]) * 2 + 1;	
	}

	int k;
	ll a, b;

	while (~scanf("%d", &k)) {
		scanf("%lld%lld", &a, &b);
		if (a >= 0 && b >= 0) {
			if (data[k] - a < b) {
				puts("Yes");	
			}	
			else 
				puts("WaHaHa");
		}
		else if (a <= 0 && b <= 0) {
			if (-data[k] - 1 - a > b) {
				puts("Yes");	
			}	
			else 
				puts("WaHaHa");
		}
		else {
			puts("WaHaHa");	
		}
	}

	return 0;
}
