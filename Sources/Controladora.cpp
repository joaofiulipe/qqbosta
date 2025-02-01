#include "../Includes/Controladora.hpp"

Controladora::~Controladora()
{
    delete AmbienteConta;
    delete AmbienteViagem;
    delete AmbienteDestino;
    delete AmbienteHospedagem;
    delete AmbienteAtividade;
}

void Controladora::setAmbienteConta(InterfaceApresentacao *AmbienteConta)
{
    this->AmbienteConta = AmbienteConta;
}

void Controladora::setAmbienteViagem(InterfaceApresentacao *AmbienteViagem)
{
    this->AmbienteViagem = AmbienteViagem;
}

void Controladora::setAmbienteDestino(InterfaceApresentacao *AmbienteDestino)
{
    this->AmbienteDestino = AmbienteDestino;
}

void Controladora::setAmbienteHospedagem(InterfaceApresentacao *AmbienteHospedagem)
{
    this->AmbienteHospedagem = AmbienteHospedagem;
}

void Controladora::setAmbienteAtividade(InterfaceApresentacao *AmbienteAtividade)
{
    this->AmbienteAtividade = AmbienteAtividade;
}

void Controladora::Executar()
{
  while (true)
  {
    try
    {
      cout << "\033[2J\033[1;1H";

      cout << "//////////////////////" << endl;
      cout << " Painel Central (HUB) " << endl;
      cout << "//////////////////////" << endl;
      cout << "1 - Ambiente Conta" << endl;

      if (this->CodigoUsuario.getValor() != "000000")
      {
        cout << "2 - Ambiente Viagens" << endl;
        cout << "3 - Ambiente Destinos" << endl;
        cout << "4 - Ambiente Hospedagens" << endl;
        cout << "5 - Ambiente Atividades" << endl;
        cout << "6 - Sair" << endl;
        cout << "Escolha uma das opções (1 a 6): ";
        string option;
        cin >> option;

        cout << "\033[2J\033[1;1H";

        if (option == "1")
            this->AmbienteConta->Executar(this->CodigoUsuario);
        else if (option == "2")
            this->AmbienteViagem->Executar(this->CodigoUsuario);
        else if (option == "3")
            this->AmbienteDestino->Executar(this->CodigoUsuario);
        else if (option == "4")
            this->AmbienteHospedagem->Executar(this->CodigoUsuario);
        else if (option == "5")
            this->AmbienteAtividade->Executar(this->CodigoUsuario);
        else
          break;
      }
      else
      {
        cout << "2 - Sair" << endl;
        cout << "Escolha uma opção (1 a 2): ";
        int option;
        cin >> option;

        cout << "\033[2J\033[1;1H";

        if (option == 1)

            this->AmbienteConta->Executar(this->CodigoUsuario);
        else
        {
          return;
        }
      }

      cout << endl
           << "***** OPERAÇÃO FEITA COM SUCESSO *****" << endl
           << endl;
    }
    catch (const std::exception &e)
    {
      cout << endl
           <<  "****** FALHA NA OPERAÇÃO ******" << endl;
      cout << e.what() << endl;
      cout << "********************************" << endl;
    }

    cout << "Pressione qualquer tecla para continuar...";
    cin.ignore();
    cin.get();
  }
}
