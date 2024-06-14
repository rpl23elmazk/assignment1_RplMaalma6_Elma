# termasuk  < WiFi.h >
# sertakan  < HTTPClient.h >

// Konfigurasi Wi-Fi
const  char *ssid = " 123456789" ;
const  char *kata sandi = " saropahh " ;

// Konfigurasi sensor
const  int sensorPin = 4 ;
const String sensorName = " sg2alok " ;

// Konfigurasi RestAPI
const  char * baseRoute = " http://192.168.43.34:5000/sensor/ " ;
const  int permintaanPenundaan = 1000 ;

batalkan  pengaturan () {
  Serial. mulai ( 9600 );

  Wifi. mulai (ssid, kata sandi);
  Serial. println ( " Menghubungkan ke jaringan WiFi " );
  while (WiFi.status ( ) != WL_CONNECTED) {
    penundaan ( 500 );
    Serial. mencetak ( " . " );
  }
  Serial. println ( " " );
  Serial. print ( " Terhubung ke jaringan WiFi dengan Alamat IP: " );
  Serial. println (WiFi.localIP ( ));
}

 lingkaran kosong () {
  penundaan (permintaan Penundaan);
  int gas = analogRead (sensorPin);

  if (WiFi.status ( )== WL_CONNECTED){
    Klien WiFiClient;
    Klien HTTP http;

    http. mulai (klien, baseRoute+sensorName);
    int kode status = http. POST ( String (gas));

    http. akhir ();
  } kalau tidak {
    Serial. println ( " WiFi Terputus " );
  }
}