# BlueGuard-Edge

Este projeto consiste na criação de uma boia com um sistema de sensores para a captação de dados de temperatura, ph e turbidez da água do oceano.

Os dados de coletados de temperatura, turbidez e ph, serão visualizados em um lcd_I2C. Além disso, utilizaremos uma bargraph para mostrar o quão ácido está a água. Será utilizado uma  bargraph com as seguintes indicações:

Menos que 3 barras acessas: indica que o ambiente está básico.

3 barras acessas: indica que o ambiente está neutro.

Mais que 3 barras acessas: indica que o ambiente está ácido.

## Dependências - Materiais Necessários

| Quantidade        | Componente                                                       |
| ----------------- | ---------------------------------------------------------------- |
| 1                 | Arduino Uno R3                                                   |
| 1                 | LDR (Fotorresistor)                                              |
| 1                 | Resistor de 10 kOhm                                              |
| 10                | Resistores de 1 kOhm                                             |
| 1                 | Sensor de temperatura DS18B20                                    |
| 1                 | Potenciomêtro                                                    |
| 1                 | Bargraph                                                         |
| 1                 | Lcd 16X2 I2C                                                     |
|                   | Fios (Jumpers)                                                   |
| 1                 | Protoboard                                                       |

## Como reproduzir o projeto?

- Após reunir todos os materiais necessários siga o passo a passo abaixo:

**1. Montagem do circuito:**

- Conecte o Arduino Uno à protoboard, ligando um pino GND a linha negativa e o pino 5V na linha positiva.
- Conecte a Bargraph a 10 pinos digitais do Arduino (por exemplo, 2 ao 11) e ligue o outro lado aos 10 resistores de 1 kOhm e os ligue na linha negativa da protoboard. 
- Conecte o LDR a um dos pinos analógicos do Arduino (por exemplo, A1) o terminal do meio a linha negativa da protoboard e o outro terminal conecte a linha positiva da protoboard.
- Conecte o sensor de temperatura na protoboard. O terminal da ponta conecte na linha negativa da protoboard, o terminal central em um resistor de 10kOhms e em um pino digital(por exemplo, 12) e o último a linha positiva da protoboard.
- Conecte o potenciômetro a linha negativa da protoboard, o terminal do meio a um pino analógico (por exemplo, A0) e o outro terminal na linha positiva da protoboard.
- Conecte a placa LCD a linha negativa da protoboard, o segundo terminal na linha positiva da protoboard, o terceiro terminal no pino analógio A4 e o último terminal no pino analógico A5.
- A seguir, uma imagem para auxiliar na montagem:

    <img src="CheckPoint.JPG"/>

**2. Codificação do Arduino:**

- Abra o Arduino IDE ou utilize a plataforma online Tinkercad para escrever o código.
- Copie o [código fornecido](Codigo.cpp) e cole no editor de código do Arduino.
- Verifique se o código está de acordo com a montagem do seu circuito.

**3. Teste do sistema:**

- Observe o comportamento dos LEDs e do buzzer de acordo com a luminosidade do ambiente.
- Teste diferentes níveis de luminosidade para verificar a resposta do sistema.

**4. Ajustes (se necessário):**

- Se os limiares de luminosidade ou o comportamento dos LEDs/buzzer precisarem ser ajustados, faça as modificações no código conforme necessário.

## Autores

- [@AliAndrea1](https://github.com/AliAndrea1)

- [@brunacostaz](https://github.com/brunacostaz)

- [@Laurasdc](https://github.com/Laurasdc)

- [@querenprates](https://github.com/querenprates)

- [@sofiafernandes857](https://github.com/sofiafernandes857)
