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
public:
    Jegy(Vonat *jarat, size_t kocsi, size_t ules);
    Jegy(const Jegy &j);
    ~Jegy();

    Jegy operator=(const Jegy &rhs);
    bool operator==(const Jegy &rhs);
    bool operator!=(const Jegy &rhs);
    std::ostream operator<<(const std::ostream &os) const;
};


#endif // !JEGY_HPP