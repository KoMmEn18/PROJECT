# AIR HOCKEY CLONE

1. Tematyka gry
Jest to klon popularnej gry o nazwie Air Hockey dla 2 graczy. Do poruszania się w menu nalezy uzyc strzalek. Rozgrywka toczy sie do 5 punktow. Gracz nr 1 porusza sie strzalkami, natomiast gracz nr 2 uzywa WSAD'u. 

2. Zagadnienia w kodzie

Projekt obiektowy: 
- klasy (cały program)
- konstruktory, destruktory (np. w klasie Ball)
- konstruktor kopiujący (brak)
- deklaracja przyjaciela (klasa Ball)
- dziedziczenie (np. klasa Ball)
- polimorfizm (wskaznik na obiekt klasy Form, ktory odpowiada graczom, uzyty np. do drawowania graczy)
- klasa abstrakcyjna (klasa Form)
- czysto wirtualne metody (w klasie Form)

STL (brak - nie byłem w stanie znaleźć zastosowania w tym programie)

C++ 
- zakresowa pętla for (np. 37 linijka gameover.cpp)
- własny szablon klasy (lub funkcji) (1 linijka Actualgame.cpp)
- przeciążanie operatorów (62 linijka ball.cpp)
- wyjątki (np. 151 linijka actualgame.cpp)
- plik .h z deklaracja i .cpp z definicją metod (cały program)
- linker

3. Sposób uruchomienia
W celu zklonowania lokalnie nalezy uzyc: "git clone https://github.com/KoMmEn18/PROJECT.git"
W plikach znajduje sie program Makefile umozliwiajacy kompilacje i uruchomienie programu na komputerze. Musimy w nim jednak zaktualizac sciezke do biblioteki sfml. Komenda "make all" kompiluje program, a "make run" umozliwia jego uruchomienie. 