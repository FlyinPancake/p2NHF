#ifndef JEGY_HPP
#define JEGY_HPP

#include "vonat.hpp"
#include <iostream>

class Jegy
{
private:
    Vonat *jarat;
    size_t kocsi;
    size_t ules; 
    bool validity;
public:

    /**
     * Jegy 
     * 
     * @param  {Vonat*} jarat : Vonatra mutató ptr.
     * @param  {size_t} kocsi : hanyadik kocsiba szól a jegy
     * @param  {size_t} ules  : hányas számú ülésre szól a jegy
     */
    Jegy(Vonat *jarat, size_t kocsi, size_t ules):  jarat(jarat),
                                                    kocsi(kocsi),
                                                    ules(ules), 
                                                    validity(false)
    {
        if(!(jarat -> IsVald()))
        {
            throw "Nem ervenyes VONAT"; 
            return;
        }

        validity = (jarat -> ReserveSeat(kocsi, ules));
    }
    
    /**
     * 
     * @param  {Jegy} rhs : 
     * @return {bool}     : 
     */
    bool operator==(const Jegy &rhs)
    {
        return (rhs.jarat == jarat && rhs.kocsi == kocsi && rhs.ules == ules);
    }
    
    /**
     * 
     * @param  {Jegy} rhs : 
     * @return {bool}     : 
     */
    bool operator!=(const Jegy &rhs);
    
    /**
     * 
     * @param  {std::ostream} os : 
     * @param  {Jegy} jgy        : 
     * @return {std::ostream}    : 
     */
    friend std::ostream operator<<(std::ostream &os, const Jegy& jgy);
    
    /**
     * 
     * @return {bool}  : 
     */
    bool GetValidity() { return validity; }

};

#endif // !
