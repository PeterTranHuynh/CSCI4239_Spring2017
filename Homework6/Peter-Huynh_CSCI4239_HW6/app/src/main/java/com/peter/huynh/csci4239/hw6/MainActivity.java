package com.peter.huynh.csci4239.hw6;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;

import android.app.Activity;
import android.util.Log;
import android.content.res.Configuration;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}
