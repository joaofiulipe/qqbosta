#ifndef TRAVEL_SERVICE_HPP
#define TRAVEL_SERVICE_HPP

#include "./Modelo.hpp"
#include "../Interfaces/Servicos.hpp"

/**
 * @class ModeloViagem
 * @brief Classe que implementa a interface de serviço de viagem.
 * 
 * Esta classe herda de InterfaceServicoViagem e Modelo, e implementa os métodos para criar, ler, atualizar e remover viagens.
 */
class ModeloViagem : public InterfaceServicoViagem, public Modelo
{
public:
  /**
   * @brief Cria uma nova viagem.
   * @param CodigoUsuario Código do usuário.
   * @param NovaViagem Nova viagem a ser criada.
   */
  void Criar(Codigo &CodigoUsuario, Viagem &NovaViagem) override;

  /**
   * @brief Atualiza uma viagem existente.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoViagem Código da viagem a ser atualizada.
   * @param ViagemAtualizada Viagem atualizada.
   */
  void Atualizar(Codigo &CodigoUsuario, Codigo &CodigoViagem, Viagem &ViagemAtualizada) override;

  /**
   * @brief Remove uma viagem.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoViagem Código da viagem a ser removida.
   */
  void Remover(Codigo &CodigoUsuario, Codigo &CodigoViagem) override;

  /**
   * @brief Lê todas as viagens do usuário.
   * @param CodigoUsuario Código do usuário.
   * @return vector<Viagem> Vetor contendo as viagens do usuário.
   */
  vector<Viagem> LerTudo(Codigo &CodigoUsuario) override;

  /**
   * @brief Consulta o custo de uma viagem.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoViagem Código da viagem.
   * @return int Custo da viagem.
   */
  int ConsultaCusto(Codigo &CodigoUsuario, Codigo &CodigoViagem) override;

  /**
   * @brief Lista os destinos de uma viagem.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoViagem Código da viagem.
   * @return vector<Destino> Vetor contendo os destinos da viagem.
   */
  vector<Destino> ListaDestinos(Codigo &CodigoUsuario, Codigo &CodigoViagem) override;

  /**
   * @brief Consulta informações de um destino.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoDestino Código do destino.
   * @return Destino Informações do destino.
   */
  Destino ConsultaDestino(Codigo &CodigoUsuario, Codigo &CodigoDestino) override;

  /**
   * @brief Lista as hospedagens de um destino.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoDestino Código do destino.
   * @return vector<Hospedagem> Vetor contendo as hospedagens do destino.
   */
  vector<Hospedagem> ListaHospedagems(Codigo &CodigoUsuario, Codigo &CodigoDestino) override;

  /**
   * @brief Lista as atividades de um destino.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoDestino Código do destino.
   * @return vector<Atividade> Vetor contendo as atividades do destino.
   */
  vector<Atividade> ListaAtividades(Codigo &CodigoUsuario, Codigo &CodigoDestino) override;

  /**
   * @brief Destrutor da classe ModeloViagem.
   */
  ~ModeloViagem() override {};
};

#endif