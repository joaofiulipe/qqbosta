#ifndef HOSPEDAGEM_SERVICE_HPP
#define HOSPEDAGEM_SERVICE_HPP

#include "./Modelo.hpp"
#include "../Interfaces/Servicos.hpp"

class ModeloHospedagem : public InterfaceServicoHospedagem, public Modelo
{
public:
  void Criar(Codigo &CodigoUsuario, Codigo &CodigoDestinoHospedagem, Hospedagem &NovaHospedagem) override;
  vector<Hospedagem> Ler(Codigo &CodigoUsuario) override;
  void Atualizar(Codigo &CodigoUsuario, Codigo &CodigoHospedagem, Hospedagem &HospedagemAtualizada) override;
  void Remover(Codigo &CodigoUsuario, Codigo &CodigoHospedagem) override;
  ~ModeloHospedagem() override {}
};

#endif 