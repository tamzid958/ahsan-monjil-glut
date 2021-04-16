#include <windows.h>
#include<mmsystem.h>
#include "components.h"

GLfloat rotation_increaser = 0.0f;
GLfloat position = 0.0f;
GLfloat speed = 0.1f;
GLfloat car_pos = 0.0f;
GLfloat car_speed = 0.079f;
GLfloat car3_pos = 0.0f;
GLfloat car4_pos = 0.78f;

GLfloat cloud_position = -0.20f;
GLfloat cloud_speed = 0.008f;
GLfloat rainPos= -1.0;

GLfloat ship_pos = 0.78f;
GLfloat ship_pos_1 = -0.78f;
GLfloat ship_speed = 0.005f;

GLfloat autoNightTimer = 0.0f;
GLfloat autoNightSpeed = 0.05f;

GLfloat autoRainTimer = 0.0f;
GLfloat autoRainSpeed = 0.05f;

bool isDay = true;
bool isRainy = false;
bool isHide = false;
bool isFullScreen = false;
bool isAuto = true;


void autoView(){
  if(autoNightTimer > 25){
        isDay = !isDay;
        autoNightTimer = 0.0f;
    }
    autoNightTimer += autoNightSpeed;

    if(autoRainTimer > 10){
        isRainy = !isRainy;
        (isRainy) ? PlaySound("assets/rain.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP) : PlaySound(NULL, 0, 0);
        autoRainTimer = 0.0f;
    }
    autoRainTimer +=autoRainSpeed;
}



void update(int value) {

    if(position <-1.0)
        position = 1.0f;
    position -= speed;

    if(car_pos > 1.0)
        car_pos = -1.2f;
    car_pos += car_speed;


    if(car3_pos < -1.0)
        car3_pos = 1.2f;
    car3_pos -= car_speed;


    if(car4_pos < -1.0)
        car4_pos = 1.2f;
    car4_pos -= car_speed;

    if(cloud_position < -1.2)
        cloud_position = 1.2f;
    cloud_position -=cloud_speed;

    if(rainPos<-1.0)
        rainPos = -1.0;
    rainPos -=1.47;

    if(ship_pos < -1.8)
        ship_pos = 1.2f;
    ship_pos -= ship_speed;

    if(ship_pos_1 > 1.3)
        ship_pos_1 = -1.4f;
    ship_pos_1 += ship_speed;

    (isAuto) ? autoView() : blank();

	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}


void Idle()
{
    glutPostRedisplay();
}

void initState(){
    glClearColor(0.5f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_COLOR_MATERIAL | GL_LIGHTING);
    glLineWidth(4);
    glPointSize(7);
    glClear(GL_COLOR_BUFFER_BIT );
    GLfloat global_ambient[] = {1.9,0.0,0.0, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
}


void axisDraw(){
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0, -1.0f);
    glEnd();
}

void ahsanMonjilView(){

    anyQuad(0.8f, 0.5f, 0.8f, 0.1f, -0.8f, 0.1f, -0.8f, 0.5f, 255, 99, 71);;

    glBegin(GL_LINES);
    glColor3ub(255, 99, 71);
    glVertex2f(-0.81f, 0.51f);
    glVertex2f(0.86f, 0.51f);
    glEnd();


    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(255, 99, 71);
    glVertex2f(-0.55f, 0.53f);
    glVertex2f(0.6f, 0.53f);
    glEnd();
    glLineWidth(4);

     //middleBody
    glLoadIdentity();
    //glColor3ub(255, 99, 71);
    anyQuad(-0.06, 0.54, -0.06, 0.3, 0.11, 0.3, 0.11, 0.54, 255, 99, 71);
    glLoadIdentity();

    //mainDoor
    glLoadIdentity();
    glTranslatef(0.736, -0.1245, 0);
    glScalef(1, 1.5, 0);
    ovalWindowComponent(178, 34, 34);
    glLoadIdentity();

    //leftDoor
    glLoadIdentity();
    glTranslatef(0.32, -0.066, 0);
    glScalef(0.5, 1.3, 0);
    ovalWindowComponent(178, 34, 34);
    glLoadIdentity();

    //rightDoor
    glLoadIdentity();
    glTranslatef(0.44, -0.066, 0);
    glScalef(0.5, 1.3, 0);
    ovalWindowComponent(178, 34, 34);
    glLoadIdentity();

    //mainGombujhRight
    glLoadIdentity();
    glColor3ub(255, 99, 71);
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, 0.655);
    glVertex2f(0.025, 0.655);
    glVertex2f(0.025, 0.8);
    glVertex2f(0.0, 0.79);
    glVertex2f(-0.025, 0.76);
    glVertex2f(-0.04, 0.735);
    glVertex2f(-0.05, 0.71);
    glEnd();

    glLoadIdentity();
    //glColor3ub(255, 99, 71);
    anyQuad(0.02, 0.8, 0.03, 0.8, 0.027, 0.815, 0.023, 0.815, 255, 99, 71);//topPoint
    glLoadIdentity();

    glLoadIdentity();
    glColor3ub(0, 0, 0);
    glLineWidth(2);
    lineComponent(0.025, 0.815, 0.025, 0.83);
    glLoadIdentity();

    //mainGombujhLeft
    glLoadIdentity();
    glColor3ub(255, 99, 71);
    glBegin(GL_POLYGON);
    glVertex2f(0.11, 0.655);
    glVertex2f(0.025, 0.655);
    glVertex2f(0.025, 0.8);
    glVertex2f(0.05, 0.79);
    glVertex2f(0.075, 0.76);
    glVertex2f(0.09, 0.735);
    glVertex2f(0.10, 0.71);
    glEnd();

    glLoadIdentity();
    glColor3ub(0, 0, 0);//gombuhjMiddleBorder
    glTranslatef(0, 0.02, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.065, 0.63);
    glVertex2f(-0.06, 0.54);
    glVertex2f(0.11, 0.54);
    glVertex2f(0.115, 0.63);
    glVertex2f(0.085, 0.65);
    glVertex2f(0.06, 0.66);
    glVertex2f(0.025, 0.665);
    glVertex2f(-0.005, 0.66);
    glVertex2f(-0.03, 0.65);
    glEnd();
    glLoadIdentity();

    glLoadIdentity();
    glColor3ub(255, 99, 71);//lowerPartOfGombujh
    glBegin(GL_POLYGON);
    glVertex2f(-0.06, 0.63);
    glVertex2f(-0.06, 0.54);
    glVertex2f(0.11, 0.54);
    glVertex2f(0.11, 0.63);
    glVertex2f(0.085, 0.65);
    glVertex2f(0.06, 0.66);
    glVertex2f(0.025, 0.665);
    glVertex2f(-0.005, 0.66);
    glVertex2f(-0.03, 0.65);
    glEnd();
    glLoadIdentity();



//middleLeftPillar
    glLoadIdentity();
    //glColor3ub(255,140,0);
    anyQuad(-0.09, 0.59, -0.084, 0.564, -0.062, 0.564, -0.057, 0.59, 255,140,0);
    glLoadIdentity();
    glTranslatef(0.237, 0.24, 0);
    glScalef(0.4, 0.64, 0);
    pillarComponent();
    glLoadIdentity();

    //DecorLines
    glLoadIdentity();
    glColor3ub(255,140,0);
    glLineWidth(5);
    lineComponent(-0.015, 0.575, 0.062, 0.575);
    glLoadIdentity();

    glLoadIdentity();
    glColor3ub(0,0,0);
    glLineWidth(3);
    lineComponent(-0.011, 0.57, -0.011, 0.48);
    lineComponent(0.059, 0.57, 0.059, 0.48);
    glLoadIdentity();

    glLoadIdentity();
    glColor3ub(0,0,0);
    glLineWidth(2);
    lineComponent(0.05, 0.57, 0.05, 0.5);
    lineComponent(0.038, 0.57, 0.038, 0.52);
    lineComponent(0.025, 0.57, 0.025, 0.54);
    lineComponent(0.013, 0.57, 0.013, 0.52);
    lineComponent(0.0, 0.57, 0.0, 0.5);
    glLoadIdentity();

    glLoadIdentity();
    glColor3ub(255,140,0);
    glLineWidth(3);
    lineComponent(-0.06, 0.545, -0.013, 0.545);
    lineComponent(0.064, 0.545, 0.11, 0.545);
    glLoadIdentity();

    glLoadIdentity();
    glColor3ub(0,0,0);
    glLineWidth(1);
    lineComponent(-0.0525, 0.54, -0.0525, 0.52);
    lineComponent(-0.04, 0.54, -0.04, 0.52);
    lineComponent(-0.025, 0.54, -0.025, 0.52);
    lineComponent(0.0725, 0.54, 0.0725, 0.52);
    lineComponent(0.085, 0.54, 0.085, 0.52);
    lineComponent(0.1, 0.54, 0.1, 0.52);
    glLoadIdentity();

    glLoadIdentity();
    glColor3ub(0,0,0);
    glLineWidth(3);
    lineComponent(-0.05, 0.65, -0.05, 0.546);
    lineComponent(-0.013, 0.67, -0.013, 0.58);
    lineComponent(0.061, 0.67, 0.061, 0.58);
    lineComponent(0.1, 0.65, 0.1, 0.543);
    glLoadIdentity();

    glLoadIdentity();//topDoor
    glTranslatef(0.308, 0.49, 0);
    glScalef(0.4, 0.3, 0);
    ovalWindowComponent(178, 34, 34);
    glLoadIdentity();

//middleRightPillar
    glLoadIdentity();
    //glColor3ub(255,140,0);
    glTranslatef(0.197, 0, 0);
    anyQuad(-0.09, 0.59, -0.084, 0.564, -0.062, 0.564, -0.057, 0.59, 255,140,0);
    glLoadIdentity();
    glTranslatef(0.434, 0.24, 0);
    glScalef(0.4, 0.64, 0);
    pillarComponent();
    glLoadIdentity();//end

    glLoadIdentity();
    glTranslatef(0.15, -0.09, 0);
    threeDotComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.25, -0.09, 0);
    threeDotComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.35, -0.09, 0);
    threeDotComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.45, -0.09, 0);
    threeDotComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.55, -0.09, 0);
    threeDotComponent();
    glLoadIdentity();


    glLoadIdentity();
    glTranslatef(0.82, -0.09, 0);
    threeDotComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.92, -0.09, 0);
    threeDotComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.02, -0.09, 0);
    threeDotComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.12, -0.09, 0);
    threeDotComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.22, -0.09, 0);
    threeDotComponent();
    glLoadIdentity();

    glLoadIdentity();
    pillarComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.2, 0, 0);
    pillarComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.4, 0, 0);
    pillarComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.6, 0, 0);
    pillarComponent();
    glLoadIdentity();

    glLoadIdentity();
    gombujhComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.4, 0, 0);
    gombujhComponent();
    glLoadIdentity();

    glLoadIdentity();
    squareWindowComponent(178, 34, 34);
    glLoadIdentity();

