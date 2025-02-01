#include "../../Includes/Entidades/Conta.hpp"

Conta::Conta(const Codigo &codigo, const Senha &senha)
    : codigo(codigo), senha(senha) {}

void Conta::set(const Dominio &dominio, string NomeProprio)
{
    if (NomeProprio == "codigo")
    {
        this->codigo = static_cast<const Codigo &>(dominio);
    }
    else if (NomeProprio == "senha")
    {
        this->senha = static_cast<const Senha &>(dominio);
    }
    else
    {
        throw invalid_argument("Tipo desconhecido para o domínio fornecido");
    }
}

const Dominio &Conta::get(const string NomeProprio) const
{
  if (NomeProprio == "codigo")
  {
    return this->codigo;
  }
  else if (NomeProprio == "senha")
  {
    return this->senha;
  }
  else
  {
    throw invalid_argument("Propriedade desconhecida");
  }
}
