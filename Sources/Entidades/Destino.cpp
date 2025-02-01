#include "../../Includes/Entidades/Destino.hpp"

Destino::Destino(const Codigo &codigo, const Nome &nome, const Data &chegada, const Data &partida, const Avaliacao &avaliacao)
    : codigo(codigo), nome(nome), chegada(chegada), partida(partida), avaliacao(avaliacao) {}

void Destino::set(const Dominio &dominio, string NomeProprio)
{
    if (NomeProprio == "codigo")
    {
        this->codigo = static_cast<const Codigo &>(dominio);
    }
    else if (NomeProprio == "nome")
    {
        this->nome = static_cast<const Nome &>(dominio);
    }
    else if (NomeProprio == "chegada")
    {
        this->chegada = static_cast<const Data &>(dominio);
    }
    else if (NomeProprio == "partida")
    {
        this->partida = static_cast<const Data &>(dominio);
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

const Dominio &Destino::get(const string NomeProprio) const
{
    if (NomeProprio == "codigo")
    {
        return this->codigo;
    }
    else if (NomeProprio == "nome")
    {
        return this->nome;
    }
    else if (NomeProprio == "chegada")
    {
        return this->chegada;
    }
    else if (NomeProprio == "partida")
    {
        return this->partida;
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
