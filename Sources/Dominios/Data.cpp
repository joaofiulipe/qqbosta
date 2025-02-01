#include "../../Includes/Dominios/Data.hpp"
#include "../../Includes/Separador/Separador.hpp"
using namespace Separador;

const std::vector<int> Data::DiasMes = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Data::validar(string valor)
{
  if (valor.find("-") != string::npos)
  {
    throw invalid_argument("Argumento invalido: formato inválido.");
  }

  if (valor.find(" ") != string::npos)
  {
    throw invalid_argument("Argumento invalido: espaços em branco não são permitidos.");
  }

  vector<string> ValorSeparado = split(valor, "/");

  if (ValorSeparado.size() != 3)
  {
    throw invalid_argument("Argumento invalido.");
  };

  int EntradaDias = stoi(ValorSeparado[0]);
  int EntradaMeses = stoi(ValorSeparado[1]);
  int EntradaAnos = stoi(ValorSeparado[2]);

  if (EntradaAnos < 0 || EntradaAnos > AnoMaximo || EntradaMeses < 1 || EntradaMeses > MesMaximo || EntradaDias < 1)
  {
    throw invalid_argument("Argumento invalido.");
  }

  int MaximoDias = DiasMes[EntradaMeses - 1];

  if ((EntradaMeses == 2 &&
       ((EntradaAnos % 4 == 0 && EntradaDias > DiasFevereiroBIS) ||
        (EntradaAnos % 4 != 0 && EntradaDias > DiasFevereiroNORMAL))) ||
      (EntradaMeses != 2 && (EntradaDias > MaximoDias)))
  {
    throw invalid_argument("Argumento invalido.");
  }
}

int Data::CalcularAlcanceDatas(string DataInicial, string DataFinal)
{
  vector<string> splitedDataInicial = split(DataInicial, "/");
  vector<string> splitedDataFinal = split(DataFinal, "/");

  int DiasIniciais = stoi(splitedDataInicial[0]);
  int MesesIniciais = stoi(splitedDataInicial[1]);
  int AnosIniciais = stoi(splitedDataInicial[2]);

  int DiasFinais = stoi(splitedDataFinal[0]);
  int MesesFinais = stoi(splitedDataFinal[1]);
  int AnosFinais = stoi(splitedDataFinal[2]);

  if (AnosIniciais > AnosFinais ||
      (AnosIniciais == AnosFinais && MesesIniciais > MesesFinais) ||
      (AnosIniciais == AnosFinais && MesesIniciais == MesesFinais && DiasIniciais > DiasFinais))
  {
    throw invalid_argument("Argumento invalido: data inicial posterior à data final.");
  }

  int Dias = DiasFinais - DiasIniciais;
  int Meses = MesesFinais - MesesIniciais;
  int Anos = AnosFinais - AnosIniciais;

  if (Dias < 0)
  {
    if (MesesIniciais == 2)
    {
      if (AnosIniciais % 4 == 0)
      {
        Dias += DiasFevereiroBIS;
      }
      else
      {
        Dias += DiasFevereiroNORMAL;
      }
    }
    else
    {
      Dias += DiasMes[MesesIniciais - 1];
    }

    Meses--;
  }

  if (Meses < 0)
  {
    Meses += MesMaximo;
    Anos--;
  }

  int DiasTotais = Anos * 365 + Meses * 30 + Dias;

  DiasTotais += Anos / 4;

  return DiasTotais;
}

bool Data::AlcanceDatas(string Data, string DataInicial, string DataFinal)
{
  vector<string> splitedData = split(Data, "/");
  vector<string> splitedDataInicial = split(DataInicial, "/");
  vector<string> splitedDataFinal = split(DataFinal, "/");

  int EntradaDias = stoi(splitedData[0]);
  int EntradaMeses = stoi(splitedData[1]);
  int EntradaAnos = stoi(splitedData[2]);

  int DiasIniciais = stoi(splitedDataInicial[0]);
  int MesesIniciais = stoi(splitedDataInicial[1]);
  int AnosIniciais = stoi(splitedDataInicial[2]);

  int DiasFinais = stoi(splitedDataFinal[0]);
  int MesesFinais = stoi(splitedDataFinal[1]);
  int AnosFinais = stoi(splitedDataFinal[2]);

  if (EntradaAnos > AnosIniciais && EntradaAnos < AnosFinais)
  {
    return true;
  }
  else if (EntradaAnos == AnosIniciais && EntradaMeses > MesesIniciais)
  {
    return true;
  }
  else if (EntradaAnos == AnosFinais && EntradaMeses < MesesFinais)
  {
    return true;
  }
  else if (EntradaAnos == AnosIniciais && EntradaMeses == MesesIniciais && EntradaDias >= DiasIniciais)
  {
    return true;
  }
  else if (EntradaAnos == AnosFinais && EntradaMeses == MesesFinais && EntradaDias <= DiasFinais)
  {
    return true;
  }
  else
  {
    return false;
  }
}