/*
 * 10278.cpp
 *
 *  Created on: 2014/4/8
 *      Author: LukeWu
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct path {
	int target;
	int dis;
};

char s[100];
int f[1000], graph[510] = { 0 }, m, n;
vector<path> v[510];
queue<int> q;

int find() {
	int i, cur, max = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (i = 0; i < v[cur].size(); i++) {
			if (graph[cur] + v[cur][i].dis < graph[v[cur][i].target]) {
				graph[v[cur][i].target] = graph[cur] + v[cur][i].dis;
				q.push(v[cur][i].target);
			}
		}
	}
	for (i = 1; i <= m; i++) {
		if (graph[i] > max) {
			max = graph[i];
		}
	}
	return max;
}

int main() {
	path p;
	int N, i, j, a, b, dis, cur, ans, max;
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &n, &m);

		for (i = 1; i <= m; i++) {
			graph[i] = 1000000;
		}
		max = 1000000;
		ans = -1;

		for (i = 0; i < n; i++) {
			scanf("%d", &f[i]);
		}
		gets(s);
		for (;;) {
			if (gets(s) == NULL)
				break;
			if (strlen(s) == 0)
				break;
			sscanf(s, "%d %d %d", &a, &b, &dis);
			p.target = b;
			p.dis = dis;
			v[a].push_back(p);
			p.target = a;
			v[b].push_back(p);
		}

		for (i = 0; i < n; i++) {
			q.push(f[i]);
			graph[f[i]] = 0;
		}
		for (j = 1; j <= m; j++) {
			if (graph[j] != 0) {
				q.push(j);
				graph[j] = 0;
				cur = find();
				if (cur < max) {
					max = cur;
					ans = j;
				}
				for (i = 1; i <= m; i++) {
					graph[i] = 1000000;
				}
				for (i = 0; i < n; i++) {
					q.push(f[i]);
					graph[f[i]] = 0;
				}
			}

		} /////
		if (ans == -1)
			ans = 1;
		printf("%d\n", ans);
		if (N > 0)
			printf("\n");
		for (i = 1; i <= m; i++) {
			v[i].clear();
		}
	}
	return 0;
}
