# Projeto: Controle de Matriz de LEDs com Botões e LED RGB
Este projeto foi desenvolvido para consolidar o uso de interrupções, tratamento de debouncing em botões, controle de LEDs comuns e LEDs endereçáveis WS2812, além de integrar hardware e software em um projeto funcional utilizando a placa BitDogLab e o microcontrolador RP2040.

# Descrição do Projeto
O projeto consiste em controlar uma matriz de LEDs WS2812 utilizando dois botões e também inicializar o LED RGB por um período específico. As funcionalidades implementadas são:

1. LED RGB:
O LED vermelho pisca continuamente 5 vezes por segundo.

2. Botões:
Botão A: Incrementa o número exibido na matriz de LEDs. Botão B: Decrementa o número exibido na matriz de LEDs.

2. Matriz de LEDs WS2812:
Exibe números de 0 a 9. Cada número é exibido em um formato fixo, como caracteres em estilo digital.

# Componentes Utilizados: 
1. Placa de desenvolvimento: BitDogLab (com microcontrolador RP2040).
2. Matriz de LEDs: 5x5 LEDs WS2812 (conectada à GPIO 7).
3. LED RGB: Conectado à GPIO 13.
4. Botão A: Conectado à GPIO 5.
5. Botão B: Conectado à GPIO 6.

# Estrutura do Código
O projeto está organizado em módulos para facilitar a manutenção e reutilização do código:

1. Projeto_MatrizInterativa.c:
Integra todos os módulos e implementa a lógica principal do projeto. Controla o LED RGB, os botões e a exibição dos números na matriz de LEDs.

2. buttons.c e buttons.h:
Gerencia os botões A e B, utilizando interrupções e debouncing via software.

3. matriz_leds.c e matriz_leds.h:
Controla a matriz de LEDs WS2812, exibindo os números.

4. ws2818b.pio.h:
Contém o código PIO para controlar os LEDs WS2812.

# Funcionalidades Implementadas
1. Controle de Botões com Interrupções:
Os botões são configurados para gerar interrupções quando pressionados. O debouncing é implementado via software para evitar leituras falsas.

2. Exibição de Números na Matriz de LEDs:
Cada número de 0 a 9 é exibido na matriz de LEDs. Os números foram criados manualmente usando o Piskel.

3. Piscar do LED RGB:
O LED RGB pisca continuamente em um intervalo definido de 5 vezes por segundo.


# Vídeo de Demonstração: 
Link do vídeo explicativo do projeto: https://drive.google.com/file/d/1jigIELGHVlfGz3u59r_zae0aMJ8lQpYc/view?usp=sharing



