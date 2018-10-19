#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Graph{
	int V;
		vector<vector<int>>graph;
		public:
		Graph(vector<vector<int>> sample){
			V=sample.size();
			for(int i=0;i<V;i++){
				vector<int>temp;
				for(int j=0;j<sample[i].size();j++){
					temp.push_back(sample[i][j]);
				}
				graph.push_back(temp);
			}
		}
		
		void printMST(vector<int> &parent){
			for(int i=1;i<V;i++)
			cout<<parent[i]<<"--"<<i<<"=="<<graph[i][parent[i]]<<endl;
		}
		
		int minKeyVertex(vector<int> &key,vector<bool> &mstVertex){
			int min=INT_MAX;
			int minIndex;
			for(int v=0;v<V;v++){
				if(mstVertex[v]==false&&key[v]<min){
					min=key[v];
					minIndex=v;
				}
			}
			return minIndex;
		}
			
		void PrimMST(){
				vector<int>parent(V);
				vector<int>key(V,INT_MAX);
				vector<bool>MSTVertex(V,false);
				key[0]=0;
				parent[0]=-1;
				for(int mstIndex=0;mstIndex<V-1;mstIndex++){
					int u=minKeyVertex(key,MSTVertex);
					MSTVertex[u]=true;
					for(int v=0;v<V;v++){		if(graph[u][v]&&MSTVertex[v]==false&&graph[u][v]<key[v]){
						key[v]=graph[u][v];
						parent[v]=u;
						}
					}
				}
				printMST(parent);
		}
};

int main(void){
	Graph sample({{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}});
	sample.PrimMST();
	return 0;
}