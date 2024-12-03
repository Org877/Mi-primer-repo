#include <iostream>
    #include <vector>
    #include <algorithm>
    
    using namespace std;
    
    // Función para mostrar la palabra con las letras adivinadas
    void mostrarPalabra(const string& palabraSecreta, const vector<char>& letrasAdivinadas) {
        for (char letra : palabraSecreta) {
            if (find(letrasAdivinadas.begin(), letrasAdivinadas.end(), letra) != letrasAdivinadas.end()) {
                cout << letra << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
    
    // Función para verificar si la palabra está completa
    bool palabraCompleta(const string& palabraSecreta, const vector<char>& letrasAdivinadas) {
        for (char letra : palabraSecreta) {
            if (find(letrasAdivinadas.begin(), letrasAdivinadas.end(), letra) == letrasAdivinadas.end()) {
                return false;
            }
        }
        return true;
    }
    
    int main() {
        string palabraSecreta = "sistemas"; // Palabra secreta a adivinar
        vector<char> letrasAdivinadas;      // Letras que has adivinado
        int intentosRestantes = 10;          // Número máximo de intentos
    
        cout << "Bienvenido al Juego del Ahorcado" << endl;
    
        // Ciclo principal del juego
        while (intentosRestantes > 0) {
            mostrarPalabra(palabraSecreta, letrasAdivinadas);
    
            // Pedir al usuario que ingrese una letra
            char letra;
            cout << "Ingresa una letra: ";
            cin >> letra;
    
            // Convertidor de letras minusculas y mayusculas
            letra = tolower(letra);
    
            // Verificar si la letra ya ha sido adivinada
            if (find(letrasAdivinadas.begin(), letrasAdivinadas.end(), letra) != letrasAdivinadas.end()) {
                cout << "¡Ya intentaste con esa letra!" << endl;
                continue;
            }
    
            // Agregar la letra a la lista de letras adivinadas
            letrasAdivinadas.push_back(letra);
    
            // Verificar si la letra es correcta
            if (palabraSecreta.find(letra) == string::npos) {
                intentosRestantes--;
                cout << "Letra incorrecta. Intentos restantes: " << intentosRestantes << endl;
            }
    
            // Verificar si el jugador ha ganado
            if (palabraCompleta(palabraSecreta, letrasAdivinadas)) {
                cout << "¡Ganaste! La palabra era: " << palabraSecreta << endl;
                break;
            }
    
            // Verificar si el jugador ha perdido
            if (intentosRestantes == 0) {
                cout << "Perdiste. La palabra era: " << palabraSecreta << endl;
            }
        }
    
        return 0;
    }
     