#include "../../Includes/Dominios/Dinheiro.hpp"

void Dinheiro::validar(string valor)
{
    valor.erase(remove(valor.begin(), valor.end(), ' '), valor.end());

    if (valor.find(".") != string::npos && valor.find(",") != string::npos) 
    {
        valor.erase(remove(valor.begin(), valor.end(), '.'), valor.end());
        replace(valor.begin(), valor.end(), ',', '.');
    }

    if (!regex_match(valor, regex(R"(^\d+(\.\d{1,2})?$)")))
    {
        throw invalid_argument("Argumento invalido: formato incorreto.");
    }

    float quantidade = stof(valor);
    
    if (quantidade < DinheiroMinimo || quantidade > DinheiroMaximo)
    {
        throw invalid_argument("Argumento invalido.");
    }
}