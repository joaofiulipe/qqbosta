#ifndef MODELO_INTERFACE_HPP
#define MODELO_INTERFACE_HPP

#include <sqlite3.h>
#include <bits/stdc++.h>
using namespace std;

/**
 * @class Modelo
 * @brief Classe base para a interação com o banco de dados SQLite.
 * 
 * Esta classe fornece métodos para criar tabelas e executar comandos SQL.
 */
class Modelo
{
private:
    /**
     * @brief Cria a tabela de contas no banco de dados.
     */
    void CriarTableConta();

    /**
     * @brief Cria a tabela de viagens no banco de dados.
     */
    void CriarTableViagem();

    /**
     * @brief Cria a tabela de destinos no banco de dados.
     */
    void CriarTableDestino();

    /**
     * @brief Cria a tabela de atividades no banco de dados.
     */
    void CriarTableAtividade();

    /**
     * @brief Cria a tabela de hospedagens no banco de dados.
     */
    void CriarTableHospedagem();

    /**
     * @brief Função de callback para processar os resultados das consultas SQL.
     * @param notUsed Parâmetro não utilizado.
     * @param argc Número de colunas no resultado.
     * @param argv Valores das colunas no resultado.
     * @param azColName Nomes das colunas no resultado.
     * @return int Código de retorno.
     */
    static int callback(void *notUsed, int argc, char **argv, char **azColName);

protected:
    int status; ///< Status da execução do comando SQL.
    static vector<map<string, string>> results; ///< Resultados das consultas SQL.
    string ComandoSQL; ///< Comando SQL a ser executado.
    sqlite3 *db; ///< Ponteiro para o banco de dados SQLite.

public:
    /**
     * @brief Cria todas as tabelas no banco de dados.
     */
    void CriarTables();

    /**
     * @brief Executa o comando SQL armazenado em ComandoSQL.
     */
    void Executar();

    /**
     * @brief Construtor da classe Modelo.
     */
    Modelo();

    /**
     * @brief Destrutor da classe Modelo.
     */
    virtual ~Modelo();
};

#endif