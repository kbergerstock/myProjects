package com.krb.zhat;

import android.graphics.Canvas;

/**
 * Created by bergerstock on 8/14/2015.
 */

public class updateLoop extends Thread {
    private DrawTheHat view;
    private boolean running = false;

    public updateLoop(DrawTheHat view) {
        this.view = view;
    }

    public void setRunning(boolean run) {
        running = run;
    }

    // WAIT
    void wait( int ms) {
        try {
            sleep(ms);
        } catch (InterruptedException e) {

        }
    }



    @Override
    public void run()
    {
        while (running)
        {
            Canvas c = null;
            try {
                c = view.getHolder().lockCanvas();
                synchronized (view.getHolder()) {
                    view.draw_it(c);
                }
            } finally {
                if ( c != null){
                    view.getHolder().unlockCanvasAndPost(c);
                }
            }
            wait(25);
        }   // end of while

    }   // end of run

}   // end of class



