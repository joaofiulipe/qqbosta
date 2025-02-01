#include "../../Includes/Servicos/Conta.hpp"

bool ModeloConta::Autenticar(Codigo &CodigoUsuario, Senha &SenhaUsuario)
{
  ComandoSQL = "SELECT senha FROM conta WHERE codigo = '" + CodigoUsuario.getValor() + "';";
  results.clear();
  this->Executar();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na autenticação");
  }

  if (results.empty() || results[0]["senha"] != SenhaUsuario.getValor())
  {
    return false;
  }

  return true;
}

void ModeloConta::Criar(Codigo &CodigoUsuario, Senha &SenhaUsuario)
{
  ComandoSQL = "INSERT INTO conta (codigo, senha) VALUES ('" + CodigoUsuario.getValor() + "', '" + SenhaUsuario.getValor() + "');";
  results.clear();
  this->Executar();

  if (status != SQLITE_OK)
    throw invalid_argument("Erro na criação da conta");
}