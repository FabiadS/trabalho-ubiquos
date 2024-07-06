# Sensor de corrente

## Descrição

Os sensores de corrente são responsáveis por medir os níveis de corrente dos postes de iluminação até 15A.

<img src="/hardware_utilizado/Sensor de corrente/sensor de corrente.png" width="250" height="200">

## Especificações e características

- Modelo: SCT-013-000 ([Datasheet](https://www.makerhero.com/img/files/download/SCT013-Datasheet.pdf))
- Corrente de entrada: 0 – 100 A
- Tipo de entrada; Corrente Alternada (AC)
- Sinal de saída: Corrente/50mA
- Precisão: ±3%
- Material do Core: Ferrite
- Dielétrico: 6000V AC/1min
- Taxa anti-chama: UL94-V0
- Plug de saída: 3,5mm
- Dimensão abertura: 13 mm x 13 mm
- Temperatura de trabalho: -25 a +70°C
- Comprimento do cabo: 150 cm

## Pinagem

## Código

```bash

#include "EmonLib.h"

EnergyMonitor SCT013;
//EnergyMonitor emon1;
int pinSCT = 5;   //Pino analógico conectado ao SCT-013
int tensao = 220;
int potencia;
void setup()
{
    Serial.begin(115200);

    SCT013.current(5, 6);
    //SCT013.current(pinSCT, 111.1);

}
void loop()
{
    double Irms = SCT013.calcIrms(1480);   // Calcula o valor da Corrente
   
    potencia = Irms * tensao;          // Calcula o valor da Potencia Instantanea   
    if (potencia < 35 || potencia > 500){
      Irms = 0;
      potencia = 0;
  } 

    Serial.print("Corrente = ");
    Serial.print(Irms);
    Serial.println(" A");
    
    Serial.print("Potencia = ");
    Serial.print(potencia);
    Serial.println(" W");
    delay(1000);

}

```



