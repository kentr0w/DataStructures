
#ifndef KDZ_VERTEX_H
#define KDZ_VERTEX_H

#include <iostream>
#include <vector>

//
// Created by Denis Kumar on 2019-03-24.
//

/*
 * number_of_vertex - номер вершины
 * capaity - пропускная способность
 * remainder - остаточная пропусканя способность
 * [balance; from] - поток; откуда
 */

class Vertex{
public:
    int number_of_vertex;
    Vertex* from;
    std::vector<Vertex*> neighbors;
    std::vector<int> stream;
    int level;
    std::vector<int> real_stream;
    bool come_to;
    bool come_from;
};

#endif //KDZ_VERTEX_H
