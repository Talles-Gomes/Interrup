#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "matriz_leds.h"
#include "pico/bootrom.h"

#define tempo_frame 250
const char leitura;
// RGB_cod cor1 = obter_cor_por_parametro_RGB(0,0,0);

void animacao(PIO pio, uint sm){
    Matriz_leds_config matriz = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    
    imprimir_desenho(matriz, pio, sm);//animacao joaoeman
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz2, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz3, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz4, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz5, pio, sm);
    sleep_ms(tempo_frame);
}

void animacao_b(PIO pio, uint sm){
    Matriz_leds_config matriz_b = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 0
        {{0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}}, // Linha 1
        {{0.5, 0.5, 0.0}, {0.0, 0.0, 0.5}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.5}, {0.5, 0.5, 0.0}}, // Linha 2
        {{0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}}, // Linha 3
        {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_b2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 0
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 1
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 2
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 3
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };
    Matriz_leds_config matriz_b3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 0
        {{0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}}, // Linha 1
        {{0.5, 0.5, 0.0}, {0.0, 0.0, 0.5}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.5}, {0.5, 0.5, 0.0}}, // Linha 2
        {{0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}}, // Linha 3
        {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_b4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 0
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 1
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 2
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 3
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };
    Matriz_leds_config matriz_b5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 0
        {{0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}}, // Linha 1
        {{0.5, 0.5, 0.0}, {0.0, 0.0, 0.5}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.5}, {0.5, 0.5, 0.0}}, // Linha 2
        {{0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}}, // Linha 3
        {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 4
    };

    imprimir_desenho(matriz_b, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_b2, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_b3, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_b4, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_b5, pio, sm);
    sleep_ms(tempo_frame);
}

void animacao_c(PIO pio, uint sm){
    Matriz_leds_config matriz_c = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config matriz_c2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config matriz_c3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };

    Matriz_leds_config matriz_c5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };


    imprimir_desenho(matriz_c, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_c2, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_c3, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_c4, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_c5, pio, sm);
    sleep_ms(tempo_frame);
}

void animacao_d(PIO pio, uint sm){
    Matriz_leds_config matriz_d = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 0
        {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.3, 0.0, 0.3}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 1
        {{0.2, 0.2, 0.2}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.2, 0.2, 0.2}}, // Linha 2
        {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.3, 0.0, 0.3}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 3
        {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 4
    };

    Matriz_leds_config matriz_d2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.3, 0.0, 0.3}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 0
        {{0.2, 0.2, 0.2}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.2, 0.2, 0.2}}, // Linha 1
        {{0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}}, // Linha 2
        {{0.2, 0.2, 0.2}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.2, 0.2, 0.2}}, // Linha 3
        {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.3, 0.0, 0.3}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 4
    };

    Matriz_leds_config matriz_d3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.2, 0.2, 0.2}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.2, 0.2, 0.2}}, // Linha 0
        {{0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}}, // Linha 2
        {{0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}}, // Linha 3
        {{0.2, 0.2, 0.2}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.2, 0.2, 0.2}}, // Linha 4
    };

    Matriz_leds_config matriz_d4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}}, // Linha 0
        {{0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}}, // Linha 1
        {{0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}}, // Linha 2
        {{0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}}, // Linha 3
        {{0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}}, // Linha 4
    };

    Matriz_leds_config matriz_d5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}}, // Linha 0
        {{0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}}, // Linha 1
        {{0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}}, // Linha 2
        {{0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}}, // Linha 3
        {{0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}, {0.0, 0.3, 0.3}, {0.3, 0.0, 0.3}}, // Linha 4
    };


    imprimir_desenho(matriz_d, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_d2, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_d3, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_d4, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_d5, pio, sm);
    sleep_ms(tempo_frame);
}
void apagar(PIO pio, uint sm){
    Matriz_leds_config matriz_w = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    imprimir_desenho(matriz_w, pio, sm);
    }
void branco(PIO pio, uint sm){
Matriz_leds_config matriz_branco = {
    //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
    // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
    {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 0
    {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 1
    {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 2
    {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 3
    {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 4
    };
    imprimir_desenho(matriz_branco, pio, sm);
    }
void anima_05(PIO pio, uint sm){
    Matriz_leds_config matriz_f1 =  {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f6 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.7, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.7, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f7 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.8, 0.8, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.7, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.7, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.8, 0.8, 0.0}}, // Linha 4
    };
    imprimir_desenho(matriz_f1, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f2, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f3, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f4, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f5, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f6, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f7, pio, sm);
    sleep_ms(1000);
}    
int main()
{
    PIO pio = pio0;
    uint sm = configurar_matriz(pio);
    while (true)
    {
            switch(leitura)
        {
            case 'A' :
            //desliga todos os leds
            break;
            case 'B' :
            //Acende os leds azuis com 100% de intensidade
            break;
            case 'C' :
            //Acende os leds vermelhos com 80% de intensidade
            break;
            case 'D' :
            //Acende os leds verdes com 50% de intensidade
            break;
            case '#' :
            branco(pio, sm);//Acende os leds brancos com 20% de intensidade
            break;
            case '1' :
            //Animação de Douglas
            break;
            case '2' :
            //Animação de Ana Luiza
            break;
            case '3' :
            //Animação de Léo Nunes
            break;
            case '4' :
            //Animação de Alisson
            break;
            case '5' :
            anima_05(pio, sm);//Animação de Talles Gomes
            break;
            case '6' :
            //Animação de Carolina
            break;
            case '7' :
            animacao_b(pio, sm);//Animação de Enzo Lisboa
            break;
            case '8' :
            animacao(pio, sm);//Animação de João, joaoeman
            break;
            case '9' :
            animacao_c(pio, sm);//Animação de Enzo Lisboa
            break;
            case '0' :
            animacao_d(pio, sm);//Animação de Enzo Lisboa
            break;
            case '*' :
            reset_usb_boot(0, 0);//Animação de Enzo Lisboa
            break;
            
        }      
    }
    
}
