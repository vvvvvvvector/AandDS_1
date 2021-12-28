# Zadanie "Ogródki działkowe" (Dziel i zwyciężaj)

## Treść zadania

Nieopodal gospodarstwa Uli znajdują się pozostałości po starych ogródkach działkowych. Nasza bohaterka postanowiła przestudiować mapę tego miejsca. Według tutejszych opowieści początkowo było tam ***n*** działek o kształtach prostokątnych. Boki tych prostokątów były równoległe do osi współrzędnych, a rogi znajdowały się w punktach o całkowitych współrzędnych. Ogrodzenia działek nie przecinały się, ale mogły się ze sobą stykać. Z biegiem czasu właściciele zaczęli łączyć działki w większe, ale tylko wtedy, gdy złączenie ich również tworzyło prostokąt. W końcu pozostał jeden właściciel i jedna duża działka.

Początkowo także na terenie każdej działki stał prostokątny budynek (na przykład szopa lub altanka). Boki również były równoległe do osi współrzędnych, a rogi znajdowały się w punktach o całkowitych współrzędnych. Niektóre budynki mogły stykać się z granicami ogrodzenia lub bokami innych budynków. Niestety dzisiaj nie wiadomo już gdzie przebiegały początkowe granice działek.

Ula podejrzewa, że cała ta historia jest nieprawdziwa i chce sprawdzić, czy dla zadanego rozmieszczenia budynków podział działek jest możliwy.

## Wejście:
W pierwszej linii wejścia znajduje się liczba naturalna ***t*** - liczba testów.\
Następnie dla każdego testu znajduje się opis terytorium działkowego. Test składa się z liczby naturalnej ***n***, która oznacza liczbę budynków i działek. W kolejnych ***n*** liniach znajdują sie cztery liczby całkowite ***x<sub>1</sub>***,***y<sub>1</sub>***,***x<sub>2</sub>***,***y<sub>2</sub>***, które są współrzędnymi kolejnych budynków, gdzie ***x<sub>1</sub>*** i ***y<sub>1</sub>*** to współrzędne lewego dolnego rogu, a ***x<sub>2</sub>*** i ***y<sub>2</sub>*** - prawego górnego. Należy przyjąć, że budynki nie nachodzą na siebie.

***1 ≤ n ≤ 1000***\
***0 ≤ x<sub>1</sub>,y<sub>1</sub>,x<sub>2</sub>,y<sub>2</sub> ≤ 1000000000***

## Wyjście:
Na wyjściu dla każdego testu należy wypisać słowo ***TAK***, jeżeli dla tak rozstawionych budynków możliwe jest podzielenie terytorium na działki zgodnie z zasadami. Jeżeli nie można wykonać takiego podziału, należy wypisać słowo ***NIE***.

## Przykład:
### Wejście:
```
2
4
0 0 1 2
0 2 1 3
1 0 2 1
1 1 2 3
4
0 0 2 1
1 2 3 3
2 0 3 2
0 1 1 3
```
### Wyjście:
```
TAK
NIE
```

**Uwaga! Zadanie powinno być rozwiązane przy użyciu metody "dziel i zwyciężaj".**