//left windows
    glLoadIdentity();
    squareWindowComponent(178, 34, 34);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.07, 0, 0);
    squareWindowComponent(178, 34, 34);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0, -0.15, 0);
    ovalWindowComponent(178, 34, 34);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.07, -0.15, 0);
    ovalWindowComponent(178, 34, 34);
    glLoadIdentity();

//right windows
    glLoadIdentity();
    glTranslatef(1.4, 0, 0);
    squareWindowComponent(178, 34, 34);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.47, 0, 0);
    squareWindowComponent(178, 34, 34);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.4, -0.15, 0);
    ovalWindowComponent(178, 34, 34);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.47, -0.15, 0);
    ovalWindowComponent(178, 34, 34);
    glLoadIdentity();

//bottom row of windows (left)
    glLoadIdentity();
    glTranslatef(0.2, -0.2, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.3, -0.2, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.4, -0.2, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.5, -0.2, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

//upper row of windows (left)
    glLoadIdentity();
    glTranslatef(0.2, 0, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.3, 0, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.4, 0, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.5, 0, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.6, 0, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();


//bottom row of windows (right)
    glLoadIdentity();
    glTranslatef(1.27, -0.2, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.17, -0.2, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.07, -0.2, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.97, -0.2, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();


//upper row of windows (right)
    glLoadIdentity();
    glTranslatef(1.27, 0, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.17, 0, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.07, 0, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.97, 0, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.87, 0, 0);
    ovalWindowComponent(0, 0, 0);
    glLoadIdentity();

//stairs
    anyQuad(-0.08f, 0.3f, 0.13f, 0.3f, 0.29f, 0.0f, -0.25f, 0.0f, 36, 33, 36);

    anyQuad(-0.17f, 0.15f, 0.21f, 0.15f, 0.29f, 0.0f, -0.25f, 0.0f, 53, 56, 57);

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(35,43,43);
    glVertex2f(0.13f, 0.3f);
    glVertex2f(-0.08f, 0.3f);

    glVertex2f(0.16f, 0.25f);
    glVertex2f(-0.11f, 0.25f);

    glVertex2f(0.19f, 0.20f);
    glVertex2f(-0.14f, 0.20f);

    glVertex2f(0.21f, 0.15f);
    glVertex2f(-0.17f, 0.15f);

    glVertex2f(0.24f, 0.10f);
    glVertex2f(-0.20f, 0.10f);

    glVertex2f(0.27f, 0.05f);
    glVertex2f(-0.22f, 0.05f);

    glVertex2f(0.29f, 0.0f);
    glVertex2f(-0.25f, 0.0f);
    glEnd();
    glLineWidth(4);


}

void WaterView(int R, int G, int B)
{

    anyQuad(-1.0f, -0.22f, -1.0f, -1.0f, 1.0f, -1.0f,1.0f, -0.22f, R, G, B);

    glBegin(GL_POLYGON);

    glColor3ub(R + 2, G + 3, B + 10);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.6f, -0.7f);
    glVertex2f(-0.4f, -0.7f);
    glVertex2f(-0.2f, -0.8f);
    glVertex2f(-0.0f, -0.7f);
    glVertex2f(0.2f, -0.7f);
    glVertex2f(0.4f, -0.8f);
    glVertex2f(0.6f, -0.8f);
    glVertex2f(0.8f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glEnd();

	//waves
    glBegin(GL_LINE_STRIP);
    glColor3ub(R, G, B);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.6f, -0.7f);
    glVertex2f(-0.4f, -0.7f);
    glVertex2f(-0.2f, -0.8f);
    glVertex2f(-0.0f, -0.7f);
    glVertex2f(0.2f, -0.7f);
    glVertex2f(0.4f, -0.8f);
    glVertex2f(0.6f, -0.8f);
    glVertex2f(0.8f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glEnd();

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(ship_pos_1,0,0);
    glScalef(0.6, 0.6, 0);
    shipComponent();
    glPopMatrix();
    glLoadIdentity();

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(ship_pos,0,0);
    glScalef(0.9, 0.9, 0);
    shipComponent();
    glPopMatrix();
    glLoadIdentity();
}

void roadView(int R, int G, int B)
{
    glLoadIdentity();
    glTranslatef(0.025, 0.0, 0);
    lampComponent(R, G, B);
    glLoadIdentity();
  //road-base

    glLoadIdentity();
    glTranslatef(-0.2, 0.0, 0);
    lampComponent(R, G, B);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.3, 0.0, 0);
    lampComponent(R, G, B);
    glLoadIdentity();


    glLoadIdentity();
    glTranslatef(1.15, 0.0, 0);
    lampComponent(R, G, B);
    glLoadIdentity();


    glLoadIdentity();
    glTranslatef(1.4, 0.0, 0);
    lampComponent(R, G, B);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.6, 0.0, 0);
    lampComponent(R, G, B);
    glLoadIdentity();



    anyQuad(-1.0f, 0.0f, -1.0f, -0.22f, 1.0f, -0.22f, 1.0f, 0.0f, 145, 145, 145);

    //road border
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-1.0f, -0.005f);//building front road border
    glVertex2f(1.0f, -0.005f);
    glEnd();

    //Road lines
    float x1,x2,y;
    x1=-1.0; x2=-0.92; y=-0.0999;
    glLineWidth(6.0);

    glBegin(GL_LINES);

        for(int i =0; i<17; i++)
        {
            glVertex2f(x1,y );
            glVertex2f(x2,y);

            x1=x1+.12;
            x2=x2+.12;
        }

    glEnd();

    credit();

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(car_pos,0,0);
    carComponent();
    glPopMatrix();
    glLoadIdentity();

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(car_pos,0,0);
    car_2Component();
    glPopMatrix();
    glLoadIdentity();

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(car3_pos,0,0);
    car_3Component();
    glPopMatrix();
    glLoadIdentity();

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(car4_pos,0,0);
    car_4Component();
    glPopMatrix();
    glLoadIdentity();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-1.0f, -0.21f);//building front road border
    glVertex2f(1.0f, -0.21f);
    glEnd();
    glLineWidth(4.0);
}

