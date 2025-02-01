#ifndef DURACAO_DOMAIN_INTERFACE_HPP
#define DURACAO_DOMAIN_INTERFACE_HPP

#include "./Dominio.hpp"
#include <stdexcept>
#include <string>

using namespace std;

/**
 * @class Duracao
 * @brief Classe responsável pela representação de uma duração.
 * 
 * Esta classe herda de Dominio e gerencia a validação e manipulação de durações.
 */
class Duracao : public Dominio
{
private:
    static const int DuracaoMinima = 0; ///< Duração mínima permitida.
    static const int DuracaoMaxima = 360; ///< Duração máxima permitida.

    /**
     * @brief Método para validar o valor da duração.
     * @param valor Valor da duração a ser validado.
     */
    void validar(string valor) override;

public:
    /**
     * @brief Construtor da classe Duracao com valor inicial.
     * @param valor Valor inicial da duração.
     */
    Duracao(string valor);
};

/**
     * @brief Construtor da classe Duracao com valor inicial.
     * @param valor Valor inicial da duração.
     */
inline Duracao::Duracao(string valor)
{
    this->setValor(valor);
}

#endif // DURACAO_DOMAIN_INTERFACE_HPP