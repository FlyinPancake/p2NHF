#ifndef ALLOMAS_HPP
#define ALLOMAS_HPP

class Allomas
{
public:
    Allomas();
    Allomas(Allomas &&) = default;
    Allomas(const Allomas &) = default;
    Allomas &operator=(Allomas &&) = default;
    Allomas &operator=(const Allomas &) = default;
    ~Allomas();

private:
    
};

#endif // !ALLOMAS_HPP