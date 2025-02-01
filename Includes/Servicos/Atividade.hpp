#ifndef ATIVIDADE_SERVICE_HPP
#define ATIVIDADE_SERVICE_HPP

#include "./Modelo.hpp"
#include "../Interfaces/Servicos.hpp"

/**
 * @class ModeloAtividade
 * @brief Classe que implementa a interface de serviço de atividade.
 * 
 * Esta classe herda de InterfaceServicoAtividade e Modelo, e implementa os métodos para criar, ler, atualizar e remover atividades.
 */
class ModeloAtividade : public InterfaceServicoAtividade, public Modelo
{
public:
  /**
   * @brief Cria uma nova atividade.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoDestinoAtividade Código do destino da atividade.
   * @param NovaAtividade Nova atividade a ser criada.
   */
  void Criar(Codigo &CodigoUsuario, Codigo &CodigoDestinoAtividade, Atividade &NovaAtividade) override;

  /**
   * @brief Lê todas as atividades do usuário.
   * @param CodigoUsuario Código do usuário.
   * @return vector<Atividade> Vetor contendo as atividades do usuário.
   */
  vector<Atividade> Ler(Codigo &CodigoUsuario) override;

  /**
   * @brief Atualiza uma atividade existente.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoAtividade Código da atividade a ser atualizada.
   * @param AtividadeAtualizada Atividade atualizada.
   */
  void Atualizar(Codigo &CodigoUsuario, Codigo &CodigoAtividade, Atividade &AtividadeAtualizada) override;

  /**
   * @brief Remove uma atividade.
   * @param CodigoUsuario Código do usuário.
   * @param CodigoAtividade Código da atividade a ser removida.
   */
  void Remover(Codigo &CodigoUsuario, Codigo &CodigoAtividade) override;

  /**
   * @brief Destrutor da classe ModeloAtividade.
   */
  ~ModeloAtividade() override {}
};

#endif