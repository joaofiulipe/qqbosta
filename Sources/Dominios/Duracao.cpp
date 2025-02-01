#include "../../Includes/Dominios/Duracao.hpp"

void Duracao::validar(string valor)
{

    for (char c : valor)
    {
        if (!isdigit(c))
        {
            throw invalid_argument("Valor inválido: Deve ser um número inteiro.");
        }
    }


    int Duracao = stoi(valor);


    if (Duracao < DuracaoMinima || Duracao > DuracaoMaxima)
    {
        throw invalid_argument("Argumento invalido.");
    }
}
