# Nagy házi feladat dokumentáció
## Feladat

Tervezze meg egy vonatjegy eladó rendszer egyszerűsített objektummodelljét, majd valósítsa azt meg! A vonatjegy a feladatban mindig jegyet és helyjegyet jelent együtt. Így egy jegyen minimum a következőket kell feltüntetni:

- vonatszám, kocsiszám, hely
- indulási állomás, indulási idő
- érkezési állomás, érkezési idő

A rendszerrel minimum a következő műveleteket kívánjuk elvégezni:

- vonatok felvétele
- jegy kiadása

A rendszer később lehet bővebb funkcionalitású (pl. késések kezelése, vonat törlése, menetrend, stb.), ezért nagyon fontos, hogy jól határozza meg az objektumokat és azok felelősségét.
Valósítsa meg a jeggyel végezhető összes értelmes műveletet operátor átdefiniálással (overload), de nem kell ragaszkodni az összes operátor átdefiniálásához! A megoldáshoz **ne** használjon STL tárolót!

## Osztálydiagram

```mermaid
classDiagram
Palya <|-- Allomas
Palya : - Allomas* allomasLista
Palya : - size_t hossz
Palya : - size_t maxHossz
Palya : - Vonat[maxVon] vonatok
Palya : - size_t vonatszam
Palya : - size_t maxVona
Palya : + Palya(maxHossz)
Palya : + Palya(istream)
Palya : + AddStation(string)
Palya : + EditStation(string, size_t)
Palya : + RemStation(size_t)
Palya : + AddTrain(Vonat)
Palya : + Save(ostream)

Allomas : - std::string nev
Allomas : + Allomas(std::string, size_t)
Allomas : + operator==(Allomas)
Allomas : + operator!=(Allomas)
Palya <|-- Vonat
Vonat : - size_t vonatszam
Vonat : - Allomas* kezdo
Vonat : - Allomas* vegzo
Vonat : - std::tm indulas
Vonat : - std::tm erkezes

Vonat : - size_t kocsikSzama
Vonat : - Kocsi kocsik[kocsikSzama]

Vonat : + Vonat()
Vonat : + Vonat(Allomas *kezdo, Allomas *vegzo, std::tm indul, std::tm erkez)
Vonat : + ~Vonat()


Vonat <|-- Kocsi
Kocsi : - size_t szam
Kocsi : - size_t helyekSzama
Kocsi : - bool helyek[helyekSzama]

Kocsi : + Kocsi()
Kocsi : + ~Kocsi()
Kocsi : + bool CheckOcc(size_t hely)
Kocsi : + Occupy(size_t hely)
Kocsi : + operator[]()

Jegy <|-- Vonat

Jegy : - size_t szam
Jegy : - size_t helyekszama
Jegy : - bool helyek[helyekszama]

Jegy : + Jegy(Vonat*, size_t kocsi, size_t ules)
Jegy : + Jegy(Jegy)
Jegy : + ~Jegy()
Jegy : + operator=()
Jegy : + operator==()
Jegy : + operator!=()
Jegy : + operator<<()

```

