/*
  Created by bergerstock on 8/4/2015.
  java class to draw the graphic
*/

package com.krb.zhat;

import android.content.*;
import android.view.*;
import android.graphics.*;
import android.graphics.Paint;

public class DrawTheHat extends SurfaceView {
     SurfaceHolder holder;
     updateLoop tLoop;
     int start_color = 0xff000000;
     int inc_color = 0x00000003;
     Paint color;

    // helper functions to calculate the center point
    private int calcCY(int hgt) {
        return (((hgt / 2) * 9) / 10);
    }

    private int calcCX(int width) {
        return (int) (width / 2.0);
    }


    private void draw_the_hat(Canvas canvas) {
        // defined constants
        final double pi = 3.14159265358979323846;
        final double XP = 300;
        final double YP = 110;
        final double ZP = 90;
        final double XR = (1.5 * pi);
        final double YR = 1.0;

        // define local variables
        int zi, xi, xl, yy;
        double zt, xt;
        double xf = XR / XP;
        double yf = YP / YR;
        double zf = XP / ZP;
        double xp2 = XP * XP;

        double dxi;
        int sx, sy;

        //  get boundries
        int cx = calcCX(getWidth());
        int cy = calcCY(getHeight());


        // do the hard stuff - plot the equation
        for (zi = (int) -ZP; zi < (int) ZP; zi++) {
            zt = zf * (double) (zi);
            xl = (int) (0.5 + Math.sqrt(xp2 - (zt * zt)));

            for (xi = -xl; xi <= xl; xi += 2) {
                dxi = (double) (xi);
                xt = Math.sqrt(dxi * dxi + zt * zt) * xf;
                yy = (int) (Math.sin(Math.sin(xt) + 0.4 * Math.sin(3.0 * xt)) * yf);
                sx = (cx + xi + zi);
                sy = (cy + zi - yy);
                canvas.drawPoint(sx, sy, color); // fix color defination
            }
        }
    }

    protected void draw_it(Canvas canvas) {
        canvas.drawColor(0xff000000);
        draw_the_hat(canvas);
        start_color += inc_color;
        //start_color &= 0xFF00FF00;
        color.setColor(start_color);
    }

    public  DrawTheHat(Context context) {
        super(context);
        color = new Paint();
        tLoop = new updateLoop(this);
        holder = getHolder();
        holder.addCallback(new SurfaceHolder.Callback() {

            @Override
            public void surfaceDestroyed(SurfaceHolder holder) {
                boolean retry = true;
                tLoop.setRunning(false);
                while (retry) {
                    try {
                        tLoop.join();
                        retry = false;
                    } catch (InterruptedException e) { }
                }
            }

            @Override
            public void surfaceCreated(SurfaceHolder holder) {
                color.setColor(start_color);
                tLoop.setRunning(true);
                tLoop.start();
            }

            @Override
            public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
            }
        });
    }

} // end of class






