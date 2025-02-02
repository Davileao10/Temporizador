# Temporizador de Um Disparo (One Shot)

## Código Fonte

O código principal encontra-se no arquivo [`temporizador.c`](./temporizador.c).

Este projeto implementa um sistema de temporização para o acionamento de LEDs, utilizando a função `add_alarm_in_ms()` do Pico SDK. O sistema é controlado por um botão (pushbutton) e aciona três LEDs (azul, vermelho e verde), mudando seu estado com base em um temporizador.

## Componentes Utilizados

- **Microcontrolador**: Raspberry Pi Pico W
- **LEDs**: Azul, Vermelho e Verde
- **Resistores**: 330 Ω (para cada LED)
- **Botão (Pushbutton)**: Usado para iniciar a sequência de LEDs

## Funcionamento

1. **Clique no Botão**: Quando o usuário pressiona o botão, todos os três LEDs são ligados (nível alto).
2. **Temporização**: A cada 3 segundos (3.000ms), a sequência de LEDs muda:
   - Primeiro, os três LEDs acesos.
   - Depois, dois LEDs ligados.
   - Por fim, apenas um LED ligado.
3. **Botão Desabilitado Durante o Tempo de Atraso**: O botão só pode alterar o estado dos LEDs quando o último LED for desligado, prevenindo mudanças enquanto as rotinas de temporização estão em execução.

## Funcionalidades

- O código utiliza a função `add_alarm_in_ms()` para a temporização dos LEDs.
- A mudança de estado dos LEDs é implementada em funções de callback.
- O código foi projetado para garantir que o botão só seja capaz de acionar uma nova sequência quando o processo anterior for concluído.

## Como Executar

### Pré-requisitos:

- **Hardware**:
  - Raspberry Pi Pico W
  - LEDs (azul, vermelho e verde)
  - Resistores de 330 Ω
  - Pushbutton

- **Software**:
  - **VS Code** configurado com o ambiente Pico SDK
  - **Simulador Wokwi** integrado ao VS Code

### Passos para Configuração:

1. **Configuração do Ambiente**:
   - Certifique-se de ter o **VS Code** configurado com o **Pico SDK** e o **simulador Wokwi** integrado. O arquivo `diagrama.json` foi configurado para facilitar o uso do simulador no ambiente de desenvolvimento.
   - **Configuração do Wokwi**: O arquivo `diagrama.json` define a configuração do hardware para a simulação, incluindo o Raspberry Pi Pico W, LEDs e o botão. Abra o simulador no VS Code e utilize este arquivo para garantir que a simulação será realizada corretamente.

2. **Compilação e Execução**:
   1. Conecte os LEDs aos GPIOs correspondentes do Raspberry Pi Pico W.
   2. Conecte o botão ao GPIO 5.
   3. Compile o código utilizando o VS Code com o ambiente Pico SDK configurado.
   4. Carregue o código no Raspberry Pi Pico W ou execute a simulação no Wokwi.

3. **Testando**:
   - Ao pressionar o botão, observe os LEDs mudarem de estado a cada 3 segundos.

### Simulação no Wokwi:

Se você deseja testar o código sem a necessidade de hardware físico, utilize o **simulador Wokwi**. O arquivo `diagrama.json` já está configurado para a simulação com o Raspberry Pi Pico W, LEDs e o botão. Para isso:
1. Abra o **VS Code** e execute o simulador Wokwi com o diagrama já configurado.
2. Você verá a simulação dos LEDs mudando de estado conforme a temporização definida no código.



