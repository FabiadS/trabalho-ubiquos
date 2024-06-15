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

Continue lendo para obter uma visão detalhada da implementação do projeto, que inclui instruções de montagem de hardware, configuração de software e operação do sistema.

## Hardware

### Sensor de corrente não invasivo
<p>Os sensores de corrente são responsáveis por medir os níveis de corrente dos postes de iluminação até 15A.</p>
<img src="hardware_utilizado/sensor de corrente.png">

### Sensor de luminosidade
<p>Os sensores de luminosidade são responsáveis por medir os níveis de luminosidade dos postes de iluminação através da variação de sua resistência interna.</p>
<img src="hardware_utilizado/sensor de luminosidade.png">

### Gateway Dragino
<p>Responsável por coletar dados enviados pelo Lora e transmiti-los para a nuvem IoT.</p>

### Esp 32 Lora Wifi (V3)
<p>Responsável pela comunicação sem fio entre os sensores de corrente, luminosidade e o gateway através do recurso de rede LoRaWan.</p>
<img src="hardware_utilizado/esp 32 wifi v3.png">



## Esquema de Conexão

###


 
