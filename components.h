#include "shapes.h"

void blank(){
}

void pillarComponent(){

    anyQuad(-0.75f, 0.5f, -0.75f, 0.1f, -0.8f, 0.1f, -0.8f, 0.5f, 255, 140, 0);

    anyQuad(-0.755f, 0.55f, -0.755f, 0.5f, -0.795f, 0.5f, -0.795f, 0.55f, 255, 140, 0);

    Circle(-.775f, .55f, .02f, 255, 140, 0);

	glBegin(GL_LINES);
    glColor3ub(255,140,0);
	glVertex2f(-0.776f, 0.59f);
    glVertex2f(-0.776f, 0.56f);
    glVertex2f(-0.785f, 0.58f);
    glVertex2f(-0.77f, 0.58f);
	glEnd();
}

void gombujhComponent(){

  anyQuad(-0.6f, 0.57f, -0.6f, 0.52f, -0.75f, 0.52f, -0.75f, 0.57f, 255, 140, 0);

  Circle(-.68f, .56f, .045f, 255, 140, 0);

  glBegin(GL_POINTS);
  glColor3ub(255,140,0);
  glVertex2f(-0.68f, 0.62f);
  glEnd();
}

void squareWindowComponent(int R, int G, int B){
    anyQuad(-0.69f, 0.4f, -0.69f, 0.3f, -0.73f, 0.3f, -0.73f, 0.4f, R, G, B);
}

void ovalWindowComponent(int R, int G, int B){
    anyQuad(-0.69f, 0.4f, -0.69f, 0.3f, -0.73f, 0.3f, -0.73f, 0.4f, R, G, B);
    Circle(-.71f, .4f, .021f, R, G, B);
}




void threeDotComponent(){
   glBegin(GL_POINTS);
   glColor3ub(0, 0, 0);
   glVertex2f(-0.68f, 0.62f);
   glVertex2f(-0.66f, 0.62f);
   glVertex2f(-0.64f, 0.62f);
   glEnd();
}


void grassComponent(){
    anyQuad(-1, 0.1, -1, -0.2, 1, -0.2, 1, 0.1, 10, 255, 100);
}

void carComponent()
{
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



    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-0.255,-0.038,0);
    glVertex3f(-0.235,-0.038,0);
    glVertex3f(-0.241,-0.030,0);
    glVertex3f(-0.248,-0.030,0);
    glVertex3f(-0.255,-0.035,0);
    glEnd();


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

    Circle(-0.26f, -0.070f, 0.010f,0, 0, 0);
    Circle(-0.199f, -0.07f, 0.01f, 0, 0, 0);
}


void car_2Component()
{

    anyQuad(0.025f, 0.001f,0.025f, -0.045f, 0.222f, -0.045f, 0.222f, 0.001f, 255, 77, 255);

    glBegin(GL_POLYGON);
    glColor3ub(255, 77, 255);

    glVertex2f(0.065f, 0.031f);
    glVertex2f(0.055f, 0.001f);
    glVertex2f(0.20f, -0.001f);

    glVertex2f(0.185f, 0.031f);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(168,204,215);

    glVertex2f(0.065f, 0.027f);
    glVertex2f(0.058f, 0.001f);
    glVertex2f(0.198f, 0.001f);

    glVertex2f(0.185f, 0.027f);


    glEnd();

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


    anyQuad(0.233f, -0.033f, 0.233f, -0.038f, 0.252f, -0.038f, 0.252f, -0.033f, 204, 204, 0);

    anyQuad(0.015f, -0.035f, 0.015f, -0.045f, 0.025f, -0.045f, 0.025f, -0.035f, 255, 77, 255);

    Circle(0.055f,-0.045f, 0.010f,0,0,0);
    Circle(0.20f,-0.045f, 0.01f,0,0,0);
}

void car_3Component()
{
    anyQuad(0.04f, -0.14f, 0.04f, -0.19f, 0.19f, -0.19f, 0.19f, -0.14f, 0, 128, 0);

    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);

    glVertex2f(0.078f, -0.11f);
    glVertex2f(0.055f, -0.14f);
    glVertex2f(0.16f, -0.14f);

    glVertex2f(0.13f, -0.11f);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(168,204,215);

    glVertex2f(0.078f, -0.115f);
    glVertex2f(0.059f, -0.14f);
    glVertex2f(0.11f, -0.14f);
    glVertex2f(0.11f, -0.115f);



    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(168,204,215);

    glVertex2f(0.113f, -0.115f);
    glVertex2f(0.113f, -0.14f);
    glVertex2f(0.155f, -0.14f);
    glVertex2f(0.13f, -0.115f);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);

    glVertex2f(0.04f, -0.14f);
    glVertex2f(0.015f, -0.17f);
    glVertex2f(0.015f, -0.19f);

    glVertex2f(0.04f, -0.19f);


    glEnd();
    anyQuad(0.015f, -0.17f, 0.015f, -0.18f, 0.029f, -0.18f, 0.029f, -0.17f, 204, 204, 0);
    anyQuad(0.19f, -0.18f, 0.19f, -0.19f, 0.196f, -0.19f, 0.196f, -0.18f, 0, 128, 0);
    Circle(0.068f,-0.19f,0.010f,0,0,0);
    Circle(0.15f,-0.19f,0.01f,0,0,0);
}


