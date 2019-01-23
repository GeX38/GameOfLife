#include <unistd.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>
#include "Life.h"

#define GL_CLEAR_MODE GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT
int speedChangeStep = 1000;
int width=1000;
int height=1000;
bool pauseGame=true;
int delay=50000;
Matrix2d Game(DEFAULT_SIZE,std::vector<Cell>(DEFAULT_SIZE));
void drawCell (const Cell & cell,int x, int y, bool highlight=false){
    glPushMatrix();
        glColor3f(1.0f*highlight,0.8f*cell.value+0.2f+1.0f*highlight,0.0f+1.0f*highlight);
        glTranslatef(x+0.5, y+0.5, 0);
        glutSolidSphere(0.45,20,20);
    glPopMatrix();
}
void render(){//Отрисовывает живые клетки.
	for(int i=0;i<Game.size();++i){
		for(int j=0;j<Game[i].size();++j){
			drawCell(Game[i][j],(j),(i),(i==0||j==0||i==Game.size()-1||j==Game[i].size()-1));
		}
	}
}










void reshape (int w, int h);
void  proceed ();
void keyboard (unsigned char key, int x, int y);
void clicker(int button,int state,int x, int y);
void display();

int main(int argc, char  *argv[])
{
	glutInit(&argc,argv);//Инициализация OpenGL.
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);//Задание режимов отображения #Количество буферов, цветовая схема и прочее.
    glutInitWindowSize (width, height);//Задание изначальных размеров окна.
    glutInitWindowPosition (100, 100);//Определение начальной позиции окна на экране.
    glutCreateWindow ("");//Создание окна
    glClearColor (0.15,0.45, 0.30, 0.0);//Базовый цвет очистки экрана.
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(proceed);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(clicker);
	glutMainLoop();//Вход в цикл отрисовки(Запуск циклов отрисовки).
	
	return 0;
}
void reshape (int w, int h)
{
    width = w;
    height = h;
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);//Переходим в режим проекции и выбираем используемую проекцию.
   glLoadIdentity ();
   glOrtho(0, 100, 0, 100, -50.0, 80.0);//Выбор и настройка ортогональной проекции(min x, max x, min y, max y, min z, max z).
glMatrixMode(GL_MODELVIEW);//Переход в режим модели.
   glLoadIdentity();
   gluLookAt(
        0.0f,0.0f,40.0f, // положение камеры.
        0.0f,0.0f,0.0f, // центр сцены.
        0.0f,1.0f,0.0f); // положительное направление оси y.
}
void display(){
    glClear (GL_CLEAR_MODE);//Очистка экрана перед отрисовкой.
    glPushMatrix();
    render();
        glutSolidSphere(0.45,20,20);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
    		case 51:if(pauseGame){
                Pentamino(Game);
            }
                break;
    	    case 49:if(pauseGame){
                GalaxyOfCocke(Game);
                }break;
            case 50:if(pauseGame){
                GosperGun(Game);
            }
                break;
            case 32:
            pauseGame=!pauseGame;
                glutPostRedisplay();
                break;
            case 27:
                glutLeaveMainLoop();
                break;
            case 8:
             fullClear(Game);
             glutPostRedisplay();
             break;
            default:
                break;
    }
}
void clicker(int button,int state,int x, int y)
{
    
    if (state == GLUT_DOWN) 
    {
        switch(button) 
        {
        case GLUT_LEFT_BUTTON:
        if(pauseGame){
                int I = Game.size()-y/(height/Game.size())-1;
                int J = x/(width/Game.size());
                if(!(I==0||J==0||I==Game.size()-1||J==Game[I].size()-1))
                Game[I][J].value=1;
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
        if(pauseGame){
                int I = Game.size()-y/(height/Game.size())-1;
                int J = x/(width/Game.size());
                Game[I][J].value=0;
            }
            break;
        case 3:
        if(delay>1500)
                (delay-=speedChangeStep);
            break;
        case 4:
        delay+=speedChangeStep;
               break;
        }
        printf("button pressed at (%d,%d)\n",x,y);
    }
    else 
    {
        switch(button) 
        {
        case GLUT_LEFT_BUTTON:
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
            break;
        }
    }

    glutPostRedisplay();
}
void  proceed ()
{
	if(!pauseGame){
        genNextGeneration(Game);
applyChanges(Game);
}

    glutPostRedisplay ();
    usleep(pauseGame?1:delay);
    glutPostRedisplay ();
}