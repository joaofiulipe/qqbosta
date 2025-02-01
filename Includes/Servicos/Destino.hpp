#ifndef DESTINATION_SERVICE_HPP
#define DESTINATION_SERVICE_HPP

#include "Modelo.hpp"
#include "../Interfaces/Servicos.hpp"

/**
 * @class ModeloDestino
 * @brief Classe que implementa a interface de serviço de destino.
 * 
 * Esta classe herda de InterfaceServicoDestino e Modelo, e implementa os métodos para criar, ler, atualizar e remover destinos.
 */
class ModeloDestino : public InterfaceServicoDestino, public Modelo
{
public:
  /**
   * @brief Cria um novo destino.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoDestinoViagem Código da viagem do destino.
   * @param NovoDestino Novo destino a ser criado.
   */
  void Criar(Codigo &CodigoUsuario, Codigo &CodigoDestinoViagem, Destino &NovoDestino) override;

  /**
   * @brief Atualiza um destino existente.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoDestino Código do destino a ser atualizado.
   * @param DestinoAtualizado Destino atualizado.
   */
  void Atualizar(Codigo &CodigoUsuario, Codigo &CodigoDestino, Destino &DestinoAtualizado) override;

  /**
   * @brief Remove um destino.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoDestino Código do destino a ser removido.
   */
  void Remover(Codigo &CodigoUsuario, Codigo &CodigoDestino) override;

  /**
   * @brief Lê todos os destinos do usuário.
   * @param CodigoUsuario Código do usuário.
   * @return vector<Destino> Vetor contendo os destinos do usuário.
   */
  vector<Destino> Ler(Codigo &CodigoUsuario) override;

  /**
   * @brief Destrutor da classe ModeloDestino.
   */
  ~ModeloDestino() override {};
};

#endif