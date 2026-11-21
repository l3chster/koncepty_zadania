# Koncepty C++20 - zadania

Treści zadań znajdziesz w [zadania.md](zadania.md). 

Rozwiązania wpisuj w plikach `zadanie1/main.cpp`–`zadanie5/main.cpp`.
Każdy zawiera komentarze TODO i zakomentowane przykłady wywołań.
Uzupełniaj kod, a następnie odkomentowuj przykłady. Początkowo programy
wypisują tylko tytuł zadania.

## Uruchamianie w IDE

Otwórz główny katalog jako projekt CMake, wybierz program `zadanie1`–`zadanie5`
i uruchom go. Możesz też otworzyć folder pojedynczego zadania jako osobny projekt.

## Uruchamianie w terminalu

Potrzebujesz CMake 3.16 lub nowszego i kompilatora obsługującego C++20.
Polecenia wykonuj w głównym katalogu projektu.

Każde zadanie możesz kompilować osobno. Przykład dla zadania 1:

### Windows

```powershell
cmake -S zadanie1 -B zadanie1/build
cmake --build zadanie1/build --config Debug
.\zadanie1\build\Debug\zadanie1.exe
```

Jeśli program powstał bez podfolderu `Debug`, uruchom
`.\zadanie1\build\zadanie1.exe`.

### Linux i macOS

```bash
cmake -S zadanie1 -B zadanie1/build -DCMAKE_BUILD_TYPE=Debug
cmake --build zadanie1/build
./zadanie1/build/zadanie1
```

Dla pozostałych zadań zamień `zadanie1` na `zadanie2`, `zadanie3`, `zadanie4`
lub `zadanie5`.

Po zmianach w kodzie ponownie wykonaj polecenie budowania i uruchom program.
