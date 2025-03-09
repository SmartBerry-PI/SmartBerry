// declarando a porta do sensor
const int PINO_SENSOR_UMIDADE_SOLO = A0;

// função executada assim que o arduino ligar
void setup() {
  //  taxa de velocidade de processamento entre o arduino  e a  máquina 
  Serial.begin(9600);
  // o dado que o arduino armazenará atraves do sensor 
  pinMode(PINO_SENSOR_UMIDADE_SOLO, INPUT);
}
// função para o cálculo e apresentação dos dados da umidade do solo 
// a função será executada  constantemente enquanto o arduino estiver ligado
void loop() {
  // variavel local do tipo inteiro que irá armazenar o dado coletado anteriormente pela porta A0
  int leituraSensor = analogRead(PINO_SENSOR_UMIDADE_SOLO);
  // variavel local que ira armazenar o calulo da porcentagem da umidade do solo 
  // float porcentagemUmidade = (leituraSensor *5 / 1023.0) * 100; ao fazer desta maneira quando o sensor entra
  //em contato com a agua ao inves da umidade aumentar ela diminui
  float porcentagemUmidade = (leituraSensor / 1023.0) * 100; // o sensor de solo capacitivo retorna um valor
  //analogivo maior para solos umidos e menor para soloso secos lá encima o codigo esta invertendo os valorer 
  // imprimindo o calculo  feito anteriormente na tela 
  Serial.print("Umidade do Solo: ");
  Serial.print(porcentagemUmidade);
  Serial.println(" %");

  // o tempo da espera de um segundo para repetir o loop 
  delay(1000);
}