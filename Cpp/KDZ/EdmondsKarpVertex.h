//
// Created by Denis Kumar on 2019-04-03.
//

#ifndef KDZ_EDMONDSKARPVERTEX_H
#define KDZ_EDMONDSKARPVERTEX_H


#include "Vertex.h"

class EdmondsKarpVertex {

public:
    int solve(std::vector<Vertex> &vertex, Vertex* source, Vertex* sink);

    bool FindPath(std::vector<Vertex> &vertex, Vertex *istok, Vertex *stok);
};


#endif //KDZ_EDMONDSKARP_H
