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
    Jegy(Vonat *jarat, size_t kocsi, size_t ules):  kocsi(kocsi), 
                                                    ules(ules), 
                                                    jarat(jarat),
                                                    validity(true)
    {
        if(!(jarat -> IsVald()))
        {
            throw "Nem ervenyes VONAT";
            return;
        }

        
    }
    
    /**
     * 
     * @param  {Jegy} rhs : 
     * @return {bool}     : 
     */
    bool operator==(const Jegy &rhs);
    
    /**
     * 
     * @param  {Jegy} rhs : 
     * @return {bool}     : 
     */
    bool operator!=(const Jegy &rhs);

    /**
     * 
     * @param  {std::ostream} os : 
     * @return {std::ostream}    : 
     */
    std::ostream operator<<(const std::ostream &os) const;
};

#endif // !JEGY_HPP