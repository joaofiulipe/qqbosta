#ifndef DESTINATION_SERVICE_HPP
#define DESTINATION_SERVICE_HPP

#include "Modelo.hpp"
#include "../Interfaces/Servicos.hpp"

class ModeloDestino : public InterfaceServicoDestino, public Modelo
{
public:
  void Criar(Codigo &CodigoUsuario, Codigo &CodigoDestinoViagem, Destino &NovoDestino) override;
  void Atualizar(Codigo &CodigoUsuario, Codigo &CodigoDestino, Destino &DestinoAtualizado) override;
  void Remover(Codigo &CodigoUsuario, Codigo &CodigoDestino) override;
  vector<Destino> Ler(Codigo &CodigoUsuario) override;
  ~ModeloDestino() override {};
};

#endif 