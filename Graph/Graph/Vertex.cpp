#include "Vertex.h"

template<class T>
Vertex<T>::Vertex(){
	marked = false;
	visited = false;
	index = 0;
	//type =
	edgeCount = 0;
}

template<class T>
Vertex<T>::Vertex(int index, T type) {
	marked = false;
	visited = false;
	Vertex::index = index;
	Vertex::type = type;
	edgeCount = 0;
}

template<class T>
Vertex<T>::~Vertex(){

}

template<class T>
void Vertex<T>::Set(int index, T type){
	marked = false;
	visited = false;
	Vertex::index = index;
	Vertex::type = type;
}

//TODO: Should sort all edges after insertions
//Edge *Vertex::AddEdge(int otherVertex, int weight) {
//	edges[edgeCount].vertexIndex = index;
//	edges[edgeCount].DestVertexIndex = otherVertex;
//	edges[edgeCount].Weight = weight;
//	edges[edgeCount].Marked = false;
//	edges[edgeCount].Visited = false;
//	edgeCount++;
//	return &edges[edgeCount - 1];
//}

template<class T>
void Vertex<T>::Mark(bool mark){
	marked = mark;
}

template<class T>
void Vertex<T>::Visit(bool mark){
	visited = mark;
}

template<class T>
bool Vertex<T>::IsMarked() const{
	return marked;
}

template<class T>
bool Vertex<T>::IsVisited() const{
	return visited;
}

template<class T>
int Vertex<T>::GetIndex() const
{
	return index;
}

template<class T>
T Vertex<T>::GetT() const{
	return type;
}

//template<class T>
//int Vertex::EdgeCount() const{
//	return edgeCount;
//}

//template<class T>
//Edge *Vertex::GetEdge(int index){
//	return (edges + index);
//}