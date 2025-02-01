#include "../../Includes/Dominios/Nome.hpp"

void Nome::validar(string nome)
{ 
    if (nome.length() > 30 || nome.empty())
    {
        throw invalid_argument("Argumento invalido.");
    }
}
