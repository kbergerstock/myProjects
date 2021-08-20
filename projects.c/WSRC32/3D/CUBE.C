/* cube.c                               K. R. BERGERSTOCK */

#include "graphics.h"

#ifdef VID_EGA

  #define C1 1
  #define C2 0x82
  #define H 320
  #define K 160
  #define MODE 0x10

#endif

#ifdef VID_CGA

  #define C1 1
  #define C2 1
  #define H 320
  #define K 90
  #define MODE 0x06

#endif

#define RHO 10
#define THETA .7
#define PHI 1.0
#define D 500

points xyz[] = {
          { 1,1,0 },
          { 1,1,1 },
          { 0,1,1 },
          { 0,1,0 },
          { 1,1,0 },
          { 1,0,0 },
          { 1,0,1 },
          { 0,0,1 },
          { 0,1,1 },
          { 1,0,1 },
          { 1,1,1 },
              } ;


void init_3d(float r, float theta, float phi, float dis, float h, float k );
void plot_3d( float x, float y, float z, int _mode);
void line_3d(float x, float y, float z,int _mode);

cube()
  {
  int i;

  init_3d(RHO,THETA,PHI,D,H,K);

  for ( i = 0; i < 11; i++)
    plot_3d(xyz[i].x, xyz[i].y, xyz[i].z, C2);

  plot_3d(xyz[0].x,xyz[0].y,xyz[0].z,C2);
  for(i = 1; i < 9; i++)
   line_3d(xyz[i].x,xyz[i].y,xyz[i].z,C2);

  plot_3d(xyz[9].x,xyz[9].y,xyz[9].z,C2);
  line_3d(xyz[10].x,xyz[10].y,xyz[10].z,C2);

  getkey();

  }
