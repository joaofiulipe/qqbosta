#ifndef APRESENTACAO_INTERFACE_H
#define APRESENTACAO_INTERFACE_H

#include "../Dominios/Codigo.hpp"

/**
 * @class InterfaceApresentacao
 * @brief Classe base abstrata para a interface de apresentação.
 * 
 * Esta classe fornece a interface para a execução de operações de apresentação.
 */
class InterfaceApresentacao
{
protected:
  Codigo &CodigoUsuario; ///< Referência ao código do usuário.

public:
  /**
   * @brief Construtor da classe InterfaceApresentacao.
   * @param CodigoUsuario Referência ao código do usuário.
   */
  InterfaceApresentacao(Codigo &CodigoUsuario) : CodigoUsuario(CodigoUsuario) {}

  /**
   * @brief Método virtual puro para executar operações de apresentação.
   * @param CodigoUsuario Referência ao código do usuário.
   */
  virtual void Executar(Codigo &CodigoUsuario) = 0;

  /**
   * @brief Destrutor virtual padrão.
   */
  virtual ~InterfaceApresentacao() {};
};

#endif // APRESENTACAO_INTERFACE_H