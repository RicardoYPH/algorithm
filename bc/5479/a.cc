#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1e3 + 10;

int main() {

	int t;

	char str[N];

	int a[N];

	char flag[N];

	scanf("%d", &t);

	while (t--) {
		
		scanf("%s", str);
		memset(a, 0, sizeof(a));
		memset(flag, 0, sizeof(flag));
		int len = strlen(str);

		int ans = 0;
		for (int i = 0; i < len; i++) {
			int tmp = 0;
			for (int j = i; j < len; j++) {
				if (str[j] == '(') {
					tmp ++;	
				}
			
			}		
			for (int j = i; j >= 0; j--) {
				if (str[j] == ')') {
					tmp++;	
				}	
			}
			ans = max(ans, tmp);
		
		}

		cout << len - ans << endl;

	
	}


	return 0;
}
