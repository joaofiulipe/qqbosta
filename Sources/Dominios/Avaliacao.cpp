#include "../../Includes/Dominios/Avaliacao.hpp"

void Avaliacao::validar(string valor)
{
    int NovaAvaliacao = stoi(valor);

    if (NovaAvaliacao < 0 || NovaAvaliacao > 5)
    {
        throw invalid_argument("Argumento invalido.");
    }
}
