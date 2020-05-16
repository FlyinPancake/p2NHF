#ifndef VONAT_HPP
#define VONAT_HPP

#include "allomas.hpp"
#include <ctime>

class Kocsi
{
private:
    size_t helyekSzama;
    bool *helyek;
public:

    /**
     * Kocsi 
     * 
     */
    Kocsi() : helyekSzama(0),
              helyek(nullptr) {}

    /**
     * Kocsi 
     * 
     * @param  {size_t} helyekSz : 
     * 
     * Letrehoz egy Kocsi peldanyt, ugy hogy minden ules szabad.
     */
    Kocsi(size_t helyekSz);
    
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
    void OccupySeat(size_t hely) { helyek[hely] = false; }

    /**
     * 
     * @param  {size_t} hely : 
     * 
     * felszabaditja a parameterben kapott helyet
     */
    void FreeSeat(size_t hely) { helyek[hely] = true; }
};

class Vonat
{
private:
    size_t vonatszam;
    Allomas* kezdo;
    Allomas* vegzo;
    tm indulas;
    tm erkezes;

    size_t kocsikSzama;
    Kocsi **kocsik;
public:


    /**
     * Vonat 
     * 
     * @param  {Allomas*} kezdo    : 
     * @param  {Allomas*} vegzo   : 
     * @param  {tm} indul         : 
     * @param  {tm} erkez         : 
     * @param  {size_t} kocsiszam : 
     * @param  {size_t} ulohely   : 
     */
    Vonat(Allomas *kezdo, Allomas *vegzo, tm indul, tm erkez, size_t kocsiszam, size_t ulohely);
    
    /**
     * ~Vonat 
     * 
     */
    ~Vonat();

    /**
     * 
     * @return {bool}  : 
     * Ha ervenyes a vonat, igazat ad
     */
    bool IsVald();
    
};





#endif // !VONAT_HPP