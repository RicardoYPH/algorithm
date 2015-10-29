#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	
	int n, m;

	scanf("%d%d", &n, &m);
	if (n > m) {
		int tmp = n;
		n = m;
		m = tmp;
	}

	printf("%d %d\n", n, (m - n) / 2);

}
