cmake_minimum_required(VERSION 3.10)
project(ProjetoTP1)

# Configuração do padrão de C++
set(CMAKE_CXX_STANDARD 17)

# Localizar o SQLite3
find_package(SQLite3 REQUIRED)

# Incluir diretórios
include_directories(include lib)

# Localizar fontes automaticamente
file(GLOB SOURCES "Sources/*.cpp" "Sources/**/*.cpp" )

# Adicionar o executável
add_executable(ProjetoTP1 ${SOURCES})

# Linkar bibliotecas
target_link_libraries(ProjetoTP1 PRIVATE SQLite::SQLite3)

# Configurações de compilação específicas
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Otimizações de performance para Release
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -march=native -DNDEBUG")
else()
    # Configurações para Debug
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -fsanitize=address -fno-omit-frame-pointer")
endif()
