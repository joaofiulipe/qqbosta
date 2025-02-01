#ifndef DESTINO_ENTITY_INTERFACE_H
#define DESTINO_ENTITY_INTERFACE_H

#include "../Dominios/Codigo.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Data.hpp"
#include "../Dominios/Avaliacao.hpp"
#include "./Entidade.hpp"

/**
 * @class Destino
 * @brief Classe responsável pela representação de um destino.
 * 
 * Esta classe herda de Entidade e gerencia os atributos e operações relacionados a um destino.
 */
class Destino : public Entidade
{
private:
    Codigo codigo; ///< Código do destino.
    Nome nome; ///< Nome do destino.
    Data chegada; ///< Data de chegada ao destino.
    Avaliacao avaliacao; ///< Avaliação do destino.
    Data partida; ///< Data de partida do destino.

public:
    /**
     * @brief Construtor da classe Destino.
     * @param codigo Código do destino.
     * @param nome Nome do destino.
     * @param chegada Data de chegada ao destino.
     * @param partida Data de partida do destino.
     * @param avaliacao Avaliação do destino.
     */
    Destino(const Codigo &codigo, const Nome &nome, const Data &chegada, const Data &partida, const Avaliacao &avaliacao);

    /**
     * @brief Define o valor de um atributo do destino.
     * @param dominio Objeto do tipo Dominio contendo o valor a ser definido.
     * @param NomeProprio Nome do atributo a ser definido.
     */
    void set(const Dominio &dominio, string NomeProprio) override;

    /**
     * @brief Obtém o valor de um atributo do destino.
     * @param NomeProprio Nome do atributo a ser obtido.
     * @return const Dominio& Valor do atributo.
     */
    const Dominio &get(const string NomeProprio) const override;
};

#endif // DESTINO_ENTITY_INTERFACE_H