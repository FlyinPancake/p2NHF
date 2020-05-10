#ifndef VONAT_HPP
#define VONAT_HPP

#include "allomas.hpp"
#include <ctime>

class Kocsi
{
private:
    size_t szam;
    size_t helyekSzama;
    bool helyek[]; 
public:
    Kocsi();
    ~Kocsi();
    bool CheckOcc(size_t hely);
    void Occupy(size_t hely);
};

class Vonat
{
private:
    size_t vonatszam;
    Allomas* kezdo;
    Allomas* vegzo;
    tm induls;
    tm erkezes; 

    size_t kocsikSzama;
    Kocsi kocsik[];
public:
    Vonat();
    Vonat(Allomas *kezo, Allomas *vegzo, tm indul, tm erkez);
    ~Vonat();
};





#endif // !VONAT_HPP