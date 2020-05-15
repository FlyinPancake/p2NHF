#ifndef ALLOMAS_HPP
#define ALLOMAS_HPP

#include <string>
#include <iostream>

using std::string;
class Allomas
{
public:
    Allomas(string allomasNev) : nev(allomasNev) {}

    bool operator==(const Allomas& rhs)
    {
        return (rhs.nev == nev);
    }

    bool operator!=(const Allomas& rhs)
    {
        return (rhs.nev != nev);
    }

    friend std::ostream &operator<<(std::ostream& os,const Allomas &all)
    {
        os << "Allomas: " << all.nev;
        return os;
    }
    
private:
    string nev;
};  


#endif // !ALLOMAS_HPP



