#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "lib/matriz_leds.h" // Biblioteca para controle da matriz de LEDs
#include "lib/buttons.h"     // Biblioteca para controle dos botões

// Definições de pinos e constantes
#define MATRIZ_PIN 7
#define LED_PIN 13
#define BLINK_INTERVAL_MS 10
#define ANIMACAO 1

// Declaração das animações dos números de 0 a 9 
extern uint32_t num0[][25];
extern uint32_t num1[][25];
extern uint32_t num2[][25];
extern uint32_t num3[][25];
extern uint32_t num4[][25];
extern uint32_t num5[][25];
extern uint32_t num6[][25];
extern uint32_t num7[][25];
extern uint32_t num8[][25];
extern uint32_t num9[][25];

// Array de ponteiros para as animações
uint32_t (*numeros[])[25] = {num0, num1, num2, num3, num4, num5, num6, num7, num8, num9};

// Variáveis globais
volatile int current_number = 0;

// Função para exibir o número na matriz de LEDs
void exibir_numero(PIO pio, uint sm, uint8_t num) {
    if (num < 10) {
        rgb_led rgb_data[ANIMACAO][25];
        hex_to_rgb(numeros[num], rgb_data, ANIMACAO); // Converte cores hex para RGB
        ajustar_brilho(rgb_data, 0.8, ANIMACAO);     // Ajusta brilho para 80%
        enviar_animacao(rgb_data, pio, sm, ANIMACAO); // Envia dados para a matriz
    }
}

// Função para piscar o LED 
void blink_led() {
    gpio_put(LED_PIN, 1); // LED on
    sleep_ms(BLINK_INTERVAL_MS);
    gpio_put(LED_PIN, 0); // LED off
    sleep_ms(BLINK_INTERVAL_MS);
}

int main() {
    stdio_init_all(); // Inicializa a comunicação USB (opcional)
    PIO pio = pio0;   // Usa o bloco PIO 0
    uint sm = configurar_matriz(pio, MATRIZ_PIN); // Configura a matriz de LEDs

    // Configuração do LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Inicializa os botões
    init_buttons();

    while (1) {
        // Verifica botão A (incrementa número)
        if (is_button_a_pressed()) {
            current_number = (current_number + 1) % 10;
        }

        // Verifica botão B (decrementa número)
        if (is_button_b_pressed()) {
            current_number = (current_number - 1 + 10) % 10;
        }

        // Atualiza a matriz de LEDs com o número atual
        exibir_numero(pio, sm, current_number);

        blink_led();
    }

    return 0;
}