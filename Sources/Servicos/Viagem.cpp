#include "../../Includes/Servicos/Viagem.hpp"

void ModeloViagem::Criar(Codigo &CodigoUsuario, Viagem &NovaViagem)
{
  string CodigoConta = CodigoUsuario.getValor();
  string CodigoViagem = NovaViagem.get("codigo").getValor();
  string NomeViagem = NovaViagem.get("nome").getValor();
  string AvaliacaoViagem = NovaViagem.get("avaliacao").getValor();
  ComandoSQL = "INSERT INTO viagem (codigo, nome, avaliacao, codigoconta) VALUES ('" + CodigoViagem + "', '" + NomeViagem + "', '" + AvaliacaoViagem + "', '" + CodigoConta + "');";
  results.clear();
  this->Executar();
  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro criação da viagem");
  }
}

void ModeloViagem::Atualizar(Codigo &CodigoUsuario, Codigo &CodigoViagem, Viagem &ViagemAtualizada)
{
  ComandoSQL = "SELECT codigoconta FROM viagem WHERE codigo = '" + CodigoViagem.getValor() + "';";
  results.clear();
  this->Executar();

  if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
  {
    throw invalid_argument("Viagem não existente ou pertencente a outra conta");
  }

  string NomeViagem = ViagemAtualizada.get("nome").getValor();
  string AvaliacaoViagem = ViagemAtualizada.get("avaliacao").getValor();

  ComandoSQL = "UPDATE viagem SET nome = '" + NomeViagem + "', avaliacao = '" + AvaliacaoViagem + "' WHERE codigo = '" + CodigoViagem.getValor() + "';";
  results.clear();
  this->Executar();
  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro atualização da viagem");
  }
}

void ModeloViagem::Remover(Codigo &CodigoUsuario, Codigo &CodigoViagem)
{
  ComandoSQL = "SELECT codigoconta FROM viagem WHERE codigo = '" + CodigoViagem.getValor() + "';";
  results.clear();
  this->Executar();

  if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
  {
    throw invalid_argument("Viagem não existente ou pertencente a outra conta");
  }

  ComandoSQL = "DELETE FROM viagem WHERE codigo = '" + CodigoViagem.getValor() + "';";
  results.clear();
  this->Executar();
  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na remoção da viagem");
  }
}

vector<Viagem> ModeloViagem::LerTudo(Codigo &CodigoUsuario)
{
  ComandoSQL = "SELECT * FROM viagem WHERE codigoconta = '" + CodigoUsuario.getValor() + "';";
  results.clear();
  this->Executar();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na leitura das viagens");
  }

  vector<Viagem> Viagens;
  for (size_t i = 0; i < results.size(); i++)
  {
    Codigo codigo = Codigo(results[i]["codigo"]);
    Nome nome = Nome(results[i]["nome"]);
    Avaliacao avaliacao = Avaliacao(results[i]["avaliacao"]);
    Viagem viagem = Viagem(codigo, nome, avaliacao);
    Viagens.push_back(viagem);
  }
  return Viagens;
}

int ModeloViagem::ConsultaCusto(Codigo &CodigoUsuario, Codigo &CodigoViagem)
{
  ComandoSQL = "SELECT codigoconta FROM viagem WHERE codigo = '" + CodigoViagem.getValor() + "';";
  results.clear();
  this->Executar();

  if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
  {
    throw invalid_argument("Viagem não existente ou pertencente a outra conta");
  }

  ComandoSQL = "SELECT SUM(preco) AS custototalatividade FROM atividade WHERE codigodestino IN (SELECT codigo FROM destino WHERE codigoviagem = '" + CodigoViagem.getValor() + "');";
  results.clear();
  this->Executar();

  int CustoTotalAtividade = 0;
  if (status == SQLITE_OK && !results.empty() && results[0]["custototalatividade"] != "NULL")
  {
    CustoTotalAtividade= stoi(results[0]["custototalatividade"]);
  }

  ComandoSQL = "SELECT precodiaria, partida, chegada FROM hospedagem INNER JOIN destino ON hospedagem.codigodestino = destino.codigo WHERE destino.codigoviagem = '" + CodigoViagem.getValor() + "';";
  results.clear();
  this->Executar();

  int CustoTotalHospedagem = 0;
  if (status == SQLITE_OK && !results.empty())
  {
    for (size_t i = 0; i < results.size(); i++)
    {
      int PrecoDiaria = stoi(results[i]["precodiaria"]);
      Data chegada = Data(results[i]["chegada"]);
      Data partida = Data(results[i]["partida"]);
      int dias = Data::CalcularAlcanceDatas(chegada.getValor(), partida.getValor());
      CustoTotalHospedagem += PrecoDiaria * dias;
    }
  }

  return CustoTotalAtividade + CustoTotalHospedagem;
}

