#ifndef ALLOMAS_HPP
#define ALLOMAS_HPP

#include <string>
using std::string;
class Allomas
{
public:
    Allomas(string allomasNev, int sorszam);
    ~Allomas();
    bool operator==(const Allomas& rhs);
private:
    string nev;
};

#endif // !ALLOMAS_HPP