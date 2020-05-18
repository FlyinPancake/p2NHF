#ifndef ALLOMAS_HPP
#define ALLOMAS_HPP

#include <string>
#include <iostream>

using std::string;
class Allomas
{
public:

    /**
     * 
     * @param  {allomasNev} undefined : Álloműas neve
     * @return {Allomas(string}       
     */
    Allomas(string allomasNev) : nev(allomasNev) {}
    
    /**
     * 
     * @param  {Allomas} rhs  
     * @return {bool}        
     */
    bool operator==(const Allomas& rhs) { return (rhs.nev == nev); }
    /**
     * 
     * @param  {Allomas} rhs : 
     * @return {bool}        : 
     */
    bool operator!=(const Allomas& rhs) { return (rhs.nev != nev); }
    
    /**
     * 
     * @param  {std::ostream} os 
     * @param  {Allomas} all 
     * @return {std::ostream} 
     */
    friend std::ostream &operator<<(std::ostream& os,const Allomas &all)
    {
        os << "Allomas: " << all.nev;
        return os;
    }
    
private:
    string nev;
};  


#endif // !ALLOMAS_HPP
