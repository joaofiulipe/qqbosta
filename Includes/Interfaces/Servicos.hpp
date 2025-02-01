#ifndef SERVICES_INTERFACE_H
#define SERVICES_INTERFACE_H

#include "../Interfaces/Apresentacao.hpp"
#include "../Dominios/Codigo.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Avaliacao.hpp"
#include "../Dominios/Senha.hpp"
#include "../Entidades/Viagem.hpp"
#include "../Entidades/Destino.hpp"
#include "../Entidades/Hospedagem.hpp"
#include "../Entidades/Atividades.hpp"

/**
 * @class InterfaceServicoViagem
 * @brief Interface para serviços relacionados a viagens.
 * 
 * Esta interface define métodos para criar, atualizar, remover, ler e consultar informações sobre viagens.
 */
class InterfaceServicoViagem
{
public:
  virtual void Criar(Codigo &CodigoUsuario, Viagem &NovaViagem) = 0;
  virtual void Atualizar(Codigo &CodigoUsuario, Codigo &CodigoViagem, Viagem &ViagemAtualizada) = 0;
  virtual void Remover(Codigo &CodigoUsuario, Codigo &ViagemCodigo) = 0;
  virtual vector<Viagem> LerTudo(Codigo &CodigoUsuario) = 0;
  virtual int ConsultaCusto(Codigo &CodigoUsuario, Codigo &ViagemCodigo) = 0;
  virtual vector<Destino> ListaDestinos(Codigo &CodigoUsuario, Codigo &ViagemCodigo) = 0;
  virtual Destino ConsultaDestino(Codigo &CodigoUsuario, Codigo &CodigoDestino) = 0;
  virtual vector<Hospedagem> ListaHospedagems(Codigo &CodigoUsuario, Codigo &CodigoDestino) = 0;
  virtual vector<Atividade> ListaAtividades(Codigo &CodigoUsuario, Codigo &CodigoDestino) = 0;
  virtual ~InterfaceServicoViagem() {};
};

/**
 * @class InterfaceServicoConta
 * @brief Interface para serviços relacionados a contas.
 * 
 * Esta interface define métodos para autenticar e criar contas de usuário.
 */
class InterfaceServicoConta
{
public:
  virtual bool Autenticar(Codigo &CodigoUsuario, Senha &SenhaUsuario) = 0;
  virtual void Criar(Codigo &CodigoUsuario, Senha &SenhaUsuario) = 0;
  virtual ~InterfaceServicoConta() {};
};

/**
 * @class InterfaceServicoDestino
 * @brief Interface para serviços relacionados a destinos.
 * 
 * Esta interface define métodos para criar, ler, atualizar e remover destinos.
 */
class InterfaceServicoDestino
{
public:
  virtual void Criar(Codigo &CodigoUsuario, Codigo &DestinoViagemCodigo, Destino &NovoDestino) = 0;
  virtual vector<Destino> Ler(Codigo &CodigoUsuario) = 0;
  virtual void Atualizar(Codigo &CodigoUsuario, Codigo &CodigoDestino, Destino &DestinoAtualizado) = 0;
  virtual void Remover(Codigo &CodigoUsuario, Codigo &CodigoDestino) = 0;
  virtual ~InterfaceServicoDestino() {};
};

/**
 * @class InterfaceServicoHospedagem
 * @brief Interface para serviços relacionados a hospedagens.
 * 
 * Esta interface define métodos para criar, ler, atualizar e remover hospedagens.
 */
class InterfaceServicoHospedagem
{
public:
  virtual void Criar(Codigo &CodigoUsuario, Codigo &HospedagemCodigoDestino, Hospedagem &NovaHospedagem) = 0;
  virtual vector<Hospedagem> Ler(Codigo &CodigoUsuario) = 0;
  virtual void Atualizar(Codigo &CodigoUsuario, Codigo &HospedagemCodigo, Hospedagem &HospedagemAtualizada) = 0;
  virtual void Remover(Codigo &CodigoUsuario, Codigo &HospedagemCodigo) = 0;
  virtual ~InterfaceServicoHospedagem() {};
};

/**
 * @class InterfaceServicoAtividade
 * @brief Interface para serviços relacionados a atividades.
 * 
 * Esta interface define métodos para criar, ler, atualizar e remover atividades.
 */
class InterfaceServicoAtividade
{
public:
  virtual void Criar(Codigo &CodigoUsuario, Codigo &AtividadeCodigoDestino, Atividade &NovaAtividade) = 0;
  virtual vector<Atividade> Ler(Codigo &CodigoUsuario) = 0;
  virtual void Atualizar(Codigo &CodigoUsuario, Codigo &AtividadeCodigo, Atividade &AtividadeAtualizada) = 0;
  virtual void Remover(Codigo &CodigoUsuario, Codigo &AtividadeCodigo) = 0;
  virtual ~InterfaceServicoAtividade() {};
};

#endif // SERVICES_INTERFACE_H