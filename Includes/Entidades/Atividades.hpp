#ifndef ATIVIDADE_ENTITY_INTERFACE_H
#define ATIVIDADE_ENTITY_INTERFACE_H

#include "../Dominios/Codigo.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Data.hpp"
#include "../Dominios/Duracao.hpp"
#include "../Dominios/Dinheiro.hpp"
#include "../Dominios/Avaliacao.hpp"
#include "../Dominios/Horario.hpp"
#include "./Entidade.hpp"

/**
 * @class Atividade
 * @brief Classe responsável pela representação de uma atividade.
 * 
 * Esta classe herda de Entidade e gerencia os atributos e operações relacionados a uma atividade.
 */
class Atividade : public Entidade
{
private:
    Codigo codigo; ///< Código da atividade.
    Nome nome; ///< Nome da atividade.
    Data data; ///< Data da atividade.
    Horario horario; ///< Horário da atividade.
    Duracao duracao; ///< Duração da atividade.
    Dinheiro preco; ///< Preço da atividade.
    Avaliacao avaliacao; ///< Avaliação da atividade.

public:
    /**
     * @brief Construtor da classe Atividade.
     * @param codigo Código da atividade.
     * @param nome Nome da atividade.
     * @param data Data da atividade.
     * @param horario Horário da atividade.
     * @param duracao Duração da atividade.
     * @param preco Preço da atividade.
     * @param avaliacao Avaliação da atividade.
     */
    Atividade(const Codigo &codigo, const Nome &nome, const Data &data, const Horario &horario, const Duracao &duracao, const Dinheiro &preco, const Avaliacao &avaliacao);

    /**
     * @brief Define o valor de um atributo da atividade.
     * @param dominio Objeto do tipo Dominio contendo o valor a ser definido.
     * @param NomeProprio Nome do atributo a ser definido.
     */
    void set(const Dominio &dominio, string NomeProprio) override;

    /**
     * @brief Obtém o valor de um atributo da atividade.
     * @param NomeProprio Nome do atributo a ser obtido.
     * @return const Dominio& Valor do atributo.
     */
    const Dominio &get(const string NomeProprio) const override;
};

#endif // ATIVIDADE_ENTITY_INTERFACE_H