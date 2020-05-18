#include "vonat.hpp"

size_t Vonat::aktVonat = 100;

Vonat::Vonat(Allomas *kezdo, Allomas *vegzo, tm indul, tm erkez, size_t kocsiszam, size_t ulohely) : kezdo(kezdo),
                                                                                                     vegzo(vegzo),
                                                                                                     indulas(indul),
                                                                                                     erkezes(erkez),
                                                                                                     kocsikSzama(kocsiszam)
{
    vonatszam = ++aktVonat;
    
    kocsik = new Kocsi*[kocsikSzama];
    for (size_t i = 0; i < kocsikSzama; i++)
    {
        kocsik[i] = new Kocsi(ulohely);
    }
    
}

Vonat::Vonat(const Vonat &vt)                              
{    
    kocsikSzama = vt.kocsikSzama;
    kocsik = new Kocsi*[kocsikSzama];
    for (size_t i = 0; i < kocsikSzama; i++)
        kocsik[i] = new Kocsi(*vt.kocsik[i]);
    
    indulas = vt.indulas;
    erkezes = vt.erkezes;
    kezdo = vt.kezdo;
    vegzo = vt.vegzo;
    vonatszam = vt.vonatszam;
}

Vonat::~Vonat()
{
    for (size_t i = 0; i < kocsikSzama; i++)
    {
        delete kocsik[i];

    }
    delete[] kocsik;
}

bool Vonat::ReserveSeat(size_t kocsiSzam, size_t helySzam)
{
    if (kocsiSzam >= kocsikSzama)
    {
        throw "Ilyen szamu kocsi nincs a vonaton";
        return false;
    }

    if (helySzam >= kocsik[kocsiSzam]->HelyekSzama())
    {
        throw "Nincs ilyen szamu hely a kocsiban";
        return false;
    }

    if (!(kocsik[kocsiSzam] -> CheckOcc(helySzam)))
    {
        throw "A hely mar foglalt";
        return false;
    }

    kocsik[kocsiSzam]-> OccupySeat(helySzam);
    return true;
}

Vonat& Vonat::operator=(const Vonat &vt)
    {
        if (this != &vt)
        {
            for (size_t i = 0; i < kocsikSzama; i++)
                delete kocsik[i];
            delete[] kocsik; 
        
            
            kocsikSzama = vt.kocsikSzama;
            kocsik = new Kocsi*[kocsikSzama];
            for (size_t i = 0; i < kocsikSzama; i++)
                kocsik[i] = new Kocsi(*vt.kocsik[i]);
            
            indulas = vt.indulas;
            erkezes = vt.erkezes;
            kezdo = vt.kezdo;
            vegzo = vt.vegzo;
            vonatszam = vt.vonatszam;
        }
        return *this;
    }

