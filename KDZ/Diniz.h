//
// Created by Denis Kumar on 2019-04-11.
//

#ifndef KDZ_DINIZ_H
#define KDZ_DINIZ_H


#include "Vertex.h"

using namespace std;
class Diniz {
private:

    int CreatePath(vector<vector<int>>& array, int v, int sink, int flow, vector<int>& d, vector<vector<int>>& f);

    bool FindPath(vector<vector<int>>& array, vector<vector<int>>& real_stream, int source, int sink, vector<int>& d);

public:
    int Solve (vector<vector<int>>& array, int source, int sink);

};


#endif //KDZ_DINIZ_H
