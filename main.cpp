#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#define PI  3.14159265358979323846

int i;
int triangleAmount = 100;
GLfloat rotation_increaser = 0.0f;
GLfloat position = 0.0f;
GLfloat speed = 0.1f;
GLfloat x = 0,y = 0,radius = 0;
GLfloat twicePi = 2.0f * PI;
GLfloat car_position = 0.0f;
GLfloat car_speed = 0.079f;
GLfloat car3_pos = 0.0f;
GLfloat car4_pos = 0.78f;


void update(int value) {

    if(position <-1.0)
        position = 1.0f;

    position -= speed;

    //car
    if(car_position > 1.0)
        car_position = -1.2f;

    car_position += car_speed;


    if(car3_pos < -1.0)
        car3_pos = 1.2f;

    car3_pos -= car_speed;


    if(car4_pos < -1.0)
        car4_pos = 1.2f;

    car4_pos -= car_speed;

	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}



//make circle
void Circle(GLfloat cx, GLfloat cy,GLfloat cz, GLfloat radius,int r,int g,int b)
{
    glColor3ub(r,g,b);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(cx, cy,cz); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex3f(
		            cx + (radius * cos(i *  twicePi / triangleAmount)),
			    cy + (radius * sin(i * twicePi / triangleAmount)),cz
			);
		}
	glEnd();
}



void Idle()
{
    glutPostRedisplay();
}

void initState(){
    glClearColor(0.5f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4);
    glPointSize(7);
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
void pillarComponent(){

    glBegin(GL_QUADS);
    glColor3ub(255,140,0);
    glVertex2f(-0.75f, 0.5f);
    glVertex2f(-0.75f, 0.1f);
    glVertex2f(-0.8f, 0.1f);
    glVertex2f(-0.8f, 0.5f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,140,0);
    glVertex2f(-0.755f, 0.55f);
    glVertex2f(-0.755f, 0.5f);
    glVertex2f(-0.795f, 0.5f);
    glVertex2f(-0.795f, 0.55f);
    glEnd();

    Circle(-.775f,.55f,0.0f,.02f,255,140,0);

	glBegin(GL_LINES);
    glColor3ub(255,140,0);
	glVertex2f(-0.776f, 0.59f);
    glVertex2f(-0.776f, 0.56f);
    glVertex2f(-0.785f, 0.58f);
    glVertex2f(-0.77f, 0.58f);
	glEnd();
}

void gombujhComponent(){
  glBegin(GL_QUADS);
  glColor3ub(255,140,0);
  glVertex2f(-0.6f, 0.57f);
  glVertex2f(-0.6f, 0.52f);
  glVertex2f(-0.75f, 0.52f);
  glVertex2f(-0.75f, 0.57f);
  glEnd();

  Circle(-.68f, .56f, 0.0f, .045f, 255, 140, 0);

  glBegin(GL_POINTS);
  glColor3ub(255,140,0);
  glVertex2f(-0.68f, 0.62f);
  glEnd();
}

void squareWindowComponent(){
    glBegin(GL_QUADS);
    glColor3ub(178, 34, 34);
    glVertex2f(-0.69f, 0.4f);
    glVertex2f(-0.69f, 0.3f);
    glVertex2f(-0.73f, 0.3f);
    glVertex2f(-0.73f, 0.4f);
    glEnd();
}

void ovalWindowComponent(int R, int G, int B){

    glBegin(GL_QUADS);
    glColor3ub(R, G, B);
    glVertex2f(-0.69f, 0.4f);
    glVertex2f(-0.69f, 0.3f);
    glVertex2f(-0.73f, 0.3f);
    glVertex2f(-0.73f, 0.4f);
    glEnd();

    Circle(-.71f, .4f, 0.0f, .021f, R, G, B);
}


void threeDotComponent(){
   glBegin(GL_POINTS);
   glColor3ub(0, 0, 0);
   glVertex2f(-0.68f, 0.62f);
   glVertex2f(-0.66f, 0.62f);
   glVertex2f(-0.64f, 0.62f);
   glEnd();
}

void anyQuad( float a, float b, float c, float d, float e, float f, float g, float h, int R, int G, int B ){
    glBegin(GL_QUADS);
    glColor3ub(R, G, B);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glEnd();
}

void lineComponent(float a, float b, float c, float d){
   glBegin(GL_LINES);
   glVertex2f(a, b);
   glVertex2f(c, d);
   glEnd();
}



void carComponent()
{

    glPushMatrix();
    glTranslatef(car_position,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 51);
    glVertex3f(-0.3,-0.07,0);
    glVertex3f(-0.15,-0.07,0);
    glVertex3f(-0.15,-0.035,0);
    glVertex3f(-0.18,-0.035,0);
    glVertex3f(-0.20,-0.02,0);
    glVertex3f(-0.25,-0.02,0);
    glVertex3f(-0.27,-0.035,0);
    glVertex3f(-0.3,-0.035,0);
    glVertex3f(-0.27,-0.035,0);
    glVertex3f(-0.3,-0.07,0);
    glEnd();

    //car window

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    //car window left
    glVertex3f(-0.255,-0.038,0);
    glVertex3f(-0.235,-0.038,0);
    glVertex3f(-0.241,-0.030,0);
    glVertex3f(-0.248,-0.030,0);
    glVertex3f(-0.255,-0.035,0);
    glEnd();

     //car window right
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-0.221,-0.038,0);
    glVertex3f(-0.20,-0.038,0);
    glVertex3f(-0.209,-0.030,0);
    glVertex3f(-0.216,-0.030,0);
    glVertex3f(-0.221,-0.035,0);
    glEnd();


    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3ub(185,0,0);
    glVertex2f(-0.27,-.04);
    glVertex2f(-0.18,-.04);
    glEnd();

    //Wheels
    //backbumper
    Circle(-0.26f,-0.070f,0.0f,0.010f,0,0,0);
     //front bumper
    Circle(-0.199f,-0.07f,0.0f,0.01f,0,0,0);
    glPopMatrix();
}