vector<Destino> ModeloViagem::ListaDestinos(Codigo &CodigoUsuario, Codigo &CodigoViagem)
{
  ComandoSQL = "SELECT codigoconta FROM viagem WHERE codigo = '" + CodigoViagem.getValor() + "';";
  results.clear();
  this->Executar();

  if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
  {
    throw invalid_argument("Viagem não existente ou pertencente a outra conta");
  }

  ComandoSQL = "SELECT * FROM destino WHERE codigoviagem = '" + CodigoViagem.getValor() + "';";
  results.clear();
  this->Executar();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na listagem de destinos");
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

Destino ModeloViagem::ConsultaDestino(Codigo &CodigoUsuario, Codigo &CodigoDestino)
{
  ComandoSQL = "SELECT codigoconta FROM destino WHERE codigo = '" + CodigoDestino.getValor() + "';";
  results.clear();
  this->Executar();

  if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
  {
    throw invalid_argument("Viagem não existente ou pertencente a outra conta");
  }

  ComandoSQL = "SELECT * FROM destino WHERE codigo = '" + CodigoDestino.getValor() + "';";
  results.clear();
  this->Executar();

  if (results.empty())
  {
    throw invalid_argument("Destino não encontrado");
  }

  Codigo codigo = Codigo(results[0]["codigo"]);
  Nome nome = Nome(results[0]["nome"]);
  Data chegada = Data(results[0]["chegada"]);
  Data partida = Data(results[0]["partida"]);
  Avaliacao avaliacao = Avaliacao(results[0]["avaliacao"]);
  Destino destino = Destino(codigo, nome, chegada, partida, avaliacao);

  return destino;
}

vector<Hospedagem> ModeloViagem::ListaHospedagems(Codigo &CodigoUsuario, Codigo &CodigoDestino)
{
  ComandoSQL = "SELECT codigoviagem FROM destino WHERE codigo = '" + CodigoDestino.getValor() + "';";
  results.clear();
  this->Executar();

  ComandoSQL = "SELECT codigoconta from viagem WHERE codigo = '" + results[0]["codigoviagem"] + "';";
  results.clear();
  this->Executar();

  if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
  {
    throw invalid_argument("Informações sobre viagem não existem ou pertencem a outra conta");
  }

  ComandoSQL = "SELECT * FROM hospedagem WHERE codigodestino = '" + CodigoDestino.getValor() + "';";
  results.clear();
  this->Executar();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro leitura das hospedagens");
  }

  vector<Hospedagem> hospedagens;
  for (size_t i = 0; i < results.size(); i++)
  {

    Codigo codigo = Codigo(results[i]["codigo"]);
    Nome nome = Nome(results[i]["nome"]);
    Dinheiro precodiaria = Dinheiro(results[i]["precodiaria"]);
    Avaliacao avaliacao = Avaliacao(results[i]["avaliacao"]);
    Hospedagem hospedagem = Hospedagem(codigo, nome, precodiaria, avaliacao);
    hospedagens.push_back(hospedagem);

  }
  return hospedagens;
}

vector<Atividade> ModeloViagem::ListaAtividades(Codigo &CodigoUsuario, Codigo &CodigoDestino)
{
  ComandoSQL = "SELECT codigoviagem FROM destino WHERE codigo = '" + CodigoDestino.getValor() + "';";
  results.clear();
  this->Executar();

  ComandoSQL = "SELECT codigoconta from viagem WHERE codigo = '" + results[0]["codigoviagem"] + "';";
  results.clear();
  this->Executar();

  if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
  {
    throw invalid_argument("Informações sobre viagem não existentes ou pertencente a outra conta");
  }

  ComandoSQL = "SELECT * FROM atividade WHERE codigodestino = '" + CodigoDestino.getValor() + "';";
  results.clear();
  this->Executar();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na leitura das atividades");
  }

  vector<Atividade> atividades;
  for (size_t i = 0; i < results.size(); i++)
  {
    Codigo codigo = Codigo(results[i]["codigo"]);
    Nome nome = Nome(results[i]["nome"]);
    Data data = Data(results[i]["data"]);
    Horario horario = Horario(results[i]["horario"]);
    Duracao duracao = Duracao(results[i]["duracao"]);
    Dinheiro preco = Dinheiro(results[i]["preco"]);
    Avaliacao avaliacao = Avaliacao(results[i]["avaliacao"]);
    Atividade atividade = Atividade(codigo, nome, data, horario, duracao, preco, avaliacao);
    atividades.push_back(atividade);
  }
  return atividades;
}