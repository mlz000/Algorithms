double MST(int root) {
	double t = 0.0;
	while (1) {
		for (int i = 1; i <= n; ++i)	in[i] = inf;
		for (int i = 1; i <= m; ++i) {
			int u = e[i].u;
			int v = e[i].v;
			if (e[i].dis < in[v] && u != v) {
				pre[v] = u;
				in[v] = e[i].dis;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (i == root)	continue;
			if (in[i] == inf)	return -1;
		}
		//find cycle
		int cnt = 0;
		memset(id, -1 ,sizeof(id));
		memset(vis, -1 ,sizeof(vis));
		in[root] = 0;
		for (int i = 1; i <= n; ++i) {
			t += in[i];
			int v = i;
			while (vis[v] != i && id[v] == -1 && v != root) {
				vis[v] = i;
				v = pre[v];
			}
			if (v != root && id[v] == -1) {
				for (int u = pre[v]; u != v; u = pre[u])	id[u] = ++cnt;
				id[v] = cnt;
			}
		}
		if (!cnt)	break;//no cycle
		for (int i = 1; i <= n; ++i)
			if (id[i] == -1)	id[i] = ++cnt;
		for (int i = 1; i <= m; ++i) {
			int v = e[i].v;
			e[i].u = id[e[i].u];
			e[i].v = id[e[i].v];
			if (e[i].u != e[i].v)	e[i].dis -= in[v];
		}
		n = cnt;
		root = id[root];
	}
	return t;
}
