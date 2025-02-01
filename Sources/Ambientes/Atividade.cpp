#include "../../Includes/Ambientes/Atividade.hpp"

void AmbienteAtividade::Executar(Codigo &CodigoUsuario)
{
  this->CodigoUsuario = CodigoUsuario;

  while (true)
  {
    try
    {
      // Limpa o terminal
      cout << "\033[2J\033[1;1H";

      // Aparece as opções
      cout << "//////////////////////" << endl;
      cout << " Ambiente Atividades " << endl;
      cout << "//////////////////////" << endl;
      cout << "1 - Criar nova atividade" << endl;
      cout << "2 - Listar atividades existentes" << endl;
      cout << "3 - Atualizar atividade" << endl;
      cout << "4 - Deletar atividade" << endl;
      cout << "5 - Retornar ao HUB" << endl;
      cout << "Escolha uma das opções acima (1 a 5): ";
      string option;
      cin >> option;

      // Limpa o terminal
      cout << "\033[2J\033[1;1H";

      // Executa a opção escolhida
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

    cout << "Pressione qualquer tecla para continuar.";
    cin.ignore();
    cin.get();
  }
}

void AmbienteAtividade::Criar()
{
  Codigo codigo = Codigo();
  Avaliacao avaliacao = Avaliacao("0");
  string nome, data, horario, duracao, preco, CodigoDestinoAtividade;

  cout << "//////////////////////" << endl;
  cout << "   Criar atividade" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o nome da nova atividade: ";
  cin >> nome;
  Nome NomeDominio = Nome(nome);

  cout << "2 - Digite a data da nova atividade (DD/MM/AA): ";
  cin >> data;
  Data DataDominio = Data(data);

  cout << "3 - Digite o horário da atividade (HH:MM): ";
  cin >> horario;
  Horario HorarioDominio = Horario(horario);

  cout << "4 - Digite a duração da atividade (0 a 360 min): ";
  cin >> duracao;
  Duracao DuracaoDominio = Duracao(duracao);

  cout << "5 - Digite o preço da atividade: ";
  cin >> preco;
  Dinheiro PrecoDominio = Dinheiro(preco);

  cout << "6 - Digite o código do destino atrelado: ";
  cin >> CodigoDestinoAtividade;
  Codigo CodigoDestinoAtividadeDominio = Codigo(CodigoDestinoAtividade);

  Atividade atividade = Atividade(codigo, NomeDominio, DataDominio, HorarioDominio, DuracaoDominio, PrecoDominio, avaliacao);
  ServicoAtividade->Criar(CodigoUsuario, CodigoDestinoAtividadeDominio, atividade);
}

void AmbienteAtividade::Atualizar()
{
  string CodigoAtividade, nome, data, horario, duracao, preco, avaliacao;
  cout << "//////////////////////" << endl;
  cout << " Atualizar atividade" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o código da atividade a ser atualizada: ";
  cin >> CodigoAtividade;
  Codigo CodigoAtividadeDominio = Codigo(CodigoAtividade);

  cout << "2 - Digite o novo nome da atividade: ";
  cin >> nome;
  Nome NomeDominio = Nome(nome);

  cout << "3 - Digite a nova data da atividade (DD/MM/AA): ";
  cin >> data;
  Data DataDominio = Data(data);

  cout << "4 - Digite o novo horário da atividade (HH:MM): ";
  cin >> horario;
  Horario HorarioDominio = Horario(horario);

  cout << "5 - Digite a nova duração da atividade (0 a 360 min): ";
  cin >> duracao;
  Duracao DuracaoDominio = Duracao(duracao);

  cout << "6 - Digite o novo preço da atividade: ";
  cin >> preco;
  Dinheiro PrecoDominio = Dinheiro(preco);

  cout << "7 - Digite a nova avaliação da atividade: ";
  cin >> avaliacao;
  Avaliacao AvaliacaoDominio = Avaliacao(avaliacao);
  
  Atividade atividade = Atividade(CodigoAtividadeDominio, NomeDominio, DataDominio, HorarioDominio, DuracaoDominio, PrecoDominio, AvaliacaoDominio);
  ServicoAtividade->Atualizar(CodigoUsuario, CodigoAtividadeDominio, atividade);
}

void AmbienteAtividade::Remover()
{
  string CodigoAtividade;

  cout << "//////////////////////" << endl;
  cout << "  Deletar atividade" << endl;
  cout << "//////////////////////" << endl;
  cout << "1 - Digite o código da atividade: ";
  cin >> CodigoAtividade;
  Codigo codigo = Codigo(CodigoAtividade);

  ServicoAtividade->Remover(CodigoUsuario, codigo);
}

void AmbienteAtividade::Ler()
{
  cout << "//////////////////////" << endl;
  cout << " Lista das atividades" << endl;
  cout << "//////////////////////" << endl;

  vector<Atividade> atividades = ServicoAtividade->Ler(CodigoUsuario);

  if (atividades.size() == 0)
    cout << "Você não possui nenhuma atividade atrelada a esta conta" << endl;

  for (const auto &atividade : atividades)
  {
    cout << "Código: " << atividade.get("codigo").getValor() << endl;
    cout << "Nome: " << atividade.get("nome").getValor() << endl;
    cout << "Data: " << atividade.get("data").getValor() << endl;
    cout << "Horário: " << atividade.get("horario").getValor() << endl;
    cout << "Duração: " << atividade.get("duracao").getValor() << endl;
    cout << "Preço: " << atividade.get("preco").getValor() << endl;
    cout << "Avaliação: " << atividade.get("avaliacao").getValor() << endl;
    cout << "//////////////////////" << endl;
  }
}