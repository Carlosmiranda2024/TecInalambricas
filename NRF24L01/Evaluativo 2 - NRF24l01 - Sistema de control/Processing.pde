import processing.serial.*; 

Serial myPort;

// variables
String data="";
String noObject;

float pixsDistance;
int iAngle = 0, iDistance = 0;

void setup() {
  
  size(1200, 700);
  smooth();

  println(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);

  myPort.bufferUntil('\n'); // 🔥 ahora leemos por línea completa
}

void draw() {
  
  fill(98,245,31);

  noStroke();
  fill(0,4); 
  rect(0, 0, width, height-height*0.065); 
  
  fill(98,245,31);

  drawRadar(); 
  drawLine();
  drawObject();
  drawText();
}

void serialEvent(Serial myPort) {

  data = myPort.readStringUntil('\n');

  if (data != null) {
    data = trim(data);

    // 🔥 ejemplo: "Angulo: 90 | 20 | ENVIADO"
    try {
      String[] partes = split(data, '|');

      if (partes.length >= 2) {

        // ---- ANGULO ----
        String anguloStr = partes[0]; // "Angulo: 90"
        anguloStr = anguloStr.replace("Angulo:", "");
        anguloStr = trim(anguloStr);
        iAngle = int(anguloStr);

        // ---- DISTANCIA ----
        String distStr = trim(partes[1]); // "20"
        iDistance = int(distStr);
      }

    } catch(Exception e) {
      println("Error parseando: " + data);
    }
  }
}

void drawRadar() {

  pushMatrix();
  translate(width/2,height-height*0.074);
  noFill();
  strokeWeight(2);
  stroke(98,245,31);

  arc(0,0,(width-width*0.0625),(width-width*0.0625),PI,TWO_PI);
  arc(0,0,(width-width*0.27),(width-width*0.27),PI,TWO_PI);
  arc(0,0,(width-width*0.479),(width-width*0.479),PI,TWO_PI);
  arc(0,0,(width-width*0.687),(width-width*0.687),PI,TWO_PI);

  line(-width/2,0,width/2,0);
  line(0,0,(-width/2)*cos(radians(30)),(-width/2)*sin(radians(30)));
  line(0,0,(-width/2)*cos(radians(60)),(-width/2)*sin(radians(60)));
  line(0,0,(-width/2)*cos(radians(90)),(-width/2)*sin(radians(90)));
  line(0,0,(-width/2)*cos(radians(120)),(-width/2)*sin(radians(120)));
  line(0,0,(-width/2)*cos(radians(150)),(-width/2)*sin(radians(150)));

  popMatrix();
}

void drawObject() {

  pushMatrix();
  translate(width/2,height-height*0.074);
  strokeWeight(9);
  stroke(255,10,10);

  pixsDistance = iDistance*((height-height*0.1666)*0.025);

  if(iDistance < 40){
    line(
      pixsDistance*cos(radians(iAngle)),
      -pixsDistance*sin(radians(iAngle)),
      (width-width*0.505)*cos(radians(iAngle)),
      -(width-width*0.505)*sin(radians(iAngle))
    );
  }

  popMatrix();
}

void drawLine() {

  pushMatrix();
  strokeWeight(9);
  stroke(30,250,60);
  translate(width/2,height-height*0.074);

  line(0,0,
    (height-height*0.12)*cos(radians(iAngle)),
    -(height-height*0.12)*sin(radians(iAngle))
  );

  popMatrix();
}

void drawText() {

  pushMatrix();

  if(iDistance>40) {
    noObject = "Out of Range";
  } else {
    noObject = "In Range";
  }

  fill(0,0,0);
  noStroke();
  rect(0, height-height*0.0648, width, height);

  fill(98,245,31);
  textSize(40);

  text("Angle: " + iAngle +" °", width-width*0.48, height-height*0.0277);
  text("Dist: " + iDistance +" cm", width-width*0.26, height-height*0.0277);

  popMatrix(); 
}