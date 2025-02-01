#ifndef CONTA_ENTITY_INTERFACE_H
#define CONTA_ENTITY_INTERFACE_H

#include "../Dominios/Codigo.hpp"
#include "../Dominios/Senha.hpp"
#include "./Entidade.hpp"

/**
 * @class Conta
 * @brief Classe responsável pela representação de uma conta.
 * 
 * Esta classe herda de Entidade e gerencia os atributos e operações relacionados a uma conta.
 */
class Conta : public Entidade
{
private:
    Codigo codigo; ///< Código da conta.
    Senha senha; ///< Senha da conta.

public:
    /**
     * @brief Construtor da classe Conta.
     * @param codigo Código da conta.
     * @param senha Senha da conta.
     */
    Conta(const Codigo &codigo, const Senha &senha);

    /**
     * @brief Define o valor de um atributo da conta.
     * @param dominio Objeto do tipo Dominio contendo o valor a ser definido.
     * @param NomeProprio Nome do atributo a ser definido.
     */
    void set(const Dominio &dominio, string NomeProprio) override;

    /**
     * @brief Obtém o valor de um atributo da conta.
     * @param NomeProprio Nome do atributo a ser obtido.
     * @return const Dominio& Valor do atributo.
     */
    const Dominio &get(const string NomeProprio) const override;
};

#endif // CONTA_ENTITY_INTERFACE_H