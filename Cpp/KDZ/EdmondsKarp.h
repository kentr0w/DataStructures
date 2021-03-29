//
// Created by denis on 11.04.19.
//

#ifndef KDZ_EDMONDSKARP_H
#define KDZ_EDMONDSKARP_H


#include <vector>

using namespace std;
class EdmondsKarp{

public:
    int solve(vector<vector<int>>& array, int source, int sink);

private:
    bool FindPath(vector<vector<int>>& array, int source, int sink, vector<int>& parent);

};


#endif //KDZ_EDMONDSKARP_H
