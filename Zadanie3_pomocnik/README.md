# Zadanie "Mechaniczny pomocnik"

## Treść zadania

Ula odkąd pamięta wszystkie prace w ogrodzie robi ręcznie. Sama przygotowuje ogrodowe kompozycje wykorzystując tylko podstawowe narzędzia. Jej ogród od pewnego czasu niezwykle powiększył swój rozmiar. Olbrzymia ilość pracy spowodowała u naszej bohaterki ból kręgosłupa. Należało działać jak najszybciej.

Ula musiała coś zrobić aby ratować resztki swojego nadszarpniętego zdrowia. Zobaczyła ofertę firmy Cybertron. Oferują oni robotycznego ogrodnika który wedle swojego machine learningowego poczucia estetyki wykona nasadzenia za naszą bohaterkę. Ula jednak nie ufa blaszakowi który od pewnego czasu porusza się po jej działce. Zaczęła studiować w jaki sposób funkcjonuje jej robot.

Okazuje się, że nasz mechaniczny przyjaciel pogrupował rośliny w kilka zapętlonych list. To natomiast pozwala na stworzenie listy gatunków. Posiada on zatem pewną listę gatunków a każdy gatunek jest listą roślin. Oprócz tego każda roślina ma ustaloną przestrzeń którą zajmie na rabacie. Jego robotyczne upodobanie do przepychu wymusza, żeby podczas każdego sadzenia wziął dokładnie jedną roślinę z każdego dostępnego gatunku. Robot jest perfekcjonistą i musi idealnie wypełnić powierzchnię rabaty. To znaczy, że musi znaleźć takie dopasowanie roślin, żeby suma ich wymaganych powierzchni była dokładnie taka jak jeden z dostępnych rozmiarów rabatek. Oczywiście na każdej z nich sadzi rośliny tylko raz. Ula jednak wciąż zastanawiała się w jaki sposób jej mechaniczny towarzysz wybiera rośliny do zasadzenia. Okazuje się, że generuje on pewien sygnał sterujący. Jego elektroniczny mózg tworzy pary liczb mówiące do którego gatunku powinien przejść, a następnie którą roślinę z listy wybrać. To znaczy, że wykonuje odpowiednią ilość ruchów do przodu lub do tyłu od ostatnio przeglądanej pozycji na liście gatunków w kolejności w której zostały dodane, a następnie porusza się w analogiczny sposób na samej liście roślin. Ruch zgodnie z otrzymaną instrukcją jest wykonywany jedynie jeżeli suma przestrzeni które potrzebują rośliny nie pasuje do żadnej z pozostałych rabat. To znaczy, że zawsze przed wykonaniem wspomnianej operacji najpierw sprawdza, czy aktualne ustawienie nie pasuje do którejś z rabat. Jeżeli suma wymaganych powierzchni wszystkich wybranych roślin (po jednej z każdego pozostałego gatunku) odpowiada którejś z niezasadzonych rabat, rozpoczyna się sadzenie. Oczywiście każda z roślin może być wykorzystana tylko raz. Po zasadzeniu rośliny wybieramy kolejną z listy zgodnie z kolejnością w jakiej zostały dodane. Jeżeli rośliny z danego gatunku się skończą wtedy należy usunąć go z listy. Naturalnie może zdarzyć się sytuacja w której rabata nie zostanie w ogóle zasadzona ponieważ robot nie znajdzie roślin idealnie ją wypełniających i skończą mu się pomysły jak ustawiać je w dalszym ciągu (sekwencja sterująca dobiegnie do końca).

Ula chciałaby upewnić się że rośliny zostaną estetycznie dobrane. Młotkiem wymusiła z blaszaka sygnał sterujący wskazujący na sposób dobierania roślin. Pomóż naszej bohaterce wyznaczyć kolejność sadzenia roślin na rabatach wykorzystując podany opis działania.

## Wejście:
W pierwszej linii wejścia program otrzymuje liczbę n określającą ilość list gatunków roślin. W kolejnych n liniach program otrzymuje n opisów dostępnych roślin. Każdy opis składa się z liczby m określającej początkową liczbę roślin w obrębie gatunku a następnie w m liniach pary składające się z ciągu znaków s będącego nazwą rośliny oraz liczby całkowitej c oznaczającej wymaganą powierzchnię. Następnie program otrzymuje liczbę l po czym l rozmiarów rabat w kolejności rosnącej. W dalszym kroku program otrzymuję sygnał sterujący rozpoczynając od liczby h a potem h par liczb całkowitych x i y gdzie x określa o ile list gatunków się przesunąć zgodnie a y o roślin przesunąć się na liście.

***1 ≤ n ≤ 5000***\
***1 ≤ c ≤ 1000***\
***-10000 ≤ x ≤ 10000***\
***-10000 ≤ y ≤ 10000***

## Wyjście:
Na wyjściu program powinien wyświetlić znaleziony rozmiar rabaty oraz ciąg nazw roślin. Rośliny zawsze są wyświetlane w kolejności w jakiej ich gatunki pojawiły się na wejściu.

## Przykładowe wejście 1:
```
3
3
Roza 2
Bratek 3
Piwonia 8
4
Sosna 1
Dab 6
Klon 5
Jesion 3
3
Bluszcz 1
Powojnik 6
Trzmielina 12
2
19
20
5
2 2
2 1
-1 1
2 1
2 1
```
## Przykładowe wyjście 1:
```
20 Roza Dab Trzmielina
19 Piwonia Klon Powojnik
```
### Ilustracja przykładu 1:
[Kliknij aby wyświetlić](https://drive.google.com/file/d/163SR-RzQ1UIi9GGhGui6dKKh0LCsENN4/view?usp=sharing)

## Przykładowe wejście 2:
```
3
1
Roza 1
2
Sosna 2
Dab 3
3
Bluszcz 4
Powojnik 5
Trzmielina 6
3
5
7
9
1
1 1
```
## Przykładowe wyjście 2:
```
7 Roza Sosna Bluszcz 
9 Dab Trzmielina 
5 Powojnik
```

### Ilustracja przykładu 2:
[Kliknij aby wyświetlić](https://drive.google.com/file/d/1GCWbW6ujYqLa5bgy8wF1RhN-TNC9DhSI/view?usp=sharing)

**Uwaga: Zadanie ma być samodzielną implementacją list bez wykorzystania bibliotek STL.**





