#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>


float imc(float peso, float altura) {
    return peso / (altura * altura);
}

void classificacao(float imc) {
    printf("\nClassificacao do IMC:\nIMC <18,5 - baixo peso.\nIMC >18,5 até 24,9 - Peso adequado.\nIMC >=25 até 29,9 - Sobrepeso.\nIMC >30,0 até 34,9 - obesidade grau I.\nIMC >35 até 39,9 - obesidade grau II.\nIMC >40 - obesidade grau III\n\nSua classificação é: ");

    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc <= 24.9) {
        printf("Peso saudavel\n");
    } else if (imc <= 29.9) {
        printf("Sobrepeso\n");
    } else if (imc <= 34.9) {
        printf("Obesidade Grau I\n");
    } else if (imc <= 39.9) {
        printf("Obesidade Grau II\n");
    } else {
        printf("Obesidade Grau III\n");
    }
}

void pesoIdeal(float altura) {
    printf("Seu peso ideal é entre %.2f kg e %.2f kg.\n", (altura * altura * 18.5), (altura * altura * 24.9));
}

int main() {

    printf("=========================================================\n"
           "Projeto: Calculadora Índice de Massa Corporal\n"
           "Data de criação: 30/10/2023\n"
           "Autor: Luana Martins, Pedro, Lucas Nascimento, Jonathan\n"
           "Curso: Análise e Desenvolvimento de Sistemas º1N-30\n"
           "Disciplina: Coding: Algoritmo e Estrutura de Dados\n"
           "Descrição: Este programa calcula o Índice de Massa Corporal (IMC) de um paciente, classifica o resultado e exibe as informações em um formato fácil de entender. \n \n"
           "O IMC é uma medida comum utilizada para avaliar se uma pessoa está acima do peso ideal, se está com o peso ideal ou se está abaixo do peso.\n =========================================================\n\n\n");

    printf("CALCULADORA IMC - Indice de Massa Corporal\n\n");

    char nome[100];
    float peso, altura;

    printf("Digite seu nome completo: "); 
    scanf("%[^\n]", nome);

    printf("Digite seu peso em kg: "); //Lê peso
    scanf("%f", &peso);
    while (peso <= 0 || isnan(peso)) { // Verifica se o peso é válido
        printf("Peso inválido, digite novamente: \n");
        getchar();
        scanf("%f", &peso);
      }

    printf("Digite sua altura em metros: "); //Lê altura
    scanf("%f", &altura);
    while (altura <= 0 || isnan(altura)) { // Verifica se a altura é válida
        printf("Altura inválida, digite novamente: \n");
        getchar();
        scanf("%f", &altura);
  }

    system("clear"); //Limpa o console


    float resultadoIMC = imc(peso, altura);

    printf("\n--------------Fixa do paciente--------------\n Nome: %s\n Altura: %.2f m\n Peso: %.2f kg\n IMC: %.2f kg/m2 \n", nome, altura, peso, resultadoIMC);

    classificacao(resultadoIMC);
    pesoIdeal(altura);

  printf("--------------------------------------------");

    return 0;
}




/* O %[^\n] é um formato de entrada que diz ao scanf() para ler uma string de qualquer tamanho, 
  até que encontre um caractere de nova linha (\n)
  %s só lê até o primeiro espaço em branco*/