#include <concepts>
#include <iostream>

// TODO: Napisz is_even z ograniczeniem std::integral.

int main()
{
    std::cout << "Zadanie 1 - Sprawdzanie parzystosci\n";
    std::cout << std::boolalpha;

    // std::cout << is_even(4) << '\n';    // oczekiwane: true
    // std::cout << is_even(7) << '\n';    // oczekiwane: false
    // std::cout << is_even(10L) << '\n';  // oczekiwane: true
    // std::cout << is_even(13L) << '\n';  // oczekiwane: false
    // is_even(4.5);

    return 0;
}
