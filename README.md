# Controle de Matriz de LEDs e LED RGB com Botões

Este projeto foi desenvolvido como parte do curso **EmbarcaTech**, promovido pelo **CEPEDI**, **SOFTEX** e **HwIT - Hardware Innovation Technologies**, para consolidar conhecimentos em interrupções, debouncing e controle de LEDs no microcontrolador **RP2040**, utilizando a placa de desenvolvimento **BitDogLab**.

## 📝 Enunciado do Projeto

O objetivo é criar um sistema que combine hardware e software para:
1. Demonstrar o uso de interrupções e tratamento de bouncing em botões.
2. Manipular LEDs comuns e endereçáveis (WS2812).
3. Fixar o uso de resistores de pull-up internos em botões.

### 🔧 Componentes Utilizados
- **Matriz 5x5 de LEDs WS2812**: Conectada à GPIO 7.
- **LED RGB**: Conectado às GPIOs 11, 12 e 13.
- **Botão A**: Conectado à GPIO 5.
- **Botão B**: Conectado à GPIO 6.

---

## 🎯 Funcionalidades do Projeto

1. **LED RGB Vermelho Pisca Continuamente**  
   O LED vermelho do RGB pisca 5 vezes por segundo.
   
2. **Controle de Números na Matriz de LEDs WS2812**  
   - **Botão A**: Incrementa o número exibido na matriz de LEDs.  
   - **Botão B**: Decrementa o número exibido na matriz de LEDs.  
   Os números são exibidos em formato digital claro e fixo (0 a 9).

3. **Uso de Interrupções e Debouncing**  
   - As ações dos botões são tratadas por interrupções (IRQs).  
   - Implementação de **debouncing via software** para evitar múltiplos acionamentos.

---

## 📂 Organização do Código

### Arquivos Incluídos
- **`main.c`**: Código principal com implementação de funcionalidades.
- **`ws2812.pio`**: Código PIO para controlar os LEDs WS2812.

---

## 📋 Requisitos do Projeto

1. **Interrupções:**  
   As funcionalidades dos botões utilizam rotinas de interrupção para garantir responsividade.  

2. **Debouncing:**  
   O bouncing dos botões é tratado via software, utilizando controle de tempo entre os acionamentos.  

3. **Controle de LEDs:**  
   - LED RGB conectado diretamente às GPIOs.  
   - Matriz de LEDs WS2812 controlada via PIO.

4. **Estrutura do Código:**

O código está organizado da seguinte forma:

- **Inicialização dos componentes**: LEDs RGB, botões e matriz de LEDs WS2812.
- **Definição dos números**: Cada número de 0 a 9 é representado por uma matriz 5x5 de LEDs.
- **Funções auxiliares**: Funções para manipulação de cores e exibição de números na matriz.
- **Rotina de interrupção**: Trata os eventos dos botões A e B, realizando o debouncing e atualizando o número exibido.
- **Loop principal**: Controla o piscar do LED RGB vermelho.

## 🚀 Como Executar o Projeto

### Pré-requisitos
- **Placa BitDogLab** configurada e conectada.
- Ambiente de desenvolvimento configurado com **SDK do RP2040**.

### Passos
1. Clone este repositório:
   ```bash
   git clone <[URL_DO_REPOSITORIO](https://github.com/queirozPatrick/interrupcoes)>
