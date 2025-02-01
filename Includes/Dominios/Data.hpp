#ifndef DATA_DOMAIN_INTERFACE_HPP
#define DATA_DOMAIN_INTERFACE_HPP

#include "./Dominio.hpp"
#include <vector>
#include <string>

using namespace std;

/**
 * @class Data
 * @brief Classe responsável pela representação de uma data.
 * 
 * Esta classe herda de Dominio e gerencia a validação e manipulação de datas.
 */
class Data : public Dominio
{
private:
    static const int DiasFevereiroBIS = 29; ///< Número de dias em fevereiro em ano bissexto.
    static const int DiasFevereiroNORMAL = 28; ///< Número de dias em fevereiro em ano não bissexto.
    static const vector<int> DiasMes; ///< Vetor contendo o número de dias em cada mês.
    static const int MesMaximo = 12; ///< Número máximo de meses.
    static const int AnoMaximo = 99; ///< Número máximo de anos.

    /**
     * @brief Método para validar o valor da data.
     * @param valor Valor da data a ser validada.
     */
    void validar(string valor) override;

public:
    /**
     * @brief Construtor da classe Data com valor inicial.
     * @param valor Valor inicial da data.
     */
    Data(string valor);

    /**
     * @brief Método estático para calcular o alcance entre duas datas.
     * @param DataInicial Data inicial.
     * @param DataFinal Data final.
     * @return int Número de dias entre as duas datas.
     */
    static int CalcularAlcanceDatas(string DataInicial, string DataFinal);

    /**
     * @brief Método estático para verificar se uma data está dentro de um intervalo.
     * @param date Data a ser verificada.
     * @param DataInicial Data inicial do intervalo.
     * @param DataFinal Data final do intervalo.
     * @return bool Verdadeiro se a data estiver dentro do intervalo, falso caso contrário.
     */
    static bool AlcanceDatas(string date, string DataInicial, string DataFinal);
};

/**
 * @brief Construtor da classe Data com valor inicial.
 * @param valor Valor inicial da data.
 */
inline Data::Data(string valor)
{
    this->setValor(valor);
}

#endif // DATA_DOMAIN_INTERFACE_HPP