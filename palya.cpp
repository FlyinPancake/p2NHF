#include "palya.hpp"

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
