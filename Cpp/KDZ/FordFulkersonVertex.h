//
// Created by Denis Kumar on 2019-04-03.
//

#ifndef KDZ_FORDFULKERSONVERTEX_H
#define KDZ_FORDFULKERSONVERTEX_H


#include "Vertex.h"

class FordFulkersonVertex {

public:
    int solve(std::vector<Vertex> &vertex, Vertex* source, Vertex* sink);

    Vertex* dfs(std::vector<Vertex> &vertex, std::vector<bool>& used, Vertex *obj, Vertex *stok);

};


#endif //KDZ_FORDFULKERSON_H
