#ifndef ENTIDADE_INTERFACE_H
#define ENTIDADE_INTERFACE_H

#include "../Dominios/Dominio.hpp"

/**
 * @class Entidade
 * @brief Classe base abstrata para representação de entidades.
 * 
 * Esta classe fornece a interface para a definição e obtenção de valores de atributos de entidades.
 */
class Entidade
{
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Entidade() = default;

    /**
     * @brief Define o valor de um atributo da entidade.
     * @param dominio Objeto do tipo Dominio contendo o valor a ser definido.
     * @param NomeProprio Nome do atributo a ser definido.
     */
    virtual void set(const Dominio &dominio, string NomeProprio) = 0;

    /**
     * @brief Obtém o valor de um atributo da entidade.
     * @param NomeProprio Nome do atributo a ser obtido.
     * @return const Dominio& Valor do atributo.
     */
    virtual const Dominio &get(const string NomeProprio) const = 0;
};

#endif // ENTIDADE_INTERFACE_H