/*  Basic code to driver Stepper Motor using A4988
    Dibuat oleh : Djukarna
    sumbu Z menggunakan lead screw dengan pitch 8 mm artinya 1 putaran penuh berpindah 8 mm
    stepper motor untuk 1 putaran butuh 200 step, sehingga per step, lead screww akan berpindah
    sejauh 1/100 mm.
    HIGH = turun, LOW = naik
    PWM atmega 256 pipn 44, 45 atau 46 !
    koreksi lagi sistem modul nya, string dan integer !!!
    buat UI dengan processing !
*/
#include <Servo.h>
#define stepZ 4
#define arahZ 7
#define stepX 2
#define arahX 5
#define stepY 3
#define arahY 6
#define stepB 12
#define arahB 13
#define limitZ 11
#define limitY 10
#define limitX 9
#define limitB A3
#define turun HIGH
#define naik LOW
#define cw HIGH
#define ccw LOW
int Zlimit;
int Ylimit;
int Xlimit;
int Blimit;

Servo DOF5;
Servo Gripper;

void setup() {
  Serial.begin(9600);
  DOF5.attach(44);
  Gripper.attach(45);
  pinMode(stepZ, OUTPUT);
  pinMode(arahZ, OUTPUT);
  pinMode(limitZ, INPUT);
  pinMode(stepX, OUTPUT);
  pinMode(arahX, OUTPUT);
  pinMode(limitY, INPUT);
  pinMode(stepY, OUTPUT);
  pinMode(arahY, OUTPUT);
  pinMode(limitX, INPUT);
  pinMode(limitB, INPUT);
  pinMode(stepB, OUTPUT);
  pinMode(arahB, OUTPUT);
  digitalWrite(limitZ, HIGH);
  digitalWrite(limitY, HIGH);
  digitalWrite(limitX, HIGH);
  digitalWrite(limitB, HIGH);
  Serial.println("ROBOT SCARA");
  Serial.println("format command : arah,perpindahan(mm);arah,sudut;arah,sudut:0.");
  // homeZ();
  //delay(1000);
  //homeY();
  // delay(1000);
  // homeX();
  //delay(1000);
  // homeB();
  // delay(1000);
  // DOF5.write(65);
  // Gripper.write(70);
}

