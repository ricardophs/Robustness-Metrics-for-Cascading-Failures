#include <igraph.h>
#include <iostream>

using namespace std;

#define N 5000 // Number of nodes
#define N_GRAPHS 10 // Number of repetitions

int main() {

	igraph_t graph; // The graph itself

	// Path to the output file
	char file_name[35] = "Simulations/Graphs/ws_0.gml";

	igraph_rng_seed(igraph_rng_default(), 0);

	for(int n = 0; n < N_GRAPHS; ++n) {

		FILE * file;

		// Change path name according to the network
		file_name[22] = n + '0';

		file = fopen(file_name, "w");
		if (file == 0) {
			exit(1);
		}

		// Create graph using the barabasi albert model
		igraph_watts_strogatz_game(&graph, 1, N, 2, 1e-2, 0, 0);
		igraph_write_graph_gml(&graph, file, NULL, 0);
		
		fclose(file);

		igraph_destroy(&graph);

	}

	return 0;

}