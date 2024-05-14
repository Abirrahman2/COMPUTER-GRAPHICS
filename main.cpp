#include <windows.h>
#include<mmsystem.h>
#include <GL/glut.h>
#include<math.h>
float move_boat_third=0.0f;
float move_car_second=0.0f;
float move_clouds= 0.0f;
float move_car=0.0f;
float move_truck=0.0f;
float move_bird_x=0.0f;
float move_bird_y=0.0f;
float move_train=0.0f;
float move_boat=0.0f;
float move_boat_second=0.0f;
float move_wave=0.0f;
float count=0;
bool main_page=false;
bool bird_position_status=false;
int perDisplayTime=15000;
int totalScreenTime=0;
int currentScenario=1;

/*void sound()
{

        sndPlaySound("secondbird.wav",SND_FILENAME|SND_SYNC|SND_LOOP);



}*/
void init()
{
   glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,80);
    glMatrixMode(GL_MODELVIEW);
}
void update_boat_third(int value)
{
    move_boat_third=move_boat_third-0.1;
    if(move_boat_third<-100)
    {
        move_boat_third=0;
    }
    glutPostRedisplay();
    glutTimerFunc(60,update_boat_third,0);
}
void update_car_second(int value)
{
    move_car_second=move_car_second+0.1;
    if(move_car_second>100)
    {
        move_car_second=0;
    }
      glutPostRedisplay();
    glutTimerFunc(20,update_car_second,0);
}
void update_wave(int value)
{
    move_wave=move_wave+0.1;

    if(move_wave>100)
    {
        move_wave=-10;

    }
    glutPostRedisplay();
glutTimerFunc(50,update_wave,0);
}
void update_boat(int value)
{
     move_boat=move_boat+0.15;

    if(move_boat>100)
    {
        move_boat=-5;

    }
    glutPostRedisplay();
glutTimerFunc(50,update_boat,0);

}
void update_boat_two(int value)
{
     move_boat_second=move_boat_second+0.1;

    if(move_boat_second>100)
    {
        move_boat_second=-5;

    }
    glutPostRedisplay();
glutTimerFunc(50,update_boat_two,0);

}
void update_train(int value)
{
    move_train=move_train-0.2;
    if(move_train<-100)
    {
        move_train=120;
    }
    glutPostRedisplay();
glutTimerFunc(20,update_train,0);
}
void update_cloud(int value)
{
move_clouds+= 0.12;
    if(move_clouds >100)
    {
    move_clouds =-42;
    }
glutPostRedisplay();
glutTimerFunc(30, update_cloud, 0);
}

void update_car(int value)     ///car_right to left _move
{
    move_car-=0.15;
    if(move_car<-100)
    {
    move_car =5;
    }
    glutPostRedisplay();
glutTimerFunc(20,update_car,0);
}
void update_truck(int value)
{
    move_truck=move_truck+0.1;
    if(move_truck>100)
    {
        move_truck=-5;
    }
    glutPostRedisplay();
glutTimerFunc(20,update_truck,0);
}
void update_bird(int value)
{
    if(bird_position_status==false)
    {
    move_bird_x=move_bird_x+0.9;
    move_bird_y=move_bird_y-1;
    bird_position_status=true;
    }
    else{
            move_bird_x=move_bird_x+0.9;
            move_bird_y=move_bird_y+1;
        bird_position_status=false;
    }

    if(move_bird_x>100)
    {
        move_bird_x=-10;
        move_bird_y=0;
    }
    glutPostRedisplay();
glutTimerFunc(200,update_bird,0);
}
void circle(float x, float y, float radius)
{

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();
}
void circle_for_night(float x, float y, float radius)
{

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(165, 167, 167);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();
}
void circle_star(float x,float y,float radius)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(249, 248, 245);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();
}
void wheel_for_train(float x,float y,float radius)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(23, 32, 42);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();

}

void grass(float x,float y,float radius)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(7, 126, 8);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();

}

void wheel(float x,float y,float radius)//truck er jonno
{
     glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(252, 249, 252);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();
}

void circle_for_flower(float x,float y,float radius)
{
      glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(231, 76, 60);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();

}
void circle_for_flower_two(float x,float y,float radius)
{
      glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(213, 223, 13);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();

}
void circle_for_flower_middle(float x,float y,float radius)
{
      glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        glColor3ub(247, 220, 111);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        //float r=5.0;
        float a = radius* cos(A);
        float b= radius * sin(A);
        glVertex2f(a+x,b+y);
    }

    glEnd();

}
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void info()
{
     glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glColor3f(1.0,0.0,0.0);
    renderBitmapString(35, 75, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "RURAL AND URBAN VIEW");
    renderBitmapString(30, 70, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "COURSE: COMPUTER GRAPHICS");
    renderBitmapString(30, 65, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "SECTION: H");
    glColor3f(0.0,0.0,0.0);
    renderBitmapString(20, 57, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "ID");
    renderBitmapString(50, 57, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "NAME");

     glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
     glVertex2f(35,60);
    glVertex2f(35,36);
    glVertex2f(5,60);
    glVertex2f(5,36);
    glVertex2f(5,60);
    glVertex2f(80,60);
    glVertex2f(5,56);
    glVertex2f(80,56);
    glVertex2f(80,60);
    glVertex2f(80,36);
    glVertex2f(5,36);
    glVertex2f(80,36);
    glVertex2f(5,52);
    glVertex2f(80,52);
    glVertex2f(5,48);
    glVertex2f(80,48);
    glVertex2f(5,44);
    glVertex2f(80,44);
    glVertex2f(5,40);
    glVertex2f(80,40);
    glVertex2f(5,36);
    glVertex2f(80,36);
    glVertex2f(36,32);
    glVertex2f(56,32);

    glVertex2f(80,60);

    glVertex2f(100,60);

    glVertex2f(80,56);

    glVertex2f(100,56);
    glVertex2f(80,36);
    glVertex2f(100,36);

    glVertex2f(80,52);
    glVertex2f(100,52);

    glVertex2f(80,48);
    glVertex2f(100,48);

    glVertex2f(80,44);
    glVertex2f(100,44);

    glVertex2f(80,40);
    glVertex2f(100,40);







    glEnd();

    renderBitmapString(6, 53, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "22-46363-1");
    renderBitmapString(36, 53, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "MD MAHMUDUR RAHMAN");


    renderBitmapString(6, 49, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "22-46172-1");
    renderBitmapString(36, 49, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "SUMAIYA SARKAR SHIMLA");

    renderBitmapString(6, 45, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "22-46319-1");
    renderBitmapString(36, 45, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "SOWHANUR RAHMAN NIROB");

    renderBitmapString(6, 41, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "22-46358-1");
    renderBitmapString(36, 41, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "PRIYA RANI DAS");

    renderBitmapString(6, 37, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "22-46042-1");
    renderBitmapString(36, 37, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "MD. NURUZZAMAN");


    renderBitmapString(81, 57, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "CONTRIBUTION");

    renderBitmapString(81, 53, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "20%");
    renderBitmapString(81, 49, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "20%");
    renderBitmapString(81, 45, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "20%");
    renderBitmapString(81, 41, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "20%");
    renderBitmapString(81, 37, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "20%");





    renderBitmapString(36, 33, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "SUPERVISED BY:");
    renderBitmapString(28, 28, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "MAHFUJUR RAHMAN");

    renderBitmapString(28, 24, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "LECTURER");
    renderBitmapString(28, 20, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "DEPARTMENT OF COMPUTER SCIENCE");

    renderBitmapString(28, 16, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "AMERICAN INTERNATIONAL UNIVERSITY-BANGLADESH");


    renderBitmapString(60, 10, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "PRESS 'S' TO CONTINUE......");


    glFlush();

}
void mountain_for_night()
{
    //171, 235, 198
    //background mountain drawing
    //163, 235, 131->previous color...

    glColor3ub(123, 171, 127);
    glBegin(GL_POLYGON);
    glVertex2f(20,55);
    glVertex2f(34,67);
    glVertex2f(36,67);
    glVertex2f(38,68);
    glVertex2f(40,68);
    glVertex2f(41,67);
    glVertex2f(43,67);
    glVertex2f(45,68);
    glVertex2f(46,68);
    glVertex2f(60,55);
    glVertex2f(20,55);

    glEnd();

    //front
    //prothom pahar
    glColor3ub(9, 105, 5);
    glBegin(GL_POLYGON);
    glVertex2f(0,55);
    glVertex2f(30,55);
    glVertex2f(15,71);
    glVertex2f(0,55);
    //glEnd();

    //prothom pahar e ektu 3d shape
    //123, 171, 127
    //206, 235, 163->previous

    glColor3ub(123, 171, 127);
    glBegin(GL_POLYGON);
    glVertex2f(5,60);
    glVertex2f(6,60);
    glVertex2f(8,61);
    glVertex2f(15,71);
    glVertex2f(5,60);
    glEnd();
    //first pahar e arektu 3d shape


    glColor3ub(123, 171, 127);
    glBegin(GL_POLYGON);
    glVertex2f(15,71);
    glVertex2f(16,69.5);
    glVertex2f(17,69);
    glVertex2f(18,68.2);
    glVertex2f(19,67);
    glVertex2f(20,66.5);
    glVertex2f(21.6,66);
    glVertex2f(20,65);
    glVertex2f(15,71);

    glEnd();


  //front mountain drawing
     glColor3ub(110, 151, 93);
    glBegin(GL_POLYGON);
    glVertex2f(0,63);
    glVertex2f(1,64);
    glVertex2f(3,64);
    glVertex2f(6,67);
    glVertex2f(9,64);
    glVertex2f(8,62);
    glVertex2f(5,65);
    glVertex2f(0,60);
    glVertex2f(0,63);
   // glEnd();

     glColor3ub(59, 187, 4);
    glBegin(GL_POLYGON);
    glVertex2f(0,60);
    glVertex2f(5,65);
    glVertex2f(8,62);
    glVertex2f(0,55);
    glVertex2f(0,60);
    glEnd();

     //second pahar
     glColor3ub(9, 105, 5);
    glBegin(GL_POLYGON);
    glVertex2f(20,65);
    glVertex2f(23,69);
    glVertex2f(24,69);
    glVertex2f(37,55);
    glVertex2f(30,55);
    glVertex2f(20,65);
   // glEnd();
   //second pahar a 3d shape
    glColor3ub(152, 225, 120);
    glBegin(GL_POLYGON);
    glVertex2f(20,65);
    glVertex2f(21,64);
    glVertex2f(21.5,65);
    glVertex2f(22.5,67);
    glVertex2f(23,68);
    glVertex2f(23,69);
    glVertex2f(20,65);
    glEnd();
    //third pahar
   glColor3ub(9, 105, 5);
    glBegin(GL_POLYGON);
    glVertex2f(30,55);
    glVertex2f(50,67);
    glVertex2f(52,67);
    glVertex2f(70,55);
    glVertex2f(30,55);
    //third pahar er 3d shape

     glColor3ub(168, 235, 139);
    glBegin(GL_POLYGON);
    glVertex2f(52,67);
    glVertex2f(56,66);
    glVertex2f(59,64.5);
    glVertex2f(60,63.5);
    glVertex2f(62,62);
    glVertex2f(65,60);
    glVertex2f(67,58);
    glVertex2f(68,58);
    glVertex2f(71,55);
    glVertex2f(70,55);
    glVertex2f(52,67);

    glEnd();


}
void mountain()
{

//171, 235, 198
    //background mountain drawing
    glColor3ub(163, 235, 131);
    glBegin(GL_POLYGON);
    glVertex2f(20,55);
    glVertex2f(34,67);
    glVertex2f(36,67);
    glVertex2f(38,68);
    glVertex2f(40,68);
    glVertex2f(41,67);
    glVertex2f(43,67);
    glVertex2f(45,68);
    glVertex2f(46,68);
    glVertex2f(60,55);
    glVertex2f(20,55);

    glEnd();

    //front
    //prothom pahar
    glColor3ub(9, 105, 5);
    glBegin(GL_POLYGON);
    glVertex2f(0,55);
    glVertex2f(30,55);
    glVertex2f(15,71);
    glVertex2f(0,55);
    //glEnd();

    //prothom pahar e ektu 3d shape

    glColor3ub(206, 235, 163);
    glBegin(GL_POLYGON);
    glVertex2f(5,60);
    glVertex2f(6,60);
    glVertex2f(8,61);
    glVertex2f(15,71);
    glVertex2f(5,60);
    glEnd();
    //first pahar e arektu 3d shape


    glColor3ub(168, 235, 139);
    glBegin(GL_POLYGON);
    glVertex2f(15,71);
    glVertex2f(16,69.5);
    glVertex2f(17,69);
    glVertex2f(18,68.2);
    glVertex2f(19,67);
    glVertex2f(20,66.5);
    glVertex2f(21.6,66);
    glVertex2f(20,65);
    glVertex2f(15,71);

    glEnd();


  //front mountain drawing
     glColor3ub(110, 151, 93);
    glBegin(GL_POLYGON);
    glVertex2f(0,63);
    glVertex2f(1,64);
    glVertex2f(3,64);
    glVertex2f(6,67);
    glVertex2f(9,64);
    glVertex2f(8,62);
    glVertex2f(5,65);
    glVertex2f(0,60);
    glVertex2f(0,63);
   // glEnd();

     glColor3ub(59, 187, 4);
    glBegin(GL_POLYGON);
    glVertex2f(0,60);
    glVertex2f(5,65);
    glVertex2f(8,62);
    glVertex2f(0,55);
    glVertex2f(0,60);
    glEnd();

     //second pahar
     glColor3ub(9, 105, 5);
    glBegin(GL_POLYGON);
    glVertex2f(20,65);
    glVertex2f(23,69);
    glVertex2f(24,69);
    glVertex2f(37,55);
    glVertex2f(30,55);
    glVertex2f(20,65);
   // glEnd();
   //second pahar a 3d shape
    glColor3ub(152, 225, 120);
    glBegin(GL_POLYGON);
    glVertex2f(20,65);
    glVertex2f(21,64);
    glVertex2f(21.5,65);
    glVertex2f(22.5,67);
    glVertex2f(23,68);
    glVertex2f(23,69);
    glVertex2f(20,65);
    glEnd();
    //third pahar
   glColor3ub(9, 105, 5);
    glBegin(GL_POLYGON);
    glVertex2f(30,55);
    glVertex2f(50,67);
    glVertex2f(52,67);
    glVertex2f(70,55);
    glVertex2f(30,55);
    //third pahar er 3d shape

     glColor3ub(168, 235, 139);
    glBegin(GL_POLYGON);
    glVertex2f(52,67);
    glVertex2f(56,66);
    glVertex2f(59,64.5);
    glVertex2f(60,63.5);
    glVertex2f(62,62);
    glVertex2f(65,60);
    glVertex2f(67,58);
    glVertex2f(68,58);
    glVertex2f(71,55);
    glVertex2f(70,55);
    glVertex2f(52,67);

    glEnd();


}
void day()
{
     //glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glLoadIdentity();
    glColor3f(0.4f,0.69f,1.0f);
    //SKY AND MOUNTAIN PORTION AND SUN
    glBegin(GL_POLYGON);

    glVertex2f(0,55);
    glVertex2f(100,55);
    glVertex2f(100,80);
    glVertex2f(0,80);
    glEnd();

    //SUN
      glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(250, 229, 211);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=5.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+50,y+73);
        }
  glEnd();

  //MOUNTAINS
  glPushMatrix();
   mountain();
  glPopMatrix();
   //Mountain er nicher part......
   glColor3ub(100, 97, 11);
   glBegin(GL_POLYGON);
   glVertex2f(0,50);
   glVertex2f(100,50);
   glVertex2f(100,55);
   glVertex2f(0,55);
   glVertex2f(0,50);

   glEnd();
   glLoadIdentity();
   //houses....
   glPushMatrix();
   glColor3ub(234, 233, 131);
   glBegin(GL_POLYGON);
   glVertex2f(80,55);
   glVertex2f(84,55);
   glVertex2f(84,58);
   glVertex2f(80,58);
   glVertex2f(80,55);


   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(84,55);
   glVertex2f(84,58);
   glEnd();

glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(80,55);
   glVertex2f(80,58);
   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(80,58);
   glVertex2f(84,58);
   glEnd();

   glColor3ub(190, 189, 139);
   glBegin(GL_POLYGON);
   glVertex2f(84,55);
   glVertex2f(89,55);
   glVertex2f(89,58);
   glVertex2f(84,58);
   glVertex2f(84,55);

   glEnd();

   glColor3ub(242, 145, 13);
   glBegin(GL_POLYGON);
   glVertex2f(80,58);
   glVertex2f(84,58);
   glVertex2f(82,60);
   glVertex2f(80,58);


   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(82,60);
   glVertex2f(84,58);
   glEnd();


    glColor3ub(177, 108, 14);
   glBegin(GL_POLYGON);
   glVertex2f(82,60);
   glVertex2f(84,58);
   glVertex2f(89,58);
   glVertex2f(87,60);
    glVertex2f(82,60);


   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(84,58);
   glVertex2f(89,58);
   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(87,60);
   glVertex2f(89,58);
   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(82,60);
   glVertex2f(87,60);
   glEnd();


   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(89,55);
   glVertex2f(89,58);
   glEnd();

    glColor3ub(111, 111, 105);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2f(82,60);
   glVertex2f(80,58);
   glEnd();

    glColor3ub(177, 108, 14);
   glBegin(GL_POLYGON);
   glVertex2f(86,55);
   glVertex2f(87,55);
   glVertex2f(87,57);
   glVertex2f(86,57);
    glVertex2f(86,55);


   glEnd();

    glColor3ub(177, 108, 14);
   glBegin(GL_POLYGON);
   glVertex2f(81.5,56);
   glVertex2f(82.5,56);
   glVertex2f(82.5,57);
   glVertex2f(81.5,57);
    glVertex2f(81.5,56);


   glEnd();





   glPopMatrix();


   //crop yeild one
   glTranslatef(+0.0f,0.0f,0.0f);
   glPushMatrix();
   glColor3ub(191, 189, 115);
   glBegin(GL_POLYGON);
   glVertex2f(15,51);
   glVertex2f(22,51);
   glVertex2f(24,54);
   glVertex2f(18,54);
   glVertex2f(15,51);
   glEnd();
   //dhaan
    glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();
   glLoadIdentity();
   glTranslatef(-0.5f,-1.0f,0.0f);
   //second raw dhaan er
   glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();


   glPopMatrix();
    //glLoadIdentity();
    // crop yield field second number
    glTranslatef(+8.0f,0.0f,0.0f);
    glPushMatrix();
   glColor3ub(191, 189, 115);
   glBegin(GL_POLYGON);
   glVertex2f(15,51);
   glVertex2f(22,51);
   glVertex2f(24,54);
   glVertex2f(18,54);
   glVertex2f(15,51);
   glEnd();
   //dhaan
    glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();
   //glLoadIdentity();
   glTranslatef(-0.5f,-1.0f,0.0f);
   //second raw dhaan er
   glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();


   glPopMatrix();
   glLoadIdentity();
   //crop field third number...
   glTranslatef(+8.0f,0.0f,0.0f);

    glTranslatef(+8.0f,0.0f,0.0f);
    glPushMatrix();
   glColor3ub(191, 189, 115);
   glBegin(GL_POLYGON);
   glVertex2f(15,51);
   glVertex2f(22,51);
   glVertex2f(24,54);
   glVertex2f(18,54);
   glVertex2f(15,51);
   glEnd();
   //dhaan
    glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();
   //glLoadIdentity();
   glTranslatef(-0.5f,-1.0f,0.0f);
   //second raw dhaan er
   glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();


   glPopMatrix();
   glLoadIdentity();
    //TREES........








    glPushMatrix();
    //back boro boro trees......

    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

    glTranslatef(2.5f,0.0f,0.0f);

    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

    glTranslatef(2.5f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
    glTranslatef(4.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
     glTranslatef(4.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(4.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();


     glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();

    glPopMatrix();


     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
     glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();


     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
 glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
    glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
 glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();











    //finished tree back.......




     glLoadIdentity();
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslatef(1.0f,0.0f,0.0f);


    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();

    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();

    glPopMatrix();


    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();

   glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();



    glPopMatrix();





  //CLOUDS
   glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_clouds, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
        glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+5,y+70);
        }

  glEnd();
   glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {

        glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+7,y+72);
        }
  glEnd();
  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
      glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+9,y+70);
        }
  glEnd();
  glPopMatrix();
  //CLOUD 2

 // glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_clouds, 0.0f, 0.0f);

  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
        glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+20,y+68);
        }
  glEnd();

  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
       glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+25,y+68);
        }
  glEnd();

  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
        glColor3ub(220, 220, 230);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+23,y+71);
        }
  glEnd();
  glLoadIdentity();
  glPopMatrix();
  glTranslatef(move_clouds,0.0f,0.0f);
   //CLOUD 3
   glPushMatrix();
   circle(43,70,3);
   circle(40,70,3);
   circle(41.5,72,3);
   circle(44,71,3);
   circle(38,71,3);
   glPopMatrix();

   //BIRDS
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(move_bird_x,move_bird_y,0.0f);
   glColor3ub(22, 20, 22);
   glLineWidth(1.5);
   glBegin(GL_LINES);
    glVertex2f(2,70);
    glVertex2f(4,69);
    glVertex2f(4,69);
    glVertex2f(6,71);


   glEnd();

   glColor3ub(22, 20, 22);
   glLineWidth(1.5);
   glBegin(GL_LINES);
    glVertex2f(8,73);
    glVertex2f(10,71);
    glVertex2f(10,71);
    glVertex2f(12,74);

   glEnd();

   glColor3ub(22, 20, 22);
   glLineWidth(1.5);
   glBegin(GL_LINES);
    glVertex2f(11,70);
    glVertex2f(13,68);
    glVertex2f(13,68);
    glVertex2f(15,70);


   glEnd();


   glPopMatrix();




  //SEA AND BOATS

   glLoadIdentity();
   //river border....
   //124, 237, 245
   glColor3ub(124, 237, 245);
    glBegin(GL_POLYGON);

    glVertex2f(0,30);
    glVertex2f(100,30);
    glVertex2f(100,50);
    glVertex2f(0,50);
    glVertex2f(0,30);

    glEnd();
    glLoadIdentity();
    //panir sroooot......
    glPushMatrix();

     glTranslatef(move_wave,0.0f,0.0f);
    glColor3ub(212, 230, 241);
    glBegin(GL_POLYGON);
    glVertex2f(28,40);
    glVertex2f(37,39.5);
    glVertex2f(48,39.5);
    glVertex2f(51,40);
    glVertex2f(48,40.5);
    glVertex2f(37,40.5);
    glVertex2f(28,40);


    glEnd();


     glColor3ub(212, 230, 241);
    glBegin(GL_POLYGON);
    glVertex2f(60,45.5);
    glVertex2f(72,45.5);
    glVertex2f(80,45.5);
    glVertex2f(88,46);
    glVertex2f(60,46);
    glVertex2f(60,45.5);
    glVertex2f(60,45.5);


    glEnd();


     glColor3ub(212, 230, 241);
    glBegin(GL_POLYGON);
    glVertex2f(20,47.5);
    glVertex2f(40,47.5);
    glVertex2f(47,47);
    glVertex2f(52,48);
    glVertex2f(20,48);
    glVertex2f(20,47.5);



    glEnd();

    glPopMatrix();
    glLoadIdentity();
    //boats.....

    //boat one  moving.....
    glPushMatrix();

      glTranslatef(move_boat,0.0f,0.0f);
    glColor3ub(100, 68, 73);
    glBegin(GL_POLYGON);
    glVertex2f(10,47);
    glVertex2f(12,46);
    glVertex2f(14,46);
    glVertex2f(16,47);
    glVertex2f(10,47);
    glEnd();

    glColor3ub(168, 161, 162);
    glBegin(GL_POLYGON);
    glVertex2f(12,47);
    glVertex2f(14,47);
    glVertex2f(14,47.5);
    glVertex2f(12,47.5);
    glVertex2f(12,47);
    glEnd();



    glPopMatrix();
    glLoadIdentity();

    //boat two moving......
    glPushMatrix();
     glTranslatef(move_boat_second,0.0f,0.0f);
    glColor3ub(41, 38, 38);
    glBegin(GL_POLYGON);
    glVertex2f(3,42);
    glVertex2f(5,40);
    glVertex2f(10,40);
    glVertex2f(12,42);
    glVertex2f(3,42);
    glEnd();



    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(7,46);
    glVertex2f(10,43);
    glVertex2f(7,42);
    glVertex2f(7,46);

    glEnd();

    glColor3ub(20, 20, 19);
    glLineWidth(1.5);
    glBegin(GL_LINES);

    glVertex2f(7,42);
    glVertex2f(7,46);


    glEnd();


    glPopMatrix();

      glLoadIdentity();
    //MOSQUE
    //basement
    glColor3ub(153.0f,57.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(35,30);
    glVertex2f(50,30);
    glVertex2f(50,31);
    glVertex2f(35,31);
    glVertex2f(35,30);
    glEnd();
    //body
     glColor3ub(204.0f,105.0f,0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(36,31);
    glVertex2f(49,31);
    glVertex2f(49,35);
    glVertex2f(36,35);
    glVertex2f(36,31);
    glEnd();

    //moshjid er uporer part
    /* glColor3ub(0.0f,204.0f,204.0f);
    glBegin(GL_POLYGON);
    glVertex2f(39,35);
    glVertex2f(46,35);
    glVertex2f(42.5,38);
    glVertex2f(39,35);

    glEnd();*/
     //mosjid er uporer part 2
     glColor3ub(213, 245, 227);
    glBegin(GL_POLYGON);
    for (int i = 20; i <= 70; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(180);
        float x = 5.0f * cos(theta);
        float y =  5.0f * sin(theta);
        glVertex2f(x+42.5, y+31.8);
    }
    glEnd();
     glColor3ub(246, 221, 204);
    glBegin(GL_POLYGON);
    glVertex2f(40,31);
    glVertex2f(45,31);
    glVertex2f(45,33);
    glVertex2f(42.5,35);
    glVertex2f(40,33);
    glVertex2f(40,31);
    glEnd();

    //LEFT SIDE basement

     glColor3ub(153.0f,57.0f,0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(29,30);
    glVertex2f(33,30);
    glVertex2f(33,31);
    glVertex2f(29,31);
    glVertex2f(29,30);
    glEnd();
   //LEFT SIDE MINAR
   glColor3ub(255.0f,170.0f,0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(30,31);
    glVertex2f(32,31);
    glVertex2f(32,37);
    glVertex2f(30,37);
    glVertex2f(30,31);
    glEnd();

    //left side minar er uporer part
      glColor3ub(213, 245, 227);
    glBegin(GL_POLYGON);
    for (int i = 20; i <= 70; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(180);
        float x = 3.0f * cos(theta);
        float y =  3.0f * sin(theta);
        glVertex2f(x+31, y+35);
    }
    glEnd();

    //RIGHT SIDE MINAR

     //basement

       glColor3ub(153.0f,57.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(52,30);
    glVertex2f(56,30);
    glVertex2f(56,31);
    glVertex2f(52,31);
    glVertex2f(52,30);
    glEnd();

    //RIGHT SIDE MINAR
    glColor3ub(255.0f,170.0f,0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(53,31);
    glVertex2f(55,31);
    glVertex2f(55,37);
    glVertex2f(53,37);
    glVertex2f(53,31);
    glEnd();

    //RIGHT SIDE MINAR ER uporer part

     glColor3ub(213, 245, 227);
    glBegin(GL_POLYGON);
    for (int i = 20; i <= 70; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(180);
        float x = 3.0f * cos(theta);
        float y =  3.0f * sin(theta);
        glVertex2f(x+54, y+35);
    }
    glEnd();




    //ROAD AND CARS
    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex2f(0,10);
    glVertex2f(100,10);
    glVertex2f(100,30);
    glVertex2f(0,30);
    glVertex2f(0,0);
    glEnd();


     glLoadIdentity();
    glPushMatrix();
    glTranslatef(+0.0f,0.0f,0.0f);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();
    glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();


    glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();


     glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();

     glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();
    glPopMatrix();

    //MOVING CAR ONE
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_car,0.0f, 0.0f);
    glColor3f(0.1373, 0.5725,0.5529);
    glBegin(GL_QUADS);
    glVertex2f(85,23.5);
    glVertex2f(94,23.5);
    glVertex2f(94,25);
    glVertex2f(85,25);
    glVertex2f(85,23.5);
    glEnd();

    glColor3ub(170, 183, 184);
    glBegin(GL_POLYGON);
    glVertex2f(86.5,25);//glVertex2f(5,38)
                        //glVertex2f(14,38)
                        //.....(14,42)
                        //(5,40)
                        //(5,38)
    glVertex2f(88,26.5);
    glVertex2f(92,26.5);
    glVertex2f(93,25);
    glVertex2f(86.5,25);
    glEnd();


     glColor3ub(23, 32, 42);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(86.5,25);
    glVertex2f(88,26.5);
    glVertex2f(88,26.5);
    glVertex2f(88,25);
    glVertex2f(88,25);
     glVertex2f(86.5,25);
    glEnd();

     glColor3ub(23, 32, 42);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(92,25);
    glVertex2f(92,26.5);
    glVertex2f(92,26.5);
    glVertex2f(93,25);
    glVertex2f(93,25);
    glVertex2f(92,25);

    glEnd();
  //wheel 1
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(213, 216, 220);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+87,y+23.5);
        }
  glEnd();

     //wheel 2
      glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(213, 216, 220);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+93,y+23.5);
        }
  glEnd();


    glPopMatrix();


    //MOVING TRUCK
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_truck,0.0f,0.0f);
    glColor3ub(222, 13, 187);
    glBegin(GL_POLYGON);
    glVertex2f(5,14);
    glVertex2f(15,14);
    glVertex2f(15,18);
    glVertex2f(5,18);
    glVertex2f(5,14);

    glEnd();

     glColor3ub(91, 86, 90);
    glBegin(GL_POLYGON);
    glVertex2f(15,14);
    glVertex2f(17,14);
    glVertex2f(17,16);
    glVertex2f(15,17);
    glVertex2f(15,14);

    glEnd();

    glColor3ub(234, 228, 233);
    glBegin(GL_POLYGON);

    glVertex2f(15,16);
    glVertex2f(17,16);
    glVertex2f(15,17);
    glVertex2f(15,16);

    glEnd();

    wheel(6.5,14,0.8);
    wheel(14,14,0.8);


    glPopMatrix();
    glLoadIdentity();
     //NICHER ROAD BORDER......
     glPushMatrix();
    glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(0,13);
    glVertex2f(100,13);
    glVertex2f(100,14);
    glVertex2f(0,14);
    glVertex2f(0,13);

    glEnd();
     glTranslatef(+0.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();

     glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();

    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();



    glPopMatrix();
    glLoadIdentity();

    //TRAIN
    //train er ekdom niche...
    glColor3ub(97, 84, 4);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,0);
    glVertex2f(100,2.5);
    glVertex2f(0,2.5);
    glVertex2f(0,0);

    glEnd();
    //TRAIN LINE  BORDER......
     glColor3ub(204, 209, 209);
    glBegin(GL_POLYGON);
    glVertex2f(0,2.5);
    glVertex2f(100,2.5);
    glVertex2f(100,6.5);
    glVertex2f(0,6.5);
    glVertex2f(0,2.5);

    glEnd();


    glPushMatrix();
    glTranslatef(+0.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
     glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();



    glPopMatrix();

   glLoadIdentity();
   //nicher rail line border....
    glColor3ub(93, 109, 126);
    glBegin(GL_POLYGON);
    glVertex2f(0,2.5);
    glVertex2f(100,2.5);
    glVertex2f(100,3);
    glVertex2f(0,3);
    glVertex2f(0,2.5);

    glEnd();
    //rail line er uporer border.....
    glColor3ub(93, 109, 126);
    glBegin(GL_POLYGON);
    glVertex2f(0,6.5);
    glVertex2f(100,6.5);
    glVertex2f(100,7);
    glVertex2f(0,7);
    glVertex2f(0,6.5);

    glEnd();
    //TRAIN ER body.....
    //TRAIN MOVING.....


    glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_train,0.0f, 0.0f);


    //train wheel....

    wheel_for_train(25,4,1);
    wheel_for_train(27,4,1);
    wheel_for_train(33,4,1);
    wheel_for_train(35,4,1);
    wheel_for_train(37,4,1);
    wheel_for_train(46,4,1);
    wheel_for_train(48,4,1);
    wheel_for_train(51,4,1);
    wheel_for_train(53,4,1);
    wheel_for_train(60,4,1);
    wheel_for_train(62,4,1);
    wheel_for_train(65,4,1);
    wheel_for_train(67,4,1);
    wheel_for_train(73,4,1);
    wheel_for_train(75,4,1);
    //engine...
    glColor3ub(100, 30, 22);
    glBegin(GL_POLYGON);
    glVertex2f(20,4);
    glVertex2f(27,4);
    glVertex2f(27,7);
    glVertex2f(20,7);
    glVertex2f(20,4);

    glEnd();
   //glass....

    glColor3ub(235, 237, 239);
    glBegin(GL_POLYGON);
    glVertex2f(22,7);
    glVertex2f(25,7);
    glVertex2f(25,10);
    glVertex2f(22,7);

    glEnd();
    glColor3ub(23, 32, 42);
      glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2f(22,7);
    glVertex2f(25,10);
    glVertex2f(22,7);
    glVertex2f(25,7);
     glVertex2f(25,7);
     glVertex2f(25,10);
    glEnd();

   //train engine er janala...

     glColor3ub(100, 30, 22);
    glBegin(GL_POLYGON);
    glVertex2f(25,7);
    glVertex2f(27,7);
    glVertex2f(27,10);
    glVertex2f(25,10);
    glVertex2f(25,7);

    glEnd();
    //engine back....
     glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(27,4);
    glVertex2f(35,4);
    glVertex2f(35,10);
    glVertex2f(27,10);
    glVertex2f(27,4);

    glEnd();
    //body one.....

    glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(35,4);
    glVertex2f(49,4);
    glVertex2f(49,10);
    glVertex2f(35,10);
    glVertex2f(35,4);

    glEnd();
   //body two.....
    glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(49,4);
    glVertex2f(63,4);
    glVertex2f(63,10);
    glVertex2f(49,10);
    glVertex2f(49,4);

    glEnd();
    //body three.....
    glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(63,4);
    glVertex2f(77,4);
    glVertex2f(77,10);
    glVertex2f(63,10);
    glVertex2f(63,4);

    glEnd();

    //border engine -1 bold....
     glColor3ub(151, 154, 154);
    glBegin(GL_POLYGON);
    glVertex2f(35,4);
    glVertex2f(35.5,4);
    glVertex2f(35.5,10);
    glVertex2f(35,10);
    glVertex2f(35,4);

    glEnd();

   //border 1-2 bold....

    glColor3ub(151, 154, 154);
    glBegin(GL_POLYGON);
    glVertex2f(49,4);
    glVertex2f(49.5,4);
    glVertex2f(49.5,10);
    glVertex2f(49,10);
    glVertex2f(49,4);

    glEnd();
    //border 2-3 bold.....
    glColor3ub(151, 154, 154);
    glBegin(GL_POLYGON);
    glVertex2f(63,4);
    glVertex2f(63.5,4);
    glVertex2f(63.5,10);
    glVertex2f(63,10);
    glVertex2f(63,4);

    glEnd();

    //train er window 1...
    glPushMatrix();
    glTranslatef(+0.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
     glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();

    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+4.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+4.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();

    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();

    glTranslatef(+4.0f,0.0f,0.0f);
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();


    glPopMatrix();

     glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(20,4);
    glVertex2f(21,4);
    glVertex2f(21,7);
    glVertex2f(20,7);
    glVertex2f(20,4);

    glEnd();
    //engine er janala alada kore draw.....
    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(28,7);
    glVertex2f(30,7);
    glVertex2f(30,9);
    glVertex2f(28,9);
    glVertex2f(28,7);

    glEnd();


    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(32,7);
    glVertex2f(34,7);
    glVertex2f(34,9);
    glVertex2f(32,9);
    glVertex2f(32,7);

    glEnd();


    glPopMatrix();
    glLoadIdentity();
   //train er niche grass.....

  grass(4,0,4);
  grass(2,2,4);

  grass(19,0,3);
  grass(23,0,5);
  grass(27,0,3);

  grass(40,0,5);
  grass(38,3,3);
  grass(42,3,3);
  grass(45,2,3);
  grass(47,3,3);
  grass(48,0,3.2);

  grass(60,0,3);
  grass(64,1,4.5);
  grass(68,0,3);

  grass(100,0,6);
  grass(94,0,3);


    glFlush();

}
void nightDisplayTwo()
{
    glClear(GL_COLOR_BUFFER_BIT);
     //glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3ub(21, 67, 96);
   // 0.4f,0.69f,1.0f
    //SKY AND MOUNTAIN PORTION AND SUN
    glBegin(GL_POLYGON);

    glVertex2f(0,55);
    glVertex2f(100,55);
    glVertex2f(100,80);
    glVertex2f(0,80);
    glEnd();
    circle_star(5,75,0.2);
    circle_star(2,68,0.2);
    circle_star(1,71,0.2);
    circle_star(10,71,0.2);
    circle_star(15,75,0.2);
    circle_star(20,76,0.2);
    circle_star(26,74,0.2);
    circle_star(34,72,0.2);
    circle_star(42,75,0.2);
    circle_star(50,73,0.2);
    circle_star(60,70,0.2);
    circle_star(65,75,0.2);
    circle_star(70,65,0.2);
    circle_star(75,69,0.2);
    circle_star(80,71,0.2);



    //MOOON FIRST BIG CIRCLE.....
      glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(236, 240, 241);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+93,y+72);
        }
  glEnd();
  //MOON SECOND CIRCLE....
   glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(21, 67, 96);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+95,y+74);
        }
  glEnd();

  //MOUNTAINS
  glPushMatrix();
  // mountain();
  mountain_for_night();
  glPopMatrix();
   //Mountain er nicher part......
   //125, 102, 8

   //100, 97, 11->previous value
   glColor3ub(120, 66, 18);
   glBegin(GL_POLYGON);
   glVertex2f(0,50);
   glVertex2f(100,50);
   glVertex2f(100,55);
   glVertex2f(0,55);
   glVertex2f(0,50);

   glEnd();
   glLoadIdentity();
   //houses....
   glPushMatrix();
   //LEFT SIDE BODY.....
   //234, 233, 131->PREVIOUS VALUE...
   glColor3ub(186, 184, 127);
   glBegin(GL_POLYGON);
   glVertex2f(80,55);
   glVertex2f(84,55);
   glVertex2f(84,58);
   glVertex2f(80,58);
   glVertex2f(80,55);


   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(84,55);
   glVertex2f(84,58);
   glEnd();

glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(80,55);
   glVertex2f(80,58);
   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(80,58);
   glVertex2f(84,58);
   glEnd();
   //HOUSE ER MIDDLE BODY...
   glColor3ub(186, 184, 127);
   glBegin(GL_POLYGON);
   glVertex2f(84,55);
   glVertex2f(89,55);
   glVertex2f(89,58);
   glVertex2f(84,58);
   glVertex2f(84,55);

   glEnd();
   //CHAAD LEFT SIDE...
   glColor3ub(177, 108, 14);
   glBegin(GL_POLYGON);
   glVertex2f(80,58);
   glVertex2f(84,58);
   glVertex2f(82,60);
   glVertex2f(80,58);


   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(82,60);
   glVertex2f(84,58);
   glEnd();

   //CHAADD....
    glColor3ub(177, 108, 14);
   glBegin(GL_POLYGON);
   glVertex2f(82,60);
   glVertex2f(84,58);
   glVertex2f(89,58);
   glVertex2f(87,60);
    glVertex2f(82,60);


   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(84,58);
   glVertex2f(89,58);
   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(87,60);
   glVertex2f(89,58);
   glEnd();

   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(82,60);
   glVertex2f(87,60);
   glEnd();


   glColor3ub(111, 111, 105);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(89,55);
   glVertex2f(89,58);
   glEnd();

    glColor3ub(111, 111, 105);
   glLineWidth(2);
   glBegin(GL_LINES);
   glVertex2f(82,60);
   glVertex2f(80,58);
   glEnd();
 //DORJAAA....
    glColor3ub(247, 220, 111);
   glBegin(GL_POLYGON);
   glVertex2f(86,55);
   glVertex2f(87,55);
   glVertex2f(87,57);
   glVertex2f(86,57);
    glVertex2f(86,55);


   glEnd();
   //LEFT SIDE WINDOW ....
   //247, 220, 111
   //177, 108, 14->previous value
    glColor3ub(247, 220, 111);
   glBegin(GL_POLYGON);
   glVertex2f(81.5,56);
   glVertex2f(82.5,56);
   glVertex2f(82.5,57);
   glVertex2f(81.5,57);
    glVertex2f(81.5,56);


   glEnd();





   glPopMatrix();


   //crop yeild one
   glTranslatef(+0.0f,0.0f,0.0f);
   glPushMatrix();
   //164, 133, 5
   //191, 189, 115->PREVIOUS VALUE...
   glColor3ub(164, 133, 5);
   glBegin(GL_POLYGON);
   glVertex2f(15,51);
   glVertex2f(22,51);
   glVertex2f(24,54);
   glVertex2f(18,54);
   glVertex2f(15,51);
   glEnd();
   //dhaan
    glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();
   glLoadIdentity();
   glTranslatef(-0.5f,-1.0f,0.0f);
   //second raw dhaan er
   glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();


   glPopMatrix();
    //glLoadIdentity();
    // crop yield field second number
    glTranslatef(+8.0f,0.0f,0.0f);
    glPushMatrix();
   glColor3ub(164, 133, 5);
   glBegin(GL_POLYGON);
   glVertex2f(15,51);
   glVertex2f(22,51);
   glVertex2f(24,54);
   glVertex2f(18,54);
   glVertex2f(15,51);
   glEnd();
   //dhaan
    glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();
   //glLoadIdentity();
   glTranslatef(-0.5f,-1.0f,0.0f);
   //second raw dhaan er
   glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();


   glPopMatrix();
   glLoadIdentity();
   //crop field third number...
   glTranslatef(+8.0f,0.0f,0.0f);

    glTranslatef(+8.0f,0.0f,0.0f);
    glPushMatrix();
   glColor3ub(164, 133, 5);
   glBegin(GL_POLYGON);
   glVertex2f(15,51);
   glVertex2f(22,51);
   glVertex2f(24,54);
   glVertex2f(18,54);
   glVertex2f(15,51);
   glEnd();
   //dhaan
    glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();
   //glLoadIdentity();
   glTranslatef(-0.5f,-1.0f,0.0f);
   //second raw dhaan er
   glPushMatrix();
   glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

    glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();

     glTranslatef(+1.0f,0.0f,0.0f);
   //dhaaannn
    glColor3ub(69, 68, 28);
   glLineWidth(1.5);
   glBegin(GL_LINES);
   glVertex2f(18,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53);
   glVertex2f(19,53.5);
   glVertex2f(18.5,53);
   glVertex2f(18.5,53.7);
    glEnd();
   glPopMatrix();


   glPopMatrix();
   glLoadIdentity();
    //TREES........








    glPushMatrix();
    //back boro boro trees......

    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

    glTranslatef(2.5f,0.0f,0.0f);

    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

    glTranslatef(2.5f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
    glTranslatef(4.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
     glTranslatef(4.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(4.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();

     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();


     glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();

    glPopMatrix();


     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
     glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();


     glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
 glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
    glTranslatef(2.0f,1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();
 glTranslatef(2.0f,-1.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,56);
   glVertex2f(3.5,56);
   glVertex2f(2.5,57);
   glVertex2f(1.5,56);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,53);
   glVertex2f(2.5,54);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1,54);
   glVertex2f(4,54);
   glVertex2f(2.5,55);
   glVertex2f(1,54);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1,55);
   glVertex2f(4,55);
   glVertex2f(2.5,56);
   glVertex2f(1,55);

    glEnd();



    glPopMatrix();











    //finished tree back.......




     glLoadIdentity();
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslatef(1.0f,0.0f,0.0f);


    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();

    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();

    glPopMatrix();


    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();

   glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();
    glTranslated(1.0f,0.0f,0.0f);
    glPushMatrix();
     //first triangle of a tree...
    glColor3ub(39, 174, 96);
    glBegin(GL_POLYGON);
   glVertex2f(2,54);
   glVertex2f(3,54);
   glVertex2f(2.5,55.5);
   glVertex2f(2,54);

    glEnd();
    //tree er line...
    glColor3ub(23, 32, 42);
    glLineWidth(1.5);
    glBegin(GL_LINES);
   glVertex2f(2.5,51);
   glVertex2f(2.5,52);

    glEnd();
    //third triangle of a tree...
     glColor3ub(20, 90, 50);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,52);
   glVertex2f(3.5,52);
   glVertex2f(2.5,53.5);
   glVertex2f(1.5,52);

    glEnd();
   //second triangle of a tree...
    glColor3ub(25, 111, 61);
    glBegin(GL_POLYGON);
   glVertex2f(1.5,53);
   glVertex2f(3.5,53);
   glVertex2f(2.5,54);
   glVertex2f(1.5,53);

    glEnd();



    glPopMatrix();



    glPopMatrix();





  //CLOUDS
  //220, 220, 230->previous color...

   glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_clouds, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
        glColor3ub(165, 167, 167);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+5,y+70);
        }

  glEnd();
   glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {

        glColor3ub(165, 167, 167);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+7,y+72);
        }
  glEnd();
  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
      glColor3ub(165, 167, 167);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+9,y+70);
        }
  glEnd();
  glPopMatrix();
  //CLOUD 2

 // glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_clouds, 0.0f, 0.0f);

  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
        glColor3ub(165, 167, 167);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+20,y+68);
        }
  glEnd();

  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
       glColor3ub(165, 167, 167);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+25,y+68);
        }
  glEnd();

  glBegin(GL_POLYGON);
  for(int i=0;i<200;i++)
        {
        glColor3ub(165, 167, 167);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+23,y+71);
        }
  glEnd();
  glLoadIdentity();
  glPopMatrix();
  glTranslatef(move_clouds,0.0f,0.0f);
   //CLOUD 3
   glPushMatrix();
   circle_for_night(43,70,3);
   circle_for_night(40,70,3);
   circle_for_night(41.5,72,3);
   circle_for_night(44,71,3);
   circle_for_night(38,71,3);
   glPopMatrix();

   //BIRDS
   glLoadIdentity();
  /* glPushMatrix();
   glTranslatef(move_bird_x,move_bird_y,0.0f);
   glColor3ub(22, 20, 22);
   glLineWidth(1.5);
   glBegin(GL_LINES);
    glVertex2f(2,70);
    glVertex2f(4,69);
    glVertex2f(4,69);
    glVertex2f(6,71);


   glEnd();

   glColor3ub(22, 20, 22);
   glLineWidth(1.5);
   glBegin(GL_LINES);
    glVertex2f(8,73);
    glVertex2f(10,71);
    glVertex2f(10,71);
    glVertex2f(12,74);

   glEnd();

   glColor3ub(22, 20, 22);
   glLineWidth(1.5);
   glBegin(GL_LINES);
    glVertex2f(11,70);
    glVertex2f(13,68);
    glVertex2f(13,68);
    glVertex2f(15,70);


   glEnd();


   glPopMatrix();*/




  //SEA AND BOATS

   glLoadIdentity();
   //river border....
   //124, 237, 245
   glColor3ub(15, 145, 186);
    glBegin(GL_POLYGON);

    glVertex2f(0,30);
    glVertex2f(100,30);
    glVertex2f(100,50);
    glVertex2f(0,50);
    glVertex2f(0,30);

    glEnd();
    glLoadIdentity();
    //panir sroooot......
    glPushMatrix();

     glTranslatef(move_wave,0.0f,0.0f);
    glColor3ub(212, 230, 241);
    glBegin(GL_POLYGON);
    glVertex2f(28,40);
    glVertex2f(37,39.5);
    glVertex2f(48,39.5);
    glVertex2f(51,40);
    glVertex2f(48,40.5);
    glVertex2f(37,40.5);
    glVertex2f(28,40);


    glEnd();


     glColor3ub(212, 230, 241);
    glBegin(GL_POLYGON);
    glVertex2f(60,45.5);
    glVertex2f(72,45.5);
    glVertex2f(80,45.5);
    glVertex2f(88,46);
    glVertex2f(60,46);
    glVertex2f(60,45.5);
    glVertex2f(60,45.5);


    glEnd();


     glColor3ub(212, 230, 241);
    glBegin(GL_POLYGON);
    glVertex2f(20,47.5);
    glVertex2f(40,47.5);
    glVertex2f(47,47);
    glVertex2f(52,48);
    glVertex2f(20,48);
    glVertex2f(20,47.5);



    glEnd();

    glPopMatrix();
    glLoadIdentity();
    //boats.....

    //boat one  moving.....
    glPushMatrix();

      glTranslatef(move_boat,0.0f,0.0f);
    glColor3ub(100, 68, 73);
    glBegin(GL_POLYGON);
    glVertex2f(10,47);
    glVertex2f(12,46);
    glVertex2f(14,46);
    glVertex2f(16,47);
    glVertex2f(10,47);
    glEnd();

    glColor3ub(168, 161, 162);
    glBegin(GL_POLYGON);
    glVertex2f(12,47);
    glVertex2f(14,47);
    glVertex2f(14,47.5);
    glVertex2f(12,47.5);
    glVertex2f(12,47);
    glEnd();



    glPopMatrix();
    glLoadIdentity();

    //boat two moving......
    glPushMatrix();
     glTranslatef(move_boat_second,0.0f,0.0f);
    glColor3ub(41, 38, 38);
    glBegin(GL_POLYGON);
    glVertex2f(3,42);
    glVertex2f(5,40);
    glVertex2f(10,40);
    glVertex2f(12,42);
    glVertex2f(3,42);
    glEnd();



    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(7,46);
    glVertex2f(10,43);
    glVertex2f(7,42);
    glVertex2f(7,46);

    glEnd();

    glColor3ub(20, 20, 19);
    glLineWidth(1.5);
    glBegin(GL_LINES);

    glVertex2f(7,42);
    glVertex2f(7,46);


    glEnd();


    glPopMatrix();

      glLoadIdentity();
    //MOSQUE
    //basement
    glColor3ub(153.0f,57.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(35,30);
    glVertex2f(50,30);
    glVertex2f(50,31);
    glVertex2f(35,31);
    glVertex2f(35,30);
    glEnd();
    //body
     glColor3ub(204.0f,105.0f,0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(36,31);
    glVertex2f(49,31);
    glVertex2f(49,35);
    glVertex2f(36,35);
    glVertex2f(36,31);
    glEnd();

    //moshjid er uporer part
    /* glColor3ub(0.0f,204.0f,204.0f);
    glBegin(GL_POLYGON);
    glVertex2f(39,35);
    glVertex2f(46,35);
    glVertex2f(42.5,38);
    glVertex2f(39,35);

    glEnd();*/
     //mosjid er uporer part 2
     glColor3ub(94, 122, 153);
    glBegin(GL_POLYGON);
    for (int i = 20; i <= 70; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(180);
        float x = 5.0f * cos(theta);
        float y =  5.0f * sin(theta);
        glVertex2f(x+42.5, y+31.8);
    }
    glEnd();
    //majher part
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(40,31);
    glVertex2f(45,31);
    glVertex2f(45,33);
    glVertex2f(42.5,35);
    glVertex2f(40,33);
    glVertex2f(40,31);
    glEnd();

    //LEFT SIDE basement

     glColor3ub(153.0f,57.0f,0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(29,30);
    glVertex2f(33,30);
    glVertex2f(33,31);
    glVertex2f(29,31);
    glVertex2f(29,30);
    glEnd();
   //LEFT SIDE MINAR
   glColor3ub(255.0f,170.0f,0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(30,31);
    glVertex2f(32,31);
    glVertex2f(32,37);
    glVertex2f(30,37);
    glVertex2f(30,31);
    glEnd();

    //left side minar er uporer part
    //213, 245, 227->previous color....
      glColor3ub(94, 122, 153);
    glBegin(GL_POLYGON);
    for (int i = 20; i <= 70; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(180);
        float x = 3.0f * cos(theta);
        float y =  3.0f * sin(theta);
        glVertex2f(x+31, y+35);
    }
    glEnd();

    //RIGHT SIDE MINAR

     //basement

       glColor3ub(153.0f,57.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(52,30);
    glVertex2f(56,30);
    glVertex2f(56,31);
    glVertex2f(52,31);
    glVertex2f(52,30);
    glEnd();

    //RIGHT SIDE MINAR
    glColor3ub(255.0f,170.0f,0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(53,31);
    glVertex2f(55,31);
    glVertex2f(55,37);
    glVertex2f(53,37);
    glVertex2f(53,31);
    glEnd();

    //RIGHT SIDE MINAR ER uporer part

     glColor3ub(94, 122, 153);
    glBegin(GL_POLYGON);
    for (int i = 20; i <= 70; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(180);
        float x = 3.0f * cos(theta);
        float y =  3.0f * sin(theta);
        glVertex2f(x+54, y+35);
    }
    glEnd();




    //ROAD AND CARS
    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex2f(0,10);
    glVertex2f(100,10);
    glVertex2f(100,30);
    glVertex2f(0,30);
    glVertex2f(0,0);
    glEnd();


     glLoadIdentity();
    glPushMatrix();
    glTranslatef(+0.0f,0.0f,0.0f);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();
    glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();


    glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();


     glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();

     glTranslatef(+20.0f,0.0f,0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(3,19.5);
    glVertex2f(15,19.5);
    glVertex2f(15,20.5);
    glVertex2f(3,20.5);
    glVertex2f(3,19.5);
    glEnd();
    glPopMatrix();

    //MOVING CAR ONE
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_car,0.0f, 0.0f);
    glColor3f(0.1373, 0.5725,0.5529);
    glBegin(GL_QUADS);
    glVertex2f(85,23.5);
    glVertex2f(94,23.5);
    glVertex2f(94,25);
    glVertex2f(85,25);
    glVertex2f(85,23.5);
    glEnd();

    glColor3ub(170, 183, 184);
    glBegin(GL_POLYGON);
    glVertex2f(86.5,25);
    glVertex2f(88,26.5);
    glVertex2f(92,26.5);
    glVertex2f(93,25);
    glVertex2f(86.5,25);
    glEnd();


     glColor3ub(23, 32, 42);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(86.5,25);
    glVertex2f(88,26.5);
    glVertex2f(88,26.5);
    glVertex2f(88,25);
    glVertex2f(88,25);
     glVertex2f(86.5,25);
    glEnd();

     glColor3ub(23, 32, 42);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(92,25);
    glVertex2f(92,26.5);
    glVertex2f(92,26.5);
    glVertex2f(93,25);
    glVertex2f(93,25);
    glVertex2f(92,25);

    glEnd();
  //wheel 1
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(213, 216, 220);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+87,y+23.5);
        }
  glEnd();

     //wheel 2
      glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(213, 216, 220);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+93,y+23.5);
        }
  glEnd();

  //MOVING CAR ER LIGHT....
  glColor3ub(247, 223, 125);
    glBegin(GL_POLYGON);
    glVertex2f(81,23);
    glVertex2f(85,24);
    glVertex2f(81,25);
    glVertex2f(81,23);


    glEnd();


    glPopMatrix();


    //MOVING TRUCK
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_truck,0.0f,0.0f);
    glColor3ub(222, 13, 187);
    glBegin(GL_POLYGON);
    glVertex2f(5,14);
    glVertex2f(15,14);
    glVertex2f(15,18);
    glVertex2f(5,18);
    glVertex2f(5,14);

    glEnd();

     glColor3ub(91, 86, 90);
    glBegin(GL_POLYGON);
    glVertex2f(15,14);
    glVertex2f(17,14);
    glVertex2f(17,16);
    glVertex2f(15,17);
    glVertex2f(15,14);

    glEnd();

    glColor3ub(234, 228, 233);
    glBegin(GL_POLYGON);

    glVertex2f(15,16);
    glVertex2f(17,16);
    glVertex2f(15,17);
    glVertex2f(15,16);

    glEnd();

    wheel(6.5,14,0.8);
    wheel(14,14,0.8);
    //MOVIING TRUCK ER LIGHT.....
     glColor3ub(247, 223, 125);
    glBegin(GL_POLYGON);
    glVertex2f(17,15);
    glVertex2f(22,14);
    glVertex2f(22,16);
    glVertex2f(17,15);


    glEnd();

    glPopMatrix();
    glLoadIdentity();
     //NICHER ROAD BORDER......
     glPushMatrix();
    glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(0,13);
    glVertex2f(100,13);
    glVertex2f(100,14);
    glVertex2f(0,14);
    glVertex2f(0,13);

    glEnd();
     glTranslatef(+0.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();

     glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();

    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();
    glTranslatef(9.0f,0.0f,0.0f);
     glColor3ub(189, 195, 199);
    glBegin(GL_POLYGON);
    glVertex2f(3,10);
    glVertex2f(4,10);
    glVertex2f(4,13);
    glVertex2f(3,13);
    glVertex2f(3,10);

    glEnd();



    glPopMatrix();
    glLoadIdentity();

    //TRAIN
    //train er ekdom niche...
    glColor3ub(97, 84, 4);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,0);
    glVertex2f(100,2.5);
    glVertex2f(0,2.5);
    glVertex2f(0,0);

    glEnd();
    //for night upper yellow part change...
    glColor3ub(180, 180, 178);
    glBegin(GL_POLYGON);
    glVertex2f(0,6.5);
    glVertex2f(100,6.5);
    glVertex2f(100,10);
    glVertex2f(0,10);
    glVertex2f(0,6.5);

    glEnd();
    //TRAIN LINE  BORDER......
     glColor3ub(204, 209, 209);
    glBegin(GL_POLYGON);
    glVertex2f(0,2.5);
    glVertex2f(100,2.5);
    glVertex2f(100,6.5);
    glVertex2f(0,6.5);
    glVertex2f(0,2.5);

    glEnd();


    glPushMatrix();
    glTranslatef(+0.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
     glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
    glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();
glTranslatef(+3.0f,0.0f,0.0f);
    glColor3ub(39, 55, 70);
    glBegin(GL_POLYGON);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(5,8);
    glVertex2f(4,8);
    glVertex2f(1,2);

    glEnd();



    glPopMatrix();

   glLoadIdentity();
   //nicher rail line border....
    glColor3ub(93, 109, 126);
    glBegin(GL_POLYGON);
    glVertex2f(0,2.5);
    glVertex2f(100,2.5);
    glVertex2f(100,3);
    glVertex2f(0,3);
    glVertex2f(0,2.5);

    glEnd();
    //rail line er uporer border.....
    glColor3ub(93, 109, 126);
    glBegin(GL_POLYGON);
    glVertex2f(0,6.5);
    glVertex2f(100,6.5);
    glVertex2f(100,7);
    glVertex2f(0,7);
    glVertex2f(0,6.5);

    glEnd();
    //TRAIN ER body.....
    //TRAIN MOVING.....


    glLoadIdentity();
    glPushMatrix();
    glTranslatef(move_train,0.0f, 0.0f);


    //train wheel....

    wheel_for_train(25,4,1);
    wheel_for_train(27,4,1);
    wheel_for_train(33,4,1);
    wheel_for_train(35,4,1);
    wheel_for_train(37,4,1);
    wheel_for_train(46,4,1);
    wheel_for_train(48,4,1);
    wheel_for_train(51,4,1);
    wheel_for_train(53,4,1);
    wheel_for_train(60,4,1);
    wheel_for_train(62,4,1);
    wheel_for_train(65,4,1);
    wheel_for_train(67,4,1);
    wheel_for_train(73,4,1);
    wheel_for_train(75,4,1);
    //engine...
    glColor3ub(100, 30, 22);
    glBegin(GL_POLYGON);
    glVertex2f(20,4);
    glVertex2f(27,4);
    glVertex2f(27,7);
    glVertex2f(20,7);
    glVertex2f(20,4);

    glEnd();
   //glass....
    //241, 241, 182
    //235, 237, 239->previous
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(22,7);
    glVertex2f(25,7);
    glVertex2f(25,10);
    glVertex2f(22,7);

    glEnd();
    glColor3ub(23, 32, 42);
      glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2f(22,7);
    glVertex2f(25,10);
    glVertex2f(22,7);
    glVertex2f(25,7);
     glVertex2f(25,7);
     glVertex2f(25,10);
    glEnd();

   //train engine er janala...

     glColor3ub(100, 30, 22);
    glBegin(GL_POLYGON);
    glVertex2f(25,7);
    glVertex2f(27,7);
    glVertex2f(27,10);
    glVertex2f(25,10);
    glVertex2f(25,7);

    glEnd();
    //engine back....
     glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(27,4);
    glVertex2f(35,4);
    glVertex2f(35,10);
    glVertex2f(27,10);
    glVertex2f(27,4);

    glEnd();
    //body one.....

    glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(35,4);
    glVertex2f(49,4);
    glVertex2f(49,10);
    glVertex2f(35,10);
    glVertex2f(35,4);

    glEnd();
   //body two.....
    glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(49,4);
    glVertex2f(63,4);
    glVertex2f(63,10);
    glVertex2f(49,10);
    glVertex2f(49,4);

    glEnd();
    //body three.....
    glColor3ub(202, 111, 30);
    glBegin(GL_POLYGON);
    glVertex2f(63,4);
    glVertex2f(77,4);
    glVertex2f(77,10);
    glVertex2f(63,10);
    glVertex2f(63,4);

    glEnd();

    //border engine -1 bold....
     glColor3ub(151, 154, 154);
    glBegin(GL_POLYGON);
    glVertex2f(35,4);
    glVertex2f(35.5,4);
    glVertex2f(35.5,10);
    glVertex2f(35,10);
    glVertex2f(35,4);

    glEnd();

   //border 1-2 bold....

    glColor3ub(151, 154, 154);
    glBegin(GL_POLYGON);
    glVertex2f(49,4);
    glVertex2f(49.5,4);
    glVertex2f(49.5,10);
    glVertex2f(49,10);
    glVertex2f(49,4);

    glEnd();
    //border 2-3 bold.....
    glColor3ub(151, 154, 154);
    glBegin(GL_POLYGON);
    glVertex2f(63,4);
    glVertex2f(63.5,4);
    glVertex2f(63.5,10);
    glVertex2f(63,10);
    glVertex2f(63,4);

    glEnd();

    //train er window 1...
    glPushMatrix();
    //236, 223, 65->new
    //249, 231, 159->previous
    glTranslatef(+0.0f,0.0f,0.0f);
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
     glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();

    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+4.0f,0.0f,0.0f);
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();
    glTranslatef(+4.0f,0.0f,0.0f);
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();

    glTranslatef(+5.0f,0.0f,0.0f);
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();

    glTranslatef(+4.0f,0.0f,0.0f);
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(36,7);
    glVertex2f(38,7);
    glVertex2f(38,9);
    glVertex2f(36,9);
    glVertex2f(36,7);

    glEnd();


    glPopMatrix();

     glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(20,4);
    glVertex2f(21,4);
    glVertex2f(21,7);
    glVertex2f(20,7);
    glVertex2f(20,4);

    glEnd();
    //engine er janala alada kore draw.....
    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(28,7);
    glVertex2f(30,7);
    glVertex2f(30,9);
    glVertex2f(28,9);
    glVertex2f(28,7);

    glEnd();


    glColor3ub(236, 223, 65);
    glBegin(GL_POLYGON);
    glVertex2f(32,7);
    glVertex2f(34,7);
    glVertex2f(34,9);
    glVertex2f(32,9);
    glVertex2f(32,7);

    glEnd();


    glPopMatrix();
    glLoadIdentity();
   //train er niche grass.....

  grass(4,0,4);
  grass(2,2,4);

  grass(19,0,3);
  grass(23,0,5);
  grass(27,0,3);

  grass(40,0,5);
  grass(38,3,3);
  grass(42,3,3);
  grass(45,2,3);
  grass(47,3,3);
  grass(48,0,3.2);

  grass(60,0,3);
  grass(64,1,4.5);
  grass(68,0,3);

  grass(100,0,6);
  grass(94,0,3);


    glFlush();


}
void night_display()
{




    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    //SKY PORTION.....


    glColor3ub(21, 67, 96);
    glBegin(GL_POLYGON);

    glVertex2f(0,45);
    glVertex2f(100,45);
    glVertex2f(100,80);
    glVertex2f(0,80);
     glVertex2f(0,45);
    glEnd();
    circle_star(5,75,0.2);
    circle_star(2,68,0.2);
    circle_star(1,71,0.2);
    circle_star(10,71,0.2);
    circle_star(15,75,0.2);
    circle_star(20,76,0.2);
    circle_star(26,74,0.2);
    circle_star(34,72,0.2);
    circle_star(42,75,0.2);
    circle_star(50,73,0.2);
    circle_star(60,70,0.2);
    circle_star(65,75,0.2);
    circle_star(70,65,0.2);
    circle_star(75,69,0.2);
    circle_star(80,71,0.2);



    //MOOON FIRST BIG CIRCLE.....
      glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(236, 240, 241);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+93,y+72);
        }
  glEnd();
  //MOON SECOND CIRCLE....
   glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
        glColor3ub(21, 67, 96);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+95,y+74);
        }
  glEnd();
  glLoadIdentity();
   //houses....


    //house number one.....
    glPushMatrix();
    glColor3ub(241, 148, 138);
    glBegin(GL_POLYGON);
    glVertex2f(0,45);
    glVertex2f(15,45);
    glVertex2f(15,65);
    glVertex2f(0,65);
    glVertex2f(0,45);

    glEnd();
    //window....
    glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(2,61);
    glVertex2f(13,61);
    glVertex2f(13,63);
    glVertex2f(2,63);
    glVertex2f(2,41);

    glEnd();

    glTranslatef(+0.0f,-4.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(2,61);
    glVertex2f(13,61);
    glVertex2f(13,63);
    glVertex2f(2,63);
    glVertex2f(2,41);

    glEnd();

    glTranslatef(+0.0f,-4.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(2,61);
    glVertex2f(13,61);
    glVertex2f(13,63);
    glVertex2f(2,63);
    glVertex2f(2,41);

    glEnd();

    glTranslatef(+0.0f,-4.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(2,61);
    glVertex2f(13,61);
    glVertex2f(13,63);
    glVertex2f(2,63);
    glVertex2f(2,41);

    glEnd();




    glPopMatrix();


    glLoadIdentity();


    //HOUSE NUMBER TWO......

    glPushMatrix();
      glColor3ub(5, 167, 153);
    glBegin(GL_POLYGON);
    glVertex2f(20,45);
    glVertex2f(35,45);
    glVertex2f(35,70);
    glVertex2f(20,70);
    glVertex2f(20,45);

    glEnd();
     glLoadIdentity();
    //window...
    glTranslatef(+0.0f,0.0f,0.0f);
    glPushMatrix();
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();


     glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();

    glPopMatrix();


      glTranslatef(+0.0f,-4.0f,0.0f);
    glPushMatrix();
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();


     glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();

    glPopMatrix();



    glTranslatef(+0.0f,-4.0f,0.0f);
    glPushMatrix();
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();


     glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();

    glPopMatrix();

    glTranslatef(+0.0f,-4.0f,0.0f);
    glPushMatrix();
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();


     glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();

    glPopMatrix();

    glTranslatef(+0.0f,-4.0f,0.0f);
    glPushMatrix();
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();


     glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();

    glPopMatrix();

   glTranslatef(+0.0f,-4.0f,0.0f);
    glPushMatrix();
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();
    glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();


     glTranslatef(+5.0f,0.0f,0.0f);
     glColor3ub(247, 220, 111);
    glBegin(GL_POLYGON);
    glVertex2f(21,67);
    glVertex2f(24,67);
    glVertex2f(24,69);
    glVertex2f(21,69);
    glVertex2f(21,67);

    glEnd();

    glPopMatrix();


    glPopMatrix();

   glLoadIdentity();
   //house number three.....



  //ROADS PORTION....

   glColor3ub(50,50,50);
    glBegin(GL_POLYGON);

    glVertex2f(0,25);
    glVertex2f(100,25);
    glVertex2f(100,45);
    glVertex2f(0,45);
    glVertex2f(0,25);

    glEnd();


    // roads er uporer border...

    glColor3ub(245, 203, 167);
    glBegin(GL_POLYGON);
    glVertex2f(0,43);
    glVertex2f(100,43);
    glVertex2f(100,45);
    glVertex2f(0,45);
    glVertex2f(0,43);

    glEnd();

   glLoadIdentity();

   //LAMP POST.....
   glPushMatrix();

   glPushMatrix();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(84,43);
    glVertex2f(85,43);
    glVertex2f(85,50);
    glVertex2f(84,50);
    glVertex2f(84,43);
    glEnd();


    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(80,49);
    glVertex2f(85,49);
    glVertex2f(85,50);
    glVertex2f(80,50);
    glVertex2f(80,49);
    glEnd();

    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(82,49);
    glVertex2f(80,42);
    glVertex2f(84,42);
    glVertex2f(82,49);
    glEnd();

   glPopMatrix();


   glTranslatef(-25.0f,0.0f,0.0f);


   glPushMatrix();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(84,43);
    glVertex2f(85,43);
    glVertex2f(85,50);
    glVertex2f(84,50);
    glVertex2f(84,43);
    glEnd();


    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(80,49);
    glVertex2f(85,49);
    glVertex2f(85,50);
    glVertex2f(80,50);
    glVertex2f(80,49);
    glEnd();

    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(82,49);
    glVertex2f(80,42);
    glVertex2f(84,42);
    glVertex2f(82,49);
    glEnd();

   glPopMatrix();


    glTranslatef(-25.0f,0.0f,0.0f);


   glPushMatrix();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(84,43);
    glVertex2f(85,43);
    glVertex2f(85,50);
    glVertex2f(84,50);
    glVertex2f(84,43);
    glEnd();


    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(80,49);
    glVertex2f(85,49);
    glVertex2f(85,50);
    glVertex2f(80,50);
    glVertex2f(80,49);
    glEnd();

    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(82,49);
    glVertex2f(80,42);
    glVertex2f(84,42);
    glVertex2f(82,49);
    glEnd();

   glPopMatrix();
 glTranslatef(-25.0f,0.0f,0.0f);


   glPushMatrix();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(84,43);
    glVertex2f(85,43);
    glVertex2f(85,50);
    glVertex2f(84,50);
    glVertex2f(84,43);
    glEnd();


    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(80,49);
    glVertex2f(85,49);
    glVertex2f(85,50);
    glVertex2f(80,50);
    glVertex2f(80,49);
    glEnd();

    glColor3ub(249, 231, 159);
    glBegin(GL_POLYGON);
    glVertex2f(82,49);
    glVertex2f(80,42);
    glVertex2f(84,42);
    glVertex2f(82,49);
    glEnd();

   glPopMatrix();


   glPopMatrix();

  glLoadIdentity();


  //road er majkhaan.....
    glPushMatrix();

       glTranslatef(+0.0f,0.0f,0.0f);
     glColor3ub(236, 238, 236);
    glBegin(GL_POLYGON);
    glVertex2f(5,35);
    glVertex2f(15,35);
    glVertex2f(15,36);
    glVertex2f(5,36);
    glVertex2f(5,35);
    glEnd();

    glTranslatef(+15.0f,0.0f,0.0f);

      glColor3ub(236, 238, 236);
    glBegin(GL_POLYGON);
    glVertex2f(5,35);
    glVertex2f(15,35);
    glVertex2f(15,36);
    glVertex2f(5,36);
    glVertex2f(5,35);
    glEnd();


    glTranslatef(+15.0f,0.0f,0.0f);

      glColor3ub(236, 238, 236);
    glBegin(GL_POLYGON);
    glVertex2f(5,35);
    glVertex2f(15,35);
    glVertex2f(15,36);
    glVertex2f(5,36);
    glVertex2f(5,35);
    glEnd();


    glTranslatef(+15.0f,0.0f,0.0f);

      glColor3ub(236, 238, 236);
    glBegin(GL_POLYGON);
    glVertex2f(5,35);
    glVertex2f(15,35);
    glVertex2f(15,36);
    glVertex2f(5,36);
    glVertex2f(5,35);
    glEnd();


    glTranslatef(+15.0f,0.0f,0.0f);

      glColor3ub(236, 238, 236);
    glBegin(GL_POLYGON);
    glVertex2f(5,35);
    glVertex2f(15,35);
    glVertex2f(15,36);
    glVertex2f(5,36);
    glVertex2f(5,35);
    glEnd();


    glTranslatef(+15.0f,0.0f,0.0f);

      glColor3ub(236, 238, 236);
    glBegin(GL_POLYGON);
    glVertex2f(5,35);
    glVertex2f(15,35);
    glVertex2f(15,36);
    glVertex2f(5,36);
    glVertex2f(5,35);
    glEnd();


    glPopMatrix();

    glLoadIdentity();

    //ROAD BORDER NICHER PART.....


     glColor3ub(178, 186, 187);
    glBegin(GL_POLYGON);
    glVertex2f(0,29);
    glVertex2f(100,29);
    glVertex2f(100,30);
    glVertex2f(0,30);
    glVertex2f(0,29);
    glEnd();

    glPushMatrix();

   glTranslatef(+0.0f,0.0f,0.0f);
    glColor3ub(178, 186, 187);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(5,30);
    glVertex2f(5,25);
    glEnd();

    glTranslatef(+10.0f,0.0f,0.0f);
    glColor3ub(178, 186, 187);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(5,30);
    glVertex2f(5,25);
    glEnd();

    glTranslatef(+10.0f,0.0f,0.0f);
    glColor3ub(178, 186, 187);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(5,30);
    glVertex2f(5,25);
    glEnd();

    glTranslatef(+10.0f,0.0f,0.0f);
    glColor3ub(178, 186, 187);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(5,30);
    glVertex2f(5,25);
    glEnd();

    glTranslatef(+10.0f,0.0f,0.0f);
    glColor3ub(178, 186, 187);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(5,30);
    glVertex2f(5,25);
    glEnd();

    glTranslatef(+10.0f,0.0f,0.0f);
    glColor3ub(178, 186, 187);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(5,30);
    glVertex2f(5,25);
    glEnd();

    glTranslatef(+10.0f,0.0f,0.0f);
    glColor3ub(178, 186, 187);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(5,30);
    glVertex2f(5,25);
    glEnd();

    glTranslatef(+10.0f,0.0f,0.0f);
    glColor3ub(178, 186, 187);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(5,30);
    glVertex2f(5,25);
    glEnd();

    glTranslatef(+10.0f,0.0f,0.0f);
    glColor3ub(178, 186, 187);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(5,30);
    glVertex2f(5,25);
    glEnd();

    glTranslatef(+10.0f,0.0f,0.0f);
    glColor3ub(178, 186, 187);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(5,30);
    glVertex2f(5,25);
    glEnd();


    glPopMatrix();

    glLoadIdentity();

    //GROUND PORTION......

     glColor3ub(7, 122, 43);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,0);
    glVertex2f(100,25);
    glVertex2f(0,25);
    glVertex2f(0,0);

    glEnd();

  //CHAIR.....
    glPushMatrix();


    glColor3ub(177, 133, 5);
    glBegin(GL_POLYGON);
    glVertex2f(10,16);
    glVertex2f(25,16);
    glVertex2f(25,20);
    glVertex2f(10,20);
    glVertex2f(10,16);

    glEnd();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(10,13);
    glVertex2f(10.5,13);
    glVertex2f(10.5,16);
    glVertex2f(10,16);
    glEnd();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(24.5,13);
    glVertex2f(25,13);
    glVertex2f(25,16);
    glVertex2f(24.5,16);
    glVertex2f(25,13);
    glEnd();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(28.5,15);
    glVertex2f(29,15);
    glVertex2f(29,18);
    glVertex2f(28.5,18);
    glVertex2f(28.5,15);
    glEnd();


    glColor3ub(156, 100, 12);
    glBegin(GL_POLYGON);
    glVertex2f(25,16);
    glVertex2f(29,18);
    glVertex2f(25,18);
    glVertex2f(25,16);

    glEnd();




     glTranslatef(+30.0f,0.0f,0.0f);


     glColor3ub(177, 133, 5);
    glBegin(GL_POLYGON);
    glVertex2f(10,16);
    glVertex2f(25,16);
    glVertex2f(25,20);
    glVertex2f(10,20);
    glVertex2f(10,16);

    glEnd();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(10,13);
    glVertex2f(10.5,13);
    glVertex2f(10.5,16);
    glVertex2f(10,16);
    glEnd();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(24.5,13);
    glVertex2f(25,13);
    glVertex2f(25,16);
    glVertex2f(24.5,16);
    glVertex2f(25,13);
    glEnd();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(28.5,15);
    glVertex2f(29,15);
    glVertex2f(29,18);
    glVertex2f(28.5,18);
    glVertex2f(28.5,15);
    glEnd();


    glColor3ub(156, 100, 12);
    glBegin(GL_POLYGON);
    glVertex2f(25,16);
    glVertex2f(29,18);
    glVertex2f(25,18);
    glVertex2f(25,16);

    glEnd();


     glTranslatef(+30.0f,0.0f,0.0f);


     glColor3ub(177, 133, 5);
    glBegin(GL_POLYGON);
    glVertex2f(10,16);
    glVertex2f(25,16);
    glVertex2f(25,20);
    glVertex2f(10,20);
    glVertex2f(10,16);

    glEnd();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(10,13);
    glVertex2f(10.5,13);
    glVertex2f(10.5,16);
    glVertex2f(10,16);
    glEnd();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(24.5,13);
    glVertex2f(25,13);
    glVertex2f(25,16);
    glVertex2f(24.5,16);
    glVertex2f(25,13);
    glEnd();

    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(28.5,15);
    glVertex2f(29,15);
    glVertex2f(29,18);
    glVertex2f(28.5,18);
    glVertex2f(28.5,15);
    glEnd();


    glColor3ub(156, 100, 12);
    glBegin(GL_POLYGON);
    glVertex2f(25,16);
    glVertex2f(29,18);
    glVertex2f(25,18);
    glVertex2f(25,16);

    glEnd();


    glPopMatrix();

    glLoadIdentity();


    glPushMatrix();


    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
    glTranslatef(+2.5f,0.0f,0.0f);


    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
 glTranslatef(+2.5f,0.0f,0.0f);


    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
     glTranslatef(+2.5f,1.0f,0.0f);


    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();


     glTranslatef(+2.5f,1.0f,0.0f);


    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
     glTranslatef(+2.5f,-1.0f,0.0f);


    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

    glTranslatef(+2.5f,-0.0f,0.0f);


    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

    glTranslatef(+2.5f,-1.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

     glTranslatef(+2.5f,-1.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

    glTranslatef(+2.5f,-0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

    glTranslatef(+2.5f,-0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();


    glTranslatef(+20.5f,-0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

     glTranslatef(+2.5f,1.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

    glTranslatef(+2.5f,1.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
    glTranslatef(+2.5f,1.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

    glTranslatef(+2.5f,-1.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
    glTranslatef(+2.5f,-1.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
    glTranslatef(+2.5f,-1.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
    glTranslatef(+2.5f,0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

    glTranslatef(+2.5f,0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
    glTranslatef(+10.5f,0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

    glTranslatef(+2.5f,0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
     glTranslatef(+2.5f,0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
     glTranslatef(+2.5f,0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
     glTranslatef(+2.5f,0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
     glTranslatef(+2.5f,0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
     glTranslatef(+2.5f,0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();
     glTranslatef(+2.5f,0.0f,0.0f);
    glPushMatrix();

    glColor3ub(11, 83, 69);
    glBegin(GL_LINES);
    glLineWidth(1.5);
    glVertex2f(5,1);
    glVertex2f(5,4);

    glEnd();
    circle_for_flower(5,4,1);
    circle_for_flower(6,5,1);
    circle_for_flower(5,6,1);
    circle_for_flower(4,5,1);
    circle_for_flower_middle(5,5,0.5);


    glPopMatrix();

    glPopMatrix();




    glFlush();


}

void Evening_view()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //SKY PORTION.....
     glColor3ub(249.0f,226.0f,79.0f);
    glBegin(GL_QUADS);
    glVertex2f(0,40);
    glVertex2f(100,40);
    glColor3ub(255.0f,255.0f,51.0f);
    glVertex2f(100,80);
    glColor3ub(255.0f,178.0f,102.0f);
    glVertex2f(0,80);
    glEnd();
    //BUILDINGS......
     glColor3ub(9, 167, 157);
    glBegin(GL_POLYGON);
    glVertex2f(5,48);
    glVertex2f(20,48);
    glVertex2f(20,75);
    glVertex2f(5,65);
    glVertex2f(5,70);
    glEnd();


    glColor3ub(4, 71, 67);
    glBegin(GL_POLYGON);
    glVertex2f(7,48);
    glVertex2f(8,48);
    glVertex2f(8,65);
    glVertex2f(7,65);
    glVertex2f(7,48);
    glEnd();

    glTranslatef(2.0f,0.0f,0.0f);
     glColor3ub(4, 71, 67);
    glBegin(GL_POLYGON);
    glVertex2f(7,48);
    glVertex2f(8,48);
    glVertex2f(8,65);
    glVertex2f(7,65);
    glVertex2f(7,48);
    glEnd();

     glTranslatef(2.0f,0.0f,0.0f);
     glColor3ub(4, 71, 67);
    glBegin(GL_POLYGON);
    glVertex2f(7,48);
    glVertex2f(8,48);
    glVertex2f(8,65);
    glVertex2f(7,65);
    glVertex2f(7,48);
    glEnd();
     glTranslatef(2.0f,0.0f,0.0f);
     glColor3ub(4, 71, 67);
    glBegin(GL_POLYGON);
    glVertex2f(7,48);
    glVertex2f(8,48);
    glVertex2f(8,65);
    glVertex2f(7,65);
    glVertex2f(7,48);
    glEnd();
     glTranslatef(2.0f,0.0f,0.0f);
     glColor3ub(4, 71, 67);
    glBegin(GL_POLYGON);
    glVertex2f(7,48);
    glVertex2f(8,48);
    glVertex2f(8,65);
    glVertex2f(7,65);
    glVertex2f(7,48);
    glEnd();
     glTranslatef(2.0f,0.0f,0.0f);
     glColor3ub(4, 71, 67);
    glBegin(GL_POLYGON);
    glVertex2f(7,48);
    glVertex2f(8,48);
    glVertex2f(8,65);
    glVertex2f(7,65);
    glVertex2f(7,48);
    glEnd();
    glLoadIdentity();


    //SECOND BUILDING
     glColor3ub(236, 112, 99);
    glBegin(GL_POLYGON);
    glVertex2f(40,48);
    glVertex2f(50,48);
    glVertex2f(50,70);
    glVertex2f(40,70);
    glVertex2f(40,48);
    glEnd();


    glColor3ub(231, 76, 60);
    glBegin(GL_POLYGON);
    glVertex2f(50,48);
    glVertex2f(54,48);
    glVertex2f(54,69.5);
    glVertex2f(50,70);
    glVertex2f(50,48);
    glEnd();

    glPushMatrix();
    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(41,66);
    glVertex2f(43,66);
    glVertex2f(43,68);
    glVertex2f(41,68);
    glVertex2f(41,66);
    glEnd();


    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(46,66);
    glVertex2f(48,66);
    glVertex2f(48,68);
    glVertex2f(46,68);
    glVertex2f(46,66);
    glEnd();
    glPopMatrix();
    glTranslatef(0.0f,-4.0f,0.0f);
    glPushMatrix();
    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(41,66);
    glVertex2f(43,66);
    glVertex2f(43,68);
    glVertex2f(41,68);
    glVertex2f(41,66);
    glEnd();


    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(46,66);
    glVertex2f(48,66);
    glVertex2f(48,68);
    glVertex2f(46,68);
    glVertex2f(46,66);
    glEnd();
    glPopMatrix();

    glTranslatef(0.0f,-4.0f,0.0f);
    glPushMatrix();
    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(41,66);
    glVertex2f(43,66);
    glVertex2f(43,68);
    glVertex2f(41,68);
    glVertex2f(41,66);
    glEnd();


    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(46,66);
    glVertex2f(48,66);
    glVertex2f(48,68);
    glVertex2f(46,68);
    glVertex2f(46,66);
    glEnd();
    glPopMatrix();

    glTranslatef(0.0f,-4.0f,0.0f);
    glPushMatrix();
    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(41,66);
    glVertex2f(43,66);
    glVertex2f(43,68);
    glVertex2f(41,68);
    glVertex2f(41,66);
    glEnd();


    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(46,66);
    glVertex2f(48,66);
    glVertex2f(48,68);
    glVertex2f(46,68);
    glVertex2f(46,66);
    glEnd();
    glPopMatrix();

    glTranslatef(0.0f,-4.0f,0.0f);
    glPushMatrix();
    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(41,66);
    glVertex2f(43,66);
    glVertex2f(43,68);
    glVertex2f(41,68);
    glVertex2f(41,66);
    glEnd();


    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(46,66);
    glVertex2f(48,66);
    glVertex2f(48,68);
    glVertex2f(46,68);
    glVertex2f(46,66);
    glEnd();
    glPopMatrix();

    glTranslatef(0.0f,-4.0f,0.0f);
    glPushMatrix();
    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(41,66);
    glVertex2f(43,66);
    glVertex2f(43,68);
    glVertex2f(41,68);
    glVertex2f(41,66);
    glEnd();


    glColor3ub(244, 208, 63);
    glBegin(GL_POLYGON);
    glVertex2f(46,66);
    glVertex2f(48,66);
    glVertex2f(48,68);
    glVertex2f(46,68);
    glVertex2f(46,66);
    glEnd();
    glPopMatrix();
    glLoadIdentity();
    //THIRD BUILDING.....
      glColor3ub(160, 64, 0);
    glBegin(GL_POLYGON);
    glVertex2f(60,48);
    glVertex2f(68,48);
    glVertex2f(68,75);
    glVertex2f(60,75);
    glVertex2f(60,48);
    glEnd();

    glPushMatrix();
     glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(61,72);
    glVertex2f(67,72);
    glVertex2f(67,73);
    glVertex2f(61,73);
    glVertex2f(61,72);
    glEnd();

    glTranslatef(0.0f,-3.0f,0.0f);
    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(61,72);
    glVertex2f(67,72);
    glVertex2f(67,73);
    glVertex2f(61,73);
    glVertex2f(61,72);
    glEnd();

    glTranslatef(0.0f,-3.0f,0.0f);
    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(61,72);
    glVertex2f(67,72);
    glVertex2f(67,73);
    glVertex2f(61,73);
    glVertex2f(61,72);
    glEnd();
    glTranslatef(0.0f,-3.0f,0.0f);
    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(61,72);
    glVertex2f(67,72);
    glVertex2f(67,73);
    glVertex2f(61,73);
    glVertex2f(61,72);
    glEnd();
    glTranslatef(0.0f,-3.0f,0.0f);
    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(61,72);
    glVertex2f(67,72);
    glVertex2f(67,73);
    glVertex2f(61,73);
    glVertex2f(61,72);
    glEnd();
    glTranslatef(0.0f,-3.0f,0.0f);
    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(61,72);
    glVertex2f(67,72);
    glVertex2f(67,73);
    glVertex2f(61,73);
    glVertex2f(61,72);
    glEnd();
    glTranslatef(0.0f,-3.0f,0.0f);
    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(61,72);
    glVertex2f(67,72);
    glVertex2f(67,73);
    glVertex2f(61,73);
    glVertex2f(61,72);
    glEnd();
    glTranslatef(0.0f,-3.0f,0.0f);
    glColor3ub(23, 32, 42);
    glBegin(GL_POLYGON);
    glVertex2f(61,72);
    glVertex2f(67,72);
    glVertex2f(67,73);
    glVertex2f(61,73);
    glVertex2f(61,72);
    glEnd();
    glPopMatrix();




    glLoadIdentity();
    //TREES..

    glPushMatrix();

     glColor3ub(131, 81, 4);
     glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(23.5,50);
    glVertex2f(23.5,48);
    glEnd();
     glColor3ub(3, 106, 48);
    glBegin(GL_POLYGON);
    glVertex2f(22,50);
    glVertex2f(25,50);
    glVertex2f(23.5,52);
    glVertex2f(22,50);
    glEnd();
    glColor3ub(5, 162, 74);
    glBegin(GL_POLYGON);
    glVertex2f(22,51);
    glVertex2f(25,51);
    glVertex2f(23.5,53);
    glVertex2f(22,51);
    glEnd();
     glColor3ub(7, 186, 86);
    glBegin(GL_POLYGON);
    glVertex2f(22,52);
    glVertex2f(25,52);
    glVertex2f(23.5,54);
    glVertex2f(22,52);

    glEnd();
    glPopMatrix();
     glTranslatef(3.0f,0.0f,0.0f);
     glPushMatrix();

     glColor3ub(131, 81, 4);
     glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(23.5,50);
    glVertex2f(23.5,48);
    glEnd();
     glColor3ub(3, 106, 48);
    glBegin(GL_POLYGON);
    glVertex2f(22,50);
    glVertex2f(25,50);
    glVertex2f(23.5,52);
    glVertex2f(22,50);
    glEnd();
    glColor3ub(5, 162, 74);
    glBegin(GL_POLYGON);
    glVertex2f(22,51);
    glVertex2f(25,51);
    glVertex2f(23.5,53);
    glVertex2f(22,51);
    glEnd();
     glColor3ub(7, 186, 86);
    glBegin(GL_POLYGON);
    glVertex2f(22,52);
    glVertex2f(25,52);
    glVertex2f(23.5,54);
    glVertex2f(22,52);

    glEnd();
    glPopMatrix();
    glTranslatef(3.0f,0.0f,0.0f);
     glPushMatrix();

     glColor3ub(131, 81, 4);
     glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(23.5,50);
    glVertex2f(23.5,48);
    glEnd();
     glColor3ub(3, 106, 48);
    glBegin(GL_POLYGON);
    glVertex2f(22,50);
    glVertex2f(25,50);
    glVertex2f(23.5,52);
    glVertex2f(22,50);
    glEnd();
    glColor3ub(5, 162, 74);
    glBegin(GL_POLYGON);
    glVertex2f(22,51);
    glVertex2f(25,51);
    glVertex2f(23.5,53);
    glVertex2f(22,51);
    glEnd();
     glColor3ub(7, 186, 86);
    glBegin(GL_POLYGON);
    glVertex2f(22,52);
    glVertex2f(25,52);
    glVertex2f(23.5,54);
    glVertex2f(22,52);

    glEnd();
    glPopMatrix();

     glTranslatef(26.0f,0.0f,0.0f);
     glPushMatrix();

     glColor3ub(131, 81, 4);
     glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(23.5,50);
    glVertex2f(23.5,48);
    glEnd();
     glColor3ub(3, 106, 48);
    glBegin(GL_POLYGON);
    glVertex2f(22,50);
    glVertex2f(25,50);
    glVertex2f(23.5,52);
    glVertex2f(22,50);
    glEnd();
    glColor3ub(5, 162, 74);
    glBegin(GL_POLYGON);
    glVertex2f(22,51);
    glVertex2f(25,51);
    glVertex2f(23.5,53);
    glVertex2f(22,51);
    glEnd();
     glColor3ub(7, 186, 86);
    glBegin(GL_POLYGON);
    glVertex2f(22,52);
    glVertex2f(25,52);
    glVertex2f(23.5,54);
    glVertex2f(22,52);

    glEnd();
    glPopMatrix();

    glTranslatef(2.0f,0.0f,0.0f);
     glPushMatrix();

     glColor3ub(131, 81, 4);
     glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(23.5,50);
    glVertex2f(23.5,48);
    glEnd();
     glColor3ub(3, 106, 48);
    glBegin(GL_POLYGON);
    glVertex2f(22,50);
    glVertex2f(25,50);
    glVertex2f(23.5,52);
    glVertex2f(22,50);
    glEnd();
    glColor3ub(5, 162, 74);
    glBegin(GL_POLYGON);
    glVertex2f(22,51);
    glVertex2f(25,51);
    glVertex2f(23.5,53);
    glVertex2f(22,51);
    glEnd();
     glColor3ub(7, 186, 86);
    glBegin(GL_POLYGON);
    glVertex2f(22,52);
    glVertex2f(25,52);
    glVertex2f(23.5,54);
    glVertex2f(22,52);

    glEnd();
    glPopMatrix();

    glTranslatef(10.0f,0.0f,0.0f);
     glPushMatrix();

     glColor3ub(131, 81, 4);
     glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(23.5,50);
    glVertex2f(23.5,48);
    glEnd();
     glColor3ub(3, 106, 48);
    glBegin(GL_POLYGON);
    glVertex2f(22,50);
    glVertex2f(25,50);
    glVertex2f(23.5,52);
    glVertex2f(22,50);
    glEnd();
    glColor3ub(5, 162, 74);
    glBegin(GL_POLYGON);
    glVertex2f(22,51);
    glVertex2f(25,51);
    glVertex2f(23.5,53);
    glVertex2f(22,51);
    glEnd();
     glColor3ub(7, 186, 86);
    glBegin(GL_POLYGON);
    glVertex2f(22,52);
    glVertex2f(25,52);
    glVertex2f(23.5,54);
    glVertex2f(22,52);

    glEnd();
    glPopMatrix();


    glTranslatef(2.0f,0.0f,0.0f);
     glPushMatrix();

     glColor3ub(131, 81, 4);
     glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(23.5,50);
    glVertex2f(23.5,48);
    glEnd();
     glColor3ub(3, 106, 48);
    glBegin(GL_POLYGON);
    glVertex2f(22,50);
    glVertex2f(25,50);
    glVertex2f(23.5,52);
    glVertex2f(22,50);
    glEnd();
    glColor3ub(5, 162, 74);
    glBegin(GL_POLYGON);
    glVertex2f(22,51);
    glVertex2f(25,51);
    glVertex2f(23.5,53);
    glVertex2f(22,51);
    glEnd();
     glColor3ub(7, 186, 86);
    glBegin(GL_POLYGON);
    glVertex2f(22,52);
    glVertex2f(25,52);
    glVertex2f(23.5,54);
    glVertex2f(22,52);

    glEnd();
    glPopMatrix();





    //river
    glLoadIdentity();
    glColor3ub(179, 238, 226);
    glBegin(GL_POLYGON);
    glVertex2f(0,25);
    glVertex2f(100,25);
    glVertex2f(100,40);
    glVertex2f(0,40);
    glVertex2f(0,25);
    glEnd();


    //boats...
      glLoadIdentity();
      glTranslatef(move_boat_third,0.0f,0.0f);
     glPushMatrix();
    glColor3ub(15, 12, 13);
    glBegin(GL_POLYGON);
    glVertex2f(87,33);
    glVertex2f(91,33);
    glVertex2f(93,35);
    glVertex2f(85,35);
    glVertex2f(87,33);
    glEnd();


    glColor3ub(221, 234, 15);
    glBegin(GL_POLYGON);
    glVertex2f(90,35);
    glVertex2f(90,39);
    glVertex2f(88,36);
    glVertex2f(90,35);

    glEnd();
     glColor3ub(25, 25, 17);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(90,35);
    glVertex2f(90,39);
    glEnd();

     glPopMatrix();
     glLoadIdentity();




    //railings ....

     glColor3ub(49, 49, 49);
     glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(0,25);
    glVertex2f(100,25);

    glVertex2f(0,28);
    glVertex2f(100,28);

    glEnd();
    glLoadIdentity();
    glPushMatrix();

     glColor3ub(49, 49, 49);
     glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();

    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();

    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();
    glTranslatef(5.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(3,28);
    glVertex2f(3,25);
    glEnd();



    glPopMatrix();
    glLoadIdentity();

    //ROAD...
    glColor3ub(49, 49, 49);
    glBegin(GL_POLYGON);
    glVertex2f(0,40);
    glVertex2f(100,40);
    glVertex2f(100,48);
    glVertex2f(0,48);
    glEnd();

    //ROAD ER DIVIDERS....
     glLoadIdentity();
    glPushMatrix();
    glColor3ub(154, 152, 146);
    glBegin(GL_POLYGON);
    glVertex2f(4,44);
    glVertex2f(11,44);
    glVertex2f(11,44.5);
    glVertex2f(4,44.5);
    glVertex2f(4,44);
    glEnd();


    glTranslatef(12.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4,44);
    glVertex2f(11,44);
    glVertex2f(11,44.5);
    glVertex2f(4,44.5);
    glVertex2f(4,44);
    glEnd();


    glTranslatef(12.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4,44);
    glVertex2f(11,44);
    glVertex2f(11,44.5);
    glVertex2f(4,44.5);
    glVertex2f(4,44);
    glEnd();




    glTranslatef(12.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4,44);
    glVertex2f(11,44);
    glVertex2f(11,44.5);
    glVertex2f(4,44.5);
    glVertex2f(4,44);
    glEnd();




    glTranslatef(12.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4,44);
    glVertex2f(11,44);
    glVertex2f(11,44.5);
    glVertex2f(4,44.5);
    glVertex2f(4,44);
    glEnd();

    glTranslatef(12.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4,44);
    glVertex2f(11,44);
    glVertex2f(11,44.5);
    glVertex2f(4,44.5);
    glVertex2f(4,44);
    glEnd();



    glTranslatef(12.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4,44);
    glVertex2f(11,44);
    glVertex2f(11,44.5);
    glVertex2f(4,44.5);
    glVertex2f(4,44);
    glEnd();



    glTranslatef(12.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4,44);
    glVertex2f(11,44);
    glVertex2f(11,44.5);
    glVertex2f(4,44.5);
    glVertex2f(4,44);
    glEnd();
    glPopMatrix();
    glLoadIdentity();


    //CARS.....
    glTranslatef(move_car_second,0.0f,0.0f);
    glPushMatrix();
    glColor3ub(211, 16, 84);
    glBegin(GL_POLYGON);
    glVertex2f(5,43);
    glVertex2f(11,43);
    glVertex2f(11,45);
    glVertex2f(5,45);
    glVertex2f(5,43);
    glEnd();

    //wheels for car...
    wheel(6.5f,43.0f,0.7f);
    wheel(9.2f,43.0f,0.7f);
    //chaad
     glColor3ub(242, 235, 238);
    glBegin(GL_POLYGON);
    glVertex2f(6,45);
    glVertex2f(10,45);
    glVertex2f(9,46);
    glVertex2f(7,46);
    glVertex2f(6,45);
    glEnd();


    glColor3ub(35, 34, 35);
    glLineWidth(0.3);
    glBegin(GL_LINES);
    glVertex2f(9,46);
    glVertex2f(9,45);

    glVertex2f(7,46);
    glVertex2f(7,45);
    glEnd();
     glPopMatrix();
    glLoadIdentity();
    //Border upper side....
     glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(0,43);
    glVertex2f(100,43);

    glEnd();

    glColor3ub(152, 155, 155);
    glLineWidth(6);
     glBegin(GL_LINES);
    glVertex2f(0,40);
    glVertex2f(100,40);

    glEnd();


      glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();

    glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();

     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd(); glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd(); glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd(); glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();
     glTranslatef(4.0f,0.0f,0.0f);
    glColor3ub(152, 155, 155);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(3,43);
    glVertex2f(3,40);
    glEnd();


    glLoadIdentity();
     //GROUND WORK....

    glColor3ub(26, 165, 5);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,0);
    glVertex2f(100,25);
    glVertex2f(0,25);
    glVertex2f(0,0);
    glEnd();

     //flowers....
     glTranslatef(0.0f,0.0f,0.0f);
     glPushMatrix();
     glTranslatef(0.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(3.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower(5.0f,5.0f,1.0f);
     circle_for_flower(6.0f,6.0f,1.0f);
     circle_for_flower(7.0f,5.0f,1.0f);
     circle_for_flower(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(4.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();

     glPopMatrix();


     glTranslatef(7.0f,0.0f,0.0f);
     glPushMatrix();
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(3.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower(5.0f,5.0f,1.0f);
     circle_for_flower(6.0f,6.0f,1.0f);
     circle_for_flower(7.0f,5.0f,1.0f);
     circle_for_flower(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(4.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();

     glPopMatrix();


    glTranslatef(7.0f,0.0f,0.0f);
     glPushMatrix();
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(3.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower(5.0f,5.0f,1.0f);
     circle_for_flower(6.0f,6.0f,1.0f);
     circle_for_flower(7.0f,5.0f,1.0f);
     circle_for_flower(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(4.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();

     glPopMatrix();

      glTranslatef(0.0f,-3.0f,0.0f);
     glPushMatrix();
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(3.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower(5.0f,5.0f,1.0f);
     circle_for_flower(6.0f,6.0f,1.0f);
     circle_for_flower(7.0f,5.0f,1.0f);
     circle_for_flower(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(4.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();

     glPopMatrix();

 glTranslatef(-7.0f,0.0f,0.0f);
     glPushMatrix();
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(3.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower(5.0f,5.0f,1.0f);
     circle_for_flower(6.0f,6.0f,1.0f);
     circle_for_flower(7.0f,5.0f,1.0f);
     circle_for_flower(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(4.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();

     glPopMatrix();

     glTranslatef(-7.0f,0.0f,0.0f);
     glPushMatrix();
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(3.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower(5.0f,5.0f,1.0f);
     circle_for_flower(6.0f,6.0f,1.0f);
     circle_for_flower(7.0f,5.0f,1.0f);
     circle_for_flower(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();
     glTranslatef(4.0f,0.0f,0.0f);
     glPushMatrix();
     circle_for_flower_two(5.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,6.0f,1.0f);
     circle_for_flower_two(7.0f,5.0f,1.0f);
     circle_for_flower_two(6.0f,4.0f,1.0f);
     circle_for_flower_middle(6.0f,5.0f,0.5f);
     glPopMatrix();

     glPopMatrix();


    glLoadIdentity();

    circle_for_flower_two(80.0f,10.0f,1.0f);
    circle_for_flower_two(82.0f,10.0f,1.0f);
    circle_for_flower_two(81.0f,11.0f,1.0f);
    circle_for_flower_two(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);

    glTranslatef(3.0f,0.0f,0.0f);
    circle_for_flower(80.0f,10.0f,1.0f);
    circle_for_flower(82.0f,10.0f,1.0f);
    circle_for_flower(81.0f,11.0f,1.0f);
    circle_for_flower(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
    glTranslatef(3.0f,0.0f,0.0f);
    circle_for_flower_two(80.0f,10.0f,1.0f);
    circle_for_flower_two(82.0f,10.0f,1.0f);
    circle_for_flower_two(81.0f,11.0f,1.0f);
    circle_for_flower_two(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
    glTranslatef(3.0f,0.0f,0.0f);
    circle_for_flower_two(80.0f,10.0f,1.0f);
    circle_for_flower_two(82.0f,10.0f,1.0f);
    circle_for_flower_two(81.0f,11.0f,1.0f);
    circle_for_flower_two(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
    glTranslatef(3.0f,0.0f,0.0f);
    circle_for_flower(80.0f,10.0f,1.0f);
    circle_for_flower(82.0f,10.0f,1.0f);
    circle_for_flower(81.0f,11.0f,1.0f);
    circle_for_flower(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
     glTranslatef(3.0f,0.0f,0.0f);
    circle_for_flower(80.0f,10.0f,1.0f);
    circle_for_flower(82.0f,10.0f,1.0f);
    circle_for_flower(81.0f,11.0f,1.0f);
    circle_for_flower(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
    glTranslatef(3.0f,0.0f,0.0f);
    circle_for_flower_two(80.0f,10.0f,1.0f);
    circle_for_flower_two(82.0f,10.0f,1.0f);
    circle_for_flower_two(81.0f,11.0f,1.0f);
    circle_for_flower_two(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
   glTranslatef(0.0f,-3.0f,0.0f);
    circle_for_flower_two(80.0f,10.0f,1.0f);
    circle_for_flower_two(82.0f,10.0f,1.0f);
    circle_for_flower_two(81.0f,11.0f,1.0f);
    circle_for_flower_two(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);

     glTranslatef(-3.0f,0.0f,0.0f);
    circle_for_flower_two(80.0f,10.0f,1.0f);
    circle_for_flower_two(82.0f,10.0f,1.0f);
    circle_for_flower_two(81.0f,11.0f,1.0f);
    circle_for_flower_two(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
    glTranslatef(-3.0f,0.0f,0.0f);
    circle_for_flower(80.0f,10.0f,1.0f);
    circle_for_flower(82.0f,10.0f,1.0f);
    circle_for_flower(81.0f,11.0f,1.0f);
    circle_for_flower(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
    glTranslatef(-3.0f,0.0f,0.0f);
    circle_for_flower(80.0f,10.0f,1.0f);
    circle_for_flower(82.0f,10.0f,1.0f);
    circle_for_flower(81.0f,11.0f,1.0f);
    circle_for_flower(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
    glTranslatef(-3.0f,0.0f,0.0f);
    circle_for_flower_two(80.0f,10.0f,1.0f);
    circle_for_flower_two(82.0f,10.0f,1.0f);
    circle_for_flower_two(81.0f,11.0f,1.0f);
    circle_for_flower_two(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
    glTranslatef(-3.0f,0.0f,0.0f);
    circle_for_flower_two(80.0f,10.0f,1.0f);
    circle_for_flower_two(82.0f,10.0f,1.0f);
    circle_for_flower_two(81.0f,11.0f,1.0f);
    circle_for_flower_two(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
    glTranslatef(-3.0f,0.0f,0.0f);
    circle_for_flower(80.0f,10.0f,1.0f);
    circle_for_flower(82.0f,10.0f,1.0f);
    circle_for_flower(81.0f,11.0f,1.0f);
    circle_for_flower(81.0f,9.0f,1.0f);
    circle_for_flower_middle(81.0f,10.0f,0.5f);
     glLoadIdentity();
    //chairs...

    glPushMatrix();
    glColor3ub(23, 32, 42);
     glLineWidth(4);
     glBegin(GL_LINES);
      glVertex2f(49.6,20.5);
      glVertex2f(49.6,18);
    glEnd();

     glColor3ub(230, 126, 34);
     glBegin(GL_POLYGON);
    glVertex2f(35,22);
    glVertex2f(50,22);
    glVertex2f(50,26);
    glVertex2f(35,26);
    glVertex2f(35,22);
    glEnd();


    glColor3ub(23, 32, 42);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(35.2,22);
    glVertex2f(35.2,21);
    glVertex2f(49.8,22);
    glVertex2f(49.8,21);
    glEnd();

    glColor3ub(175, 96, 26);
     glBegin(GL_POLYGON);
    glVertex2f(33,17);
    glVertex2f(48,17);
    glVertex2f(50,21);
    glVertex2f(35,21);
    glVertex2f(33,17);
    glEnd();

    glColor3ub(23, 32, 42);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(33.2,17);
    glVertex2f(33.2,14);

    glVertex2f(47.8,17);
    glVertex2f(47.8,14);


    glEnd();
    glPopMatrix();
    glTranslatef(35.0f,0.0f,0.0f);
     glPushMatrix();
    glColor3ub(23, 32, 42);
     glLineWidth(4);
     glBegin(GL_LINES);
      glVertex2f(49.6,20.5);
      glVertex2f(49.6,18);
    glEnd();

     glColor3ub(230, 126, 34);
     glBegin(GL_POLYGON);
    glVertex2f(35,22);
    glVertex2f(50,22);
    glVertex2f(50,26);
    glVertex2f(35,26);
    glVertex2f(35,22);
    glEnd();


    glColor3ub(23, 32, 42);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(35.2,22);
    glVertex2f(35.2,21);
    glVertex2f(49.8,22);
    glVertex2f(49.8,21);
    glEnd();

    glColor3ub(175, 96, 26);
     glBegin(GL_POLYGON);
    glVertex2f(33,17);
    glVertex2f(48,17);
    glVertex2f(50,21);
    glVertex2f(35,21);
    glVertex2f(33,17);
    glEnd();

    glColor3ub(23, 32, 42);
    glLineWidth(4);
     glBegin(GL_LINES);
    glVertex2f(33.2,17);
    glVertex2f(33.2,14);

    glVertex2f(47.8,17);
    glVertex2f(47.8,14);


    glEnd();
    glPopMatrix();
    glLoadIdentity();
    glFlush();

}
void keyBoardFun(unsigned char key, int x, int y)
{
     switch (key)
    {
    case 'd':
        if(main_page==true)
        {
            glutDisplayFunc(day);
        }

        break;
    case 'n':
        if(main_page==true)
        {
           glutDisplayFunc(night_display);
        }

        break;
    case 'e':
        if(main_page==true)
        {
            glutDisplayFunc(Evening_view);
        }
        break;
    case 'a':
        if(main_page==true)
        {
           glutDisplayFunc(nightDisplayTwo);
        }
      break;
    case 's':
          main_page=true;
        break;
    default:
        break;
}
//glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f(1,1,1,0);
     if(main_page==true)
     {
    if (currentScenario == 1)
    {
        day();
    }
    else if (currentScenario == 2)
    {

        Evening_view();
    }
    else if(currentScenario==3)
    {
        nightDisplayTwo();
    }
    else if(currentScenario==4)
    {

        night_display();
    }

    }
    else{
        info();
    }

  //  glFlush();
    glutSwapBuffers();
}
void screenTime(int value) {
     totalScreenTime+= perDisplayTime;

    if(totalScreenTime>=4*perDisplayTime)
    {
        currentScenario=1;
        totalScreenTime=0;

    }
    else if(totalScreenTime>=3*perDisplayTime)
    {
         currentScenario=4;

    }
    else if(totalScreenTime>=2*perDisplayTime)
    {
        currentScenario=3;

    }
    else if(totalScreenTime>=perDisplayTime)
    {
        currentScenario=2;
    }
    glutPostRedisplay();
    glutTimerFunc(15000, screenTime, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(1000,600);   // Set the window's initial width & height
    //glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("FINAL PROJECT"); // Create a window with the given title
    glutDisplayFunc(night_display); // Register display callback handler for window re-paint
     init();
     glutKeyboardFunc(keyBoardFun);
     glutTimerFunc(20, update_cloud, 0);
     glutTimerFunc(20,update_car,0);
     glutTimerFunc(20,update_truck,0);
     glutTimerFunc(200,update_bird,0);
     glutTimerFunc(20,update_train,0);
     glutTimerFunc(20,update_boat,0);
     glutTimerFunc(20,update_boat_two,0);
     glutTimerFunc(20,update_wave,0);
     glutTimerFunc(20,update_car_second,0);
     glutTimerFunc(60,update_boat_third,0);
    //glutSpecialFunc(SpecialInput);
    glutTimerFunc(15000,screenTime,0);
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
