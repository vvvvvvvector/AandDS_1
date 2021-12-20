# Zadanie "Decyzyjny pomocnik"

## Treść zadania

Mechaniczny pomocnik niesamowicie spodobał się Uli. Jednak ostatnio zastanawiała się nad zrobieniem małej aktualizacji. Ula chciałaby, żeby jej robocik samodzielnie wykonywał pewne automatyczne czynności, jak podlewanie, nawożenie czy przycinanie.

Niestety nie jest to proste, ponieważ pomocnik działa w oparciu o kompletne drzewo decyzyjne. To znaczy, robot musi rozpoznać gatunek rośliny, z którą ma do czynienia i na tej podstawie użyć określonej ilości wody czy nawozu. Taka specyfikacja powinna być ułożona od gatunku najbardziej ogólnego, do najbardziej szczegółowego. Ula zdecydowała się rozdzielić wszystkie problemy w następujący sposób: stworzy pewne klasy główne, jak Owoce, Warzywa, Drzewa, Krzewy, którym ponadaje numery porządkowe. W ramach klas głównych utworzy kolejne podklasy (na przykład dla klasy Warzyw będą to Liściaste, Bulwiaste, itp.), którym także ponadaje numery (numery te nie mogą się powtarzać tylko w ramach tej samej klasy). Podklasy mogą się dzielić na kolejne podklasy, te na dalsze podklasy, i tak dalej. Na każdym poziomie szczegółowości może się znaleźć instrukcja, którą powinien zastosować mechaniczny pomocnik. Na przykład wszystkie gatunki z klasy "Drzewka owocowe" klasy "Drzewa" wymagają podcięcia gałązek na wiosnę, a gatunki z klasy "Drzewa brzoskwini" w tej klasie ("Drzewa" -> "Drzewka owocowe" -> "Drzewka brzoskwiniowe") wymagają użycia dedykowanego nawozu dla drzewek brzoskwini.

Ula zaczęła dodawać kolejne instrukcje swojemu pomocnikowi, wskazując ścieżkę klas i podklas, do których dane instrukcje się stosują. Dla ułatwienia komunikacji z robotem klasy zastąpiła wybranymi wcześniej numerami porządkowymi. Korzeniem drzewa decyzyjnego jest klasa nadrzędna o numerze 0 i nazwie procedury "Stan spoczynku".

## Wejście:
Na wejściu dostajemy liczbę naturalną ***n***, oznaczającą liczbę instrukcji, które Ula chce wprowadzić do drzewa decyzyjnego. Następnie otrzymujemy ***n*** instrukcji. Każda składa się z dwóch linii: łańcucha napisowego (z opisem procedury, którą ma wykonać robot) oraz liczby naturalnej ***k***, po której następuje ***k*** liczb naturalnych ***{k<sub>1</sub>...k<sub>k</sub>}***. Te liczby odpowiadają numerom klas, które Ula ustaliła wcześniej i są tak zwaną ścieżką w drzewie decyzyjnym prowadzącą od korzenia (0 - Stan spoczynku) aż do podklasy ***k<sub>k</sub>***, dla której dodawany jest opis (***k<sub>1</sub>*** jest główną klasą podpiętą pod korzeń drzewa decyzyjnego). Jeśli podczas dodawania do drzewa decyzyjnego okaże się, że któraś klasa pośrednia nie została jeszcze dodana do drzewa, należy ją utworzyć i jako opis ustawić literę ***X***. Jeżeli dla danej ścieżki istnieje już opis procedury, należy go nadpisać (zmianie podlega jedynie opis, struktura drzewa pozostaje bez zmian). Nowe gałęzie w ramach klasy dopinane są po kolei w kolejności pojawienia się na wejściu. W ostatniej linii wejścia znajduje się liczba naturalna ***x ∈ {1,2}***, determinująca sposób wyświetlenia drzewa (1 - preorder, 2 - postorder).

***0 ≤ n ≤ 10000***\
***1 ≤ k ≤ 100***

## Wyjście:
Na wyjściu należy wyświetlić całe drzewo decyzyjne.

## Przykład:
### Wejście:
```
9
Spryskaj liscie woda co 3 dni
2 5 7
Podlej 2 litrami wody co 2 dni
1 2
Przykryj grzadki na zime
1 5
Zgrab liscie dookola 2 razy w roku
2 1 2
Uzyj 10 ml nawozu dla roz
3 1 5 3
Uzyj 20 ml nawozu dla drzew owocowych
2 5 1
Oslon kore przed zajoncami na wiosne
2 1 5
Oslon kore przed zajacami na wiosne
2 1 5
Przekop grzadki raz w roku
1 1
2
```
### Wyjście:
```
Spryskaj liscie woda co 3 dni
Uzyj 20 ml nawozu dla drzew owocowych
Przykryj grzadki na zime
Podlej 2 litrami wody co 2 dni
Zgrab liscie dookola 2 razy w roku
Uzyj 10 ml nawozu dla roz
Oslon kore przed zajacami na wiosne
Przekop grzadki raz w roku
Stan spoczynku
```

### Ilustracja przykładowej struktury drzewiastej:
[Kliknij aby wyświetlić](https://drive.google.com/file/d/1etA5kgscIFqbPpEtMbMGxYxjrU6Ydct1/view?usp=sharing)

**Uwaga! Zadanie ma być samodzielną implementacją struktury drzewiastej. Nie można używać bibliotek STL.**