void car_2Component()
{

    glPushMatrix();
    glTranslatef(car_position,0,0);

    glBegin(GL_QUADS);
    glColor3ub(255, 77, 255);

    glVertex2f(0.025f, 0.001f);
    glVertex2f(0.025f, -0.045f);
    glVertex2f(0.222f, -0.045f);

    glVertex2f(0.222f, 0.001f);


    glEnd();

    //glass part of car

    glBegin(GL_POLYGON);
    glColor3ub(255, 77, 255);

    glVertex2f(0.065f, 0.031f);
    glVertex2f(0.055f, 0.001f);
    glVertex2f(0.20f, -0.001f);

    glVertex2f(0.185f, 0.031f);


    glEnd();
    //glass
    glBegin(GL_POLYGON);
    glColor3ub(168,204,215);

    glVertex2f(0.065f, 0.027f);
    glVertex2f(0.058f, 0.001f);
    glVertex2f(0.198f, 0.001f);

    glVertex2f(0.185f, 0.027f);


    glEnd();

    //head part

    glBegin(GL_POLYGON);
    glColor3ub(255, 77, 255);

    glVertex2f(0.222f, 0.001f);
    glVertex2f(0.222f, -0.045f);
    glVertex2f(0.252f, -0.045f);

    glVertex2f(0.252f, -0.033f);


    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);

    glColor3ub(255, 77, 255);
    glVertex2f(.12f, 0.031f);
    glVertex2f(.12f, -0.045f);
    glEnd();


    //headlight
    glBegin(GL_QUADS);
    glColor3ub(204,204,0);

    glVertex2f(0.233f, -0.033f);
    glVertex2f(0.233f, -0.038f);
    glVertex2f(0.252f, -0.038f);

    glVertex2f(0.252f, -0.033f);


    glEnd();

    // back light
    glBegin(GL_QUADS);
    glColor3ub(255, 77, 255);

    glVertex2f(0.015f, -0.035f);
    glVertex2f(0.015f, -0.045f);
    glVertex2f(0.025f, -0.045f);

    glVertex2f(0.025f, -0.035f);


    glEnd();

    //Wheels
    //backbumper

    Circle(0.055f,-0.045f,0.0f,0.010f,0,0,0);
    //front bumper
    Circle(0.20f,-0.045f,0.0f,0.01f,0,0,0);
    glPopMatrix();
}

void car_3Component()
{
    glPushMatrix();
    glTranslatef(car3_pos,0,0);

    glBegin(GL_QUADS);
    glColor3ub(0, 128, 0);

    glVertex2f(0.04f, -0.14f);
    glVertex2f(0.04f, -0.19f);
    glVertex2f(0.19f, -0.19f);

    glVertex2f(0.19f, -0.14f);


    glEnd();

    //glass part of car

    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);

    glVertex2f(0.078f, -0.11f);
    glVertex2f(0.055f, -0.14f);
    glVertex2f(0.16f, -0.14f);

    glVertex2f(0.13f, -0.11f);


    glEnd();
    //glass

    glBegin(GL_POLYGON);
    glColor3ub(168,204,215);

    glVertex2f(0.078f, -0.115f);
    glVertex2f(0.059f, -0.14f);
    glVertex2f(0.11f, -0.14f);
    glVertex2f(0.11f, -0.115f);


    // glVertex2f(0.155f, -0.14f);

    // glVertex2f(0.13f, -0.115f);


    glEnd();

    //glass-2
    glBegin(GL_POLYGON);
    glColor3ub(168,204,215);

    glVertex2f(0.113f, -0.115f);
    glVertex2f(0.113f, -0.14f);
    glVertex2f(0.155f, -0.14f);
    glVertex2f(0.13f, -0.115f);


    glEnd();



    //head part

    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);

    glVertex2f(0.04f, -0.14f);
    glVertex2f(0.015f, -0.17f);
    glVertex2f(0.015f, -0.19f);

    glVertex2f(0.04f, -0.19f);


    glEnd();

    //headlight
    glBegin(GL_QUADS);
    glColor3ub(204,204,0);

    glVertex2f(0.015f, -0.17f);
    glVertex2f(0.015f, -0.18f);
    glVertex2f(0.029f, -0.18f);

    glVertex2f(0.029f, -0.17f);


    glEnd();

    // back light
    glBegin(GL_QUADS);
    glColor3ub(0, 128, 0);

    glVertex2f(0.19f, -0.18f);
    glVertex2f(0.19f, -0.19f);
    glVertex2f(0.196f, -0.19f);

    glVertex2f(0.196f, -0.18f);


    glEnd();

    //Wheels
    //backbumper

    Circle(0.068f,-0.19f,0.0f,0.010f,0,0,0);
    //front bumper
    Circle(0.15f,-0.19f,0.0f,0.01f,0,0,0);
    glPopMatrix();
}


