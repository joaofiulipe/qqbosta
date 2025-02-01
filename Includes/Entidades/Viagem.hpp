#ifndef VIAGEM_ENTITY_INTERFACE_H
#define VIAGEM_ENTITY_INTERFACE_H

#include "../Dominios/Codigo.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Data.hpp"
#include "../Dominios/Dinheiro.hpp"
#include "../Dominios/Avaliacao.hpp"
#include "./Entidade.hpp"

/**
 * @class Viagem
 * @brief Classe responsável pela representação de uma viagem.
 * 
 * Esta classe herda de Entidade e gerencia os atributos e operações relacionados a uma viagem.
 */
class Viagem : public Entidade
{
private:
    Codigo codigo; ///< Código da viagem.
    Nome nome; ///< Nome da viagem.
    Avaliacao avaliacao; ///< Avaliação da viagem.

public:
    /**
     * @brief Construtor da classe Viagem.
     * @param codigo Código da viagem.
     * @param nome Nome da viagem.
     * @param avaliacao Avaliação da viagem.
     */
    Viagem(const Codigo &codigo, const Nome &nome, const Avaliacao &avaliacao);

    /**
     * @brief Define o valor de um atributo da viagem.
     * @param dominio Objeto do tipo Dominio contendo o valor a ser definido.
     * @param NomeProprio Nome do atributo a ser definido.
     */
    void set(const Dominio &dominio, string NomeProprio) override;

    /**
     * @brief Obtém o valor de um atributo da viagem.
     * @param NomeProprio Nome do atributo a ser obtido.
     * @return const Dominio& Valor do atributo.
     */
    const Dominio &get(const string NomeProprio) const override;
};

#endif // VIAGEM_ENTITY_INTERFACE_H