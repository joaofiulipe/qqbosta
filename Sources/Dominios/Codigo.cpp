#include <cstdlib>
#include <ctime>

#include "../../Includes/Dominios/Codigo.hpp"

void Codigo::validar(string valor)
{
  if (valor.length() != TamanhoCodigo)
  {
    throw invalid_argument("Argumento invalido.");
  }

  for (int i = 0; i < 6; i++)
  {
    if (!isalnum(valor[i]))
    {
      throw invalid_argument("Argumento invalido.");
    }
  }
};

Codigo::Codigo()
{
  string CodigoAleatorio = GerarCodigoAleatorio();
  setValor(CodigoAleatorio);
}

string Codigo::GerarCodigoAleatorio()
{
  const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  const int alphanumTamanho = sizeof(alphanum) - 1;

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(0, alphanumTamanho - 1);

  string CodigoAleatorio;
  for (int i = 0; i < TamanhoCodigo; i++)
  {
    CodigoAleatorio += alphanum[dis(gen)];
  }
  return CodigoAleatorio;
}