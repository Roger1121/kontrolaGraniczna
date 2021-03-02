# kontrolaGraniczna

Zostałeś powołany do niezwykle ważnego, ale i odpowiedzialnego zadania. Ponieważ jesteśmy w strefie Schengen, kontrole graniczne zostały zniesione. Państwo nie może jednak pozwolić na
całkowicie niekontrolowane przekraczanie granic Polski - zapadła więc decyzja o rejestracji pojazdów wjeżdżających do kraju i wyjeżdżających z niego w specjalnej bazie danych, co pozwoli na
łatwe namierzenie ewentualnych terrorystów przewożących wzbogacony uran. Posłużą ku temu dwie kamery ustawione na specjalnej bramownicy znajdującej się nad dwupasmową jezdnią, gdzie
jedna będzie skierowana do przodu, a druga do tyłu. Znajdzie się tam też detektor rejestrujący czas rozpoznania i prędkość pojazdu. Wszystko będzie obsługiwane przez rewolucyjny, inteligentny
system, który po otrzymaniu obrazu z kamery wykryje znajdujące się na nim pojazdy. Twoje zadanie to dopasowanie samochodu wykrytego przez tylną kamerę do rozpoznania z przedniej
kamery. Samochody osobowe mają takie same rejestracje z przodu i z tyłu, ale wśród samochodów ciężarowych mogą być one różne. Musisz też wziąć pod uwagę, że system nie jest nieomylny -
czasami mogą wystąpić drobne przekłamania w odczytanej rejestracji, np. różnica 1 lub 2 znaków. Wytyczne mówią, że Twój program ma najpierw próbować wyszukać identyczne rejestracje. Jeśli
się nie uda, a masz do czynienia z rozpoznaniem samochodu osobowego, musisz znaleźć najbardziej podobną rejestrację. W przypadku samochodów ciężarowych lub osobowych o tak
samo podobnych rejestracjach musisz natomiast przewidzieć, który samochód powinien pojawić się jako pierwszy na kamerze tylnej na podstawie posiadanych danych (musimy wziąć pod uwagę,
że pojazdy mogą się wyprzedzać).

Dla uproszczenia problemu zakładamy, że:
- prędkość pojazdu pozostaje niezmienna - samochód nie zwalnia i nie przyspiesza,
- wszystkie samochody są zawsze wykrywane zarówno przez kamerę przednią, jak i tylną,
- typ pojazdu, prędkość i czas są zawsze rozpoznane prawidłowo.

Dane wejściowe
W pierwszej linii podana jest liczba oczekiwanych rozpoznań (czyli par przód + tył) oraz odległość między strefą wykrywania z kamery przedniej i kamery tylnej podana w metrach. W kolejnych
liniach podane są rozpoznania zapisane w następującym formacie:
KAMERA TYP_POJAZDU REJESTRACJA PRĘDKOŚĆ CZAS_ROZPOZNANIA
gdzie:
KAMERA może przyjmować wartości: F (przednia) lub R (tylna).
TYP_POJAZDU może przyjmować wartość 1 (samochód osobowy bez przyczepki) lub 2 (samochód ciężarowy).
PRĘDKOŚĆ i CZAS_ROZPOZNANIA występują tylko w rozpoznaniach z kamer przednich (są to dane z detektora dołączone do informacji z kamery przedniej). PRĘDKOŚĆ wyrażana jest w km/h,
a CZAS_ROZPOZNANIA w milisekundach.

Dane wyjściowe
Wypisane w kolejnych liniach sparowane rozpoznania w formacie:
DOKLADNE/PRAWDOPODOBNE DOPASOWANIE (OSOBOWY/CIEZAROWY): REJESTRACJA PRZEDNIA - REJESTRACJA TYLNA 
Informacja o dokładnym rozpoznaniu ma się pojawiać tylko w przypadku, gdy mamy pełną zgodność tablic rejestracyjnych. Pozostałe przypadki to dopasowania prawdopodobne.

Przykład:
Dane wejściowe
10 100
F 1 AAA2222 120 98450
F 2 AAA1111 90 99200
F 2 BBB1111 95 100125
R 2 BBB1222
F 1 AAA1010 170 101300
F 2 CCC9999 90 102000
F 2 BBB1212 100 102300
F 2 XASD0000 101 102400
R 1 AAA1020
R 2 CCC9999
R 1 AAA2222
R 2 VVVV1111
F 2 CCC2121 89 102500
R 2 DDD0000
F 2 XXX1234 10 103000
F 2 XXX1334 90 103010
R 2 DDD1111
R 2 XXX1235
R 2 XXX1236
R 2 YYY1234

Dane wyjściowe:
PRAWDOPODOBNE DOPASOWANIE (CIEZAROWY): AAA1111 - BBB1222
PRAWDOPODOBNE DOPASOWANIE (OSOBOWY): AAA1010 - AAA1020
DOKLADNE DOPASOWANIE (CIEZAROWY): CCC9999 - CCC9999
DOKLADNE DOPASOWANIE (OSOBOWY): AAA2222 - AAA2222
PRAWDOPODOBNE DOPASOWANIE (CIEZAROWY): BBB1111 - VVVV1111
PRAWDOPODOBNE DOPASOWANIE (CIEZAROWY): BBB1212 - DDD0000
PRAWDOPODOBNE DOPASOWANIE (CIEZAROWY): XASD0000 - DDD1111
PRAWDOPODOBNE DOPASOWANIE (CIEZAROWY): CCC2121 - XXX1235
PRAWDOPODOBNE DOPASOWANIE (CIEZAROWY): XXX1334 - XXX1236
PRAWDOPODOBNE DOPASOWANIE (CIEZAROWY): XXX1234 - YYY1234
