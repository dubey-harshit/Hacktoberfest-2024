#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
	map<int, list<pair<int, int>>> adj;

	void addEdge(int u, int v, int w){
		pair<int, int> p = make_pair(v, w);
		adj[u].push_back(p);
	}

	void printAdj(){
		for(auto i: adj){
			cout << i.first << " -> ";
			for(auto j: i.second)
				cout << "[" << j.first << ", " << j.second << "] ";

			cout << endl;
		}
	}

	void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s){
		visited[node] = true;

		for(auto neighbour: adj[node]){
			if(!visited[neighbour.first])
				dfs(neighbour.first, visited, s);
		}

		s.push(node);
	}

	void getShortestPath(int src, vector<int> &dist, stack<int> &s){
		dist[src] = 0;

		while(!s.empty()){
			int top = s.top();
			s.pop();

			if(dist[top] != INT_MAX){
				for(auto i: adj[top]){
					if(dist[i.first] > dist[top] + i.second)
						dist[i.first] = dist[top] + i.second;
				}
			}
		}
	}
};

int main(){
	Graph G;
	G.addEdge(0, 1, 5);
	G.addEdge(0, 2, 3);
	G.addEdge(1, 2, 2);
	G.addEdge(1, 3, 6);
	G.addEdge(2, 3, 7);
	G.addEdge(2, 4, 4);
	G.addEdge(2, 5, 2);
	G.addEdge(3, 4, -1);
	G.addEdge(4, 5, -2);

	G.printAdj();

	unordered_map<int, bool> visited;
	stack<int> s;
	int n = 6;

	for(int i=0; i<6; i++){
		if(!visited[i])
			G.dfs(i, visited, s);
	}

	int src = 1;
	vector<int> dist(n, INT_MAX);

	G.getShortestPath(src, dist, s);

	cout << "Shortest path of each node from 1 is: ";
	for(int i=0; i<n; i++)
		cout << dist[i] << " ";

	cout << endl;

	return 0;
}
