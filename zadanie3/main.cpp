#include <concepts>
#include <iostream>
#include <cstddef>
#include <list>
#include <vector>

// TODO: Zdefiniuj IntegerContainer i funkcje count_positive.

int main()
{
    std::cout << "Zadanie 3 - Sprawdzanie kontenera\n";

    std::vector<int> numbers{-3, 0, 4, 7, -1};
    std::vector<int> empty;
    // std::cout << count_positive(numbers) << '\n';  // oczekiwane: 2
    // std::cout << count_positive(empty) << '\n';    // oczekiwane: 0

    return 0;
}
