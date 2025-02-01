
#include "../../Includes/Dominios/Senha.hpp"

void Senha::validar(std::string valor)
{
    if (valor.length() != 5)
    {
        throw invalid_argument("Argumento invalido.");
    }

    for (char c : valor)
    {
        if (!isdigit(c))
        {
            throw invalid_argument("Argumento invalido.");
        }
    }

    std::set<char> digitosUnicos(valor.begin(), valor.end());
    if (digitosUnicos.size() != 5)
    {
        throw invalid_argument("Argumento invalido.");
    }

    bool eCrescente = true;
    for (size_t i = 1; i < valor.size(); ++i)
    {
        if (valor[i] != valor[i - 1] + 1)
        {
            eCrescente = false;
            break;
        }
    }
    if (eCrescente)
    {
        throw invalid_argument("Argumento invalido.");
    }

    bool eDecrescente = true;
    for (size_t i = 1; i < valor.size(); ++i)
    {
        if (valor[i] != valor[i - 1] - 1)
        {
            eDecrescente = false;
            break;
        }
    }
    if (eDecrescente)
    {
        throw invalid_argument("Argumento invalido.");
    }
}
