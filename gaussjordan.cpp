#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void imprime(const vector<vector<double>>& matriz) {
    int linhas = matriz.size();
    int colunas = matriz[0].size();

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Use fixed e setprecision para evitar a exibição de -0
            cout << fixed << setprecision(0) << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void GaussJordan(vector<vector<double>>& matriz) {
    int linhas = matriz.size();
    int colunas = matriz[0].size();

    cout << "Matriz Inicial:" << endl;
    imprime(matriz);

    for (int i = 0; i < linhas; i++) {
        // Pivoteamento parcial
        int pivotRow = i;
        for (int j = i + 1; j < linhas; j++) {
            if (matriz[j][i] > matriz[pivotRow][i]) {
                pivotRow = j;
            }
        }
        swap(matriz[i], matriz[pivotRow]);

        cout << "Pivoteamento Parcial (linha " << i + 1 << " trocada com linha " << pivotRow + 1 << "):" << endl;
        imprime(matriz);

        // Escalonamento
        double pivot = matriz[i][i];
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] /= pivot;
        }

        cout << "Escalonamento (linha " << i + 1 << " dividida por " << pivot << "):" << endl;
        imprime(matriz);

        // Eliminação
        for (int j = 0; j < linhas; j++) {
            if (j != i) {
                double factor = matriz[j][i];
                for (int k = 0; k < colunas; k++) {
                    matriz[j][k] -= factor * matriz[i][k];
                }
                cout << "Eliminacao (linha " << j + 1 << " subtraida de " << factor << " vezes a linha " << i + 1 << "):" << endl;
                imprime(matriz);
            }
        }
    }
}

int main() {
    int n;
    cout << "Digite a ordem da matriz quadrada: ";
    cin >> n;

    // Leitura da matriz
    vector<vector<double>> matriz(n, vector<double>(n));
    cout << "Digite os elementos da matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    // Aplicação da eliminação de Gauss-Jordan
    GaussJordan(matriz);

    // Exibição da matriz resultante
    cout << "Matriz resultante:" << endl;
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(matriz[i][j] == -0){
                matriz[i][j] = 0;
            }
        }
    }

    imprime(matriz);

    return 0;
}
