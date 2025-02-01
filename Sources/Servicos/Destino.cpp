#include "../../Includes/Servicos/Destino.hpp"

void ModeloDestino::Criar(Codigo &CodigoUsuario, Codigo &CodigoDestinoViagem, Destino &NovoDestino)
{

  ComandoSQL = "SELECT codigoconta FROM viagem WHERE codigo = '" + CodigoDestinoViagem.getValor() + "';";
  results.clear();
  this->Executar();

  if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
  {
    throw invalid_argument("Destino não existente ou pertencente a outra conta");
  }

  string CodigoConta = CodigoUsuario.getValor();
  string CodigoViagem = CodigoDestinoViagem.getValor();
  string CodigoDestino = NovoDestino.get("codigo").getValor();
  string NomeDestino = NovoDestino.get("nome").getValor();
  string ChegadaDestino = NovoDestino.get("chegada").getValor();
  string PartidaDestino = NovoDestino.get("partida").getValor();
  string AvaliacaoDestino = NovoDestino.get("avaliacao").getValor();


  ComandoSQL = "INSERT INTO destino (codigo, nome, chegada, partida, avaliacao, codigoviagem) VALUES ('" + CodigoDestino + "', '" + NomeDestino + "', '" + ChegadaDestino + "', '" + PartidaDestino + "', '" + AvaliacaoDestino + "', '" + CodigoViagem + "');";
  results.clear();
  this->Executar();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na criação do destino");
  }
}

void ModeloDestino::Atualizar(Codigo &CodigoUsuario, Codigo &CodigoDestino, Destino &DestinoAtualizado)
{

    ComandoSQL = "SELECT codigoviagem FROM destino WHERE codigo = '" + CodigoDestino.getValor() + "';";
    results.clear();
    this->Executar();

    if (results.empty()) {
        throw invalid_argument("Destino não encontrado");
    }

    string codigoviagem = results[0]["codigoviagem"];


    ComandoSQL = "SELECT codigoconta FROM viagem WHERE codigo = '" + codigoviagem + "';";
    results.clear();
    this->Executar();

    if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor()) {
        throw invalid_argument("Destino não existente ou pertencente a outra conta");
    }


    string NomeDestino = DestinoAtualizado.get("nome").getValor();
    string ChegadaDestino = DestinoAtualizado.get("chegada").getValor();
    string PartidaDestino = DestinoAtualizado.get("partida").getValor();
    string AvaliacaoDestino = DestinoAtualizado.get("avaliacao").getValor();

    ComandoSQL = "UPDATE destino SET nome = '" + NomeDestino + "', chegada = '" + ChegadaDestino +
                 "', partida = '" + PartidaDestino + "', avaliacao = '" + AvaliacaoDestino +
                 "' WHERE codigo = '" + CodigoDestino.getValor() + "';";
    results.clear();
    this->Executar();

    if (status != SQLITE_OK) {
        throw invalid_argument("Erro na atualização do destino");
    }
}


void ModeloDestino::Remover(Codigo &CodigoUsuario, Codigo &CodigoDestino)
{
  ComandoSQL = "SELECT codigoviagem FROM destino WHERE codigo = '" + CodigoDestino.getValor() + "';";
  results.clear();
  this->Executar();

  ComandoSQL = "SELECT codigoconta FROM viagem WHERE codigo = '" + results[0]["codigoviagem"] + "';";
  results.clear();
  this->Executar();

  if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
  {
    throw invalid_argument("Destino inexistente ou pertencente a outra conta");
  }

  ComandoSQL = "DELETE FROM destino WHERE codigo = '" + CodigoDestino.getValor() + "';";
  results.clear();
  this->Executar();
  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na remoção do destino");
  }
}

vector<Destino> ModeloDestino::Ler(Codigo &CodigoUsuario)
{
    ComandoSQL = "SELECT d.* FROM destino d INNER JOIN viagem v ON d.codigoviagem = v.codigo WHERE v.codigoconta = '" + CodigoUsuario.getValor() + "';";
    results.clear();
    this->Executar();

    if (status != SQLITE_OK)
    {
        throw invalid_argument("Erro na leitura dos destinos");
    }

    vector<Destino> destinos;
    for (size_t i = 0; i < results.size(); i++)
    {
        Codigo codigo = Codigo(results[i]["codigo"]);
        Nome nome = Nome(results[i]["nome"]);
        Data chegada = Data(results[i]["chegada"]);
        Data partida = Data(results[i]["partida"]);
        Avaliacao avaliacao = Avaliacao(results[i]["avaliacao"]);
        Destino destino = Destino(codigo, nome, chegada, partida, avaliacao);
        destinos.push_back(destino);
    }
    return destinos;
}