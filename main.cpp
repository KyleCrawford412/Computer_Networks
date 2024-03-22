#include<iostream>
#include<climits>     
using namespace std;

//get the minimum path
int minPath(int dist[], bool visited[]){
	
	//set min to infinity
	int min = INT_MAX;
	int index;
	
	for(int i = 0; i < 10; i++){
		//check the distance of unvisited nodes
		if((visited[i] == false) && (dist[i] <= min)){
			//update min distance if it is shorter
			min = dist[i];
			index = i;
		}
	}
	
	//return shortest path
	return index;
}

 // adjacency matrix used is 6x6
void Dijkstra(int nodeEdges[10][10], int startPos){
	
	//min distance of each node
	int dist[10];

	//if node was visited
	bool visited[10];
	
	//initialize node distances to infinity and unvisited 
	for(int i = 0; i < 10; i++){
		dist[i] = INT_MAX;
		visited[i] = false;	
	}
	
	//distance to starting position is 0
	dist[startPos] = 0;         
	
	for(int i = 0; i < 10; i++){
		
		//get the next closest node
		int min = minPath(dist, visited);
		
		//visit the next closest node
		visited[min] = true;
		
		for(int i = 0; i < 10; i++){
			
			//update the min distance for each node with an edge to the current one
			//check every node that has a connection to the current node and hasn't been visited already
			if((!visited[i] && nodeEdges[min][i]) && (dist[min] != INT_MAX) && (dist[min] + nodeEdges[min][i] < dist[i])){
				//update the distance of unvisited nodes
				dist[i] = dist[min] + nodeEdges[min][i];
			}
		}
	}
	
	cout << "Vertex\t\tDistance from source"<<endl;
	
	//Print
	for(int i = 0; i < 10; i++){
		//Asci values
		char str = 65 + i;
		cout << str << "\t\t\t" << dist[i] << endl;
	}
}

//main program
int main(){
	
	//set the nodes
	int nodeEdges[10][10]={
		{0, 33, 0, 0, 20, 10, 0, 0, 0, 0},
		{33, 0, 10, 8, 0, 0, 0, 0, 0, 0},
		{0, 10, 0, 5, 0, 0, 0, 15, 0, 0},
		{0, 8, 5, 0, 5, 0, 10, 18, 0, 0},
		{20, 0, 0, 5, 0, 21, 15, 0, 0, 0},
		{10, 0, 0, 0, 21, 0, 0, 0, 10, 0},
		{0, 0, 0, 10, 15, 0, 0, 0, 4, 50},
		{0, 0, 15, 18, 0, 0, 0, 0, 0, 12},
		{0, 0, 0, 0, 0, 10, 4, 0, 0, 5},
		{0, 0, 0, 0, 0, 0, 50, 12, 5, 0}};
	
	//implement Dijkstra's algorithm on the path
	Dijkstra(nodeEdges, 0);
	
	return 0;	                        
}