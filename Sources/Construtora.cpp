#include "../Includes/Construtora.hpp"

void Construtora::construir(Controladora *controladora)
{
    ModeloConta *servicoConta = new ModeloConta();
    ModeloViagem *servicoViagem = new ModeloViagem();
    ModeloDestino *servicoDestino = new ModeloDestino();
    ModeloHospedagem *servicoHospedagem = new ModeloHospedagem();
    ModeloAtividade *servicoAtividade = new ModeloAtividade();
    
    AmbienteConta *ambienteConta = new AmbienteConta(controladora->CodigoUsuario);
    AmbienteViagem *ambienteViagem = new AmbienteViagem(controladora->CodigoUsuario);
    AmbienteDestino *ambienteDestino = new AmbienteDestino(controladora->CodigoUsuario);
    AmbienteHospedagem *ambienteHospedagem = new AmbienteHospedagem(controladora->CodigoUsuario);
    AmbienteAtividade *ambienteAtividade = new AmbienteAtividade(controladora->CodigoUsuario);

    ambienteConta->setServicoConta(servicoConta);
    ambienteViagem->setServicoViagem(servicoViagem);
    ambienteDestino->setServicoDestino(servicoDestino);
    ambienteHospedagem->setServicoHospedagem(servicoHospedagem);
    ambienteAtividade->setServicoAtividade(servicoAtividade);

    controladora->setAmbienteConta(ambienteConta);
    controladora->setAmbienteViagem(ambienteViagem);
    controladora->setAmbienteDestino(ambienteDestino);
    controladora->setAmbienteHospedagem(ambienteHospedagem);
    controladora->setAmbienteAtividade(ambienteAtividade);
}
