- you can print the max flow using capacity array as every edge before the target must be has positive capacity The
Standard Maximum Flow Problem :

- A list of pipes is given, with different flow-capacities. These pipes are connected at their endpoints. What is the
maximum amount of water that you can route from a given starting point to a given ending point?

- A company owns a factory located in city X where products are manufactured that need to be transported to the
distribution center in city Y. You are given the one-way roads that connect pairs of cities in the country, and the
maximum number of trucks that can drive along each road. What is the maximum number of trucks that the company can send
to the distribution center?”

- we are given a network - a directed graph, in which every edge has a certain capacity c associated with it, a starting
vertex (the source, X in the example above), and an ending vertex (the sink). We are asked to associate another value f
satisfying f â‰¤ c for each edge such that for every vertex other than the source and the sink, the sum of the values
associated to the edges that enter it must equal the sum of the values associated to the edges that leave it.
  ---------------------------------------------------------------------------------------------
- The residual network has the same vertices as the original network, and one or two edges for each edge in the original.
More specifically, if the flow along the edge x-y is less than the capacity there is a forward edge x-y with a capacity
equal to the difference between the capacity and the flow (this is called the residual capacity), and if the flow is
positive there is a backward edge y-x with a capacity equal to the flow on x-y.

- augmenting path is simply a path from the source to the sink in the residual network, whose purpose is to increase the
flow in the original one.

- Ford-Fulkerson method : start with no flow everywhere and increase the total flow in the network while there is an
augmenting path from the source to the sink with no full forward edges or empty backward edges a path in the residual
network

- What about the correctness of this algorithm? It is obvious that in a network in which a maximum flow has been found
  there is no augmenting path, otherwise we would be able to increase the maximum value of the flow, contradicting our
  initial assumption. If the converse of this affirmation is true, so that when there is no augmenting path, the value
  of the flow has reached its maximum, we can breathe a sigh of relief, our algo is correct and computes the maximum
  flow in a network.

- The neat part of the Ford-Fulkerson algorithm described above is that it gets the correct result no matter how we
solve (correctly!!) the sub-problem of finding an augmenting path. However, every new path may increase the flow by only
1, hence the number of iterations of the algorithm could be very large if we carelessly choose the augmenting path
algorithm to use.

- Be careful though; if the reversed arc y-x also exists in the original network, this will fail, and it is recommended
that the initial capacity of each arc be stored somewhere, and then the flow along the edge is the difference between
the initial and the residual capacity.

- The next best thing in the matter of simplicity is a breadth-first search (BFS). Recall that this search usually yields
the shortest path in an un-weighted graph. Indeed, this also applies here to get the shortest augmenting path from the
source to the sink. In the following pseudocode we will basically: find a shortest path from the source to the sink and
compute the minimum capacity of an edge (that could be a forward or a backward edge) along the path – the path capacity.
Th
  . /en, for each edge along the path we reduce its capacity and increase the capacity of the reversed edge with the path
capacity.
