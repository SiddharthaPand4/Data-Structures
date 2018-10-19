#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Edge{
	public:
	int src;
	int dest;
	int weight;
	
	/*Edge(int src,int dest,int weight){
		this->src=src;
		this->dest=dest;
		this->weight=weight;
	}*/
};

class Graph{
	int V;
	int E;
	vector<Edge>EdgeList;
	
	void printSP(vector<int> &dist){
		for(int i=0;i<dist.size();i++)
		cout<<i<<"  "<<dist[i]<<endl;
	}
	
	public:
	Graph(int V,int E){
		this->V=V;
		this->E=E;
		EdgeList.reserve(E);
	}
	
	void AddEdge(int src,int dest,int weight){
		Edge temp;
		temp.src=src;
		temp.dest=dest;
		temp.weight=weight;
		EdgeList.push_back(temp);
	}
	
	void BFSP(int src){
		vector<int>distFromSrc(V,INT_MAX);
		distFromSrc[src]=0;
		for(int i=1;i<V-1;i++){
			for(int j=0;j<E;j++){
				int u=EdgeList[j].src;
				int v=EdgeList[j].dest;
				int weight=EdgeList[j].weight;
				if(distFromSrc[u]!=INT_MAX && distFromSrc[u]+weight<distFromSrc[v]){
					distFromSrc[v]=distFromSrc[u]+weight;
				}
			}
		}
		printSP(distFromSrc);
	}
};

int main(void){
	int V,E,src;
	cin>>V>>E;
	Graph sample(V,E);
	for(int e=E,src,dest,weight;e<E;e++){
		cin>>src>>dest>>weight;
		sample.AddEdge(src,dest,weight);
	}
	cin>>src;
	sample.BFSP(src);
	return 0;
}