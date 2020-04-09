# Graph Traversability - cpp-graphs
> Developed by Nicholas Ramsay

## Classes
- Vertex
- Edge - Connects two vertices

## Methods
### istraversable
Takes two vertices, an array of edges and the array's length.
Will return a boolean representing the possibility of traversing the edges such that Vertices v1 and v2 will meet.

### degree
Takes a vertex, an array of edges and the array's length.
Will return the degree of the vertex, that being the total amount of edges connected to it.

## Todo
- Create a traversability method that returns the lowest amount of edges crossed such that vertex v1 can meet vertex v2. If a path is not found, the method shall return -1.
