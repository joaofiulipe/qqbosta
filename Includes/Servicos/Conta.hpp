#ifndef CONTA_SERVICE_HPP
#define CONTA_SERVICE_HPP

#include "./Modelo.hpp"
#include "../Interfaces/Servicos.hpp"

class ModeloConta : public InterfaceServicoConta, public Modelo
{
public:
  bool Autenticar(Codigo &CodigoUsuario, Senha &SenhaUsuario);
  void Criar(Codigo &CodigoUsuario, Senha &SenhaUsuario);
  ~ModeloConta() override {};
};

#endif 