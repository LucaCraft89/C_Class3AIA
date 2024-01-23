#include <iostream>
#include <vector>

int main() {
    std::vector<int> schedina{1, 2, 3, 4, 5}; // Inserisci qui i numeri della tua schedina

    std::cout << "Benvenuto al gioco delle schedine!" << std::endl;

    // Genera i numeri casuali per la schedina vincente
    std::vector<int> schedinaVincente;
    for (int i = 0; i < 5; i++) {
        int numeroCasuale = rand() % 10 + 1; // Genera un numero casuale da 1 a 10
        schedinaVincente.push_back(numeroCasuale);
    }

    // Stampa la schedina vincente
    std::cout << "La schedina vincente è: ";
    for (int numero : schedinaVincente) {
        std::cout << numero << " ";
    }
    std::cout << std::endl;

    // Controlla se la schedina del giocatore ha fatto bingo
    int numeriIndovinati = 0;
    for (int numero : schedina) {
        if (std::find(schedinaVincente.begin(), schedinaVincente.end(), numero) != schedinaVincente.end()) {
            numeriIndovinati++;
        }
    }

    // Stampa il risultato
    std::cout << "Hai indovinato " << numeriIndovinati << " numeri!" << std::endl;

    return 0;
}
