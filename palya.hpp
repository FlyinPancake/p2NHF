#ifndef PALYA_HPP
#define PALYA_HPP

#include "allomas.hpp"
#include "vonat.hpp"

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

class Palya
{
private:
    string name;

    Allomas **allomasLista;
    size_t hossz;
    size_t maxHossz;

    Vonat **vonatok;
    size_t maxVonat;
    size_t vonatszam;
    Palya() {};

public:
    Palya(string name, size_t mxH, size_t mxV) :    name(name), 
                                                    maxHossz(mxH),
                                                    maxVonat(mxV)
    {
        vonatok = new Vonat*[maxVonat];
        allomasLista = new Allomas*[maxHossz];
        hossz = 0;
        vonatszam = 0;
    }
    //Palya(istream is);
    ~Palya();

    void AddStation(string stationName)
    {
        allomasLista[hossz++] = new Allomas(stationName);
    }
    void EditSation(string stationName, size_t sorszam);
    void RemStation(size_t sorszam);
    Allomas& GetStation(size_t sorszam) { return *allomasLista[sorszam]; }

    //TODO


    void AddTrain(Vonat v);
    void AddTrain(int kezd, int veg, tm indul, tm erkez, int kocsik);
    void RemTrain(Vonat v);

    void Save(ostream& os);

    void ListStations() 
    {
        for (size_t i = 0; i < hossz; i++)
        {
            std::cout << *allomasLista[i] << std::endl;
        }
        
    }
};



#endif // !PALYA_HPP