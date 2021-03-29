﻿////////////////////////////////////////////////////////////////////////////////
// Module Name:  main.cpp
// Authors:      Leonid Dworzanski, Sergey Shershakov
// Version:      0.2.0
// Date:         06.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "stdfix.h"

#include "linked_list.h"

#include "dna_repairer.h"
using xi::LinkedList;
using xi::Node;

using namespace std;

static const char* INP_FILENAME = "../../res/test5.in";

int main (int argc, char* argv[])
{
    LinkedList<int> qqq;
    qqq.deleteNextNode(qqq.getPreHead());

    LinkedList<int> list;
    int a;
    list.addElementToEnd(a=1);
    list.addElementToEnd(a=2);
    list.addElementToEnd(a=3);
    list.addElementToEnd(a=4);
    list.addElementToEnd(a=5);
    list.addElementToEnd(a=6);
    list.addElementToEnd(a=7);
    list.deleteNextNode(list.getPreHead());

    LinkedList<int> list_b;
    int b;
    list_b.addElementToEnd(b=8);
    list_b.addElementToEnd(b=9);
    list_b.addElementToEnd(b=10);
    list_b.addElementToEnd(b=11);
    list_b.addElementToEnd(b=12);
    list_b.addElementToEnd(b=13);


    list_b=list;
    for(int i=0; i<list.size(); i++)
        cout<<list[i]<<endl;



    try{
        DNARepairer dnarepairer;

        dnarepairer.readFile(INP_FILENAME);

        cout << "Broken DNAs" << endl;
        dnarepairer.printDNAStorage();

        dnarepairer.repairDNA();

        cout << "\nGood as it is" << endl;
        dnarepairer.printDNAStorage();
    }
    catch(exception &e) {
        cout << e.what();
    }
    catch (...){
        cout << "Something wrong happend." << endl;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

