#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;


int data[20];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}


int main() {
	int n, m;

	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i++)
			scanf("%d", data + i);

		int tsize = n;
		int Maxs = (1 << tsize);
		int ans = 0;

		for (int s = 1; s < Maxs; s++) {
			int pro = 1, total = 0;
			for (int i = 0; i < tsize; i++) {
				if (s & (1 << i)) {
					pro = lcm(pro, data[i]);	
					total ++;
				}	
			}	
			if (total & 1)
				ans += m / pro;
			else 
				ans -= m / pro;
		}
		printf("%d\n", ans);

		
	}

	return 0;
}
