#ifndef __VGRAPH_H
#define __VGRAPH_H

#include <vector>
using std::vector;
using std::pair;

class DirectedGraph {
 public:
  // At construction, the graph has no arcs.
  explicit DirectedGraph(int num_nodes);

  int NumNodes() const;
  int NumArcs() const;

  void AddArc(int from, int to, double length);

  int OutDegree(int node) const;

  // Returns all the destination nodes that were added with arcs
  // originating from "node".
  // In the example above, Neighbors(1) is {0, 2, 3} and Neighbors(2) is {0}.
  const vector<pair<int, double>>& Neighbors(int node) const;

 private:
  vector<vector<pair<int, double>>> neighbors_;
  int num_arcs_;
};

#endif
