#include <iostream>

#define V 10
#define INF 99999


using namespace std;

int findminvertex(int distance[], bool visited[], int n){
	int minvertex = -1; // at initial we yet dont know what the minium vertex value is?
	
	for(int i=0; i<n; i++){
		if(!visited[i]){ //if already not visited?
			if(distance[i] < distance[minvertex] || (minvertex == -1)){
				minvertex = i;
			}
		}
	}
	return minvertex;
}

void dijktras(int graph[V][V], int n){
	int distance[V]; // for updating the distance.
	bool visited[V]; // for recording if the particular node is already visited or not?
	
	for(int i=0; i<n; i++){
		distance[i] = INF; // initialize all distace as infinity.
		visited[i] = false; // initialize all vertex as not visited.
	}
	
	distance[0] = 0; // initilizing the first element to 0.
	
	for(int i=0; i<n; i++){
		int minvertex = findminvertex(distance, visited, n); // finding the vertex with minimum distance.
		visited[minvertex] = true; // marking the vertex as visited.
		
		for(int j=0; j<n; j++){
			if(graph[minvertex][j] != 0){ // if the vertex are adjacent or say conected?
				if(!visited[j]){ // preventing the vertex to be visited backward.
					int dist = distance[minvertex] + graph[minvertex][j]; // this is the new distacne calculated.
					
					if(dist < distance[j])
					distance[j] = dist;
					
				}
			}
		}
	}
	
	// done with the updating of all distances.
	cout<<endl<<endl<<"Vertex\t\tDistance"<<endl;
	for(int i=0; i<n; i++){
		cout<<i<<"\t\t\t"<<distance[i]<<endl;
	}
}

int main(){
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
	int n = 9;
	
	
	
//	cout<<"Enter the number of vertices (max 10): ";
//	cin>>n;
//	
//	cout<<endl<<"Enter the graph as adjacency matrix: ";
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			cout<<endl<<"Enter ["<<i<<"]["<<j<<"] element: ";
//			cin>>graph[i][j];
//		}
//	}
	dijktras(graph, n);
	
	return 1;
}

