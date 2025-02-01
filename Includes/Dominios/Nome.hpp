#ifndef NOME_DOMAIN_INTERFACE_HPP
#define NOME_DOMAIN_INTERFACE_HPP

#include "./Dominio.hpp"

/**
 * @class Nome
 * @brief Classe responsável pela representação de um nome.
 * 
 * Esta classe herda de Dominio e gerencia a validação e manipulação de nomes.
 */
class Nome : public Dominio
{
private:
    /**
     * @brief Método para validar o valor do nome.
     * @param valor Valor do nome a ser validado.
     */
    void validar(string valor) override;

public:
    /**
     * @brief Construtor da classe Nome com valor inicial.
     * @param valor Valor inicial do nome.
     */
    Nome(string valor);
};

/**
 * @brief Construtor da classe Nome com valor inicial.
 * @param valor Valor inicial do nome.
 */
inline Nome::Nome(string valor)
{
    this->setValor(valor);
}

#endif // NOME_DOMAIN_INTERFACE_HPP