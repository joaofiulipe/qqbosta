#include "../../Includes/Entidades/Atividades.hpp"

Atividade::Atividade(const Codigo &codigo, const Nome &nome, const Data &data, const Horario &horario, const Duracao &duracao, const Dinheiro &preco, const Avaliacao &avaliacao)
    : codigo(codigo), nome(nome), data(data), horario(horario), duracao(duracao), preco(preco), avaliacao(avaliacao) {}

void Atividade::set(const Dominio &dominio, string NomeProprio)
{
  if (NomeProprio == "codigo")
  {
    this->codigo = static_cast<const Codigo &>(dominio);
  }
  else if (NomeProprio == "nome")
  {
    this->nome = static_cast<const Nome &>(dominio);
  }
  else if (NomeProprio == "data")
  {
    this->data = static_cast<const Data &>(dominio);
  }
  else if (NomeProprio == "horario")
  {
    this->horario = static_cast<const Horario &>(dominio);
  }
  else if (NomeProprio == "Duracao")
  {
    this->duracao = static_cast<const Duracao &>(dominio);
  }
  else if (NomeProprio == "preco")
  {
    this->preco = static_cast<const Dinheiro &>(dominio);
  }
  else if (NomeProprio == "avaliacao")
  {
    this->avaliacao = static_cast<const Avaliacao &>(dominio);
  }
  else
  {
    throw invalid_argument("Tipo desconhecido para o domínio fornecido");
  }
}

const Dominio &Atividade::get(const string NomeProprio) const
{
  if (NomeProprio == "codigo")
  {
    return this->codigo;
  }
  else if (NomeProprio == "nome")
  {
    return this->nome;
  }
  else if (NomeProprio == "data")
  {
    return this->data;
  }
  else if (NomeProprio == "horario")
  {
    return this->horario;
  }
  else if (NomeProprio == "duracao")
  {
    return this->duracao;
  }
  else if (NomeProprio == "preco")
  {
    return this->preco;
  }
  else if (NomeProprio == "avaliacao")
  {
    return this->avaliacao;
  }
  else
  {
    throw invalid_argument("Propriedade desconhecida");
  }
}
