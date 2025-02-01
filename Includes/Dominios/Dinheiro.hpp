#ifndef MONEY_DOMAIN_INTERFACE_HPP
#define MONEY_DOMAIN_INTERFACE_HPP

#include "./Dominio.hpp"

/**
 * @class Dinheiro
 * @brief Classe responsável pela representação de um valor monetário.
 * 
 * Esta classe herda de Dominio e gerencia a validação e manipulação de valores monetários.
 */
class Dinheiro : public Dominio
{
private:
    static constexpr float DinheiroMaximo = 200000.00; ///< Valor máximo permitido.
    static constexpr float DinheiroMinimo = 0.00; ///< Valor mínimo permitido.

    /**
     * @brief Método para validar o valor monetário.
     * @param valor Valor monetário a ser validado.
     */
    void validar(string valor) override;

public:
    /**
     * @brief Construtor da classe Dinheiro com valor inicial.
     * @param valor Valor inicial do dinheiro.
     */
    Dinheiro(string valor);
};

/**
 * @brief Construtor da classe Dinheiro com valor inicial.
 * @param valor Valor inicial do dinheiro.
 */
inline Dinheiro::Dinheiro(string valor)
{
    this->setValor(valor);
}

#endif // MONEY_DOMAIN_INTERFACE_HPP