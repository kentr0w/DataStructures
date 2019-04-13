#include "Edge.h"
#include "Vertex.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

class ReadWriter
{
private:

    std::fstream fin;
    std::fstream fout;
    std::string name;// = "input_910_0.0.txt";
    std::vector<std::vector<int>> stream;
    std::vector<std::vector<int>> real_stram;



public:

    ~ReadWriter()
    {
        fin.close();
        fout.close();
    }

    ReadWriter(string names)
    {
        name = names;
        fin.open(name, std::ios::in);
        fout.open("output.txt", std::ios::out);
    }

    // read 2 int value and empty line
    int readInt()
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");
        std::string s;
        std::getline(fin, s);
        int ty=0;
        int ag = 0;
        std::string fgns;
        int r=0;

        istringstream iss(s);

        for(int i=0; i<s.length(); ++i){
            if(s[i]=='\t' || i == s.length()-1)
                ++r;
        }

        fin.close();
        stream.resize(r);
        real_stram.resize(r);
        return r;
    }

    // read M edges, and fill vector
    /// Для Vertex
    void readEgdes(const int M, std::vector<Vertex>& vertex)
    {
        fin.open(name, std::ios::in);

        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        vector<vector<int>> qwe(M, vector<int>(M));
        std::string s;
        int k=0;
        int ty=0;
        int r=0;
        int j=0;

            while(getline(fin, s)) {
                for(int i=0; i<s.length()+1; ++i){
                    if(s[i]=='\t' || i == s.length()) {
                        r = std::atoi(s.substr(ty,i-ty).c_str());
                        ty = i;
                        ++ty;
                        qwe[k][j] = (r);
                        ++j;
                    }
                }
                ty=0;
                ++k;
                j=0;
            }

        for(int i=0; i<M; ++i){
            for(int j=0; j<M; ++j){
                if(qwe[i][j]!=0){
                    int a = qwe[i][j];
                    vertex[i].neighbors.push_back(&vertex[j]);
                    vertex[i].stream.push_back(qwe[i][j]);
                    vertex[j].neighbors.push_back(&vertex[i]);
                    vertex[j].stream.push_back(qwe[i][j]);
                    vertex[i].real_stream.push_back(0);
                    vertex[j].real_stream.push_back(0);
                    vertex[i].come_to = true;
                    vertex[j].come_from = true;

                    stream[i].push_back(qwe[i][j]);
                    stream[j].push_back(qwe[i][j]);

                    real_stram[i].push_back(0);
                    real_stram[j].push_back(0);
                }
            }
        }

      fin.close();
    }

    void ReadAgain(const int M, std::vector<Vertex>& vertex){
        for(int i=0;i<M; ++i){
            vertex[i].stream = stream[i];
            vertex[i].real_stream = real_stram[i];
        }
    }

    /// Для Vertex
    void Result(std::vector<Vertex>& vertex){
        fin.open(name, std::ios::in);

        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        vector<vector<int>> qwe(vertex.size(), vector<int>(vertex.size()));
        vector<vector<int>> qwe_2(vertex.size(), vector<int>(vertex.size()));
        std::string s;
        int k=0;
        int ty=0;
        int r=0;
        int j=0;

        while(getline(fin, s)) {
            for(int i=0; i<s.length()+1; ++i){
                if(s[i]=='\t' || i == s.length()) {
                    r = std::atoi(s.substr(ty,i-ty).c_str());
                    ty = i;
                    ++ty;
                    qwe[k][j] = (r);
                    qwe_2[k][j] = r;
                    ++j;
                }
            }
            ty=0;
            ++k;
            j=0;
        }

        vector<Vertex> S = vertex;

        for(int i=0; i<vertex.size(); ++i){
            for(int j=0; j<vertex[i].neighbors.size(); ++j){
                if(qwe[i][vertex[i].neighbors[j]->number_of_vertex]!=0){
                    qwe[i][vertex[i].neighbors[j]->number_of_vertex] = vertex[i].stream[j] - qwe[i][vertex[i].neighbors[j]->number_of_vertex];
                }
            }
        }

        for(int i=0; i<vertex.size(); ++i){
            for(int j=0; j<vertex.size(); ++j)
                cout<<qwe[i][j]<<"/"<<qwe_2[i][j]<<"  ";
            cout<<endl;
        }
    }

    // write all values

    /// Считываение из файла
    vector<vector<int>> newRead(int  M){
        fin.open(name, std::ios::in);

        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        vector<vector<int>> qwe(M, vector<int>(M));
        std::string s;
        int k=0;
        int ty=0;
        int r=0;
        int j=0;

        while(getline(fin, s)) {
            for(int i=0; i<s.length()+1; ++i){
                if(s[i]=='\t' || i == s.length()) {
                    r = std::atoi(s.substr(ty,i-ty).c_str());
                    ty = i;
                    ++ty;
                    qwe[k][j] = (r);
                    ++j;
                }
            }
            ty=0;
            ++k;
            j=0;
        }
        fin.close();
        return qwe;
    }

    void writeValues(vector<vector<int>> array, vector<vector<int>> array_2, int path){
            std::ofstream outFile("output.txt");
            if(!outFile.is_open()){
                throw std::ios_base::failure("Can't open: output.txt");
            }
            for(int i=0; i<array.size(); ++i) {
                for(int j=0; j<array.size(); ++j) {
                    if (array[i][j] != 0)
                        outFile << array[i][j] - array_2[i][j] << "/" << array[i][j] << " ";
                    else
                        outFile << array[i][j] << "/" << array[i][j] << " ";
                }
                outFile<<endl;
            }
            outFile<<path;
            outFile.close();
    };
};