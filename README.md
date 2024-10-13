# Computação Gráfica - UFABC

Repositório usado durante as aulas de Computação Gráfica na UFABC em Q3.2024
Este projeto utiliza **OpenGL**, **GLU** e **FreeGLUT** para criar um programa em C++. 
Este README contém as instruções detalhadas para preparar o ambiente de desenvolvimento e rodar o projeto no **Visual Studio Code**.

## Requisitos

Certifique-se de ter o seguinte software instalado:

1. **Visual Studio Code** - Editor de código.
2. **MSYS2** - Sistema de compilação e ambiente de desenvolvimento no Windows.
3. **MinGW-w64** - Compilador C/C++ para Windows.
4. **GDB** - Depurador para C/C++.
5. **OpenGL**, **GLU**, e **FreeGLUT** - Bibliotecas gráficas.

---

## Passo a Passo

### 1. Instalar o **MSYS2**

1. Acesse o site do [MSYS2](https://www.msys2.org) e faça o download do instalador.

2. Após a instalação, abra o terminal do MSYS2 (MSYS2 UCRT64) e atualize os pacotes:
   ```bash
   pacman -Syu
   ```
   Se for solicitado, feche e reabra o terminal e execute o comando novamente para concluir a atualização.

3. No terminal do MSYS2, execute o seguinte comando para instalar o compilador g++, o make, e o GDB:
    ```bash
   pacman -S mingw-w64-ucrt-x86_64-opengl-devel mingw-w64-ucrt-x86_64-freeglut```

4. No mesmo terminal, instale as bibliotecas necessárias:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-opengl-devel mingw-w64-ucrt-x86_64-freeglut```

### 2. Configurar o Visual Studio Code
No Visual Studio Code, vá até a aba de Extensões (Ctrl+Shift+X) e procure por C/C++ (Microsoft). Instale essa extensão para obter suporte à linguagem e depuração.

### 3. Rodando o Projeto

1. Compilar o código
Para compilar o código, pressione Ctrl+Shift+B. Isso executará a tarefa de compilação configurada no tasks.json.

2. Executar com depuração
Pressione F5 para compilar e executar o programa com depuração. O VS Code usará o GDB para depurar o código, exibindo qualquer erro ou breakpoint que tenha sido definido.

### 4. Dicas
Certifique-se de que o caminho do GDB no miDebuggerPath no launch.json está correto. Você pode verificar o caminho exato rodando where gdb no terminal do MSYS2.

### 5. Problemas Comuns

1. Erro: cannot find -lfreeglut:
Verifique se o caminho da biblioteca FreeGLUT está correto e se foi instalada usando o comando:
    ```bash
    pacman -S mingw-w64-ucrt-x86_64-freeglut
    ```

2. Erro: miDebuggerPath inválido:
Certifique-se de que o caminho para o gdb.exe no launch.json aponta para o executável correto.