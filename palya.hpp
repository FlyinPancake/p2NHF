#ifndef PALYA_HPP
#define PALYA_HPP

#include "allomas.hpp"
#include "vonat.hpp"

#include <string>
using std::string;

#include <iostream>
using std::ifstream;
using std::ofstream;

class Palya
{
private:
    Allomas* allomasLista;
    size_t hossz;
    size_t maxHossz;

    Vonat vonatok[];
    size_t maxVonat;
    size_t vonatszam;

public:
    Palya();
    Palya(ifstream is);
    ~Palya();

    void AddStation(string stationName);
    void EditSation(string stationName, size_t sorszam);
    void RemStation(size_t sorszam);

    void AddTrain(Vonat v);
    void RemTrain(Vonat v);

    void Save(ofstream& os);
};



#endif // !PALYA_HPP