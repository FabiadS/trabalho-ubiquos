#include "LoRaWan_APP.h"
#include "EmonLib.h"

EnergyMonitor SCT013;
/* OTAA para*/
uint8_t devEui[] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x06, 0x69, 0x1F };
uint8_t appEui[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t appKey[] = { 0x2F, 0xC3, 0x96, 0xD0, 0x59, 0x5F, 0xD7, 0xC4, 0xF3, 0xD0, 0x57, 0xAA, 0xC0, 0x00, 0x87, 0x7D };

//pinos usados
double tensao = 220;
int potencia;
int valorLDR;


/* ABP para*/
uint8_t nwkSKey[] = { 0x15, 0xb1, 0xd0, 0xef, 0xa4, 0x63, 0xdf, 0xbe, 0x3d, 0x11, 0x18, 0x1e, 0x1e, 0xc7, 0xda,0x85 };
uint8_t appSKey[] = { 0xd7, 0x2c, 0x78, 0x75, 0x8c, 0xdc, 0xca, 0xbf, 0x55, 0xee, 0x4a, 0x77, 0x8d, 0x16, 0xef,0x67 };
uint32_t devAddr =  ( uint32_t )0x007e6ae1;

/*LoraWan channelsmask, default channels 0-7*/ 
uint16_t userChannelsMask[6]={ 0x00FF,0x0000,0x0000,0x0000,0x0000,0x0000 };

/*LoraWan region, select in arduino IDE tools*/
LoRaMacRegion_t loraWanRegion = ACTIVE_REGION;

/*LoraWan Class, Class A and Class C are supported*/
DeviceClass_t  loraWanClass = CLASS_C;

/*the application data transmission duty cycle.  value in [ms].*/
uint32_t appTxDutyCycle = 15000;

/*OTAA or ABP*/
bool overTheAirActivation = true;

/*ADR enable*/
bool loraWanAdr = true;

/* Indicates if the node is sending confirmed or unconfirmed messages */
bool isTxConfirmed = true;

/* Application port */
uint8_t appPort = 2;

uint8_t confirmedNbTrials = 4;

/* Prepares the payload of the frame */
static void prepareTxFrame( uint8_t port ) {
    int ldrValue = le_LDR(); // Read LDR value
    Serial.println(ldrValue);
    int pot = le_potencia(); // Read LDR value
    Serial.println(pot);
   
    //int randomNumber = random(1, 200);

  
    // Print the random number to the serial monitor
    //Serial.println(randomNumber);
    char message[24];
    snprintf(message, sizeof(message), "LDR: %d, Cur: %d", ldrValue, pot);

    appDataSize = strlen(message); // Set appDataSize to the length of the message

    for (int i = 0; i < appDataSize; i++) {
        appData[i] = (uint8_t)message[i]; // Convert each character to its ASCII value
    }
}


float le_LDR() {
  valorLDR = analogRead(4);  
  valorLDR = map(valorLDR, 0, 1850, 0, 100);
  return valorLDR;
}

int le_potencia() {
  double Irms = SCT013.calcIrms(1480);   // Calcula o valor da Corrente
   
  potencia = Irms * tensao;          // Calcula o valor da Potencia Instantanea   
  if (potencia < 35 || potencia > 500){
      Irms = 0;
      potencia = 0;
  } 
  return potencia;
}

void setup() {
  Serial.begin(115200);
  Mcu.begin(HELTEC_BOARD,SLOW_CLK_TPYE);
  SCT013.current (5, 6);
  //randomSeed(analogRead(0));

}

void loop()
{
  switch( deviceState )
  {
    case DEVICE_STATE_INIT:
    {
#if(LORAWAN_DEVEUI_AUTO)
      LoRaWAN.generateDeveuiByChipID();
#endif
      LoRaWAN.init(loraWanClass,loraWanRegion);
      //Serial.print("inited");

      LoRaWAN.setDefaultDR(3);
      break;
    }
    case DEVICE_STATE_JOIN:
    {
      LoRaWAN.join();
      break;
    }
    case DEVICE_STATE_SEND:
    {
      prepareTxFrame( appPort );
      //Serial.println("ENVIANDO");

      LoRaWAN.send();
      deviceState = DEVICE_STATE_CYCLE;
      break;
    }
    case DEVICE_STATE_CYCLE:
    {
      // Schedule next packet transmission
      txDutyCycleTime = appTxDutyCycle + randr( -APP_TX_DUTYCYCLE_RND, APP_TX_DUTYCYCLE_RND );
      LoRaWAN.cycle(txDutyCycleTime);
      deviceState = DEVICE_STATE_SLEEP;
      
      //Serial.println("cycle");

      break;
    }
    case DEVICE_STATE_SLEEP:
    {
      LoRaWAN.sleep(loraWanClass);
      break;
    }
    default:
    {
      deviceState = DEVICE_STATE_INIT;
      break;
    }
  }
}





