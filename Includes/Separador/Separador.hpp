#ifndef SEPARADOR_H
#define SEPARADOR_H

#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Separador
 * @brief Namespace contendo funções utilitárias para separação de strings.
 */
namespace Separador
{
    /**
     * @brief Função para dividir uma string em substrings com base em um delimitador.
     * @param str String a ser dividida.
     * @param delimitador Delimitador usado para dividir a string.
     * @return vector<string> Vetor contendo as substrings resultantes da divisão.
     */
    vector<string> split(const string &str, const char *delimitador);
}

#endif // SEPARADOR_H
