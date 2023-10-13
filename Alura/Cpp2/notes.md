# Organização do processo de separação do arquivos

1. Arquivo main
2. Arquivos .cpp
3. Arquivos .hpp
4. Compilação separada
5. Adicionando os .hpp na main
6. Junção dos arquivos
7. Execução dos arquivos

## 1. Arquivo main

Primeiramente é necessário criar um arquivo principal do projeto. Neste caso estamos utilizando o **hangman_game.cpp**

## 2. Arquivos .cpp

Após a criação do arquivo main é necessário para cada função um arquivo .cpp separado. Nele é necessário tomar cuidado com **quatro coisas**

+ Incluir **todas as bibliotecas** utilizadas na função
+ Incluir **todas as funções** que são utilizadas dentro da função
+ Incluir com `extern` toddas as variaveis globais
+ Utilizar o `std::`.

## 3. Arquivos .hpp

Para adicionar no arquivo main todas as funções e para que não haja conflito de entre as próprias funções é necessário criar um arquvio **.hpp** para todas as funções. Da mesma forma é importante:

+ Adicionar todas bibliotecas necessárias para a declaração da função;
+ Adicionar todas funções neccessárias para a criação da função.

> Obs.: Para não copiar as bibliotecas mais de uma vez pode-se utilizar o comando `#pragma once`

## 5. Adicionando os arquivos .hpp na main

Agora basta adicionar os arquivos .hpp para que a main seja executada de maneira apropriada.

## 6. Compilação separada

Agora basta compilar todos os arquivos .cpp para criar um conjunto de arquivos pré-compilados. Utilizando o comando:

> `$ c++ -c *.cpp`

## 7. Junção dos arquivos

Com todos os arquviso pré compilados basta juntar todos em um arquivos executável para o projeto. Utilizando este comando: 

> `$ c++ *.o -o NOME_DO_ARQUIVO.out`