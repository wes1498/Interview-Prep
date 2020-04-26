#include <iostream>
#include <vector>

using namespace std;

int START;
int END;
vector<vector<int> > paths;


struct Edge {
	int src, dest;
};

class Graph
{
public:

	vector<vector<int>> adj_list;

	Graph(vector<Edge> const &edges, int N)
	{
		adj_list.resize(N);
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			adj_list[src].push_back(dest);
			adj_list[dest].push_back(src);
		}
	}
};

void print_hamiltonian_paths(Graph const& g, int x, vector<bool>visited, vector<int> &path, int N) {
	// if a path is found such taht it starts 
	if (path.size() == N && *path.begin() == START && path[N-1] == END && find(paths.begin(), paths.end(), path)==paths.end())
	{
		paths.push_back(path);
		return;
	}

	// Check if every edge starting from starting vertex x leads to a solution or not
	for (int w : g.adj_list[x]) {
		// process only unvisited vertices as Hamiltonian
		// path visits each vertex exactly once
		if (!visited[w]) {
			visited[w] = true;
			path.push_back(w);

			// check if adding vertex w to the path leads to solution or not
			print_hamiltonian_paths(g, w, visited, path, N);

			visited[w] = false;
			path.pop_back();
		}
	}
}

int position_print_helper(vector<int> vertices, int flag){
	int position;
	if (flag){
		cout<<"enter starting vertex x:" << endl;
	} else {
		cout<<"enter ending vertex y:" << endl;
	}
    cin>>position;
	while(true){
		if(find(vertices.begin(), vertices.end(), position)==vertices.end()){
			cout<<"Choose from the following existing vertices:" << endl;
			cin>>position;
		} else {break;}
	}
	return position;
}

void set_up(vector<int> vertices, vector<Edge> edges) {

    int start = position_print_helper(vertices,1);
	int end = position_print_helper(vertices,0);

	cout<<"x: " << start << " y: " << end << endl;
	START = start;
	END = end;

	int N = vertices.size();
	Graph g(edges, N);

	vector<int> path;
	path.push_back(start);

	vector<bool> visited(N);
	visited[start] = true;

	print_hamiltonian_paths(g, start, visited, path, N);
	
	if(paths.empty()){
		cout<<"Hamiltonion path does not exist starting at x: " << start << " and y: "<< end <<endl;
		return;
	}
	for(vector<int> p : paths) {
		for(int i : p){
			cout<< i << " ";
		}
		cout<<endl;
	}
	paths.clear();
}

void test_graph_large(){
		cout<<"test_one_path_large_graph: Hamiltonion path starting at 0 and ending at 99:\n";
		vector<Edge> edges = {
		{0, 1},{1, 2},{2, 3},{3, 4},{4, 5},{5, 6},{6, 7},{7, 8},{8, 9},{9, 10},
		{0, 2},{1, 3},{2, 4},{3, 5},{6, 4},{7, 3},{8, 2},{9, 1},{10, 0},
		{10, 11},{11, 12},{12, 13},{13, 14},{14, 15},{15, 16},{16, 17},{17, 18},{18, 19},{19, 20},
		{20, 21},{21, 22},{22, 23},{23, 24},{24, 25},{25, 26},{26, 27},{27, 28},{28, 29}, {29,30},
		{30, 31},{31, 32},{32, 33},{33, 34},{34, 35},{35, 36},{36, 37},{37, 38},{38, 39},{39, 40},
		{40, 41},{41, 42},{42, 43},{43, 44},{44, 45},{45, 46},{46, 47},{47, 48},{48, 49},{49, 50},
		{50, 51},{51, 52},{52, 53},{53, 54},{54, 55},{55, 56},{56, 57},{57, 58},{58, 59},{59, 60},
		{60, 61},{61, 62},{62, 63},{63, 64},{64, 65},{65, 66},{66, 67},{67, 68},{68, 69},{69, 70},
		{70, 71},{71, 72},{72, 73},{73, 74},{74, 75},{75, 76},{76, 77},{77, 78},{78, 79},{79, 80},
		{80, 81},{81, 82},{82, 83},{83, 84},{84, 85},{85, 86},{86, 87},{87, 88},{88, 89},{89, 90},
		{90, 91},{91, 92},{92, 93},{93, 94},{94, 95},{95, 96},{96, 97},{97, 98},{98, 99},
		{91, 8},{92, 7},{93, 6},{94, 5},{95, 4},{96, 3},{97, 2},{98, 1},{99, 0},

	};
	
	vector<int> vertices = {0,1,2,3,4,5,6,7,8,9,10,
							11,12,13,14,15,16,17,18,19,20,
							21,22,23,24,25,26,27,28,29,30,
							31,32,33,34,35,36,37,38,39,40,
							41,42,43,44,45,46,47,48,49,50,
							51,52,53,54,55,56,57,58,59,60,
							61,62,63,64,65,66,67,68,69,70,
							71,72,73,74,75,76,77,78,79,80,
							81,82,83,84,85,86,87,88,89,90,
							91,92,93,94,95,96,97,98,99};

	set_up(vertices, edges);
}

