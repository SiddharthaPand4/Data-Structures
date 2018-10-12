#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Edge{
	public:
	int src;
	int dest;
	int weight;

	bool operator <(const Edge &Edge1){
		return weight<Edge1.weight;
	}
	friend ostream & operator << (ostream &out,Edge tempEdge);
};

ostream & operator << (ostream &out,Edge tempEdge){
	cout<<tempEdge.src<<"   "<<tempEdge.dest<<"   "<<tempEdge.weight;
}

class Subset{
	public:
	int parent;
	int rank;
};

class Graph{
	public:
	int V;
	int E;
	vector<Edge>EdgeList;
	vector<Subset>Subsets;

	Graph(int V,int E){
		this->V=V;
		this->E=E;
		EdgeList.reserve(E);
	}

	void AddEdge(int src,int dest,int weight=1){
		Edge tempEdge;
		tempEdge.src=src;
		tempEdge.dest=dest;
		tempEdge.weight=weight;
		EdgeList.push_back(tempEdge);
	}

	int find(vector<Subset> &Subsets,int x){
		if(Subsets[x].parent!=x)
			return find(Subsets,Subsets[x].parent);
		return Subsets[x].parent;
	}

	void Union(vector<Subset> &Subsets,int x,int y){
		int xroot=find(Subsets,x);
		int yroot=find(Subsets,y);
		if(Subsets[xroot].rank>Subsets[yroot].rank)
			Subsets[yroot].parent=xroot;
		else if(Subsets[xroot].rank<Subsets[yroot].rank)
			Subsets[xroot].parent=yroot;
		else{
			Subsets[yroot].parent=xroot;
			Subsets[xroot].rank++;
		}
	}

	/*bool IsCycle(){
		Subsets.reserve(V);
		for(int v=0;v<V;v++){
			Subsets[v].parent=v;
			Subsets[v].rank=0;
		}
		for(int e=0;e<E;e++){
			int x=find(Subsets,EdgeList[e].src);
			int y=find(Subsets,EdgeList[e].dest);
			if(x==y)
				return 1;
			Union(Subsets,x,y);
		}
		return 0;
	}*/

	void KruskalMST(void){
		vector<Edge>result(V);
		Subsets.reserve(V);
		for(int i=0;i<V;i++){
			Subsets[i].parent=i;
			Subsets[i].rank=0;
		}
		sort(EdgeList.begin(),EdgeList.end());
		int e=0;
		int i=0;
		while(e<V-1){
			Edge tempEdge=EdgeList[i++];
			int x=find(Subsets,tempEdge.src);
			int y=find(Subsets,tempEdge.dest);
			if(x!=y){
				result[e++]=tempEdge;
				Union(Subsets,x,y);
			}
		}
		for(int it=0;it<V-1;it++)
			cout<<result[it]<<endl;
	}
};

int main(void){
	Graph sample(4,5);
	sample.AddEdge(0,1,10);
	sample.AddEdge(0,2,6);
	sample.AddEdge(0,3,5);
	sample.AddEdge(1,3,15);
	sample.AddEdge(2,3,4);
	sample.KruskalMST();
	return 0;
}
