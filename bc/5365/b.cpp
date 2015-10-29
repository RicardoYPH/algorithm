#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int loc[22][2];

int getDis(int i, int j) {
	int a = loc[i][0] - loc[j][0];
	int b = loc[i][1] - loc[j][1];
	return a * a + b * b;
}

int main() {

	int t;
	
	while (~scanf("%d", &t)) {

		for (int i = 0; i < t; i++) {
			scanf("%d%d", &loc[i][0], &loc[i][1]);	
		}
		
		int ans = 0;
		int a[7];
		for (int i = 0; i < t; i++) {
			for (int j = i + 1; j < t; j++) {
				for (int k = j + 1; k < t; k++) {
					for (int l = k + 1; l < t; l ++) {
						a[0] = getDis(i, j);		
						a[1] = getDis(j, k);
						a[2] = getDis(k, l);
						a[3] = getDis(l, i);
						a[4] = getDis(i, k);
						a[5] = getDis(j, l);
						sort(a, a + 6);
						if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[4] == a[5]) 
							ans++;
					}	
				
				}	
			
			}	
		}
		printf("%d\n", ans);
	
	}

	return 0;
}
