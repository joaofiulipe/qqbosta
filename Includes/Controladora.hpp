#ifndef CONTROLADORA_INTERFACE_H
#define CONTROLADORA_INTERFACE_H

#include "./Interfaces/Apresentacao.hpp"

class Controladora
{
private:
    InterfaceApresentacao *AmbienteConta;
    InterfaceApresentacao *AmbienteViagem;
    InterfaceApresentacao *AmbienteDestino;
    InterfaceApresentacao *AmbienteHospedagem;
    InterfaceApresentacao *AmbienteAtividade;

public:
  Codigo CodigoUsuario = Codigo("000000");
  ~Controladora();

    void setAmbienteConta(InterfaceApresentacao *AmbienteConta);

    void setAmbienteViagem(InterfaceApresentacao *AmbienteViagem);

    void setAmbienteDestino(InterfaceApresentacao *AmbienteDestino);

    void setAmbienteHospedagem(InterfaceApresentacao *AmbienteHospedagem);

    void setAmbienteAtividade(InterfaceApresentacao *AmbienteAtividade);

    void Executar();
};

#endif