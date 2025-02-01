#ifndef DESTINO_AMBIENTE_INTERFACE_HPP
#define DESTINO_AMBIENTE_INTERFACE_HPP

#include "../Interfaces/Apresentacao.hpp"
#include "../Interfaces/Servicos.hpp"

/**
 * @class AmbienteDestino
 * @brief Classe responsável pelo ambiente de destino do usuário.
 * 
 * Esta classe herda de InterfaceApresentacao e gerencia as operações relacionadas ao destino do usuário,
 * como criação, atualização, remoção e leitura de destinos.
 */
class AmbienteDestino : public InterfaceApresentacao
{
private:
    InterfaceServicoDestino *ServicoDestino; ///< Ponteiro para o serviço de destino.

public:
    /**
     * @brief Construtor da classe AmbienteDestino.
     * @param CodigoUsuario Código do usuário.
     */
    AmbienteDestino(Codigo &CodigoUsuario) : InterfaceApresentacao(CodigoUsuario) {};

    /**
     * @brief Define o serviço de destino.
     * @param ServicoDestino Ponteiro para o serviço de destino.
     */
    void setServicoDestino(InterfaceServicoDestino *ServicoDestino)
    {
        this->ServicoDestino = ServicoDestino;
    };

    /**
     * @brief Método para executar operações no ambiente de destino.
     * @param CodigoUsuario Código do usuário.
     */
    void Executar(Codigo &CodigoUsuario) override;

    /**
     * @brief Método para criar um novo destino.
     */
    void Criar();

    /**
     * @brief Método para atualizar um destino existente.
     */
    void Atualizar();

    /**
     * @brief Método para remover um destino.
     */
    void Remover();

    /**
     * @brief Método para ler informações de um destino.
     */
    void Ler();

    /**
     * @brief Destrutor da classe AmbienteDestino.
     * 
     * Libera a memória alocada para o serviço de destino.
     */
    ~AmbienteDestino() override
    {
        delete ServicoDestino;
    }
};

#endif // DESTINO_AMBIENTE_INTERFACE_HPP