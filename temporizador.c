#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs e do botão
#define LED_AZUL    11
#define LED_VERMELHO 12
#define LED_VERDE    13
#define BOTAO_GPIO   5

// Variável para controlar o estado do sistema
volatile bool sistema_ativo = false;

// Função de callback para o temporizador
int64_t temporizador_callback(alarm_id_t id, void *user_data) {
    static int estado = 0;

    if (estado == 0) {
        // Mantém dois LEDs
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);
        estado = 1;
        add_alarm_in_ms(3000, temporizador_callback, NULL, false);
    } else if (estado == 1) {
        // Mantém apenas um LED
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_VERDE, 1);
        estado = 2;
        add_alarm_in_ms(3000, temporizador_callback, NULL, false);
    } else {
        // Desliga todos os LEDs
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_VERDE, 0);
        estado = 0;
        sistema_ativo = false; // Permite novo acionamento do botão
    }

    return 0;
}

// Função de callback para a interrupção do botão
void gpio_callback(uint gpio, uint32_t events) {
    if (gpio == BOTAO_GPIO && (events & GPIO_IRQ_EDGE_FALL) && !sistema_ativo) {
        printf("Botão pressionadooo!\n");
        sistema_ativo = true;

        // Liga todos os LEDs
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);

        // Inicia o temporizador para mudar o estado após 3 segundos
        add_alarm_in_ms(3000, temporizador_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();

    // Inicialização dos LEDs
    gpio_init(LED_AZUL);
    gpio_init(LED_VERMELHO);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicialização do botão
    gpio_init(BOTAO_GPIO);
    gpio_set_dir(BOTAO_GPIO, GPIO_IN);
    gpio_pull_up(BOTAO_GPIO); // Considera botão com pull-up

    // Configuração da interrupção do botão
    gpio_set_irq_enabled_with_callback(BOTAO_GPIO, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true, &gpio_callback);

    while (1) {
        tight_loop_contents(); // Loop principal vazio para aguardar interrupções
    }

    return 0;
}
