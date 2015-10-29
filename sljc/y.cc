#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;

ll phi[N];

void getPhi() {

	for (int i = 0; i < N; i++) phi[i] = i;


	for (int i = 2; i < N; i += 2) 
		phi[i] /= 2;

	for (int i = 3; i < N; i += 2) if(phi[i] == i) {
		for (int j = i; j < N; j += i) 
			phi[j] = phi[j] / i * (i - 1);
	}

	phi[1] = 0;


	for (int i = 2; i < N; i++) {
		phi[i] += phi[i - 1];	
	
	}

}

int main() {

	int n;
	getPhi();

	while (scanf("%d", &n)) {
		if (!n)
			break;
		printf("%lld\n", phi[n]);	
	}


	return 0;
}