void mountainView(int R, int G, int B){

    glLoadIdentity();//Mountain
    glColor3ub(R, G, B);
    glBegin(GL_POLYGON);
    glVertex2f(-1, 0.5);
    glVertex2f(1, 0.5);
    glVertex2f(0.9, 0.7);
    glVertex2f(0.8, 0.55);
    glVertex2f(0.5, 0.75);
    glVertex2f(0.3, 0.55);
    glVertex2f(0.1, 0.88);
    glVertex2f(-0.1, 0.66);
    glVertex2f(-0.3, 0.79);
    glVertex2f(-0.6, 0.63);
    glVertex2f(-0.7, 0.71);
    glVertex2f(-0.9, 0.59);
    glEnd();//endOfMountain
    glLoadIdentity();

    grassComponent();
}


void buildingsView(int R, int G, int B ){
    buildingComponent();
    glTranslatef(0.03f, 0.1f, 0);//TallBuilding1
    glScalef(0.5, 1.1, 0);
    anyQuad(-0.7f , 0.7f, -0.7f, 0.3f, -0.9f, 0.3f, -0.9f, 0.7f, 163, 163, 117);
    glLoadIdentity();

    float wp1 = -0.195, wp2 = 0.755;
    for(int w = 0; w < 5; w++)
        {
            for(int wj = 0; wj < 8; wj++){
             glLoadIdentity();//smallWindowsTallBuilding1
             glTranslatef(wp1, wp2, 0);
             glScalef(0.3, 0.25, 0);
             squareWindowComponent(R, G, B);
             glLoadIdentity();
             wp2 -= 0.045;
            }
            wp2 = 0.755;
            wp1 += 0.018;
        }

    glLoadIdentity();
    //tallBuilding2
    glTranslatef(0.13f, 0.1f, 0);
    glScalef(0.4, 1.05, 0);
    anyQuad(-0.7f , 0.7f, -0.7f, 0.3f, -0.9f, 0.3f, -0.9f, 0.7f, 194, 194, 163);
    glLoadIdentity();

    wp1 = -0.04, wp2 = 0.745;
    for(int w = 0; w < 4; w++)
        {
            for(int wj = 0; wj < 7; wj++){
             glLoadIdentity();//smallWindowsTallBuilding2
             glTranslatef(wp1, wp2, 0);
             glScalef(0.25, 0.2, 0);
             squareWindowComponent(R, G, B);
             glLoadIdentity();
             wp2 -= 0.045;
            }
            wp2 = 0.745;
            wp1 += 0.018;
        }

    glLoadIdentity();
    anyTriangle(0.228, 0.85, 0.2905, 0.85, 0.26, 0.9, 179, 119, 0);//tallBuilding3
    glTranslatef(0.5f, 0.1f, 0);
    glScalef(0.3, 1.08, 0);
    anyQuad(-0.7f , 0.7f, -0.7f, 0.3f, -0.9f, 0.3f, -0.9f, 0.7f, 179, 119, 0);
    glLoadIdentity();

    wp1 = 0.405, wp2 = 0.75;
    for(int w = 0; w < 3; w++)
        {
            for(int wj = 0; wj < 7; wj++){
             glLoadIdentity();//smallWindowsTallBuilding3
             glTranslatef(wp1, wp2, 0);
             glScalef(0.23, 0.18, 0);
             squareWindowComponent(R, G, B);
             glLoadIdentity();
             wp2 -= 0.045;
            }
            wp2 = 0.75;
            wp1 += 0.018;
        }

        glLoadIdentity();
    //smallBuilding2
    glTranslatef(1.4f, 0.1f, 0);
    glScalef(0.6, 0.8, 0);
    anyQuad(-0.7f , 0.7f, -0.7f, 0.3f, -0.9f, 0.3f, -0.9f, 0.7f, 178, 190, 181);
    glLoadIdentity();

    wp1 = 1.275, wp2 = 0.4;

            for(int wj = 0; wj < 3; wj++){
             glLoadIdentity();//smallWindowsSmallBuilding2
             glTranslatef(wp1, wp2, 0);
             glScalef(0.5, 0.5, 0);
             ovalWindowComponent(R, G, B);
             glLoadIdentity();
             wp2 -= 0.1;
            }

            wp1 = 1.382, wp2 = 0.53;
    for(int w = 0; w < 2; w++)
        {
            for(int wj = 0; wj < 3; wj++){
             glLoadIdentity();//smallWindowsTallBuilding3
             glTranslatef(wp1, wp2, 0);
             glScalef(0.7, 0.2, 0);
             squareWindowComponent(R, G, B);
             glLoadIdentity();
             wp2 -= 0.1;
            }
            wp2 = 0.53;
            wp1 += 0.068;
        }
}

