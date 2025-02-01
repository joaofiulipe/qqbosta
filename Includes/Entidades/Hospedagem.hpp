#ifndef HOSPEDAGEM_ENTITY_INTERFACE_H
#define HOSPEDAGEM_ENTITY_INTERFACE_H

#include "../Dominios/Codigo.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Dinheiro.hpp"
#include "../Dominios/Avaliacao.hpp"
#include "./Entidade.hpp"

/**
 * @class Hospedagem
 * @brief Classe responsável pela representação de uma hospedagem.
 * 
 * Esta classe herda de Entidade e gerencia os atributos e operações relacionados a uma hospedagem.
 */
class Hospedagem : public Entidade
{
private:
    Codigo codigo; ///< Código da hospedagem.
    Nome nome; ///< Nome da hospedagem.
    Dinheiro precodiaria; ///< Preço da diária da hospedagem.
    Avaliacao avaliacao; ///< Avaliação da hospedagem.

public:
    /**
     * @brief Construtor da classe Hospedagem.
     * @param codigo Código da hospedagem.
     * @param nome Nome da hospedagem.
     * @param precodiaria Preço da diária da hospedagem.
     * @param avaliacao Avaliação da hospedagem.
     */
    Hospedagem(const Codigo &codigo, const Nome &nome, const Dinheiro &precodiaria, const Avaliacao &avaliacao);

    /**
     * @brief Define o valor de um atributo da hospedagem.
     * @param dominio Objeto do tipo Dominio contendo o valor a ser definido.
     * @param NomeProprio Nome do atributo a ser definido.
     */
    void set(const Dominio &dominio, string NomeProprio) override;

    /**
     * @brief Obtém o valor de um atributo da hospedagem.
     * @param NomeProprio Nome do atributo a ser obtido.
     * @return const Dominio& Valor do atributo.
     */
    const Dominio &get(const string NomeProprio) const override;
};

#endif // HOSPEDAGEM_ENTITY_INTERFACE_H