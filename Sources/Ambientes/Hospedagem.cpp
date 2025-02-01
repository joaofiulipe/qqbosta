#include "../../Includes/Ambientes/Hospedagem.hpp"

void AmbienteHospedagem::Executar(Codigo &CodigoUsuario)
{
  this->CodigoUsuario = CodigoUsuario;

  while (true)
  {
    try
    {

      cout << "\033[2J\033[1;1H";


      cout << "//////////////////////" << endl;
      cout << "Ambiente Hospedagem" << endl;
      cout << "//////////////////////" << endl;
      cout << "1 - Criar nova hospedagem" << endl;
      cout << "2 - Listar hospedagens existentes" << endl;
      cout << "3 - Atualizar hospedagem" << endl;
      cout << "4 - Deletar hospedagem" << endl;
      cout << "5 - Retornar ao HUB" << endl;
      cout << "Escolha uma opção (1 a 5) : ";
      string option;
      cin >> option;


      cout << "\033[2J\033[1;1H";


      if (option == "1")
      {
        Criar();
      }
      else if (option == "2")
      {
        Ler();
      }
      else if (option == "3")
      {
        Atualizar();
      }
      else if (option == "4")
      {
        Remover();
      }
      else if (option == "5")
      {
        return;
      }
         else
        {
          cout << "Opção inválida" << endl;
              cout << "Pressione qualquer tecla para continuar.";
              cin.ignore();
              cin.get();
          Executar(CodigoUsuario);
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

    cout << "Pressione qualquer botão para continuar.";
    cin.ignore();
    cin.get();
  }
}

void AmbienteHospedagem::Criar()
{
  Codigo codigo = Codigo();
  Avaliacao avaliacao = Avaliacao("0");
  string nome, precodiaria, CodigoHospedagemDestino;

  cout << "//////////////////////" << endl;
  cout << "   Criar hospedagem" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o nome da hospedagem: ";
  cin >> nome;
    Nome NomeDominio = Nome(nome);
    

  cout << "2 - Digite o valor da diária: ";
  cin >> precodiaria;
    Dinheiro PrecoDiariaDominio = Dinheiro(precodiaria);
    
  cout << "3 - Digite o código do destino atrelado: ";
  cin >> CodigoHospedagemDestino;
    Codigo CodigoHospedagemDestinoDominio = Codigo(CodigoHospedagemDestino);
    
    Hospedagem hospedagem = Hospedagem(codigo, NomeDominio, PrecoDiariaDominio, avaliacao);
    ServicoHospedagem->Criar(CodigoUsuario, CodigoHospedagemDestinoDominio, hospedagem);
}

void AmbienteHospedagem::Atualizar()
{
  string CodigoAmbiente, nome, precodiaria, avaliacao;
  cout << "//////////////////////" << endl;
  cout << " Atualizar hospedagem" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o código da hospedagem a ser atualizada: ";
  cin >> CodigoAmbiente;
    Codigo CodigoDominio = Codigo(CodigoAmbiente);

  cout << "2 - Digite o novo nome da hospedagem: ";
  cin >> nome;
    Nome NomeDominio = Nome(nome);
    
  cout << "3 - Digite o novo valor da diária: ";
  cin >> precodiaria;
    Dinheiro PrecoDiariaDominio = Dinheiro(precodiaria);

  cout << "4 - Digite a nova avaliação da hospedagem: ";
  cin >> avaliacao;
    Avaliacao AvaliacaoDominio = Avaliacao(avaliacao);
    
    Hospedagem hospedagem = Hospedagem(CodigoDominio, NomeDominio, PrecoDiariaDominio, AvaliacaoDominio);
    ServicoHospedagem->Atualizar(CodigoUsuario, CodigoDominio, hospedagem);

}

void AmbienteHospedagem::Remover()
{
  string CodigoAmbiente;

  cout << "//////////////////////" << endl;
  cout << " Deletar hospedagem" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o código da hospedagem: ";
  cin >> CodigoAmbiente;
    Codigo codigo = Codigo(CodigoAmbiente);
    
    ServicoHospedagem->Remover(CodigoUsuario, codigo);
}

void AmbienteHospedagem::Ler()
{
  cout << "//////////////////////" << endl;
  cout << "  Listar hospedagens" << endl;
  cout << "//////////////////////" << endl;

  vector<Hospedagem> hospedagens = ServicoHospedagem->Ler(CodigoUsuario);

    if (hospedagens.size() == 0)
        cout << "Você não possui nenhuma hospedagem atrelada a esta conta" << endl;

    for (const auto &hospedagem : hospedagens)
    {
        cout << "Código: " << hospedagem.get("codigo").getValor() << endl;
        cout << "Nome: " << hospedagem.get("nome").getValor() << endl;
        cout << "Diária: " << hospedagem.get("precodiaria").getValor() << endl;
        cout << "Avaliação: " << hospedagem.get("avaliacao").getValor() << endl;
        cout << "//////////////////////" << endl;
    }
}