void treeView(){
    glLoadIdentity();
    glTranslatef(0.2f, 0.2f, 0);
    treeComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.25f, 0.1f, 0);
    treeComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.15f, 0.1f, 0);
    treeComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(-1.65f, 0.3f, 0);
    treeComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(-1.59f, 0.3f, 0);
    treeComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(-1.7f, 0.2f, 0);
    treeComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(-1.62f, 0.2f, 0);
    treeComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(-1.65f, 0.1f, 0);
    treeComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(-1.55f, 0.1f, 0);
    treeComponent();
    glLoadIdentity();
}

void desertView(){
    anyQuad(1.0f, 0.5f, 1.0f, 0.1f, -1.0f, 0.1f, -1.0f, 0.5f, 76, 70, 50);
}

void NightSkyJoinedComponent(){
    anyQuad(1.0f, 1.0f, 1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 0, 0, 0);
    moonComponent();
    starComponent();
}

void skyView(){
    (isDay) ? sunComponent() : NightSkyJoinedComponent();
}

void cloudView(){
    glPushMatrix();
    glTranslatef(cloud_position,0,0);
    cloudComponent();

    glTranslatef(cloud_position + 0.8f,0,0);
    cloudComponent();

    glTranslatef(cloud_position - 0.4f,0,0);
    cloudComponent();

    glTranslatef(cloud_position + 1.5f,0,0);
    cloudComponent();

    glTranslatef(cloud_position - 1.2f,0,0);
    cloudComponent();

    glTranslatef(cloud_position - 0.9f,0,0);
    cloudComponent();
    glPopMatrix();
}