void car_4Component()
{
    anyQuad(0.04f, -0.14f, 0.04f, -0.19f, 0.19f, -0.19f, 0.19f, -0.14f, 255, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(0.078f, -0.11f);
    glVertex2f(0.055f, -0.14f);
    glVertex2f(0.16f, -0.14f);
    glVertex2f(0.13f, -0.11f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(168,204,215);
    glVertex2f(0.078f, -0.115f);
    glVertex2f(0.059f, -0.14f);
    glVertex2f(0.11f, -0.14f);
    glVertex2f(0.11f, -0.115f);
    glEnd();


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

    anyQuad(0.015f, -0.17f, 0.015f, -0.18f, 0.029f, -0.18f, 0.029f, -0.17f, 204, 204, 0);

    anyQuad(0.19f, -0.18f,0.19f, -0.19f, 0.196f, -0.19f, 0.196f, -0.18f, 255, 0, 0);

    Circle(0.068f,-0.19f,0.010f,0,0,0);

    Circle(0.15f,-0.19f,0.01f,0,0,0);
}

void buildingComponent(){

    anyQuad(-0.7f , 0.7f, -0.7f, 0.3f, -0.9f, 0.3f, -0.9f, 0.7f, 255, 255, 255);

    glLoadIdentity();
    glTranslatef(-0.15f, 0.2f, 0);
    squareWindowComponent(202, 164, 114);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(-0.09f, 0.2f, 0);
    ovalWindowComponent(202, 164, 114);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(-0.03f, 0.2f, 0);
    squareWindowComponent(202, 164, 114);
    glLoadIdentity();


    glLoadIdentity();
    glTranslatef(-0.15f, 0.01f, 0);
    squareWindowComponent(202, 164, 114);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(-0.09f, 0.01f, 0);
    ovalWindowComponent(202, 164, 114);
    glLoadIdentity();

    glLoadIdentity();
    glTranslatef(-0.03f, 0.01f, 0);
    squareWindowComponent(202, 164, 114);
    glLoadIdentity();


}
void shipComponent(){
    anyQuad(0.0f, -0.7f,0.1f,-0.8f,0.7f, -0.8f,0.8f,-0.7f, 41, 34, 31);

    anyQuad(0.1f, -0.55f, 0.1f, -0.7f, 0.7f, -0.7f, 0.7f, -0.55f, 179, 179, 179);

    anyQuad(0.15f, -0.65f, 0.15f, -0.6f, 0.35f, -0.6f, 0.35f, -0.65f, 255, 255, 255);


	glBegin(GL_LINES);
    glColor3ub(31, 31, 31);
    glVertex2f(0.2f, -0.65f);
    glVertex2f(0.2f,-0.6f);
	glEnd();

	glBegin(GL_LINES);
    glColor3ub(31, 31, 31);
    glVertex2f(0.25f, -0.65f);
    glVertex2f(0.25,-0.6f);
	glEnd();

	glBegin(GL_LINES);
    glColor3ub(31, 31, 31);
    glVertex2f(0.3f, -0.65f);
    glVertex2f(0.3f,-0.6f);
	glEnd();


    anyQuad(0.4f, -0.65f, 0.4f, -0.6f, 0.55f, -0.6f, 0.55f, -0.65f, 255, 255, 255);


    glBegin(GL_LINES);
    glColor3ub(31, 31, 31);
    glVertex2f(0.45f, -0.65f);
    glVertex2f(0.45f,-0.6f);
	glEnd();

	glBegin(GL_LINES);
    glColor3ub(31, 31, 31);
    glVertex2f(0.5f, -0.65f);
    glVertex2f(0.5f,-0.6f);
	glEnd();

    anyQuad(0.6f, -0.65f, 0.6f, -0.6f, 0.65f, -0.6f, 0.65,-0.65f, 255, 255, 255);

    anyQuad(0.2f, -0.4f, 0.2f, -0.55f, 0.25f, -0.55f, 0.25f, -0.4f, 43, 40, 40);

    anyQuad(0.21f, -0.4f, 0.2f, -0.3f, 0.25f, -0.3f, 0.24f, -0.4f, 235, 70, 0);

    anyQuad(0.3f, -0.4f, 0.3f,-0.55f, 0.35f, -0.55f, 0.35f,-0.4f, 43, 40, 40);

    anyQuad(0.31f, -0.4f,0.3f,-0.3f, 0.35f, -0.3f, 0.34f,-0.4f, 235, 70, 0);

    anyQuad(0.4f, -0.4f, 0.4f, -0.55f, 0.45f, -0.55f, 0.45f,-0.4f, 43, 40, 40);

    anyQuad(0.41f, -0.4f, 0.4f, -0.3f, 0.45f, -0.3f, 0.44f, -0.4f, 235, 70, 0);

    anyQuad(0.5f, -0.4f, 0.5f,-0.55f, 0.55f, -0.55f, 0.55f,-0.4f, 43, 40, 40);

    anyQuad(0.51f, -0.4f, 0.5f, -0.3f, 0.55f, -0.3f, 0.54f,-0.4f, 235, 70, 0);

    anyQuad(0.6f, -0.4f, 0.6f, -0.55f, 0.65f, -0.55f, 0.65f, -0.4f, 43, 40, 40);

	anyQuad(0.61f, -0.4f, 0.6f, -0.3f, 0.65f, -0.3f, 0.64f,-0.4f, 235, 70, 0);
}

void sunComponent()
{
    Circle(0.8f, 0.8f, 0.09f, 255, 255, 0);
}


void moonComponent()
{
    Circle(0.8f, 0.8f,  0.09f, 245, 245, 245);
}

void starComponent(){
    glPointSize(2);
    glBegin(GL_POINTS);
	glColor3ub(255,255,255);
	glVertex2f(-0.9,0.9);
	glVertex2f(-0.8,0.8);
	glVertex2f(-0.85,0.95);
    glVertex2f(-0.75,0.85);
    glVertex2f(-0.55,0.85);
    glVertex2f(-0.25,0.85);
    glVertex2f(-0.25,0.75);
    glVertex2f(-0.0,0.75);
    glVertex2f(0.25,0.85);
    glVertex2f(0.275,0.75);
    glVertex2f(0.0,0.75);
    glVertex2f(0.9,0.91);
	glVertex2f(0.875,0.95);
    glVertex2f(0,0.99);
    glVertex2f(-0.1,0.95);
    glVertex2f(-0.2,0.93);
    glVertex2f(-0.4,0.95);
    glVertex2f(0.1,0.95);
    glVertex2f(0.2,0.93);
    glVertex2f(0.4,0.95);
    glVertex2f(0.7,0.95);
    glVertex2f(0.8,0.95);
    glEnd();
    glPointSize(7);
}

void cloudComponent(){
    Circle(-0.58f, 0.75f,  0.060f, 70, 75, 71);//left cloud
    Circle(-0.5f, 0.82f,  0.068f, 70, 75, 71);
    Circle(-0.42f, 0.75f,  0.068f, 70, 75, 71);//right cloud
    Circle(-0.5f, 0.72f,  0.07f, 70, 75, 71);
}

void treeComponent(){
    anyQuad(0.69f, 0.13f, 0.67f, 0.10f, 0.78f, 0.10f, 0.76f, 0.13f, 0, 102, 51);
    anyQuad(0.70f, 0.16f, 0.68f, 0.13f, 0.77f, 0.13f, 0.75f, 0.16f, 0, 153, 0);
    anyQuad(0.71f, 0.19f, 0.69f, 0.16f, 0.76f, 0.16f, 0.74f, 0.19f, 0, 204, 0);
    anyQuad(0.72f, 0.22f,0.70f, 0.19f, 0.75f, 0.19f, 0.73f, 0.22f, 128, 255, 0);
    anyQuad(0.71f, 0.10f, 0.71f, 0.0f, 0.73f, 0.0f, 0.73f, 0.10f, 102, 51, 0);
    anyQuad(0.73f, 0.10f, 0.73f, 0.0f, 0.74f, 0.0f, 0.74f, 0.10f, 153, 76, 0);
}

void lampComponent(int R, int G, int B){
    anyQuad(-0.7f, 0.3f, -0.7f, 0.0f, -0.72f, 0.0f, -0.72f, 0.3f, 0, 0, 0);
    anyQuad(-0.7f, 0.3f, -0.7f, 0.28f, -0.65f, 0.28f, -0.65f, 0.3f, 0, 0, 0);
    anyQuad(-0.68f, 0.28f, -0.68f, 0.25f, -0.65f, 0.25f, -0.65f, 0.28f, R, G, B);
}

void credit(){
    anyText("Created by: @tamzid, @shohan, @torab, @tarek", 0.2f, -0.17f, 103, 72, 70);
}
