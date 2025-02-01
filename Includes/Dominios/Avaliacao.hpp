#ifndef AVALIACAO_DOMAIN_INTERFACE_HPP
#define AVALIACAO_DOMAIN_INTERFACE_HPP

#include "./Dominio.hpp"

/**
 * @class Avaliacao
 * @brief Classe responsável pela representação de uma avaliação.
 * 
 * Esta classe herda de Dominio e gerencia a validação e manipulação de avaliações.
 */
class Avaliacao : public Dominio
{
private:
    /**
     * @brief Método para validar o valor da avaliação.
     * @param valor Valor da avaliação a ser validado.
     */
    void validar(string valor) override;

public:
    /**
     * @brief Construtor da classe Avaliacao com valor inicial.
     * @param valor Valor inicial da avaliação.
     */
    Avaliacao(string valor);
};

/**
 * @brief Construtor da classe Avaliacao com valor inicial.
 * @param valor Valor inicial da avaliação.
 */
inline Avaliacao::Avaliacao(string valor)
{
    this->setValor(valor);
}

#endif // AVALIACAO_DOMAIN_INTERFACE_HPP