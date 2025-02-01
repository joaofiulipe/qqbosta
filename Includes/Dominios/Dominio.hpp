#ifndef DOMINIO_INTERFACE_HPP
#define DOMINIO_INTERFACE_HPP

#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

/**
 * @class Dominio
 * @brief Classe base abstrata para representação de domínios.
 * 
 * Esta classe fornece a interface para a validação e manipulação de valores de domínio.
 */
class Dominio
{
private:
    string valor; ///< Valor do domínio.

    /**
     * @brief Método virtual puro para validar o valor do domínio.
     * @param valor Valor do domínio a ser validado.
     */
    virtual void validar(string valor) = 0;

public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Dominio() = default;

    /**
     * @brief Define o valor do domínio.
     * @param valor Valor a ser definido.
     */
    void setValor(const string &valor);

    /**
     * @brief Obtém o valor do domínio.
     * @return const string& Valor do domínio.
     */
    const string &getValor() const;
};

/**
 * @brief Define o valor do domínio.
 * @param valor Valor a ser definido.
 */
inline void Dominio::setValor(const string &valor)
{
    validar(valor);
    this->valor = valor;
}

/**
 * @brief Obtém o valor do domínio.
 * @return const string& Valor do domínio.
 */
inline const string &Dominio::getValor() const
{
    return this->valor;
}

#endif // DOMINIO_INTERFACE_HPP