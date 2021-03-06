#include "vonat.hpp"
#include <iostream>

// Kocsi

Kocsi::Kocsi(size_t helyekSz) : helyekSzama(helyekSz)
{
    helyek = new bool[helyekSzama];
    for (size_t i = 0; i < helyekSzama; i++)
    {
        helyek[i] = true;
    }
}

Kocsi::~Kocsi() { delete[] helyek;}

bool Kocsi::CheckOcc(size_t hely) { return helyek[hely]; }

bool &Kocsi::operator[](size_t hely) { return helyek[hely]; }

Kocsi& Kocsi::operator=(const Kocsi &kocsi)
    {
        if (this != &kocsi)
        {
            delete[] helyek;

            helyekSzama = kocsi.helyekSzama;
            helyek = new bool[helyekSzama];
            for (size_t i = 0; i < helyekSzama; i++)
            {
                helyek[i] = kocsi.helyek[i];
            }
            
        }
        return *this; 
    }
