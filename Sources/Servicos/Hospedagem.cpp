#include "../../Includes/Servicos/Hospedagem.hpp"


void ModeloHospedagem::Criar(Codigo &CodigoUsuario, Codigo &CodigoHospedagemDestino, Hospedagem &NovaHospedagem) {
    sqlite3_stmt *stmt;

    ComandoSQL = "SELECT codigoviagem FROM destino WHERE codigo = ?";
    results.clear();
    sqlite3_prepare_v2(db, ComandoSQL.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, CodigoHospedagemDestino.getValor().c_str(), -1, SQLITE_STATIC);
    
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        string codigoViagem = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        sqlite3_finalize(stmt);

        ComandoSQL = "SELECT codigoconta FROM viagem WHERE codigo = ?";
        sqlite3_prepare_v2(db, ComandoSQL.c_str(), -1, &stmt, nullptr);
        sqlite3_bind_text(stmt, 1, codigoViagem.c_str(), -1, SQLITE_STATIC);
        
        if (sqlite3_step(stmt) != SQLITE_ROW || 
            CodigoUsuario.getValor() != reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))) {
            sqlite3_finalize(stmt);
            throw invalid_argument("Viagem não existente ou pertencente a outra conta");
        }
    } else {
        sqlite3_finalize(stmt);
        throw invalid_argument("Destino não encontrado");
    }
    sqlite3_finalize(stmt);

    ComandoSQL = "INSERT INTO hospedagem (codigo, nome, precodiaria, avaliacao, codigodestino) "
                 "VALUES (?, ?, ?, ?, ?)";
    sqlite3_prepare_v2(db, ComandoSQL.c_str(), -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, NovaHospedagem.get("codigo").getValor().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, NovaHospedagem.get("nome").getValor().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, NovaHospedagem.get("precodiaria").getValor().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, NovaHospedagem.get("avaliacao").getValor().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, CodigoHospedagemDestino.getValor().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw invalid_argument("Erro na criação da hospedagem");
    }

    sqlite3_finalize(stmt);
}


void ModeloHospedagem::Atualizar(Codigo &CodigoUsuario, Codigo &CodigoHospedagem, Hospedagem &HospedagemAtualizada)
{
    ComandoSQL = "SELECT codigodestino FROM hospedagem WHERE codigo = '" + CodigoHospedagem.getValor() + "';";
    results.clear();
    this->Executar();

    ComandoSQL = "SELECT codigoviagem FROM destino WHERE codigo = '" + results[0]["codigodestino"] + "';";
    results.clear();
    this->Executar();

    ComandoSQL = "SELECT codigoconta FROM viagem WHERE codigo = '" + results[0]["codigoviagem"] + "';";
    results.clear();
    this->Executar();

    if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
    {
        throw invalid_argument("Hospedagem não existente ou pertencente a outra conta");
    }

    string NomeHospedagem = HospedagemAtualizada.get("nome").getValor();
    string PrecoDiariaHospedagem = HospedagemAtualizada.get("precodiaria").getValor();
    string AvaliacaoHospedagem = HospedagemAtualizada.get("avaliacao").getValor();

    ComandoSQL = "UPDATE hospedagem SET nome = '" + NomeHospedagem + "', precodiaria = '" + PrecoDiariaHospedagem + "', avaliacao = '" + AvaliacaoHospedagem + "' WHERE codigo = '" + CodigoHospedagem.getValor() + "';";
    results.clear();
    this->Executar();

  if (status != SQLITE_OK)
  {
    throw invalid_argument("Erro na atualização da hospedagem");
  }
}

void ModeloHospedagem::Remover(Codigo &CodigoUsuario, Codigo &CodigoHospedagem)
{

    ComandoSQL = "SELECT codigodestino FROM hospedagem WHERE codigo = '" + CodigoHospedagem.getValor() + "';";
    results.clear();
    this->Executar();

    ComandoSQL = "SELECT codigoviagem FROM destino WHERE codigo = '" + results[0]["codigodestino"] + "';";
    results.clear();
    this->Executar();

    ComandoSQL = "SELECT codigoconta FROM viagem WHERE codigo = '" + results[0]["codigoviagem"] + "';";
    results.clear();
    this->Executar();

    if (results.empty() || results[0]["codigoconta"] != CodigoUsuario.getValor())
    {
        throw invalid_argument("Hospedagem inexistente ou pertencente a outra conta");
    }

    ComandoSQL = "DELETE FROM hospedagem WHERE codigo = '" + CodigoHospedagem.getValor() + "';";
    results.clear();
    this->Executar();

    if (status != SQLITE_OK)
    {
        throw invalid_argument("Erro na remoção da hospedagem");
    }
}

vector<Hospedagem> ModeloHospedagem::Ler(Codigo &CodigoUsuario)
{
    ComandoSQL = "SELECT l.* FROM hospedagem l INNER JOIN destino d ON l.codigodestino = d.codigo INNER JOIN viagem v ON d.codigoviagem = v.codigo WHERE v.codigoconta = '" + CodigoUsuario.getValor() + "';";
    results.clear();
    this->Executar();

    if (status != SQLITE_OK)
    {
        throw invalid_argument("Erro na leitura das hospedagens");
    }

    vector<Hospedagem> hospedagens;
    for (size_t i = 0; i < results.size(); i++)
    {
        Codigo codigo = Codigo(results[i]["codigo"]);
        Nome nome = Nome(results[i]["nome"]);
        Dinheiro precodiaria = Dinheiro(results[i]["precodiaria"]);
        Avaliacao avaliacao = Avaliacao(results[i]["avaliacao"]);
        Hospedagem hospedagem = Hospedagem(codigo, nome, precodiaria, avaliacao);
        hospedagens.push_back(hospedagem);
    }
    return hospedagens;
}