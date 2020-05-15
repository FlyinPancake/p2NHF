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

class Palya {
    - Allomas** allomasLista
    - size_t hossz
    - size_t maxHossz
    - Vonat*[maxVon] vonatok
    - size_t vonatszam
    - size_t maxVona
    + Palya(maxHossz)
    + Palya(istream)
    + AddStation(string)
    + EditStation(string, size_t)
    + RemStation(size_t)
    + AddTrain(Vonat)
    + Save(ostream)
    + ~Palya()
}

Palya <-- Allomas

class Allomas {
	- std::string nev

    + Allomas(std::string, size_t)
    + bool operator==(Allomas)
    + bool operator!=(Allomas)
    + ~Allomas()
}

Palya <-- Vonat

class Vonat {
	- size_t vonatszam
	- Allomas* kezdo
	- Allomas* vegzo
	- std::tm indulas
	- std::tm erkezes

	- size_t kocsikSzama
	- Kocsi kocsik[kocsikSzama]

	+ Vonat()
	+ Vonat(Allomas *kezdo, Allomas *vegzo, std::tm indul, std::tm erkez)
	+ ~Vonat()
	+ bool IsValid()
}

Vonat <-- Kocsi

class Kocsi {
	- size_t helyekSzama
	- bool helyek[helyekSzama]

	+ Kocsi(size_t id, size_t helyekSz)
	+ ~Kocsi()
	+ bool CheckOcc(size_t hely)
	+ Occupy(size_t hely)
	+ operator[]()
}

Jegy <-- Vonat

class Jegy {
	- size_t szam
	- size_t helyekszama
	- bool helyek*[helyekszama]

	+ Jegy(Vonat*, size_t kocsi, size_t ules)
	+ Jegy(Jegy)
	+ ~Jegy()
	+ operator=()
	+ operator==()
	+ operator!=()
	+ operator<<()
}
```

## Megvalósítás


## TODO 

- [ ] `README.MD`
  - [x] class diagram
  - [ ] megvalósítás
  - [ ] osztályok leírása
  - [ ] TODO lista befejezése
  - [ ] lisence
- [ ] `vonat.cpp`
  - [x] Kocsi
  - [ ] Vonat
- [ ] `jegy.cpp`
- [ ] `allomas.cpp`
- [ ] `palya.cpp`
  - [ ] Mentés
  - [ ] Betöltés / létrehozás
- [x] `vonat.hpp`
- [x] `jegy.hpp`
- [x] `allomas.hpp`
- [x] `palya.hpp`
- [ ] `main.cpp`
  - Tesztek
    - [ ] Mentés
    - [ ] Jegykiadás 