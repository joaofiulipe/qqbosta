#ifndef SENHA_DOMAIN_INTERFACE_HPP
#define SENHA_DOMAIN_INTERFACE_HPP

#include "./Dominio.hpp"

/**
 * @class Senha
 * @brief Classe responsável pela representação de uma senha.
 * 
 * Esta classe herda de Dominio e gerencia a validação e manipulação de senhas.
 */
class Senha : public Dominio
{
private:
    /**
     * @brief Método para validar o valor da senha.
     * @param valor Valor da senha a ser validada.
     */
    void validar(string valor) override;

public:
    /**
     * @brief Construtor da classe Senha com valor inicial.
     * @param valor Valor inicial da senha.
     */
    Senha(string valor);
};

/**
 * @brief Construtor da classe Senha com valor inicial.
 * @param valor Valor inicial da senha.
 */
inline Senha::Senha(string valor)
{
    this->setValor(valor);
}

#endif // SENHA_DOMAIN_INTERFACE_HPP