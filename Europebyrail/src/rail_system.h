#ifndef _RAILSYSTEM_H_
#define _RAILSYSTEM_H_

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <assert.h>
#include <climits>      // INT_MAX
#include <algorithm>    // std::find

#include "service.h"
#include "city.h"

using namespace std;


class Cheapest
{

public:
    Cheapest() {}

    bool operator()(const City* city1, const City* city2)
    {
        return city1->total_fee > city2->total_fee;
    }

    bool operator()(const City& city1, const City& city2)
    {
        return city1.total_fee > city2.total_fee;
    }

};

// For test only 
struct Route
{
    string from;
    string to;
    int fee;
    int distance;
    // recovered route. If no route was found, holds an empty vector.
    vector<string> cities;

    Route(const string& f, const string& t, int fe, int d, const vector<string>& cities)
            : from(f), to(t), fee(fe), distance(d), cities(cities) {};

    bool operator==(Route const& rhs) const
    {
        return rhs.from == this->from
               && rhs.to == this->to
               && rhs.fee == this->fee
               && rhs.distance == this->distance;
    };
};


class RailSystem
{

protected:
    map<string, list<Service*> > outgoing_services;
    map<string, City*> cities;

    /// Throws std::logic_error in case of incorrect file.
    void load_services(const string& filename);

    void reset();

    vector<string> recover_route(const string& city);

    /// Throws std::invalid_argument in case of invalid cities.
    pair<int, int> calc_route(string from, string to);

public:

    RailSystem(const string& filename);

    ~RailSystem();

    void output_cheapest_route(const string& from, const string& to);

    bool is_valid_city(const string& name);

    /// For test only.  
    Route getCheapestRoute(const string& from, const string& to);
};

#endif // _RAILSYSTEM_H_