void test_large_DAG(){
		cout<<"test_DAG: Hamiltonion path starting at 0 and ending at 99:\n";
		vector<Edge> edges = {
		{0, 1},{1, 2},{2, 3},{3, 4},{4, 5},{5, 6},{6, 7},{7, 8},{8, 9},{9, 10},
		{10, 11},{11, 12},{12, 13},{13, 14},{14, 15},{15, 16},{16, 17},{17, 18},{18, 19},{19, 20},
		{20, 21},{21, 22},{22, 23},{23, 24},{24, 25},{25, 26},{26, 27},{27, 28},{28, 29}, {29,30},
		{30, 31},{31, 32},{32, 33},{33, 34},{34, 35},{35, 36},{36, 37},{37, 38},{38, 39},{39, 40},
		{40, 41},{41, 42},{42, 43},{43, 44},{44, 45},{45, 46},{46, 47},{47, 48},{48, 49},{49, 50},
		{50, 51},{51, 52},{52, 53},{53, 54},{54, 55},{55, 56},{56, 57},{57, 58},{58, 59},{59, 60},
		{60, 61},{61, 62},{62, 63},{63, 64},{64, 65},{65, 66},{66, 67},{67, 68},{68, 69},{69, 70},
		{70, 71},{71, 72},{72, 73},{73, 74},{74, 75},{75, 76},{76, 77},{77, 78},{78, 79},{79, 80},
		{80, 81},{81, 82},{82, 83},{83, 84},{84, 85},{85, 86},{86, 87},{87, 88},{88, 89},{89, 90},
		{90, 91},{91, 92},{92, 93},{93, 94},{94, 95},{95, 96},{96, 97},{97, 98},{98, 99},
		{0, 10},{10, 20},{20, 30},{30, 40},{40, 50},{50, 60},{60, 70},{70, 80},{80, 90},{9, 99}
	};
	
	vector<int> vertices = {0,1,2,3,4,5,6,7,8,9,10,
							11,12,13,14,15,16,17,18,19,20,
							21,22,23,24,25,26,27,28,29,30,
							31,32,33,34,35,36,37,38,39,40,
							41,42,43,44,45,46,47,48,49,50,
							51,52,53,54,55,56,57,58,59,60,
							61,62,63,64,65,66,67,68,69,70,
							71,72,73,74,75,76,77,78,79,80,
							81,82,83,84,85,86,87,88,89,90,
							91,92,93,94,95,96,97,98,99};

	set_up(vertices, edges);
}

void test_multiple_solutions() {
	cout<<"test_small_with_multiple_paths: Hamiltonion path starting at 0 and ending at 5:\n";
	vector<Edge> edges = {{0, 2},{1, 2},{0, 4},{0, 5},{1, 4},{1, 5},{2, 3},{2, 4},{4, 5},{3, 4}};
	vector<int> vertices = {0,1,2,3,4,5};
	
	set_up(vertices, edges);

}

void test_undirected_graph() {
	cout<<"test_small_undirected: Hamiltonion path starting at 0 and ending at 5:\n";
	vector<Edge> edges = {{0, 2},{2, 0},{1, 2},{2, 1},{0, 4},{4, 0},{0, 5},{5, 0},{4, 5},{5, 4},
						  {1, 4},{4, 1},{1, 5},{5, 1},{2, 3},{3, 2},{2, 4},{4, 2},{3, 4},{4, 3}};
	vector<int> vertices = {0,1,2,3,4,5};
	
	set_up(vertices, edges);

}
// void test_undirected_graph() {
// 	cout<<"test_small_undirected: Hamiltonion path starting at 0 and ending at 5:\n";
// 	vector<Edge> edges = {{0, 1},{1, 0},{1, 2},{2, 1}};
// 	vector<int> vertices = {0,1,2};
	
// 	set_up(vertices, edges);

// }


// Represent a random graph with n vertices of at least degree one (n is at least 100). 
// This graph might be undirected or directed. It could have cycles or no cycles. 
// Randomly select two vertices (x,y) from the graph, and find all of the possible hamiltonian paths in the graph.
int main() {
	test_graph_large();
	test_multiple_solutions();
	test_large_DAG();
	test_undirected_graph();

	return 0;
}
