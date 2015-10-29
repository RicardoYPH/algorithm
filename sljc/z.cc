#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

typedef unsigned long long ll;

const int N = 90;

bool is[N];
//只有次方数为和数时满足要求
//筛选64以内的素数
void getPrime() {
	memset(is, 1, sizeof(is));
	is[0] = is[1] = 0;
	for (int i = 2; i * i <= N; i++)if (is[i]) {
		for (int j = i * i; j < N; j += i)
			is[j] = 0;
	}
}

set <ll> s;
set <ll>::iterator si;

int main() {
	getPrime();
	s.clear();
	s.insert(1);
	//1是特殊情况，提前加入
	for (ll i = 2; i < (1 << 16); i++) {
		//以i为底，会越界的次方数
		int e = ceil(64 / (log(i) / log(2))) - 1;	
		ll num = i;
		for (int j = 2; j <= e; j++) {
			num *= i;	
			if (is[j]) 
				continue;
			s.insert(num);
		}
	}
	for (si = s.begin(); si != s.end(); si++) {
		printf("%llu\n", *si);
	}
	return 0;
}
