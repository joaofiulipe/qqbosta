#include "../../Includes/Separador/Separador.hpp"

vector<string> Separador::split(const string &str, const char *delimitador)
{
  vector<string> Barras;
  string Barra;
  for (char ch : str)
  {
    if (ch == *delimitador)
    {
      if (!Barra.empty())
      {
        Barras.push_back(Barra);
        Barra.clear();
      }
    }
    else
    {
      Barra += ch;
    }
  }
  if (!Barra.empty())
  {
    Barras.push_back(Barra);
  }
  return Barras;
}