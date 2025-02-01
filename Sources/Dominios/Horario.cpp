#include "../../Includes/Dominios/Horario.hpp"

void Horario::validar(string valor)
{

  int dividePos = valor.find(":");


  if (!dividePos)
  {
    throw invalid_argument("Argumento invalido.");
  }

  string StringHora = valor.substr(0, dividePos);
  string StringMinuto = valor.substr(dividePos + 1, -1);


  if (StringHora.length() != 2 || StringMinuto.length() != 2)
  {
    throw invalid_argument("Argumento invalido.");
  }


  for (char c : StringHora)
  {
    if (!isdigit(c))
    {
        throw invalid_argument("Argumento invalido.");
    }
  }


  for (char c : StringMinuto)
  {
    if (!isdigit(c))
    {
        throw invalid_argument("Argumento invalido.");
    }
  }

  int Hora = stoi(StringHora);
  int Minuto = stoi(StringMinuto);

  if (Hora < 0 || Hora > HoraMaxima || Minuto < 0 || Minuto > MinutoMaximo)
  {
    throw invalid_argument("Argumento invalido.");
  }
}