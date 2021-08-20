// polyCtl.cpp : Implementation of CpolyCtl

#include "stdafx.h"
#include "Tst1.h"
#include "polyCtl.h"

/////////////////////////////////////////////////////////////////////////////
// CpolyCtl

CpolyCtl::CpolyCtl()
{
	// Construct
    m_nSides = 3;
    m_clrFillColor = RGB(0, 0xFF, 0);
}


HRESULT CpolyCtl::OnDraw(ATL_DRAWINFO& di)
{
	RECT& rc = *(RECT*)di.prcBounds;
    HDC  hdc = di.hdcDraw; 

    COLORREF    colFore;
    HBRUSH      hOldBrush, hBrush;
    HPEN        hOldPen, hPen;

   // Translate m_colFore into a COLORREF type
   OleTranslateColor(m_clrFillColor, NULL, &colFore);

   // Create and select the colors to draw the circle
   hPen = (HPEN)GetStockObject(BLACK_PEN);
   hOldPen = (HPEN)SelectObject(hdc, hPen);
   hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
   hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

   Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);

   // Create and select the brush that will be used to fill the polygon
   hBrush    = CreateSolidBrush(colFore);
   SelectObject(hdc, hBrush);

   CalcPoints(rc);
   Polygon(hdc, &m_points[0], m_nSides);

   // Select back the old pen and brush and delete the brush we created
   SelectObject(hdc, hOldPen);
   SelectObject(hdc, hOldBrush);
   DeleteObject(hBrush);

	return S_OK;
}

void CpolyCtl::CalcPoints(const RECT& rc)
{
   const double pi = 3.14159265358979;
   POINT   ptCenter;
   double  dblRadiusx = (rc.right - rc.left) / 2;
   double  dblRadiusy = (rc.bottom - rc.top) / 2;
   double  dblAngle = 3 * pi / 2;          // Start at the top
   double  dblDiff  = 2 * pi / m_nSides;   // Angle each side will make
   ptCenter.x = (rc.left + rc.right) / 2;
   ptCenter.y = (rc.top + rc.bottom) / 2;

   // Calculate the points for each side
   for (int i = 0; i < m_nSides; i++)
   {
      m_points[i].x = (long)(dblRadiusx * cos(dblAngle) + ptCenter.x + 0.5);
      m_points[i].y = (long)(dblRadiusy * sin(dblAngle) + ptCenter.y + 0.5);
      dblAngle += dblDiff;
   }

}


STDMETHODIMP CpolyCtl::get_sides(short *pVal)
{
	// TODO: Add your implementation code here
   *pVal = m_nSides;

   return S_OK;
}

STDMETHODIMP CpolyCtl::put_sides(short newVal)
{
	// TODO: Add your implementation code here

   if (newVal > 2 && newVal < 101)
    {
      m_nSides = newVal;
      FireViewChange();
      return S_OK;
    }
   else
    {
      return Error(_T("Shape must have between 3 and 100 sides"));
    }
}
