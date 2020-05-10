#include "vonat.hpp"


// Kocsi

Kocsi::Kocsi(size_t id, size_t helyekSz): szam(id), helyekSzama(helyekSz)
{
    helyek = new bool[helyekSzama];
    for(int i = 0; i < helyekSzama; i++)
    {
        helyek[i] = true;
    }   
}

Kocsi::~Kocsi()
{
    delete[] helyek;
} 

bool Kocsi::CheckOcc(size_t hely)
{
    return helyek[hely];
}

bool& Kocsi::operator[](size_t hely)
{
    return helyek[hely];
}

void Kocsi::Occupy(size_t hely) 
{ 
    helyek[hely] = false; 
}
 