void car_4Component()
{
    glPushMatrix();
    glTranslatef(car4_pos,0,0);

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);

    glVertex2f(0.04f, -0.14f);
    glVertex2f(0.04f, -0.19f);
    glVertex2f(0.19f, -0.19f);

    glVertex2f(0.19f, -0.14f);


    glEnd();

    //glass part of car

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);

    glVertex2f(0.078f, -0.11f);
    glVertex2f(0.055f, -0.14f);
    glVertex2f(0.16f, -0.14f);

    glVertex2f(0.13f, -0.11f);


    glEnd();
    //glass

    glBegin(GL_POLYGON);
    glColor3ub(168,204,215);

    glVertex2f(0.078f, -0.115f);
    glVertex2f(0.059f, -0.14f);
    glVertex2f(0.11f, -0.14f);
    glVertex2f(0.11f, -0.115f);


    glEnd();

    //glass-2
    glBegin(GL_POLYGON);
    glColor3ub(168,204,215);

    glVertex2f(0.113f, -0.115f);
    glVertex2f(0.113f, -0.14f);
    glVertex2f(0.155f, -0.14f);
    glVertex2f(0.13f, -0.115f);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);

    glVertex2f(0.04f, -0.14f);
    glVertex2f(0.015f, -0.17f);
    glVertex2f(0.015f, -0.19f);

    glVertex2f(0.04f, -0.19f);


    glEnd();

    //headlight
    glBegin(GL_QUADS);
    glColor3ub(204,204,0);

    glVertex2f(0.015f, -0.17f);
    glVertex2f(0.015f, -0.18f);
    glVertex2f(0.029f, -0.18f);

    glVertex2f(0.029f, -0.17f);


    glEnd();

    // back light
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);

    glVertex2f(0.19f, -0.18f);
    glVertex2f(0.19f, -0.19f);
    glVertex2f(0.196f, -0.19f);

    glVertex2f(0.196f, -0.18f);


    glEnd();

    //Wheels
    //backbumper

    Circle(0.068f,-0.19f,0.0f,0.010f,0,0,0);
    //front bumper
    Circle(0.15f,-0.19f,0.0f,0.01f,0,0,0);
    glPopMatrix();
}

void ahsanMonjilView(){

    glBegin(GL_QUADS);
    glColor3ub(255, 99, 71);
    glVertex2f(0.8f,0.5f);
    glVertex2f(0.8f,0.1f);
    glVertex2f(-0.8f,0.1f);
    glVertex2f(-0.8f,0.5f);
    glEnd();

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
    squareWindowComponent();
    glLoadIdentity();

//left windows
    glLoadIdentity();
    squareWindowComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(0.07, 0, 0);
    squareWindowComponent();
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
    squareWindowComponent();
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(1.47, 0, 0);
    squareWindowComponent();
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
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3ub(35,43,43);
    glVertex2f(0.17f, 0.3f);
    glVertex2f(-0.12f, 0.3f);

    glVertex2f(0.2f, 0.25f);
    glVertex2f(-0.15f, 0.25f);

    glVertex2f(0.23f, 0.20f);
    glVertex2f(-0.18f, 0.20f);

    glVertex2f(0.26f, 0.15f);
    glVertex2f(-0.21f, 0.15f);

    glVertex2f(0.29f, 0.10f);
    glVertex2f(-0.24f, 0.10f);

    glVertex2f(0.32f, 0.05f);
    glVertex2f(-0.27f, 0.05f);

    glVertex2f(0.35f, 0.0f);
    glVertex2f(-0.3f, 0.0f);
    glEnd();
    glLineWidth(4);


}




void roadView()
{

  //road-base
    glBegin(GL_POLYGON);

    glColor3ub(145,145,145);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, 0.0f);

    glEnd();

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

    carComponent();
    car_2Component();
    car_3Component();
    car_4Component();
}


void fullView()
{
   initState();
   axisDraw();
    glLoadIdentity();//Mountain
    glColor3ub(10, 255, 100);
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
   anyQuad(-1, 0.1, -1, -0.2, 1, -0.2, 1, 0.1, 10, 255, 100);//Grass
   ahsanMonjilView();
   roadView();
   glFlush();

}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Ahsan Monjil");
    glutDisplayFunc(fullView);
    glutIdleFunc(Idle);
    glutTimerFunc(1500, update, 0);
    glutMainLoop();
    return 0;
}
