#ifndef HOSPEDAGEM_AMBIENTE_HPP
#define HOSPEDAGEM_AMBIENTE_HPP

#include "../Interfaces/Apresentacao.hpp"
#include "../Interfaces/Servicos.hpp"

/**
 * @class AmbienteHospedagem
 * @brief Classe responsável pelo ambiente de hospedagem do usuário.
 * 
 * Esta classe herda de InterfaceApresentacao e gerencia as operações relacionadas à hospedagem do usuário,
 * como criação, atualização, remoção e leitura de hospedagens.
 */
class AmbienteHospedagem : public InterfaceApresentacao
{
private:
    InterfaceServicoHospedagem *ServicoHospedagem; ///< Ponteiro para o serviço de hospedagem.

public:
    /**
     * @brief Construtor da classe AmbienteHospedagem.
     * @param CodigoUsuario Código do usuário.
     */
    AmbienteHospedagem(Codigo &CodigoUsuario) : InterfaceApresentacao(CodigoUsuario) {};

    /**
     * @brief Define o serviço de hospedagem.
     * @param ServicoHospedagem Ponteiro para o serviço de hospedagem.
     */
    void setServicoHospedagem(InterfaceServicoHospedagem *ServicoHospedagem)
    {
        this->ServicoHospedagem = ServicoHospedagem;
    };

    /**
     * @brief Método para executar operações no ambiente de hospedagem.
     * @param CodigoUsuario Código do usuário.
     */
    void Executar(Codigo &CodigoUsuario) override;

    /**
     * @brief Método para criar uma nova hospedagem.
     */
    void Criar();

    /**
     * @brief Método para atualizar uma hospedagem existente.
     */
    void Atualizar();

    /**
     * @brief Método para remover uma hospedagem.
     */
    void Remover();

    /**
     * @brief Método para ler informações de uma hospedagem.
     */
    void Ler();

    /**
     * @brief Destrutor da classe AmbienteHospedagem.
     * 
     * Libera a memória alocada para o serviço de hospedagem.
     */
    ~AmbienteHospedagem() override
    {
        delete ServicoHospedagem;
    }
};

#endif // HOSPEDAGEM_AMBIENTE_HPP