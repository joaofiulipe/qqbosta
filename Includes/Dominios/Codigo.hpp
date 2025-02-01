#ifndef CODIGO_DOMAIN_INTERFACE_HPP
#define CODIGO_DOMAIN_INTERFACE_HPP

#include "./Dominio.hpp"

/**
 * @class Codigo
 * @brief Classe responsável pela representação de um código.
 * 
 * Esta classe herda de Dominio e gerencia a validação e geração de códigos.
 */
class Codigo : public Dominio
{
private:
    static const int TamanhoCodigo = 6; ///< Tamanho fixo do código.

    /**
     * @brief Método para validar o valor do código.
     * @param valor Valor do código a ser validado.
     */
    void validar(string valor) override;

public:
    /**
     * @brief Construtor padrão da classe Codigo.
     */
    Codigo();

    /**
     * @brief Construtor da classe Codigo com valor inicial.
     * @param valor Valor inicial do código.
     */
    Codigo(string valor);

    /**
     * @brief Método estático para gerar um código aleatório.
     * @return string Código gerado aleatoriamente.
     */
    static string GerarCodigoAleatorio();
};

/**
 * @brief Construtor da classe Codigo com valor inicial.
 * @param valor Valor inicial do código.
 */
inline Codigo::Codigo(string valor)
{
    this->setValor(valor);
}

#endif // CODIGO_DOMAIN_INTERFACE_HPP