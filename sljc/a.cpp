#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define LEN 1000010

using namespace std;

typedef long long LL;


LL phi[LEN];

void Init() {
	for (int i = 1; i < LEN; i++) {
		phi[i] = i;
	}
	for (int i = 2; i < LEN; i += 2) {
		phi[i] /= 2;
	}

	for (int i = 3; i < LEN; i += 2) {
		if (phi[i] == i)
			for (int j = i; j < LEN; j += i)
				phi[j] = phi[j] / i * (i - 1);

	} 

	for (int i = 1; i < LEN; i++) {
	
		phi[i] += phi[i - 1];
	}


}


int main() {


	Init();
	int t;

	while (~scanf("%d", &t) && t != 0) {
	
		printf("%lld\n", phi[t] - 1);
	
	
	}





	return 0;

}
