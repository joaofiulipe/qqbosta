#ifndef ATIVIDADE_AMBIENTE_HPP
#define ATIVIDADE_AMBIENTE_HPP

#include "../Interfaces/Apresentacao.hpp"
#include "../Interfaces/Servicos.hpp"

/**
 * @class AmbienteAtividade
 * @brief Classe responsável pela apresentação e gerenciamento das atividades no ambiente.
 * 
 * A classe AmbienteAtividade herda de InterfaceApresentacao e é responsável por
 * gerenciar a apresentação das atividades, incluindo a criação, atualização, remoção
 * e leitura de atividades. Utiliza um ponteiro para o serviço de atividades para
 * realizar essas operações.
 */

/**
 * @brief Construtor da classe AmbienteAtividade.
 * 
 * Inicializa uma instância da classe AmbienteAtividade com o código do usuário fornecido.
 * 
 * @param CodigoUsuario Código do usuário.
 */

/**
 * @brief Define o serviço de atividades.
 * 
 * Associa um ponteiro para o serviço de atividades à instância da classe AmbienteAtividade.
 * 
 * @param ServicoAtividade Ponteiro para o serviço de atividades.
 */

/**
 * @brief Executa a apresentação das atividades.
 * 
 * Realiza a apresentação das atividades para o usuário com base no código do usuário fornecido.
 * 
 * @param CodigoUsuario Código do usuário.
 */

/**
 * @brief Cria uma nova atividade.
 * 
 * Inicia o processo de criação de uma nova atividade no ambiente.
 */

/**
 * @brief Atualiza uma atividade existente.
 * 
 * Inicia o processo de atualização de uma atividade existente no ambiente.
 */

/**
 * @brief Remove uma atividade.
 * 
 * Inicia o processo de remoção de uma atividade existente no ambiente.
 */

/**
 * @brief Lê uma atividade.
 * 
 * Inicia o processo de leitura e exibição dos detalhes de uma atividade existente no ambiente.
 */

/**
 * @brief Destrutor da classe AmbienteAtividade.
 * 
 * Libera a memória alocada para o serviço de atividades e realiza a limpeza necessária
 * antes da destruição da instância da classe.
 */
 /* @brief Classe responsável por gerenciar a apresentação das atividades no ambiente.
 * 
 * Esta classe herda de InterfaceApresentacao e é responsável por criar, atualizar, remover e ler atividades.
 */
class AmbienteAtividade : public InterfaceApresentacao
{
private:
  InterfaceServicoAtividade *ServicoAtividade; /**< Ponteiro para o serviço de atividades. */

public:
  /**
   * @brief Construtor da classe AmbienteAtividade.
   * 
   * @param CodigoUsuario Código do usuário.
   */
  AmbienteAtividade(Codigo &CodigoUsuario) : InterfaceApresentacao(CodigoUsuario) {};

  /**
   * @brief Define o serviço de atividades.
   * 
   * @param ServicoAtividade Ponteiro para o serviço de atividades.
   */
  void setServicoAtividade(InterfaceServicoAtividade *ServicoAtividade)
  {
    this->ServicoAtividade = ServicoAtividade;
  };


  /**
   * @brief Executa a apresentação das atividades.
   * 
   * @param CodigoUsuario Código do usuário.
   */
  void Executar(Codigo &CodigoUsuario);

  /**
   * @brief Cria uma nova atividade.
   */
  void Criar();

  /**
   * @brief Atualiza uma atividade existente.
   */
  void Atualizar();

  /**
   * @brief Remove uma atividade.
   */
  void Remover();

  /**
   * @brief Lê uma atividade.
   */
  void Ler();

  /**
   * @brief Destrutor da classe AmbienteAtividade.
   * 
   * Libera a memória alocada para o serviço de atividades.
   */
  ~AmbienteAtividade() override
    {
    delete ServicoAtividade;
  }
};

#endif 