void rainView()
{

    float x=0.0, y = 1.5, x1=-0.099;
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(0,rainPos,0);
    glBegin(GL_LINES);

    for(int i=600;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            glVertex3f(x,y,0);
            glVertex3f(x+0.05,y+0.09,0);
            x+=float(rand()%5)/10;
           // x-=rand()%1050;
        }
        for(int j=0;j<=i;j++)
        {
            glVertex3f(x1,y,0);
            glVertex3f(x1+0.05,y+0.09,0);
            //x+=rand()%1050;
            x1-=float(rand()%5)/10;
        }
        y+=float(rand()%10)/10;
        //y-=rand()%15;
        x=0.0;
        x1=-0.099;

    }
    glEnd();
    glPopMatrix();
}

void instructions(){
    anyText("p = pause , s = start , key up = increase , key down = decrease , key left = car horn , key right = ship horn", -0.95f, -0.90f, 255, 255, 255);
    anyText("d = day \\ night , a = auto on \\ off , r = rain on \\ off , i = info hide \\ show , f = fullscreen \\ minimized , e = exit", -0.95f, -0.95f, 255, 255, 255);
}

void fullView()
{
    initState();
    //axisDraw();
    skyView();
    (isDay) ? mountainView(15, 114, 22) : mountainView(0, 51, 17);
    (isRainy) ? cloudView() : blank();
    desertView();
    (isDay) ? buildingsView(0, 0 , 0) : buildingsView(255,255,224);
    ahsanMonjilView();
    treeView();
    (isDay) ? roadView(255, 255, 255): roadView(255, 255, 0);
    (isDay) ? WaterView(2, 120, 191) : WaterView(0, 19, 77);
    (isHide) ? blank() : instructions();
    (isRainy) ? rainView() : blank();
    glDisable(GL_COLOR_MATERIAL | GL_LIGHTING);
    glFlush();
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key)
	{
        case 'p':
            car_speed = 0.0f;
            ship_speed = 0.0f;
            break;
        case 's':
            car_speed = 0.079f;
            ship_speed = 0.005f;
            break;
        case 'd':
            isAuto = false;
            isDay = !isDay;
            break;
        case 'r':
             isAuto = false;
            isRainy = !isRainy;
            (isRainy) ? PlaySound("assets/rain.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP) : PlaySound(NULL, 0, 0);
            break;
        case 'i':
            isHide = !isHide;
            break;
        case 'f':
            isFullScreen = !isFullScreen;
            (isFullScreen) ? glutFullScreen() : glutReshapeWindow(1200, 800);
            break;
        case 'a':
            isAuto = !isAuto;
            break;
        case 'e':
            exit(0);
            break;
        glutPostRedisplay();
	}
}


void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
        {
        }
    if (button == GLUT_RIGHT_BUTTON)
        {
        }
	glutPostRedisplay();

}



void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            car_speed += 0.05;
            ship_speed += 0.005f;
            break;
        case GLUT_KEY_DOWN:
            if(car_speed > 0.05 || ship_speed > 0.005){
                car_speed -= 0.05;
                ship_speed -= 0.005f;
            }
            else{
                car_speed = 0.0f;
                ship_speed = 0.0f;
            }
            break;
        case GLUT_KEY_LEFT:
            PlaySound("assets/car_double_horn.wav", NULL, SND_FILENAME|SND_ASYNC);
            break;
        case GLUT_KEY_RIGHT:
            PlaySound("assets/ship.wav", NULL, SND_FILENAME|SND_ASYNC);
            break;
        }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    FreeConsole();
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Ahsan Monjil");
    glutDisplayFunc(fullView);
    glutIdleFunc(Idle);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutSpecialFunc(SpecialInput);
    glutTimerFunc(1500, update, 0);
    glutMainLoop();
    return 0;
}
