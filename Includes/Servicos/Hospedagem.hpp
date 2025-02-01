#ifndef HOSPEDAGEM_SERVICE_HPP
#define HOSPEDAGEM_SERVICE_HPP

#include "./Modelo.hpp"
#include "../Interfaces/Servicos.hpp"

/**
 * @class ModeloHospedagem
 * @brief Classe que implementa a interface de serviço de hospedagem.
 * 
 * Esta classe herda de InterfaceServicoHospedagem e Modelo, e implementa os métodos para criar, ler, atualizar e remover hospedagens.
 */
class ModeloHospedagem : public InterfaceServicoHospedagem, public Modelo
{
public:
  /**
   * @brief Cria uma nova hospedagem.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoDestinoHospedagem Código do destino da hospedagem.
   * @param NovaHospedagem Nova hospedagem a ser criada.
   */
  void Criar(Codigo &CodigoUsuario, Codigo &CodigoDestinoHospedagem, Hospedagem &NovaHospedagem) override;

  /**
   * @brief Lê todas as hospedagens do usuário.
   * @param CodigoUsuario Código do usuário.
   * @return vector<Hospedagem> Vetor contendo as hospedagens do usuário.
   */
  vector<Hospedagem> Ler(Codigo &CodigoUsuario) override;

  /**
   * @brief Atualiza uma hospedagem existente.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoHospedagem Código da hospedagem a ser atualizada.
   * @param HospedagemAtualizada Hospedagem atualizada.
   */
  void Atualizar(Codigo &CodigoUsuario, Codigo &CodigoHospedagem, Hospedagem &HospedagemAtualizada) override;

  /**
   * @brief Remove uma hospedagem.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoHospedagem Código da hospedagem a ser removida.
   */
  void Remover(Codigo &CodigoUsuario, Codigo &CodigoHospedagem) override;

  /**
   * @brief Destrutor da classe ModeloHospedagem.
   */
  ~ModeloHospedagem() override {}
};

#endif