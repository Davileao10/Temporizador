#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_VERMELHO 11
#define LED_AMARELO  12
#define LED_VERDE    13

// Variável para controlar o estado atual do semáforo
volatile int estado_atual = 0; // 0: vermelho, 1: amarelo, 2: verde

// Função de callback para o timer
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);
    
    // Atualiza o estado e liga o LED correspondente
    if (estado_atual == 0) { // Vermelho -> Amarelo
        gpio_put(LED_AMARELO, 1);
        estado_atual = 1;
    } 
    else if (estado_atual == 1) { // Amarelo -> Verde
        gpio_put(LED_VERDE, 1);
        estado_atual = 2;
    }
    else { // Verde -> Vermelho
        gpio_put(LED_VERMELHO, 1);
        estado_atual = 0;
    }
    
    return true; // Continua o timer
}

int main() {
    // Inicializa o stdio
    stdio_init_all();
    
    // Inicializa os GPIOs dos LEDs
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    
    // Configura os GPIOs como saída
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    
    // Estado inicial: LED vermelho aceso
    gpio_put(LED_VERMELHO, 1);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);
    
    // Configura o timer para 3 segundos (3000ms)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    // Loop principal
    int contador = 0;
    while (1) {
        printf("Sistema em execucao - %d segundos decorridos\n", contador);
        contador++;
        sleep_ms(1000);
    }

    return 0;
}