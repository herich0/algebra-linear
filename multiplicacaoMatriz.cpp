#include <iostream>
#include <vector>

using namespace std;

// Função para multiplicação de matrizes
vector<vector<int>> multiplicarMatrizes(const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2) {
    int linhas1 = matriz1.size();
    int colunas1 = matriz1[0].size();
    int linhas2 = matriz2.size();
    int colunas2 = matriz2[0].size();

    // Verificar se as matrizes podem ser multiplicadas
    if (colunas1 != linhas2) {
        cerr << "Erro: As matrizes não podem ser multiplicadas." << endl;
        return {};
    }

    // Inicializar a matriz de resultado com zeros
    vector<vector<int>> resultado(linhas1, vector<int>(colunas2, 0));

    // Realizar a multiplicação
    for (int i = 0; i < linhas1; ++i) {
        for (int j = 0; j < colunas2; ++j) {
            for (int k = 0; k < colunas1; ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

// Função para imprimir uma matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& linha : matriz) {
        for (int elemento : linha) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

int main() {
    // Exemplo de matrizes para multiplicação
    vector<vector<int>> matriz1 = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> matriz2 = {{7, 8}, {9, 10}, {11, 12}};

    // Realizar a multiplicação
    vector<vector<int>> resultado = multiplicarMatrizes(matriz1, matriz2);

    // Imprimir as matrizes e o resultado
    cout << "Matriz 1:" << endl;
    imprimirMatriz(matriz1);

    cout << "\nMatriz 2:" << endl;
    imprimirMatriz(matriz2);

    cout << "\nResultado da multiplicação:" << endl;
    imprimirMatriz(resultado);

    return 0;
}