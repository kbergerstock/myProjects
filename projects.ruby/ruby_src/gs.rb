#glut shell

require "opengl"
require "glut"


   GLUT.Init
   GLUT.InitDisplayMode(GLUT::SINGLE | GLUT::RGB);
   GLUT.InitWindowSize(800, 600); 
   GLUT.InitWindowPosition(100, 100);
   GLUT.CreateWindow("hello");

   GLUT.MainLoop();