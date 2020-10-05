#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
#define buttonA 7

boolean isCelsius = false;
static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup( ){
  Serial.begin(9600);
  pinMode(buttonA, INPUT_PULLUP);  
}

static bool measure_environment( float *temperature, float *humidity ){
  static unsigned long measurement_timestamp = millis( );

  if( millis( ) - measurement_timestamp > 3000ul ){
    if( dht_sensor.measure( temperature, humidity ) == true ){
      measurement_timestamp = millis( );
      return( true );
    }
  }
  return( false );
}

float toFarenheit(float celsius) {
  return (celsius * 9/5) + 32;
}

void loop( ){
  if (digitalRead(buttonA) == LOW) {
    isCelsius = !isCelsius;
  }
  
  float temperature;
  float humidity;
  
  if( measure_environment( &temperature, &humidity ) == true ){
    Serial.print( "T = " );
    isCelsius ? Serial.print( temperature, 1 ) : Serial.print( toFarenheit(temperature), 1 );
    isCelsius ? Serial.print( " deg. C, H = " ) : Serial.print( " deg. F, H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
  }
}
