#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

#define LEN 100010

using namespace std;
typedef long long LL;

LL m, n;

vector <int> V[LEN];

int getPrime() {
	for (int i = 2; i < LEN; i++) {
		if (V[i].empty() != 1)
			continue;
		for (int j = i; j < LEN; j += i) {
			V[j].push_back(i);	
		}
	}
}
/*
LL getNum(int ind, int t, int loc) {
	if (t > n)
		return 0;
	LL tmp = 0;
	for (int i = ind; i < V[loc].size(); i++) {
		tmp += (n / (t * V[loc][i]));
		tmp -= getNum(i + 1, t * V[loc][i], loc);
	}
	return tmp;
}
*/

LL getNum(int loc) {
	int tsize = (int)V[loc].size();
	int maxs = 1 << tsize;
	int Count = 0;

	for (int s = 1; s < maxs; s++) {
		int pro = 1, num = 0;	
		for (int i = 0; i < tsize; i++) {
			if (s & (1 << i)) {
				pro *= V[loc][i];	
				num++;
			}	
		}
	
		if (num & 1) {
			Count += n / pro;		
		}
		else 
			Count -= n / pro;

	}
	return Count;

}
int main() {

	int t;
	LL ans;
	getPrime();
	n = 9;

	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &m, &n);	
		ans = m * n;
		for (int i = 2; i <= m; i++) {
			LL h = getNum(i);
//			printf("%lld\n", h);
			ans = ans - h;
		}

		printf("%lld\n", ans);
	}
	return 0;
}
