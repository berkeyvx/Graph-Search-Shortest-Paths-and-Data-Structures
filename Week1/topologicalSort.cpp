/*
	Topological Sort

Can be solved via DFS

Def: A topological ordering of a directed graph G is a labelling f of G's node such that:
1 -> f(v) 's are the set {1,2,,...,n}
2 -> (u,v) member of G, f(u) < f(v)

Every arc must go forward in ordering

IF G has directed cycle there is/are no topological order. G must not have directed cycle
Any edge cannot go backwards. If there is a directed cycle, some node goes backwards. Thats why it violate rule 2

Space Complexity : O(m+n)

! Every directic acyclic graph has a sink vertex(sink vertex is some vertex that have no outgoing arcs)
*/


#include <iostream>





int main(int argc, char const *argv[])
{
	
	return 0;
}