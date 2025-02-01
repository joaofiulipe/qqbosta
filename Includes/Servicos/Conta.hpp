#ifndef CONTA_SERVICE_HPP
#define CONTA_SERVICE_HPP

#include "./Modelo.hpp"
#include "../Interfaces/Servicos.hpp"

/**
 * @class ModeloConta
 * @brief Classe que implementa a interface de serviço de conta.
 * 
 * Esta classe herda de InterfaceServicoConta e Modelo, e implementa os métodos para autenticar e criar contas de usuário.
 */
class ModeloConta : public InterfaceServicoConta, public Modelo
{
public:
  /**
   * @brief Autentica um usuário.
   * @param CodigoUsuario Código do usuário.
   * @param SenhaUsuario Senha do usuário.
   * @return bool Verdadeiro se a autenticação for bem-sucedida, falso caso contrário.
   */
  bool Autenticar(Codigo &CodigoUsuario, Senha &SenhaUsuario) override;

  /**
   * @brief Cria uma nova conta de usuário.
   * @param CodigoUsuario Código do usuário.
   * @param SenhaUsuario Senha do usuário.
   */
  void Criar(Codigo &CodigoUsuario, Senha &SenhaUsuario) override;

  /**
   * @brief Destrutor da classe ModeloConta.
   */
  ~ModeloConta() override {};
};

#endif