void homeZ() {
  Zlimit = digitalRead(limitZ);
  while (Zlimit == HIGH) {
    digitalWrite(arahZ, turun);
    digitalWrite(stepZ, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepZ, LOW);
    delayMicroseconds(1000);
    Zlimit = digitalRead(limitZ);
  }
  delay(1000);
  digitalWrite(arahZ, naik);
  for ( int i = 0; i < 2500; i++) {
    digitalWrite(stepZ, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepZ, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
}

void homeX() {
  Xlimit = digitalRead(limitX);
  while (Xlimit == HIGH) {
    digitalWrite(arahX, ccw);
    digitalWrite(stepX, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepX, LOW);
    delayMicroseconds(2000);
    Xlimit = digitalRead(limitX);
  }
  delay(1000);
  digitalWrite(arahX, cw);
  for ( int i = 0; i < 575; i++) {
    digitalWrite(stepX, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepX, LOW);
    delayMicroseconds(2000);
  }
  delay(1000);
}

void homeY() {
  Ylimit = digitalRead(limitY);
  while (Ylimit == HIGH) {
    digitalWrite(arahY, cw);
    digitalWrite(stepY, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepY, LOW);
    delayMicroseconds(2000);
    Ylimit = digitalRead(limitY);
  }
  delay(1000);
  digitalWrite(arahY, ccw);
  for ( int i = 0; i < 285; i++) {
    digitalWrite(stepY, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepY, LOW);
    delayMicroseconds(2000);
  }
  delay(1000);
}

void homeB() {
  Blimit = digitalRead(limitB);
  while (Blimit == HIGH) {
    digitalWrite(arahB, cw);
    digitalWrite(stepB, HIGH);
    delayMicroseconds(3000);
    digitalWrite(stepB, LOW);
    delayMicroseconds(3000);
    Blimit = digitalRead(limitB);
  }
  delay(1000);
  digitalWrite(arahB, ccw);
  for ( int i = 0; i < 400; i++) {
    digitalWrite(stepB, HIGH);
    delayMicroseconds(3000);
    digitalWrite(stepB, LOW);
    delayMicroseconds(3000);
  }
  delay(1000);
}
void Movebase(int dirB, int sudutB) {
  int teta2;
  teta2 = sudutB;
  digitalWrite(arahB, dirB);
  for (int i = 0; i < teta2; i++) {
    digitalWrite(stepB, HIGH);
    delayMicroseconds(3500);
    digitalWrite(stepB, LOW);
    delayMicroseconds(3500);
  }

}

void MoveZ(int dirZ, int mm) {
  int z;
  z = mm / 0.04;
  digitalWrite(arahZ, dirZ);
  for (int i = 0; i < z; i++) {
    digitalWrite(stepZ, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepZ, LOW);
    delayMicroseconds(1000);
  }
}

void MoveX(int dirX, int sudutX) {
  int teta0;
  teta0 = sudutX;
  digitalWrite(arahX, dirX);
  for (int i = 0; i < teta0; i++) {
    digitalWrite(stepX, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepX, LOW);
    delayMicroseconds(2000);
  }
}

void MoveY(int dirY, int sudutY) {
  int teta1;
  teta1 = sudutY;
  digitalWrite(arahY, dirY);
  for (int i = 0; i < teta1; i++) {
    digitalWrite(stepY, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepY, LOW);
    delayMicroseconds(2000);
  }
}

void Move(int dirZ, int mm, int dirX, int sudutX, int dirY, int sudutY, int dirB, int sudutB, int dof, int grip) {
  int z;
  z = mm / 0.04;
  digitalWrite(arahZ, dirZ);
  for (int i = 0; i < z; i++) {
    digitalWrite(stepZ, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepZ, LOW);
    delayMicroseconds(1000);
  }
  int teta0;
  teta0 = sudutX;
  digitalWrite(arahX, dirX);
  for (int i = 0; i < teta0; i++) {
    digitalWrite(stepX, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepX, LOW);
    delayMicroseconds(2000);
  }
  int teta1;
  teta1 = sudutY;
  digitalWrite(arahY, dirY);
  for (int i = 0; i < teta1; i++) {
    digitalWrite(stepY, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepY, LOW);
    delayMicroseconds(2000);
  }
  int teta2;
  teta2 = sudutB;
  digitalWrite(arahB, dirB);
  for (int i = 0; i < teta2; i++) {
    digitalWrite(stepB, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepB, LOW);
    delayMicroseconds(2500);
  }

  int d;
  d = dof;
  DOF5.write(d);

  int g;
  g = grip;
  Gripper.write(g);
}

void loop() {
  // Serial.println("flag_0"); //sudah masuk looping
  if (Serial.available()) {
    String direction_Z;
    String Z;
    
    String direction_X;
    String X;
    
    String direction_Y;
    String Y;

    String direction_B;
    String B;
    
    String HOME;
    String DOF5;
    String Grip;
    String mode;
    int z;
    String x;
    String y;
    int bbase;

    while (Serial.available() > 0) {
      Serial.println("flag_1");
      // format command : mode; arah,perpindahan(mm);  arah,sudut;  arah,sudut:0.
      // Contoh = movez;up,20;0,0;0,0;
      // mode = mode (movex,movey,movez, dll)
      // direction_Z,Z = arah,perpindahan(mm) -> (up/down, berapa mm pindahnya) -> movez;down,40;0,0;0,0;0,0;
      // direction_X,X = arah,sudut(degree) -> (cw/ccw, berapa derajat pindahnya) -> movex;0,0;cw,40;0,0;0,0;
      // direction_Y,Y = arah,sudut(degree) -> (cw/ccw, berapa derajat pindahnya) -> movey;0,0;0,0;ccw,40;0,0;
      // direction_B,B = arah,sudut(degree) -> (cw/ccw, berapa derajat pindahnya) -> movebase;0,0;0,0;0,0;cw,40;
      mode = Serial.readStringUntil(';');         //Cek Modenya dulu
      
      
      direction_Z = Serial.readStringUntil(',');
      if (direction_Z == "up") {
        z = 0;
      }
      else if (direction_Z == "down") {
        z = 1;
      }
      Z = Serial.readStringUntil(';');


      Serial.println("flag_2");
      direction_X = Serial.readStringUntil(',');
      if (direction_X == "cw") {
        x = "1";
      }
      else if (direction_X == "ccw") {
        x = "0";
      }
      X = Serial.readStringUntil(';');


      direction_Y = Serial.readStringUntil(',');
      if (direction_Y == "cw") {
        y = "1";
      }
      else if (direction_Y == "ccw") {
        y = "0";
      }
      Y = Serial.readStringUntil(';');


      direction_B = Serial.readStringUntil(',');
      if (direction_B == "cw") {
        bbase = 1;
      }
      else if (direction_B == "ccw") {
        bbase = 0;
      }
      B = Serial.readStringUntil(';');


      DOF5 = Serial.readStringUntil(';');
      Grip = Serial.readStringUntil(';');
      Serial.read();
    }

    Serial.println("flag_3");
    if (mode == "home") {
      homeZ();
      delay(1000);
      homeY();
      delay(1000);
      homeX();
      delay(1000);
      homeB();
      delay(1000);
    }
    else if (mode == "base") {
      Movebase(bbase, B.toInt());
      delay(1000);
    }


    else if (mode == "movez") {
      MoveZ(z, Z.toInt());
      delay(1000);
    }
    else if (mode == "movex") {
      MoveX(x.toInt(), X.toInt());
      delay(1000);
    }
    else if (mode == "movey") {
      MoveY(y.toInt(), Y.toInt());
      delay(1000);
    }
    else if (mode == "movebase") {
      Movebase(bbase, B.toInt());
      delay(1000);
    }

    else if (mode == "all") {
      Move(z, Z.toInt(), x.toInt(), X.toInt(), y.toInt(), Y.toInt(), direction_B.toInt(), B.toInt(), DOF5.toInt(), Grip.toInt() );
      delay(1000);
    }
  }
}
