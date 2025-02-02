#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "matriz_leds.h"
#include "pico/bootrom.h"


int main()
{
    uint leitura;
    PIO pio = pio0;
    uint sm = configurar_matriz(pio);
    while (true)
    {
        
        switch(leitura)
        {
            case 0 :
                num0(pio, sm); // número 0
                break;
            case 1 :
                num1(pio, sm);// número 1
                break;
            case 2 :
                num2(pio, sm); // número 2
                break;
            case 3 :
                num3(pio, sm); // número 3
                break;
            case 4 :
                num4(pio,sm); // número 4
                break;
            case 5 :
                num5(pio, sm); // número 5
                break;
            case 6 :
                num6(pio, sm); // número 6
                break;
            case 7 :
                num7(pio, sm); // número 7
                break;
            case 8 :
                num8(pio, sm); // número 8
                break;
            case 9 :
                num9(pio, sm); // número 9
                break;

        }
    }
}
