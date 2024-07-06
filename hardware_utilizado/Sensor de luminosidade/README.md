# Sensor de Luminosidade (LDR)

## Descrição

Os sensores de luminosidade são responsáveis por medir os níveis de luminosidade dos postes de iluminação através da variação de sua resistência interna.

<img src="/hardware_utilizado/Sensor de luminosidade/sensor de luminosidade.png" width="250" height="200">

## Especificações e características
- Modelo: GL5528 ([datasheet](https://www.makerhero.com/img/files/download/GL5528-Datasheet.pdf))
- Diâmetro: 5mm
- Tensão máxima: 150VDC
- Potência máxima: 100mW
- Tensão de operação:  -30°C a 70°C
- Material semicondutor: CdS
- Pico de Espectro: 540nm
- Comprimento com terminais: 32mm
- Resistência no escuro: 1 MΩ (Lux 0)
- Resistência na luz: 10-20 KΩ (Lux 10)

## Pinagem

## Código
```bash

//Declaracao da variavel do pino do sensor LDR 
#define pinoLDR 4


//Declaracao da variavel que recebera a leitura dos valores do sensor
int valorLDR = 0;
// Valor mais baixo 730 0.587 volts
// valor mais 2745 2.212

void setup() {
  //Iniciamos uma comunicacao serial para fazermos as leituras no Monitor Serial
  Serial.begin(115200);

  //pinMode(18, INPUT);
  //pinMode(7, INPUT);

}

void loop() {

  delay(1000);  // Delay for a second
  //valorLDR = analogRead(15);  
  //Serial.println(valorLDR);
   
  valorLDR = analogRead(4);  
  valorLDR = map(valorLDR, 0, 1850, 0, 100);
  Serial.println(valorLDR);

  delay(250);
}

```

