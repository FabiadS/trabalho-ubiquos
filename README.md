# Sistema de monitoramento com gateway LoRaWAN para o gerenciamento da iluminação em postes de iluminação pública

## Descrição do projeto
O projeto "Sistema de Monitoramento com Gateway LoRaWAN para o gerenciamento da iluminação em postes de iluminação pública" desenvolvido como parte de um trabalho para Projeto de Sistemas Ubiquos na UFSC, tem como objetivo empregar o gateway LoRaWAN como intermediário para coletar dados de sensores instalados nos postes e transmiti-los para uma nuvem IoT, visando otimizar o monitoramento e o controle da iluminação, promovendo eficiência energética e manutenção proativa.

## Autores do projeto
* Fabiola Augusta Dahlke Spredemann;
* Ramom da Silva

## Introdução

### Objetivos específicos
* Estabelecer uma comunicação eficiente entre os sensores de iluminação e o gateway LoRaWAN, garantindo a integridade e confiabilidade dos dados coletados;
* Busca-se configurar o gateway para enviar os dados de maneira segura e eficaz para a nuvem IoT, assegurando uma transmissão eficiente e uma gestão centralizada dos dados de iluminação pública.


## Hardware
Os principais dispositivos de hardware estão mostrados nessa seção, mas no [Esquema de conexão](#esquema-de-conexão) podemos observar todos os outros dispositivos (resistores).

#### [Sensor de corrente não invasivo (SCT-013)](https://github.com/FabiadS/trabalho-ubiquos/tree/main/hardware_utilizado/Sensor%20de%20corrente)

#### [Sensor de luminosidade (LDR)](https://github.com/FabiadS/trabalho-ubiquos/tree/main/hardware_utilizado/Sensor%20de%20luminosidade)

#### [Gateway Dragino](https://github.com/FabiadS/trabalho-ubiquos/tree/main/hardware_utilizado/Dragino)

#### [Esp 32 Lora Wifi (V3)](https://github.com/FabiadS/trabalho-ubiquos/tree/main/hardware_utilizado/ESP32%20Wifi%20V3)

## Resumo do hardware utilizado
- ESP32 Lora Wifi V3
- Sensor de corrente (SCT013 100A)
- Sensor de luminosidade (LDR 5 mm)
- LoRaWan Gateway (Dragino)
- 2 resistores de 10kΩ
- 1 resistor de 220R Ω
- 1 resistor de 33R Ω
- 1 capacitor de 100μF

## Software

### Softwares Utilizados

#### [Arduino IDE](https://www.arduino.cc/en/software)
Ferramenta de desenvolvimento de software de código aberto amplamente utilizada para programar microcontroladores e dispositivos eletrônicos. A comunicação LoRaWAN pode ser implementada em dispositivos Arduino usando módulos LoRa.

#### [The Things Network (TTN)](https://www.thethingsnetwork.org/)

Fornece uma infraestrutura de rede de código aberto baseada em LoRaWAN, que permite a instalação de gateways e construção de aplicativos IoT em cima dessa infraestrutura.

#### [ThinkSpeak](https://thingspeak.com/)
A plataforma de IoT ThingSpeak fornece serviços para coleta, visualização e análise de dados de sensores e dispositivos conectados à internet.


### Configurações

#### Dragino
<p>Utilizar a frequência da Austrália AU915 e faixa de frequências 1.</p>

#### Arduino IDE
- Utilizar como código de exemplo do fabriacante (HELTEC ESP 32 → LORAWAN → LORAWAN), lembrando de configurar a região nas opções como AU e trocar a classe para C.

    ```DeviceClass_t  loraWanClass = CLASS_C;```

- Para ler os dados das portas, deve-se usar OBRIGATORIAMENTE a numeração do GPIO (senão vai dar problema de leitura, e na pinagem tem repetição das portas).

- Para enviar os dados, que devem ser inteiros, salvar em um array de char, conforme código abaixo:
  ```
    char message[24];
    snprintf(message, sizeof(message), "LDR: %d, Cur: %d", ldrValue, pot);

    appDataSize = strlen(message); // Set appDataSize to the length of the message

    for (int i = 0; i < appDataSize; i++) {
        appData[i] = (uint8_t)message[i]; // Convert each character to its ASCII value
    }

A imagem abaixo apresenta a saída no terminal dos dados vindo do LDR e do cálculo da potência através da corrente lida no SCT013, respectivamente.

<img src="software_config/resultados_cmd.jpeg">

#### TTN
<p>Criar dispositivo customizado usando OBRIGATORIAMENTE a classe C e faixa de frequências 1 (a comunicação falha se for diferente). Pode-se utilizar a TTN para gerar os ids necessários para o código (devEUI, appEUI e appkey), conforme mostra a imagem abaixo. </p>
<img src="software_config/configuracao_TTN.png">

<p>A imagem abaixo mostra como os dados chegam no TTN.</p>
<img src="software_config/dados_TTN.jpeg">

Além disso, para os dados serem enviados corretamente para o ThinkSpeak, é preciso que haja uma decodificação da mensagem do ESP no TTN. Para isso, é preciso seguir os seguintes passos:
1. Ir no payload formatter e selecionar a opção "custom javascript"
2. Usar o código abaixo.
<img src="software_config/configuracao_TTN_2.png">

#### ThinkSpeak
Basta seguir a documentação oficial e utilizar o endpoint abaixo.

- [Documentação oficial](https://www.thethingsindustries.com/docs/integrations/cloud-integrations/thingspeak/)
- [Endpoint](https://api.thingspeak.com/things_network/v3/update)

## Esquema de Conexão
<img src="hardware_utilizado/esquema_conexao.jpg">

## Pinagem

| Pino                  | Número do Pino | Observações                                                                     |
| --------------------- | -------------- | ------------------------------------------------------------------------------- |
| `LDR`                 | GPIO4          | Utilizado para leitura de dados do sensor LDR                                   |
| `SCT013`              | GPIO5          | Utilizado para leitura de dados do sensor SCT013                                |
| `3.3V`                | 2              | Utlizado como VCC para o LDR                                                    |
| `5V`                  | 2              | Utilizado como VCC para o SCT013                                                |
| `GND`                 | 1              | Utilizado como GND para os sensores                                             |


## Imagem do projeto final
<img src="hardware_utilizado/montagem_fisica.jpeg">






 
