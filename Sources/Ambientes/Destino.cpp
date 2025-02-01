#include "../../Includes/Ambientes/Destino.hpp"

void AmbienteDestino::Executar(Codigo &CodigoUsuario)
{
  this->CodigoUsuario = CodigoUsuario;

  while (true)
  {
    try
    {
      cout << "\033[2J\033[1;1H";

      cout << "//////////////////////" << endl;
      cout << "  Ambiente Destino" << endl;
      cout << "//////////////////////" << endl;
      cout << "1 - Criar novo destino" << endl;
      cout << "2 - Listar destinos existentes" << endl;
      cout << "3 - Atualizar destino" << endl;
      cout << "4 - Deletar destino" << endl;
      cout << "5 - Retornar ao HUB" << endl;
      cout << "Escolha uma das opções acima (1 a 5): ";
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
           << "****** FALHA NA OPERAÇÃO ******" << endl;
      cout << e.what() << endl;
      cout << "********************************" << endl
           << endl;
    }

    cout << "Pressione qualquer tecla para continuar.";
    cin.ignore();
    cin.get();
  }
}

void AmbienteDestino::Criar()
{
  Codigo codigo = Codigo();
  Avaliacao avaliacao = Avaliacao("0");
  string nome, chegada, partida, CodigoViagem;

  cout << "//////////////////////" << endl;
  cout << "    Criar destino" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o nome do novo destino: ";
  cin >> nome;
  Nome NomeDominio = Nome(nome);

  cout << "2 - Digite a data inicial (DD/MM/AA): ";
  cin >> chegada;
  Data ChegadaDominio = Data(chegada);

  cout << "3 - Digite a data final (DD/MM/AA): ";
  cin >> partida;
  Data PartidaDominio = Data(partida);

  ChegadaDominio.CalcularAlcanceDatas(ChegadaDominio.getValor(), PartidaDominio.getValor());

  cout << "4 - Digite o código da viagem a ser atrelada: ";
  cin >> CodigoViagem;
  Codigo CodigoViagemDominio = Codigo(CodigoViagem);

  Destino destino = Destino(codigo, NomeDominio, ChegadaDominio, PartidaDominio, avaliacao);
  ServicoDestino->Criar(CodigoUsuario, CodigoViagemDominio, destino);
}

void AmbienteDestino::Ler()
{
  cout << "//////////////////////" << endl;
  cout << "   Listar destinos" << endl;
  cout << "//////////////////////" << endl;

  vector<Destino> Destinos = ServicoDestino->Ler(CodigoUsuario);

  if (Destinos.size() == 0)
    cout << "Você não possui destinos atrelado a esta conta" << endl;

  for (const auto &destino : Destinos)
  {
    cout << "Código: " << destino.get("codigo").getValor() << endl;
    cout << "Nome: " << destino.get("nome").getValor() << endl;
    cout << "Data inicial: " << destino.get("chegada").getValor() << endl;
    cout << "Data final: " << destino.get("partida").getValor() << endl;
    cout << "Avaliação: " << destino.get("avaliacao").getValor() << endl;
    cout << "//////////////////////" << endl;
  }
}

void AmbienteDestino::Atualizar()
{
  string CodigoDestino;
  cout << "//////////////////////" << endl;
  cout << "  Atualizar destino" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o código do destino a ser atualizado: ";
  cin >> CodigoDestino;
  Codigo CodigoDominio = Codigo(CodigoDestino);

  string nome, chegada, partida, avaliacao;
  cout << "2 - Digite o novo nome do destino: ";
  cin >> nome;
  Nome NomeDominio = Nome(nome);

  cout << "3 - Digite a nova data inicial (DD/MM/AA): ";
  cin >> chegada;
  Data ChegadaDominio = Data(chegada);

  cout << "4 - Digite a nova data final (DD/MM/AA): ";
  cin >> partida;
  Data PartidaDominio = Data(partida);

  ChegadaDominio.CalcularAlcanceDatas(ChegadaDominio.getValor(), PartidaDominio.getValor());

  cout << "5 - Digite a nova avaliação do destino: ";
  cin >> avaliacao;
  Avaliacao AvaliacaoDominio = Avaliacao(avaliacao);

  Destino destino = Destino(CodigoDominio, NomeDominio, ChegadaDominio, PartidaDominio, AvaliacaoDominio);
  ServicoDestino->Atualizar(CodigoUsuario, CodigoDominio, destino);

}

void AmbienteDestino::Remover()
{
  string CodigoDestino;

  cout << "//////////////////////" << endl;
  cout << "   Deletar destino" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o código do destino: ";
  cin >> CodigoDestino;
  Codigo codigo = Codigo(CodigoDestino);
  
  ServicoDestino->Remover(CodigoUsuario, codigo);

}
