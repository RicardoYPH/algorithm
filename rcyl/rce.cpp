#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int LEN = 1e5 + 10;

vector <int> V[LEN];

void Swap(LL & a, LL & b) {
	int tmp = a;
	a = b;
	b = tmp;
}
inline LL Min(LL a, LL b){
	return a > b ? b : a;
}

void getPrime() {
	for (int i = 2; i < LEN; i += 2) 
		V[i].push_back(2);
	for (int i = 3; i < LEN; i += 2){
		if (V[i].empty() != 1)
			continue;
		for (int j = i; j < LEN; j += i) {
			V[j].push_back(i);
		}

	}
}

LL getNum(int n, int m) {
	LL ret = n;	
	int tsize = V[m].size();
	int Maxs = (1 << tsize);
	for (int s = 1; s < Maxs; s++) {
		int total = 0, pro = 1;	
		for (int i = 0; i < tsize; i++) {
			if(s & (1 << i)) {
				total ++;
				pro = pro * V[m][i];
			}		
		}	
		if (total & 1) 
			ret -= n / pro;			
		else 
			ret += n / pro;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	getPrime();

	int CASE = 1;
	while(t--) {
		int a, c;
		LL b, d, k;
		scanf("%d%lld%d%lld%lld", &a, &b, &c, &d, &k);
		if (k == 0) {	
			printf("Case %d: 0\n", CASE++);
			continue;
		}
		b = b / k;
		d = d / k;
		if (b > d) 
			Swap(b, d);
		LL ans = 0;

		for (LL i = 1; i <= d; i++) {
			k = Min(i, b);
			LL tmp = getNum(k, i);
			ans += tmp;
		}
		printf("Case %d: %lld\n", CASE++, ans);
	}
	return 0;
}
