# Graph Traversability - cpp-graphs
> Developed by Nicholas Ramsay

## Classes
- Graph
- Vertex
- Edge - Connects two vertices

## Methods
### istraversable
Takes two vertices and returns a boolean representing the possibility of traversing the edges such that Vertices v1 and v2 will meet.

### traverse
Takes two vertices and outputs the minimum distance between the given vertices. If no path exists, returns -1.

### degree
Takes a vertex and outputs the degree of the given vertex, that being the total amount of edges adjacent to the vertex.

## Todo
- Ensure that traverse outputs the minimum path
	- Compare both paths and output the shortest
