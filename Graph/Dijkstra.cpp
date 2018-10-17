#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Graph{
	private:
	vector<vector<int>>graph;
	int V;
	
	int minDistVertex(vector<bool>& SPVertex,vector<int>& DistFromSrc){
		int minDist=INT_MAX;
		int minIndex;
		for(int i=0;i<SPVertex.size();i++){
			if(SPVertex[i]==false&&DistFromSrc[i]<=minDist){
				minDist=DistFromSrc[i];
				minIndex=i;
			}
		}
		return minIndex;
	}
	
	void printSP(vector<int>& DistFromSrc){
		for(int i=0;i<DistFromSrc.size();i++)
		cout<<i<<"  "<<DistFromSrc[i]<<endl;
	}
	
	public:
	Graph(vector<vector<int>> sample){
		V=sample.size();
		for(int i=0;i<V;i++){
			vector<int>temp;
			for(int j=0;j<V;j++){
				temp.push_back(sample[i][j]);
			}
			graph.push_back(temp);
		}
	}
	
	void DijkstraSP(int src){
		vector<bool>SPVertex(V,false);
		vector<int>DistFromSrc(V,INT_MAX);
		DistFromSrc[src]=0;
		for(int count=0;count<V-1;count++){
			int u=minDistVertex(SPVertex,DistFromSrc);
			SPVertex[u]=true;
			for(int v=0;v<V;v++){
				if(!SPVertex[v] && graph[u][v]!=0 && DistFromSrc[u]!=INT_MAX && DistFromSrc[u]+graph[u][v]<DistFromSrc[v])
				DistFromSrc[v]=DistFromSrc[u]+graph[u][v];
			}
		}
		printSP(DistFromSrc);
	}
};

int main(void){
	Graph sample({{0, 4, 0, 0, 0, 0, 0, 8, 0},
	{4, 0, 8, 0, 0, 0, 0, 11, 0},
	{0, 8, 0, 7, 0, 4, 0, 0, 2},
	{0, 0, 7, 0, 9, 14, 0, 0, 0},
	{0, 0, 0, 9, 0, 10, 0, 0, 0},
	{0, 0, 4, 14, 10, 0, 2, 0, 0},
	{0, 0, 0, 0, 0, 2, 0, 1, 6},
	{8, 11, 0, 0, 0, 0, 1, 0, 7},
	{0, 0, 2, 0, 0, 0, 6, 7, 0}});
    sample.DijkstraSP(0);
    return 0;
}