#ifndef VIAGEM_AMBIENTE_INTERFACE_HPP
#define VIAGEM_AMBIENTE_INTERFACE_HPP

#include "../Interfaces/Apresentacao.hpp"
#include "../Interfaces/Servicos.hpp"

/**
 * @class AmbienteViagem
 * @brief Classe responsável pelo ambiente de viagem do usuário.
 * 
 * Esta classe herda de InterfaceApresentacao e gerencia as operações relacionadas à viagem do usuário,
 * como criação, atualização, remoção e leitura de viagens.
 */
class AmbienteViagem : public InterfaceApresentacao
{
private:
    InterfaceServicoViagem *ServicoViagem; ///< Ponteiro para o serviço de viagem.

    /**
     * @brief Consulta o custo de uma viagem.
     * @param CodigoViagem Código da viagem.
     */
    void ConsultaCusto(Codigo CodigoViagem);

    /**
     * @brief Lista os destinos de uma viagem.
     * @param CodigoViagem Código da viagem.
     */
    void ListaDestinos(Codigo CodigoViagem);

    /**
     * @brief Consulta informações de um destino.
     */
    void ConsultaDestino();

    /**
     * @brief Lista as hospedagens de um destino.
     * @param CodigoDestino Código do destino.
     */
    void ListaHospedagens(Codigo CodigoDestino);

    /**
     * @brief Lista as atividades de um destino.
     * @param CodigoDestino Código do destino.
     */
    void ListaAtividades(Codigo CodigoDestino);

public:
    /**
     * @brief Construtor da classe AmbienteViagem.
     * @param CodigoUsuario Código do usuário.
     */
    AmbienteViagem(Codigo &CodigoUsuario) : InterfaceApresentacao(CodigoUsuario) {};

    /**
     * @brief Define o serviço de viagem.
     * @param ServicoViagem Ponteiro para o serviço de viagem.
     */
    void setServicoViagem(InterfaceServicoViagem *ServicoViagem)
    {
        this->ServicoViagem = ServicoViagem;
    };

    /**
     * @brief Método para executar operações no ambiente de viagem.
     * @param CodigoUsuario Código do usuário.
     */
    void Executar(Codigo &CodigoUsuario) override;

    /**
     * @brief Método para criar uma nova viagem.
     */
    void Criar();

    /**
     * @brief Método para atualizar uma viagem existente.
     */
    void Atualizar();

    /**
     * @brief Método para remover uma viagem.
     */
    void Remover();

    /**
     * @brief Método para listar todas as informações de uma viagem.
     */
    void ListarTudo();

    /**
     * @brief Método para consultar informações de uma viagem.
     */
    void ConsultaViagem();

    /**
     * @brief Destrutor da classe AmbienteViagem.
     * 
     * Libera a memória alocada para o serviço de viagem.
     */
    ~AmbienteViagem() override
    {
        delete ServicoViagem;
    }
};

#endif // VIAGEM_AMBIENTE_INTERFACE_HPP