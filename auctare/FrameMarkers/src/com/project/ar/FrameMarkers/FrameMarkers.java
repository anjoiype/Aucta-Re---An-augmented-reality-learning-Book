


package com.project.ar.FrameMarkers;

import java.util.Vector;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.pm.ActivityInfo;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.util.DisplayMetrics;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SubMenu;
import android.view.View;
import android.view.WindowManager;
import android.view.ViewGroup.LayoutParams;
import android.widget.ImageView;

import com.qualcomm.QCAR.QCAR;


/** main activity  */
public class FrameMarkers extends Activity
{
	private static final int APPSTATUS_UNINITED         = -1;
    private static final int APPSTATUS_INIT_APP         = 0;
    private static final int APPSTATUS_INIT_QCAR        = 1;
    private static final int APPSTATUS_INIT_APP_AR      = 2;
    private static final int APPSTATUS_INIT_TRACKER     = 3;
    private static final int APPSTATUS_INITED           = 4;
    private static final int APPSTATUS_CAMERA_STOPPED   = 5;
    private static final int APPSTATUS_CAMERA_RUNNING   = 6;
    
    private static final String NATIVE_LIB_SAMPLE = "FrameMarkers";    
    private static final String NATIVE_LIB_QCAR = "QCAR"; 

   
    private openglview mGlView;
    private ImageView mSplashScreenView;
    private static final long MIN_SPLASH_SCREEN_TIME = 2000;    
    long mSplashScreenStartTime = 0;
    
    private FrameMarkersRenderer mRenderer;
    private int mScreenWidth = 0;
    private int mScreenHeight = 0;
    private int mAppStatus = APPSTATUS_UNINITED;
    private InitQCARTask mInitQCARTask;
    private LoadTrackerTask mLoadTrackerTask;
    private int mQCARFlags = 0;
    private Vector<Texture> mTextures;
    private int mSplashScreenImageResource = 0;
    
    static
    {
        loadLibrary(NATIVE_LIB_QCAR);
        loadLibrary(NATIVE_LIB_SAMPLE);
    }
    
    
       private class InitQCARTask extends AsyncTask<Void, Integer, Boolean>
    {   
            private int mProgressValue = -1;
        
        protected Boolean doInBackground(Void... params)
        {
            QCAR.setInitParameters(FrameMarkers.this, mQCARFlags);
            
            do
            {
                mProgressValue = QCAR.init();
                publishProgress(mProgressValue);
                
                 } while (!isCancelled() && mProgressValue >= 0 && mProgressValue < 100);
            
            return (mProgressValue > 0);
        }

        
        protected void onProgressUpdate(Integer... values)
        {
            }

        
        protected void onPostExecute(Boolean result)
        {
            if (result)
            {
                DebugLog.LOGD("InitQCARTask::onPostExecute: QCAR initialization" +
                                                            " successful");

                updateApplicationStatus(APPSTATUS_INIT_APP_AR);
            }
            else
            {

    AlertDialog dialogError = new AlertDialog.Builder(FrameMarkers.this).create();
                dialogError.setButton(
                    "Close",
                    new DialogInterface.OnClickListener()
                    {
                        public void onClick(DialogInterface dialog, int which)
                        {
                            System.exit(1);
                        }
                    }
                ); 
                
                String logMessage;

                if (mProgressValue == QCAR.INIT_DEVICE_NOT_SUPPORTED)
                {
                    logMessage = "Failed to initialize QCAR because this " +
                        "device is not supported.";
                }
                else if (mProgressValue ==
                            QCAR.INIT_CANNOT_DOWNLOAD_DEVICE_SETTINGS)
                {
                    logMessage = 
                        "Network connection required to initialize camera " +
                        "settings. Please check your connection and restart " +
                        "the application. If you are still experiencing " +
                        "problems, then your device may not be currently " +
                        "supported.";
                }
                else
                {
                    logMessage = "Failed to initialize QCAR.";
                }
                
                DebugLog.LOGE("InitQCARTask::onPostExecute: " + logMessage +
                                " Exiting.");
                
                dialogError.setMessage(logMessage);  
                dialogError.show();
            }
        }
    }
    
    private class LoadTrackerTask extends AsyncTask<Void, Integer, Boolean>
    {
        protected Boolean doInBackground(Void... params)
        {
            int progressValue = -1;

            do
            {
                progressValue = QCAR.load();
                publishProgress(progressValue);
                
            } while (!isCancelled() && progressValue >= 0 &&
                        progressValue < 100);
            
            return (progressValue > 0);
        }
        
        
        protected void onProgressUpdate(Integer... values)
        {
        }
        
        
        protected void onPostExecute(Boolean result)
        {
            DebugLog.LOGD("LoadTrackerTask::onPostExecute: execution " +
                        (result ? "successful" : "failed"));

            updateApplicationStatus(APPSTATUS_INITED);
        }
    }

