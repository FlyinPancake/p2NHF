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

    size_t HelyekSzama() { return helyekSzama; }
    
};

class Vonat
{
private:
    static size_t aktVonat;
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
     * @param  {Allomas*} kezdo   : PTR az állomásra, ahonnan a vonat indult
     * @param  {Allomas*} vegzo   : PTR az állomásra, ahova a vonat tart 
     * @param  {tm} indul         : Ind. ideje
     * @param  {tm} erkez         : Érk. ideje
     * @param  {size_t} kocsiszam : Hány db kocsiból áll a szerelvény
     * @param  {size_t} ulohely   : Egy vagonon belül hány ülőhely van
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
    bool IsVald() { return (vonatszam != 0); }
    
    bool ReserveSeat(size_t kocsiSzam, size_t helySzam);

    friend std::ostream& operator<<(std::ostream& os, Vonat vt) 
    {
        os << "Vonat szama: " << vt.vonatszam << std::endl
        << "Indulo " << *vt.kezdo << std::endl
        << "Erkezo " << *vt.vegzo << std::endl
        << "Indul: " << asctime(&vt.indulas)
        << "Erkezik: " << asctime(&vt.erkezes);

        return os;
    }
};

#endif // !VONAT_HPP
