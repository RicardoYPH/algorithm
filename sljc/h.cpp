#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 1e7 + 100;
vector <ll> V;
ll prime[N / 10];
bool is[N];
int cnt = 0;

void getPrime() {
	memset(is, 0, sizeof(is));
	for (ll i = 2; i < N; i++) {
		if (is[i] == 1)
			continue;
		prime[cnt++] = i;
		for (ll j = i * i; j < N; j += i) 
			is[j] = 1;
	}
}

void divide(ll n) {
	V.clear();
	int tmp = 0;	

	for(int i = 0; i < cnt && prime[i] <= n; i ++) {
		tmp = 0;
		while (n % prime[i] == 0) {
			tmp ++;	
			n /= prime[i];
		}		
		if (tmp){
			V.push_back(tmp);
		}
	}
	if (n > 1)
		V.push_back(1);
}

int main() {
	int t;
	int CASE = 1;
	getPrime();

	scanf("%d", &t);

	while (t--) {
		ll n;	
		scanf("%lld", &n);
		divide(n);
		ll ans = 1;
		for(int i = 0; i < V.size(); i++) {
			ans *= V[i] * 2 + 1;
		}
		ans = (ans + 1)/ 2;
		printf("Case %d: %lld\n", CASE++, ans);
	}
	return 0;
}
