#ifndef HORARIO_DOMAIN_INTERFACE_HPP
#define HORARIO_DOMAIN_INTERFACE_HPP

#include "./Dominio.hpp"

/**
 * @class Horario
 * @brief Classe responsável pela representação de um horário.
 * 
 * Esta classe herda de Dominio e gerencia a validação e manipulação de horários.
 */
class Horario : public Dominio
{
private:
    static const int HoraMaxima = 23; ///< Hora máxima permitida.
    static const int MinutoMaximo = 59; ///< Minuto máximo permitido.

    /**
     * @brief Método para validar o valor do horário.
     * @param valor Valor do horário a ser validado.
     */
    void validar(string valor) override;

public:
    /**
     * @brief Construtor da classe Horario com valor inicial.
     * @param valor Valor inicial do horário.
     */
    Horario(string valor);
};

/**
 * @brief Construtor da classe Horario com valor inicial.
 * @param valor Valor inicial do horário.
 */
inline Horario::Horario(string valor)
{
    this->setValor(valor);
}

#endif // HORARIO_DOMAIN_INTERFACE_HPP