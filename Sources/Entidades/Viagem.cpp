#include "../../Includes/Entidades/Viagem.hpp"

Viagem::Viagem(const Codigo &codigo, const Nome &nome, const Avaliacao &avaliacao)
    : codigo(codigo), nome(nome), avaliacao(avaliacao) {}

void Viagem::set(const Dominio &Dominio, string NomeProprio)
{
    if (NomeProprio == "codigo")
    {
        this->codigo = static_cast<const Codigo &>(Dominio);
    }
    else if (NomeProprio == "nome")
    {
        this->nome = static_cast<const Nome &>(Dominio);
    }
    else if (NomeProprio == "avaliacao")
    {
        this->avaliacao = static_cast<const Avaliacao &>(Dominio);
    }
    else
    {
        throw invalid_argument("Tipo desconhecido para o domínio fornecido");
    }
}

const Dominio &Viagem::get(const string NomeProprio) const
{
    if (NomeProprio == "codigo")
    {
        return this->codigo;
    }
    else if (NomeProprio == "nome")
    {
        return this->nome;
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
