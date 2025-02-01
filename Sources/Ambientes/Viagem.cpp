#include "../../Includes/Ambientes/Viagem.hpp"

void AmbienteViagem::Executar(Codigo &CodigoUsuario)
{
  this->CodigoUsuario = CodigoUsuario;

  while (true)
  {
    try
    {

      cout << "\033[2J\033[1;1H";

      cout << "//////////////////////" << endl;
      cout << " Ambiente Viagem" << endl;
      cout << "//////////////////////" << endl;
      cout << "1 - Criar nova viagem" << endl;
      cout << "2 - Atualizar viagem" << endl;
      cout << "3 - Deletar viagem" << endl;
      cout << "4 - Listar viagens existentes" << endl;
      cout << "5 - Consultar viagem existentes" << endl;
      cout << "6 - Retornar ao HUB" << endl;
      cout << "Escolha uma opção (1 a 6): ";
      string option;
      cin >> option;

      cout << "\033[2J\033[1;1H";


      if (option == "1")
      {
        Criar();
      }
      else if (option == "2")
      {
        Atualizar();
      }
      else if (option == "3")
      {
        Remover();
      }
      else if (option == "4")
      {
        ListarTudo();
      }
      else if (option == "5")
      {
        ConsultaViagem();
      }
      else if (option == "6")
      {
        return;
      }
        else
        {
          cout << "Opção inválida" << endl;
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

    cout << "Pressione Enter para continuar.";
    cin.ignore();
    cin.get();
  }
}

void AmbienteViagem::Criar()
{
  Codigo codigo = Codigo();
  Avaliacao avaliacao = Avaliacao("0");
  string nome;
  cout << "//////////////////////" << endl;
  cout << "    Criar viagens" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o nome da viagem: ";
  cin >> nome;
    Nome NomeDominio = Nome(nome);
    
    Viagem viagem = Viagem(codigo, NomeDominio, avaliacao);
    ServicoViagem->Criar(CodigoUsuario, viagem);
}

void AmbienteViagem::Atualizar()
{
  Codigo codigo;
  string CodigoViagemDominio;
  cout << "//////////////////////" << endl;
  cout << "   Atualizar viagem" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o código da viagem a ser atualizada: ";
  cin >> CodigoViagemDominio;
    codigo = Codigo(CodigoViagemDominio);

  string nome;
  cout << "2 - Digite o novo nome da viagem: ";
  cin >> nome;
    Nome NomeDominio = Nome(nome);

  string avaliacao;
  cout << "3 - Digite a nova avaliação da viagem: ";
  cin >> avaliacao;
    Avaliacao AvaliacaoDominio = Avaliacao(avaliacao);
    
    Viagem viagem = Viagem(codigo, NomeDominio, AvaliacaoDominio);
    ServicoViagem->Atualizar(CodigoUsuario, codigo, viagem);
}

void AmbienteViagem::Remover()
{
  Codigo codigo;
  string CodigoViagemDominio;
  cout << "//////////////////////" << endl;
  cout << "    Deletar viagem" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o código da viagem: ";
  cin >> CodigoViagemDominio;
    codigo = Codigo(CodigoViagemDominio);
    
    ServicoViagem->Remover(CodigoUsuario, codigo);
}

void AmbienteViagem::ListarTudo()
{
  cout << "//////////////////////" << endl;
  cout << "   Listar viagens" << endl;
  cout << "//////////////////////" << endl;

  vector<Viagem> viagens = ServicoViagem->LerTudo(CodigoUsuario);

    if (viagens.size() == 0)
        cout << "Você não possui viagens atreladas a esta conta" << endl;

  for (const auto &viagem : viagens)
  {
    cout << "Código: " << viagem.get("codigo").getValor() << endl;
    cout << "Nome: " << viagem.get("nome").getValor() << endl;
    cout << "Avaliação: " << viagem.get("avaliacao").getValor() << endl;
    cout << "//////////////////////" << endl;
  }
}

void AmbienteViagem::ConsultaCusto(Codigo CodigoViagem)
{
  cout << "//////////////////////" << endl;
  cout << "Consultar custo total da viagem" << endl;
  cout << "//////////////////////" << endl;
  cout << "Custo total da viagem: " << ServicoViagem->ConsultaCusto(CodigoUsuario, CodigoViagem) << endl;
  cout << "//////////////////////" << endl;
}

void AmbienteViagem::ListaDestinos(Codigo CodigoViagem)
{
  cout << "//////////////////////" << endl;
  cout << "   Listar destinos" << endl;
  cout << "//////////////////////" << endl;

  vector<Destino> destinos = ServicoViagem->ListaDestinos(CodigoUsuario, CodigoViagem);

  if (destinos.size() == 0)
    cout << "Você não possui destinos atrelados a esta viagem" << endl;

  for (int i = 0; i < destinos.size(); i++)
  {
    cout << "Código: " << destinos[i].get("codigo").getValor() << endl;
    cout << "Nome: " << destinos[i].get("nome").getValor() << endl;
    cout << "Data de Início: " << destinos[i].get("chegada").getValor() << endl;
    cout << "Data de Fim: " << destinos[i].get("partida").getValor() << endl;
    cout << "Avaliação: " << destinos[i].get("avaliacao").getValor() << endl;
    cout << "//////////////////////" << endl;
  }
}

void AmbienteViagem::ListaAtividades(Codigo CodigoDestino)
{
  cout << "//////////////////////" << endl;
  cout << "  Listar atividades" << endl;
  cout << "//////////////////////" << endl;

  vector<Atividade> atividades = ServicoViagem->ListaAtividades(CodigoUsuario, CodigoDestino);

  if (atividades.size() == 0)
    cout << "Você não possui atividades atreladas a este destino" << endl;

  for (int i = 0; i < atividades.size(); i++)
  {
    cout << "Código: " << atividades[i].get("codigo").getValor() << endl;
    cout << "Nome: " << atividades[i].get("nome").getValor() << endl;
    cout << "Data: " << atividades[i].get("data").getValor() << endl;
    cout << "Horário: " << atividades[i].get("horario").getValor() << endl;
    cout << "Duração: " << atividades[i].get("duracao").getValor() << endl;
    cout << "Preço: " << atividades[i].get("preco").getValor() << endl;
    cout << "Avaliação: " << atividades[i].get("avaliacao").getValor() << endl;
  }
}

void AmbienteViagem::ListaHospedagens(Codigo CodigoDestino)
{
  cout << "//////////////////////" << endl;
  cout << "   Listar destinos" << endl;
  cout << "//////////////////////" << endl;

  vector<Hospedagem> hospedagens = ServicoViagem->ListaHospedagems(CodigoUsuario, CodigoDestino);

  if (hospedagens.size() == 0)
    cout << "Você não possui hospedagens atreladas a este destino" << endl;

  for (int i = 0; i < hospedagens.size(); i++)
  {
    cout << "Código: " << hospedagens[i].get("codigo").getValor() << endl;
    cout << "Nome: " << hospedagens[i].get("nome").getValor() << endl;
    cout << "Diária: " << hospedagens[i].get("precodiaria").getValor() << endl;
    cout << "Avaliação: " << hospedagens[i].get("avaliacao").getValor() << endl;
  }
}

void AmbienteViagem::ConsultaDestino()
{
  string CodigoDestino = "";
  Codigo CodigoDestinoDominio ;
  while (true)
  {
    try
    {
      cout << "\033[2J\033[1;1H";

      cout << "//////////////////////" << endl;
      cout << "  Consultar destino" << endl;
      cout << "//////////////////////" << endl;

      cout << "Digite o código do destino: ";
      if (CodigoDestino == "")
      {
        cin >> CodigoDestino;
        CodigoDestinoDominio.setValor(CodigoDestino);
      }
      else
        cout << CodigoDestino << endl;

      while (CodigoDestinoDominio.getValor() != CodigoDestino)
      {
        cout << "Digite o código da viagem: ";
        cin >> CodigoDestino;
        CodigoDestinoDominio.setValor(CodigoDestino);
      }

      cout << "//////////////////////" << endl;
      cout << "1 - Listar hospedagens" << endl;
      cout << "2 - Listar atividades" << endl;
      cout << "3 - Retornar ao HUB" << endl;

      string option;
      cin >> option;

      cout << "\033[2J\033[1;1H";

      if (option == "1")
      {
        ListaHospedagens(CodigoDestinoDominio);
      }
      else if (option == "2")
      {
        ListaAtividades(CodigoDestinoDominio);
      }
      else if (option == "3")
        {
          break;
        }
        else
        {
          return;
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

    cout << "Pressione qualquer tecla para continuar.";
    cin.ignore();
    cin.get();
  }
}

void AmbienteViagem::ConsultaViagem()
{
  Codigo CodigoViagemDominio;
  string CodigoViagem = "";
  while (true)
  {
    try
    {
      cout << "\033[2J\033[1;1H";
      cout << "//////////////////////" << endl;
      cout << "   Consultar viagem" << endl;
      cout << "//////////////////////" << endl;
      cout << "Digite o código da viagem: ";
      if (CodigoViagem == "")
      {
        cin >> CodigoViagem;
        CodigoViagemDominio.setValor(CodigoViagem);
      }
      else
        cout << CodigoViagem << endl;

      while (CodigoViagemDominio.getValor() != CodigoViagem)
      {
        cout << "Digite o código da viagem: ";
        cin >> CodigoViagem;
        CodigoViagemDominio.setValor(CodigoViagem);
        
      }
      cout << "//////////////////////" << endl;
      cout << "1 - Consultar custo da viagem" << endl;
      cout << "2 - Listar destinos associados" << endl;
      cout << "3 - Consultar destino" << endl;
      cout << "4 - Retornar ao HUB" << endl;

      string option;
      cin >> option;

      cout << "\033[2J\033[1;1H";

      if (option == "1")
      {
        ConsultaCusto(CodigoViagemDominio);
      }
      else if (option == "2")
      {
        ListaDestinos(CodigoViagemDominio);
      }
      else if (option == "3")
      {
        ConsultaDestino();
      }
      else if (option == "4")
        {
          break;
        }
        else
        {
          return;
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

    cout << "Pressione qualquer tecla para continuar.";
    cin.ignore();
    cin.get();
    Executar(CodigoUsuario);
  }
}
