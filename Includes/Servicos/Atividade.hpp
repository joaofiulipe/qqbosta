#ifndef ATIVIDADE_SERVICE_HPP
#define ATIVIDADE_SERVICE_HPP

#include "./Modelo.hpp"
#include "../Interfaces/Servicos.hpp"

class ModeloAtividade : public InterfaceServicoAtividade, public Modelo
{
public:
  void Criar(Codigo &CodigoUsuario, Codigo &CodigoDestinoAtividade, Atividade &NovaAtividade) override;
  vector<Atividade> Ler(Codigo &CodigoUsuario) override;
  void Atualizar(Codigo &CodigoUsuario, Codigo &CodigoAtividade, Atividade &AtividadeAtualizada) override;
  void Remover(Codigo &CodigoUsuario, Codigo &CodigoAtividade) override;
  ~ModeloAtividade() override {}
};

#endif 