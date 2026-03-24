## graphs 

Intro 

* graph is a colection of nodes and edges which connect the nodes
* used to repersent things in poairs like family trees or tranporatiton networks
* can be directed or undirected 

Terms

* Regular graph: every node has the same degree
* Path: a length of conected nodes
* closed path: edge has same end points 
* simple: all nodes in path are distinct 
* cycle: first and last node are same 
* connected graph if there is a path from p to v 
* complete graph all nodes are connected 

Directed graph 

* digraph
* each edge has a directon (u,v)
* starts at u ends at v

Terms 

* out deg : number of edges that start at U
* indeg : amount of endges that end at U
* degree: indeg + outdeg
* isolated vertex: degee 0 
* Pendant vertex: degree 1
* cut vertex: when delete would diconect graph 

```mermaid
flowchart TD
   A --- B
   A --- C
   B --- D
   B --- C
   C --- D
   D --- A
   D --- B

