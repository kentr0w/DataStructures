//
// Created by denis on 12.04.19.
//

#ifndef KDZ_FORDFULKERSON_H
#define KDZ_FORDFULKERSON_H

#include <vector>

using namespace std;

class FordFulkerson {
private:

    bool FindPath(vector<vector<int>> &vertex, std::vector<bool>& used, vector<int>& parent, int q, int sink);

public:

    int solve(vector<vector<int>> &vertex,int source, int sink);

};


#endif //KDZ_FORDFULKERSON_H
