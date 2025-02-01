#include "../Includes/Servicos/Modelo.hpp"
#include "../Includes/Controladora.hpp"
#include "../Includes/Construtora.hpp"

#include "../Includes/Servicos/Viagem.hpp"
#include "../Includes/Ambientes/Viagem.hpp"

#include "../Includes/Servicos/Conta.hpp"
#include "../Includes/Ambientes/Conta.hpp"

int main()
{
  Modelo modelo = Modelo();
  modelo.CriarTables();

  Construtora construtora;
  Controladora controladora;

  construtora.construir(&controladora);
  controladora.Executar();


  return 0;
}