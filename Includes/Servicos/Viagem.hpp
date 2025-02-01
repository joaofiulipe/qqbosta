#ifndef TRAVEL_SERVICE_HPP
#define TRAVEL_SERVICE_HPP

#include "./Modelo.hpp"
#include "../Interfaces/Servicos.hpp"

class ModeloViagem : public InterfaceServicoViagem, public Modelo
{
public:
  void Criar(Codigo &CodigoUsuario, Viagem &NovaViagem) override;
  void Atualizar(Codigo &CodigoUsuario, Codigo &CodigoViagem, Viagem &ViagemAtualizada) override;
  void Remover(Codigo &CodigoUsuario, Codigo &CodigoViagem) override;
  vector<Viagem> LerTudo(Codigo &CodigoUsuario) override;
  int ConsultaCusto(Codigo &CodigoUsuario, Codigo &CodigoViagem) override;
  vector<Destino> ListaDestinos(Codigo &CodigoUsuario, Codigo &CodigoViagem) override;
  Destino ConsultaDestino(Codigo &CodigoUsuario, Codigo &CodigoDestino) override;
  vector<Hospedagem> ListaHospedagems(Codigo &CodigoUsuario, Codigo &CodigoDestino) override;
  vector<Atividade> ListaAtividades(Codigo &CodigoUsuario, Codigo &CodigoDestino) override;
  ~ModeloViagem() override {};
};

#endif 