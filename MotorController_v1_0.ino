#include <WiFi.h>
#include <WebServer.h>

const char* ssid="MotorDashboard";
const char* password="ESP32";

WebServer server(80);

const int MOTOR_A_PIN=18;
const int MOTOR_B_PIN=19;

int motorAPercent=0;
int motorBPercent=0;
bool motorARunning=false;
bool motorBRunning=false;

void writeMotorA(){
  int pwm = motorARunning ? map(motorAPercent,0,100,0,255):0;
  ledcWrite(MOTOR_A_PIN,pwm);
}
void writeMotorB(){
  int pwm = motorBRunning ? map(motorBPercent,0,100,0,255):0;
  ledcWrite(MOTOR_B_PIN,pwm);
}

void setup(){
  Serial.begin(115200);
  ledcAttach(MOTOR_A_PIN,5000,8);
  ledcAttach(MOTOR_B_PIN,5000,8);

  WiFi.softAP(ssid,password);

  server.on("/setA",[](){
    motorAPercent=constrain(server.arg("value").toInt(),0,100);
    writeMotorA();
    server.send(200,"text/plain","OK");
  });

  server.on("/setB",[](){
    motorBPercent=constrain(server.arg("value").toInt(),0,100);
    writeMotorB();
    server.send(200,"text/plain","OK");
  });

  server.on("/startA",[](){motorARunning=true;writeMotorA();server.send(200,"text/plain","OK");});
  server.on("/stopA",[](){motorARunning=false;writeMotorA();server.send(200,"text/plain","OK");});
  server.on("/startB",[](){motorBRunning=true;writeMotorB();server.send(200,"text/plain","OK");});
  server.on("/stopB",[](){motorBRunning=false;writeMotorB();server.send(200,"text/plain","OK");});

server.on("/", []()
{

server.send(200,"text/html",R"rawliteral(

<!DOCTYPE html>
<html>

<head>

<meta charset="UTF-8">

<title>ESP32 Motor Dashboard</title>

<style>

body{

background:#181818;
font-family:Arial;
color:white;

display:flex;

justify-content:center;

padding-top:40px;

}

.card{

width:500px;

background:#252525;

padding:30px;

border-radius:18px;

box-shadow:0 0 25px rgba(0,0,0,.5);

}

h1{

text-align:center;

margin-bottom:30px;

}

.motor{

margin-bottom:40px;

}

.slider{

width:100%;

}

.percent{

font-size:30px;

font-weight:bold;

text-align:center;

margin-bottom:10px;

}

.number{

width:80px;

font-size:20px;

text-align:center;

margin-top:10px;

}

.buttons{

margin-top:15px;

}

button{

padding:10px 20px;

border:none;

border-radius:8px;

font-size:16px;

cursor:pointer;

margin-right:10px;

}

.start{

background:#18b318;

color:white;

}

.stop{

background:#d22;

color:white;

}

</style>

</head>

<body>

<div class="card">

<h1>Motor Dashboard</h1>

<div class="motor">

<h2>Motor A</h2>

<div class="percent">

<span id="aValue">0</span>%

</div>

<input

class="slider"

type="range"

min="0"

max="100"

value="0"

id="sliderA">

<br>

<input

class="number"

type="number"

min="0"

max="100"

value="0"

id="numberA">

<div class="buttons">

<button class="start" onclick="startA()">START</button>

<button class="stop" onclick="stopA()">STOP</button>

</div>

</div>

<hr>

<div class="motor">

<h2>Motor B</h2>

<div class="percent">

<span id="bValue">0</span>%

</div>

<input

class="slider"

type="range"

min="0"

max="100"

value="0"

id="sliderB">

<br>

<input

class="number"

type="number"

min="0"

max="100"

value="0"

id="numberB">

<div class="buttons">

<button class="start" onclick="startB()">START</button>

<button class="stop" onclick="stopB()">STOP</button>

</div>

</div>

</div>

<script>

const sliderA=document.getElementById("sliderA");
const sliderB=document.getElementById("sliderB");

const numberA=document.getElementById("numberA");
const numberB=document.getElementById("numberB");

sliderA.oninput=function(){

numberA.value=this.value;

document.getElementById("aValue").innerHTML=this.value;

fetch("/setA?value="+this.value);

}

numberA.oninput=function(){

sliderA.value=this.value;

document.getElementById("aValue").innerHTML=this.value;

fetch("/setA?value="+this.value);

}

sliderB.oninput=function(){

numberB.value=this.value;

document.getElementById("bValue").innerHTML=this.value;

fetch("/setB?value="+this.value);

}

numberB.oninput=function(){

sliderB.value=this.value;

document.getElementById("bValue").innerHTML=this.value;

fetch("/setB?value="+this.value);

}

function startA(){

fetch("/startA");

}

function stopA(){

fetch("/stopA");

}

function startB(){

fetch("/startB");

}

function stopB(){

fetch("/stopB");

}

</script>

</body>

</html>

)rawliteral");

});

  server.begin();
}

void loop(){
  server.handleClient();
}
