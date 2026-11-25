# Zadania - koncepty C++20

Zestaw obejmuje dwa najprostsze zadania, jedno konkretne zadanie dotyczące wyrażenia `requires` oraz dwa zadania praktyczne. Korzystaj ze standardu C++20.

## Zadanie 1 - Sprawdzanie parzystości (najprostsze)

Napisz funkcję szablonową `is_even`, która sprawdza, czy przekazana liczba jest parzysta. Ogranicz typ argumentu za pomocą gotowego konceptu `std::integral`.

Wymagania:

- Funkcja zwraca `bool`.
- Sprawdź działanie dla liczb parzystych i nieparzystych typu `int` oraz `long`.
- Sprawdź, jaki błąd kompilacji powoduje wywołanie z argumentem typu `double`.
  Następnie zakomentuj błędne wywołanie, aby program dało się zbudować.



## Zadanie 2 - Kwadrat liczby (najprostsze)

Zdefiniuj własny koncept `Number`, który dopuszcza typy całkowite oraz zmiennoprzecinkowe, ale wyklucza `bool`. Następnie napisz funkcję szablonową `square`, która korzysta z tego konceptu i zwraca kwadrat przekazanej liczby.

Wymagania:

- W definicji konceptu wykorzystaj `std::integral`, `std::floating_point` oraz `std::same_as`.
- Sprawdź funkcję dla argumentów typu `int` i `double`.
- Dodaj sprawdzenia `static_assert`, potwierdzające, że `int` i `double`
  spełniają koncept, a `bool` i `std::string` go nie spełniają.



## Zadanie 3 - Sprawdzanie kontenera (konkretne)

Zdefiniuj koncept `IntegerContainer`, który opisuje kontener liczb całkowitych. W wyrażeniu `requires` zastosuj wszystkie cztery rodzaje wymagań:

1. Wymaganie typowe: kontener udostępnia typ zagnieżdżony `value_type`.
2. Wymaganie proste: można odczytać element kontenera przez operator `[]`.
3. Wymaganie złożone: metoda `size()` jest oznaczona `noexcept`, a jej wynik jest konwertowalny na `std::size_t`.
4. Wymaganie zagnieżdżone: `value_type` spełnia koncept `std::integral`.

Operacje odczytu sprawdzaj dla kontenera przekazanego przez stałą referencję. Napisz funkcję `count_positive`, ograniczoną tym konceptem, która przyjmuje kontener przez stałą referencję i zwraca liczbę elementów większych od zera. Możesz założyć, że indeksowanie zwraca element zgodny z `value_type`.

Wymagania:

- Sprawdź wynik dla `std::vector<int>{-3, 0, 4, 7, -1}` — powinien wynosić `2`.
- Dla pustego kontenera funkcja powinna zwracać `0`.
- Za pomocą `static_assert` potwierdź, że `std::vector<int>` spełnia koncept,
  a `std::vector<double>` i `std::list<int>` go nie spełniają.



## Zadanie 4 - Koszyk zakupowy (praktyczne)

Napisz prosty koszyk zakupowy, który wykorzystuje koncept do sprawdzania, czy dany typ może być traktowany jako produkt. Przygotuj dwie niezależne struktury: `Book` i `Food`. Każda powinna zawierać publiczne pole `price` typu `double`, przechowujące cenę produktu. Zdefiniuj koncept `Product`, który za pomocą wyrażenia `requires` sprawdza, czy:

- Dla obiektu przekazanego przez stałą referencję można odczytać pole `price`.
- Odczytana wartość jest konwertowalna na `double` (możesz wykorzystać do tego
  `std::convertible_to<double>`).

Następnie napisz szablon klasy `Cart<T>`, który dopuszcza wyłącznie typy spełniające koncept `Product`.  

Wymagania dotyczące koszyka:

- Przechowuj produkty w polu typu `std::vector<T>`. 
- Dodaj publiczną metodę `add(const T& product)`, która umieszcza kopię produktu w koszyku.
- Dodaj publiczną metodę `double total() const`, która przechodzi po produktach i zwraca sumę ich cen.
- Dla pustego koszyka metoda `total()` powinna zwracać `0.0`.

W funkcji `main()`:

- Utwórz osobny koszyk `Cart<Book>` oraz osobny `Cart<Food>`.
- Dodaj do każdego co najmniej dwa produkty i wypisz łączny koszt.
- Utwórz pusty koszyk jedzenia i sprawdź, czy jego łączny koszt wynosi zero.

Dodaj sprawdzenia `static_assert`, potwierdzające, że `Book` i `Food` spełniają
koncept `Product`, a `int` go nie spełnia ( `static_assert(Product<type>);` lub `static_assert(!Product<type>);` ).


## Zadanie 5 - Drukowanie dokumentów (praktyczne)

Studenckie koło naukowe organizuje konferencję, podczas której członkowie zaprezentują swoje projekty. Przygotowania obejmują rezerwację sal, ustalenie programu i kontakt z prelegentami. Organizatorzy zapisują krótkie notatki, np. „Potwierdzić rezerwację auli”, oraz raporty podsumowujące postępy prac poszczególnych grup. Każdy raport zawiera nazwę grupy,
tytuł oraz treść opisującą wykonane zadania.

Pomóż zespołowi przygotować wspólną funkcję `print` do wypisywania tych dokumentów w konsoli. Dla notatki powinna pokazywać samą treść, a dla raportu także tytuł oraz nazwę grupy. Wybór odpowiedniej wersji funkcji pozostaw kompilatorowi, wykorzystując koncepty.

Przygotuj dwie struktury:

- `Note` - pole `content` i metoda `text()` zwracająca jego wartość.
- `Report` - pola `content`, `heading` i `group_name` oraz metody `text()`,
  `title()` i `group()`, zwracające odpowiednio treść, tytuł oraz nazwę grupy.

Pola powinny być publiczne i zadeklarowane w podanej wyżej kolejności. Pola i wyniki metod mają typ `std::string`. Metody oznacz jako `const`. Teksty zapisuj w polach przy tworzeniu obiektów lub pobieraj przez `std::getline`.

Przykładowe tworzenie obiektów:

```cpp
Note note{"Potwierdzic rezerwacje auli"};
Report report{"Ustalono kolejnosc wystapien", "Program konferencji", "Grupa_Bez_Konceptu"};
```

Wskazówki:

- Przy definiowaniu konceptów możesz wykorzystać wyrażenie `requires` do sprawdzania dostępności metod oraz `std::same_as` do sprawdzania typów zwracanych wartości.
- Pomocne mogą być dwa koncepty: ogólny dla dokumentu z treścią i bardziej szczegółowy dla dokumentu z tytułem oraz nazwą grupy. Ten drugi możesz zbudować przez rozszerzenie pierwszego.
- Różne sposoby wypisywania możesz zrealizować za pomocą dwóch przeciążeń `print`, ograniczonych odpowiednimi konceptami. Dzięki temu kompilator wybierze wersję pasującą do dokumentu.
- Dokumenty możesz przekazywać przez stałą referencję, a raport wypisywać w osobnych wierszach: tytuł, `Grupa: nazwa grupy` i treść.
- W `main()` warto pokazać działanie dla obu rodzajów dokumentów. Do sprawdzenia konceptów możesz dodatkowo użyć `static_assert`.
