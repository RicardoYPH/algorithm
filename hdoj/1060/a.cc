#include <cstdio>
#include <cstring>

typedef long long ll;

double change(double a) {
	while (a > 10) 
		a = a / 10;

	while (a < 1)
		a = a * 10;

	return a;

}

int qpow(ll n) {
	double tmp = n;
	tmp = change(tmp);
	double ret = 1;

	while (n) {
		if (n & 1) 
			ret = change(ret * tmp);
		tmp = change(tmp * tmp);
		n >>= 1;	
	}

	return (int) ret;

}

int main() {

	ll n;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);	
		printf("%d\n", qpow(n));	
	}

	return 0;
}
