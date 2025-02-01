#ifndef CONTA_AMBIENTE_INTERFACE_HPP
#define CONTA_AMBIENTE_INTERFACE_HPP

#include "../Interfaces/Apresentacao.hpp"
#include "../Interfaces/Servicos.hpp"

/**
 * @class AmbienteConta
 * @brief Classe responsável pelo ambiente de conta do usuário.
 * 
 * Esta classe herda de InterfaceApresentacao e gerencia as operações relacionadas à conta do usuário,
 * como autenticação, criação e saída.
 */
class AmbienteConta : public InterfaceApresentacao
{
private:
    InterfaceServicoConta *ServicoConta; ///< Ponteiro para o serviço de conta.

public:
    /**
     * @brief Construtor da classe AmbienteConta.
     * @param CodigoUsuario Código do usuário.
     */
    AmbienteConta(Codigo &CodigoUsuario) : InterfaceApresentacao(CodigoUsuario) {};

    /**
     * @brief Define o serviço de conta.
     * @param ServicoConta Ponteiro para o serviço de conta.
     */
    void setServicoConta(InterfaceServicoConta *ServicoConta)
    {
        this->ServicoConta = ServicoConta;
    };

    /**
     * @brief Método para autenticar o usuário.
     */
    void Autenticar();

    /**
     * @brief Método para criar uma nova conta.
     */
    void Criar();

    /**
     * @brief Método para sair do ambiente de conta.
     */
    void Sair();

    /**
     * @brief Método para executar operações no ambiente de conta.
     * @param CodigoUsuario Código do usuário.
     */
    void Executar(Codigo &CodigoUsuario);

    /**
     * @brief Destrutor da classe AmbienteConta.
     * 
     * Libera a memória alocada para o serviço de conta.
     */
    ~AmbienteConta() override
    {
        delete ServicoConta;
    }

};

#endif // CONTA_AMBIENTE_INTERFACE_HPP