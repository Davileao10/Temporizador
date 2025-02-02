# Projeto de Semáforo com Raspberry Pi Pico W

Este repositório contém o código para simular um semáforo utilizando o microcontrolador Raspberry Pi Pico W, LEDs e temporizador periódico.

## Descrição da Atividade

A atividade consiste em criar um sistema de semáforo com temporização de 3 segundos para cada alteração de sinal, utilizando a função `add_repeating_timer_ms()` do Pico SDK. O código foi desenvolvido no arquivo `semaforo.c`.

### Componentes Utilizados

- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (vermelho, amarelo e verde)
- 03 Resistores de 330 Ω
- LED RGB para o experimento com o BitDogLab (GPIOs 11, 12 e 13)

### Funcionalidade

1. **Sequência do Semáforo**: O semáforo inicia com o LED vermelho aceso, seguido pelo LED amarelo e, por fim, o LED verde.
2. **Temporização**: Cada alteração de sinal do semáforo ocorre a cada 3 segundos (3.000ms).
3. **Função de Call-back**: A mudança de estado dos LEDs é controlada pela função de call-back do temporizador, seguindo o modelo da função `repeating_timer_callback()` apresentada em aula.
4. **Impressão Serial**: A rotina principal, dentro de um loop `while`, imprime uma mensagem a cada 1 segundo (1.000ms), com informações sobre o estado do semáforo.

### Experimentação

O código foi experimentado utilizando um LED RGB conectado aos pinos GPIO 11, 12 e 13 do Raspberry Pi Pico W.

## Como Executar

### Pré-requisitos

- Raspberry Pi Pico W
- VS Code
- Simulador do Wowki
- Pico SDK
- Diagrama JSON configurado no Wowki para simulação

### Passos para Compilação e Execução

1. Clone este repositório para o seu ambiente local.
2. Abra o projeto no VS Code.
3. Utilize o simulador do Wowki com o diagrama JSON configurado para simular o semáforo no Raspberry Pi Pico W.
4. Compile o código diretamente pelo VS Code.
5. Carregue o código no Raspberry Pi Pico W (se for testar no hardware real).
6. Conecte os LEDs (vermelho, amarelo, verde) aos pinos GPIO correspondentes, com resistores de 330Ω.
7. Se desejar realizar o experimento com o LED RGB, conecte-o aos pinos GPIO 11, 12 e 13.

### Exemplo de Saída Serial

A cada 1 segundo, será impressa uma mensagem serial no terminal informando o estado atual do semáforo.

