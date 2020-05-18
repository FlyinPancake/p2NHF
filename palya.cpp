#include "palya.hpp"

#define MaxKocsihely (size_t)40

Palya::~Palya()
    {
        for (size_t i = 0; i < vonatszam; i++)
        {
            delete vonatok[i];
        }

        delete[] vonatok;

        for (size_t i = 0; i < hossz; i++)
        {
            delete allomasLista[i];
        }

        delete[] allomasLista;
    }

void Palya::AddTrain(Allomas* kezd, Allomas* veg, tm indul, tm erkez, size_t kocsik)
{
    AddTrain(Vonat(kezd, veg, indul, erkez, kocsik, MaxKocsihely ));
}

void Palya::AddTrain(const Vonat& vt)
{
    vonatok[vonatszam++] = new Vonat(vt);
}