    protected void onCreate(Bundle savedInstanceState)
    {
        DebugLog.LOGD("FrameMarkers::onCreate");
        super.onCreate(savedInstanceState);
        
      
        
        mTextures = new Vector<Texture>();
        loadTextures();
        
        mQCARFlags = getInitializationFlags();
        
        updateApplicationStatus(APPSTATUS_INIT_APP);
    }

    
    private void loadTextures()
    {
        mTextures.add(Texture.loadTextureFromApk("a1.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("u.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("c.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("t.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("a2.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("r.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("e.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("banana.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("teapot.png", getAssets())); 
        mTextures.add(Texture.loadTextureFromApk("rhino.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("heart.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("jupiter.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("neptune.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("earth.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("venus.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("mars.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("mercury.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("moon.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("saturn.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("uranus.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("ribs.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("eye.png", getAssets()));
        mTextures.add(Texture.loadTextureFromApk("liver.png", getAssets()));




    }
    
    private int getInitializationFlags()
    {
        return QCAR.GL_20;
    }    
    private native void startCamera();
    private native void stopCamera();
    protected void onResume()
    {
        DebugLog.LOGD("FrameMarkers::onResume");
        super.onResume();
        QCAR.onResume();
        if (mAppStatus == APPSTATUS_CAMERA_STOPPED)
            updateApplicationStatus(APPSTATUS_CAMERA_RUNNING);
        if (mGlView != null)
        {
            mGlView.setVisibility(View.VISIBLE);
            mGlView.onResume();
        }        
    }
    
    protected void onPause()
    {
        DebugLog.LOGD("FrameMarkers::onPause");
        super.onPause();
        
        if (mGlView != null)
        {
            mGlView.setVisibility(View.INVISIBLE);
            mGlView.onPause();
        }
        QCAR.onPause();
        
        if (mAppStatus == APPSTATUS_CAMERA_RUNNING)
        {
            updateApplicationStatus(APPSTATUS_CAMERA_STOPPED);
        }
    }
    private native void deinitApplicationNative();
    protected void onDestroy()
    {
        DebugLog.LOGD("FrameMarkers::onDestroy");
        super.onDestroy();
        if (mInitQCARTask != null &&
            mInitQCARTask.getStatus() != InitQCARTask.Status.FINISHED)
        {
            mInitQCARTask.cancel(true);
            mInitQCARTask = null;
        }
        
        if (mLoadTrackerTask != null &&
            mLoadTrackerTask.getStatus() != LoadTrackerTask.Status.FINISHED)
        {
            mLoadTrackerTask.cancel(true);
            mLoadTrackerTask = null;
        }
        deinitApplicationNative();
                mTextures.clear();
        mTextures = null;
        QCAR.deinit();
        
        System.gc();
    }

    
    private synchronized void updateApplicationStatus(int appStatus)
    {
        if (mAppStatus == appStatus)
            return;
        mAppStatus = appStatus;
        switch (mAppStatus)
        {
            case APPSTATUS_INIT_APP:
                initApplication();
                
                updateApplicationStatus(APPSTATUS_INIT_QCAR);
                break;

            case APPSTATUS_INIT_QCAR:
                try
                {
                    mInitQCARTask = new InitQCARTask();
                    mInitQCARTask.execute();
                }
                catch (Exception e)
                {
                    DebugLog.LOGE("Initializing QCAR SDK failed");
                }
                break;
                
            case APPSTATUS_INIT_APP_AR:
                initApplicationAR();
                updateApplicationStatus(APPSTATUS_INIT_TRACKER);
                break;
                
            case APPSTATUS_INIT_TRACKER:
                try
                {
                    mLoadTrackerTask = new LoadTrackerTask();
                    mLoadTrackerTask.execute();
                }
                catch (Exception e)
                {
                    DebugLog.LOGE("Loading tracking data set failed");
                }
                break;
                
            case APPSTATUS_INITED:
                System.gc();
                long splashScreenTime = System.currentTimeMillis() - 
                                            mSplashScreenStartTime;
                long newSplashScreenTime = 0;
                if (splashScreenTime < MIN_SPLASH_SCREEN_TIME)
                {
                    newSplashScreenTime = MIN_SPLASH_SCREEN_TIME -
                                            splashScreenTime;   
                }
                
                Handler handler = new Handler();
                handler.postDelayed(
                    new Runnable() {
                        public void run()
                        {
                            mSplashScreenView.setVisibility(View.INVISIBLE);
                            mRenderer.mIsActive = true;
                            addContentView(mGlView, new LayoutParams(
                                            LayoutParams.FILL_PARENT,
                                            LayoutParams.FILL_PARENT));
                            updateApplicationStatus(APPSTATUS_CAMERA_RUNNING);
                        }
                    }
                    , newSplashScreenTime);                
        
                break;
                
            case APPSTATUS_CAMERA_STOPPED:
                stopCamera();
                break;
                
            case APPSTATUS_CAMERA_RUNNING:
                startCamera(); 
                break;
                
            default:
                throw new RuntimeException("Invalid application state");
        }
    }
    
    private native void setActivityPortraitMode(boolean isPortrait);
    
    private void initApplication()
    {
        int screenOrientation = ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE;
        
        setRequestedOrientation(screenOrientation);
        
        setActivityPortraitMode(screenOrientation == ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
        
        DisplayMetrics metrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(metrics);
        mScreenWidth = metrics.widthPixels;
        mScreenHeight = metrics.heightPixels;

        getWindow().setFlags(
            WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON,
            WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        mSplashScreenView = new ImageView(this);
        mSplashScreenView.setImageResource(mSplashScreenImageResource);
        addContentView(mSplashScreenView, new LayoutParams(
                        LayoutParams.FILL_PARENT, LayoutParams.FILL_PARENT));
        
        mSplashScreenStartTime = System.currentTimeMillis();

    }
    
    
    private native void initApplicationNative(int width, int height);

    private void initApplicationAR()
    {        
        initApplicationNative(mScreenWidth, mScreenHeight);

        int depthSize = 16;
        int stencilSize = 0;
        boolean translucent = QCAR.requiresAlpha();
        
        mGlView = new openglview(this);
        mGlView.init(mQCARFlags, translucent, depthSize, stencilSize);
        
        mRenderer = new FrameMarkersRenderer();
        mGlView.setRenderer(mRenderer);
 
    }
    
    
    public boolean onCreateOptionsMenu(Menu menu)
    {
        super.onCreateOptionsMenu(menu);
        
        menu.add("Toggle flash");
        menu.add("Autofocus");
        
        SubMenu focusModes = menu.addSubMenu("Focus Modes");
        focusModes.add("Auto Focus").setCheckable(true);
        focusModes.add("Fixed Focus").setCheckable(true);
        focusModes.add("Infinity").setCheckable(true);
        focusModes.add("Macro Mode").setCheckable(true);
        
        return true;
    }
    
    public boolean onOptionsItemSelected(MenuItem item)
    {
        if(item.getTitle().equals("Toggle flash"))
        {
            mFlash = !mFlash;
            boolean result = toggleFlash(mFlash);
            DebugLog.LOGI("Toggle flash "+(mFlash?"ON":"OFF")+" "+(result?"WORKED":"FAILED")+"!!");
        }
        else if(item.getTitle().equals("Autofocus"))
        {
            boolean result = autofocus();
            DebugLog.LOGI("Autofocus requested"+(result?" successfully.":".  Not supported in current mode or on this device."));
        }
        else 
        {
            int arg = -1;
            if(item.getTitle().equals("Auto Focus"))
                arg = 0;
            if(item.getTitle().equals("Fixed Focus"))
                arg = 1;
            if(item.getTitle().equals("Infinity"))
                arg = 2;
            if(item.getTitle().equals("Macro Mode"))
                arg = 3;
            
            if(arg != -1)
            {
                item.setChecked(true);
                if(checked!= null)
                    checked.setChecked(false);
                checked = item;
                
                boolean result = setFocusMode(arg);
                
                DebugLog.LOGI("Requested Focus mode "+item.getTitle()+(result?" successfully.":".  Not supported on this device."));
            }
        }
        
        return true;
    }
    
    private MenuItem checked;
    private boolean mFlash = false;
    private native boolean toggleFlash(boolean flash);
    private native boolean autofocus();
    private native boolean setFocusMode(int mode);

    public int getTextureCount()
    {
        return mTextures.size();
    }

    public Texture getTexture(int i)
    {
        return mTextures.elementAt(i);
    }
    public static boolean loadLibrary(String nLibName)
    {
        try
        {
            System.loadLibrary(nLibName);
            DebugLog.LOGI("Native library lib" + nLibName + ".so loaded");
            return true;
        }
        catch (UnsatisfiedLinkError ulee)
        {
            DebugLog.LOGE("The library lib" + nLibName +
                            ".so could not be loaded");
        }
        catch (SecurityException se)
        {
            DebugLog.LOGE("The library lib" + nLibName +
                            ".so was not allowed to be loaded");
        }
        
        return false;
    }    
}
