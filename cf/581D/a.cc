#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 300;

int x[6], y[6];
char map[N][N];
int vis[3];
int flag = 0;
int tmp;
char ch[6] = {'A', 'B', 'C', 'A', 'B', 'C'};

void Init() {
	memset(map, 0, sizeof(map));
	memset(vis, 0, sizeof(vis));
	flag = 0;
	tmp = 0;
}

int check(int i, int tx, int ty){
	if (tx + x[i] > tmp || ty + y[i] > tmp) 
		return 0;
	for (int j = tx; j < tx + x[i]; j++) {
		for (int k = ty; k < ty + y[i]; k++) {
			if (map[j][k] != 0)
				return 0;
		}	
	}	
	return 1;
}

void change1 (int i, int tx, int ty) {
	for (int j = tx; j < tx + x[i]; j++) {
		for (int k = ty; k < ty + y[i]; k++) {
			map[j][k] = ch[i];
		}	
	}	
}

void change2 (int i, int tx, int ty) {
	for (int j = tx; j < tx + x[i]; j++) {
		for (int k = ty; k < ty + y[i]; k++) {
			map[j][k] = 0;
		}	
	}	
}

void dfs(int cnt) {
	if (cnt == 3) {
		flag = 1;	
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (vis[i] == 1) continue;	
		for (int j = 0; j < tmp; j++) {
			for (int k = 0; k < tmp; k++) {
				if (map[j][k] == 0) {
					if (check(i, j, k) == 1) {
						vis[i] = 1;	
						change1(i, j, k);
						dfs(cnt + 1);
						if (flag == 1)
							return ;
						change2(i, j, k);
						vis[i] = 0;
					}
					if (check(i + 3, j, k) == 1) {
						vis[i] = 1;
						change1(i + 3, j, k);
						dfs(cnt + 1);
						if (flag == 1) {
							return ;
						}
						change2(i + 3, j, k);
						vis[i] = 0;
					}
				}
			
			}	
		}
	}

}

int main() {

	Init();
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%d%d", x + i, y + i);	
		y[i + 3] = x[i];
		x[i + 3] = y[i];
		sum += x[i] * y[i];
	}
	tmp = sqrt(sum);

	if (tmp * tmp != sum) {
		puts("-1");	
	}
	else {
		dfs(0);
		if (flag == 1) {
			printf("%d\n", tmp);
			for (int i = 0; i < tmp; i++) {
				printf("%s\n", map[i]);	
			}	
		}
		else 
			puts("-1");
	}
		
	
	return 0;
}
