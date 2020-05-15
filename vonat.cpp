#include "vonat.hpp"

Vonat::Vonat() : vonatszam(0),
                 kezdo(nullptr),
                 vegzo(nullptr),
                 indulas({0}),
                 erkezes({0}) {}

Vonat::Vonat(Allomas *kezdo, Allomas *vegzo, tm indul, tm erkez, size_t kocsiszam, size_t ulohely) : kezdo(kezdo),
                                                                                                     vegzo(vegzo),
                                                                                                     indulas(indul),
                                                                                                     erkezes(erkez),
                                                                                                     kocsikSzama(kocsiszam)

{
    //TODO VONATSZAM !!!!
    vonatszam = 1;
    
    kocsik = new Kocsi[kocsikSzama];
    for (size_t i = 0; i < kocsikSzama; i++)
    {
        kocsik[i] = Kocsi(ulohely);
    }
    
}

Vonat::~Vonat() 
{   
    delete[] kocsik;
}

bool Vonat::IsVald()
{
    return (vonatszam != 0);
}