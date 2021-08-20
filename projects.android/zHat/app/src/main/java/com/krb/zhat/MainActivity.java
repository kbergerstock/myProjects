
/*
    k.r.bergrstock @08/2015
    java main entry poinr
 */

package com.krb.zhat;

import android.app.ActionBar;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;


public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getActionBar().setTitle(R.string.greeting);
        setContentView(new DrawTheHat(this));
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.

        switch (  item.getItemId() )
        {
            case R.id.action_settings:
                return true;
            case R.id.action_blue_settings:
                return true;
            case R.id.action_green_settings:
                return true;
            case R.id.action_red_settings:
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }

    }
}
