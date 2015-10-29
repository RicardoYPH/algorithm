#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

char Map[3][110];

int mov[3] = {-1, 0, 1};
int n, k;	
int flag;

void dfs(int x, int y) {
	if (y >= n) {
		flag = 1;	
		return ;
	}		
	for (int i = 0; i < 3; i++) {
		int tx = x + mov[i];	
		int ty = y + 1;
		if (tx < 3 && tx >= 0) {
			if (Map[x][ty] == '.' && Map[tx][ty] == '.' && Map[tx][ty + 1] == '.' && Map[tx][ty + 2] == '.') {
				dfs(tx, ty + 2);	
				if (flag)
					return ;
			}
		}
	}
}

int main() {

	int t;

	scanf("%d", &t);

	while (t--) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 110; j++) 
				Map[i][j] = '.';
		}
		flag = 0;
		scanf("%d%d", &n, &k);

		for (int i = 0; i < 3; i++) {
			scanf("%s", Map[i]);	
			Map[i][n] = '.';
		}

		int x;
		for (int i = 0; i < 3; i++) {
			if(Map[i][0] == 's') {
				x = i;
			}
		}

		dfs(x, 0);
		if (flag) 
			puts("YES");
		else 
			puts("NO");
	}
	
	return 0;
}
