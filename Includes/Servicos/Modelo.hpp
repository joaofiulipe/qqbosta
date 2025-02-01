#ifndef MODELO_INTERFACE_HPP
#define MODELO_INTERFACE_HPP

#include <sqlite3.h>
#include <bits/stdc++.h>
using namespace std;

class Modelo
{
private:
    

    void CriarTableConta();
    void CriarTableViagem();
    void CriarTableDestino();
    void CriarTableAtividade();
    void CriarTableHospedagem();

    static int callback(void *notUsed, int argc, char **argv, char **azColName);

protected:
    int status;
    static vector<map<string, string>> results;
    string ComandoSQL;
    sqlite3 *db;

public:
    void CriarTables();
    void Executar();
    Modelo();
    virtual ~Modelo();
};

#endif 