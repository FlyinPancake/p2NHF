#ifndef VONAT_HPP
#define VONAT_HPP

#include "allomas.hpp"
#include <ctime>

class Kocsi
{
private:
    const size_t szam;
    const size_t helyekSzama;
    bool *helyek; 
public:

    /**
     * Kocsi 
     * 
     * @param  {size_t} id       : 
     * @param  {size_t} helyekSz : 
     * 
     * Letrehoz egy Kocsi peldanyt, ugy hogy minden ules szabad.
     */
    Kocsi(size_t id, size_t helyekSz);
    /**
     * ~Kocsi 
     * 
     * Kocsi DTor, torli a memoriabol a helyeket tartalmazo tombot
     */
    ~Kocsi();

    /**
     * 
     * @param  {size_t} hely : 
     * @return {bool}        :
     * 
     * visszaadja hogy szabad-e a hely 
     */
    bool CheckOcc(size_t hely);

    /**
     * 
     * @param  {size_t} hely : 
     * @return {bool}        : 
     * 
     * irhatunk a hely tombbe kozvetlenul
     */
    bool &operator[](size_t hely);

    /**
     * 
     * @param  {size_t} hely : 
     * 
     * lefoglalja a parameterben kapott helyet
     */
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