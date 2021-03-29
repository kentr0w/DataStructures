//
// Created by Denis Kumar on 2019-04-05.
//

#ifndef KDZ_DINIC_H
#define KDZ_DINIC_H

#include "Vertex.h"


class DinicVertex {
private:

    int CreatePath (Vertex* obj, int flow, std::vector<Vertex>& vertex, Vertex* istok, Vertex* stok );

    bool FindPath(std::vector<Vertex>& vertex, Vertex* istok, Vertex* stok);

public:
    int solve(std::vector<Vertex> &vertex, Vertex* source, Vertex* sink);

};


#endif //KDZ_DINIC_H
