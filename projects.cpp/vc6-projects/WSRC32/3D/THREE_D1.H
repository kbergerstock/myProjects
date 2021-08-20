//*******************************************************************
//              
//  FILE:       THREE_D1.H
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  ThreeD
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   - class to construct 3d objects with hidden lines
//              
//              
//*******************************************************************

// Includes


#ifndef __WINDOWS_H
#define  STRICT
#include <Windows.h>
#endif

#ifndef __THREED_H
#define __THREED_H

class ThreeD
{
  private:					// private variables and functions

  protected:				// functions and variables to be inheireted
	int cWidth; 			// width of client area
	int cHeigth;			// height of client area

	int cx; 				// center of x-axis
	int cy; 				// center of y-axis

	int sx; 				// current screen coordinate x,y
	int sy;

	int lx;
	int ly;

	int fl;

	// constants - used to rotate coordinate system
	double s1;			   // sine of angle theta
	double c1;			   // cosine of angle theta
	double s2;			   // sine of angle phi
	double c2;			   // cosine of angle phi
	double rho;
	double dis;


	HGLOBAL h_yx;          // used to mark when a line has passed
	HGLOBAL h_yn;          // though the vertical line so that the
	LPINT yx;			   // hidden line function works
	LPINT yn;

  public:				   // public functions and variables
	ThreeD();
	~ThreeD();

	void Init(double RHO, double THETA, double PHI, double DIS, int cW, int cH);
	void Init(int cW, int cH);

	int  CalcScreenCoordinates( double x, double y, double z);
	void plot_3d(HDC hdc, double x, double y, double z, COLORREF rgb);
	void hLine(HDC hdc, int startx, int starty, int endx, int endy, COLORREF rgb);
	void hwire( HDC hdc, double x, double y, double z, COLORREF rgb);
	void Line(HDC hdc, int startx, int starty, int endx, int endy, COLORREF rgb);
};

#endif
