# Zadanie "System nawadniania" (Backtracking)

## Treść zadania

Na ostatnich zbiorach jabłek Uli udało się zarobić dość pieniędzy, by wyposażyć swój sad w nowy system nawadniający. Ula musi wybrać spośród ***n*** stanowisk nawadniających. Dla Uli nie bez znaczenia jest estetyka wybranych rozwiązań. Niektóre stanowiska są brzydsze, inne ładniejsze. Każde stanowisko ***n<sub>i</sub>*** zmienia poziom estetyki w sadzie o wartość ***s<sub>i</sub>***, a jego montaż generuje koszt ***c<sub>i</sub>***. Ula zakłada, że idealny poziom estetyki jest równy 0 (taki, jaki jest obecnie przed montażem systemu). Które z proponowanych stanowisk Ula powinna wybrać, by osiągnąć idealny poziom estetyki przy jak najmniejszym koszcie?

## Wejście:
Na wejściu program otrzyma liczbę całkowita ***t***, która oznacza liczbę testów.\
Dalej znajduje się ***t*** zestawów danych, z których każdy składa się z liczby naturalnej ***n***, oznaczającej liczbę stanowisk oraz ***n*** linii, które opisują stanowiska. Opis składa się z dwóch liczb całkowitych ***s<sub>i</sub>*** i ***c<sub>i</sub>***, gdzie ***s<sub>i</sub>*** informuje o tym, jak zmieni się poziom estetyki sadu po zamontowaniu danego stanowiska, a ***c<sub>i</sub>*** jest kosztem montażu.

***1 ≤ t ≤ 10***\
***1 ≤ n ≤ 100***\
***-10000 ≤ s ≤ 10000***\
***0 ≤ c ≤ 10000***

## Wyjście:
Na wyjściu dla każdego testu program ma wypisać minimalny koszt montażu stanowisk, przy założeniu, że ustawienie ich nie zmieni idealnego poziomu estetyki. Jeśli nie istnieje takie ustawienie program ma wypisać słowo "NIE".

## Przykład:
### Wejście:
```
2
4
-10 2
3 3
10 9
7 3
4
1 7
3 3
-2 6
-5 2
```
### Wyjście:
```
8
NIE
```
