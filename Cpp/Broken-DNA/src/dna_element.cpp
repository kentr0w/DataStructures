////////////////////////////////////////////////////////////////////////////////
// Module Name:  dna_repairer.h/cpp
// Authors:      Sergey Shershakov, Leonid Dworzanski
// Version:      0.2.0
// Date:         06.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "dna_element.h"

DNAElement::DNAElement() {
    id=base="";
    number=0;
}
DNAElement::DNAElement(const std::string &description)
{
    readFromString(description);
}
void DNAElement::readFromString(const std::string &description)
{
    std::vector<char> alph_2 = {'A', 'T', 'C', 'G'};

    std::vector<char> alph(26);
    alph[0] = 'a';
    for (int i = 1; i < alph.size(); i++)
        alph[i] = (char) ((int) alph[i - 1] + 1);

    char _name = description[0];
    std::string numb;
    for (int i = 1; i < description.size() - 2; i++)
    {
        if (!isdigit(description[i]))
            throw std::invalid_argument("Error");
        numb += description[i];
    }
    char _type = description[description.size() - 1];

    auto result_1 = std::find(alph.begin(), alph.end(), _name); // проверка id
    auto result_2 = std::find(alph_2.begin(), alph_2.end(), _type); // проверка type


    if (result_1 != alph.end() && result_2 != alph_2.end())
    {
        number = std::stoi(numb);
        id = _name;
        base = _type;
    }
    else
        throw std::invalid_argument("error");

}

#include "dna_element.h"

// TODO: implement
