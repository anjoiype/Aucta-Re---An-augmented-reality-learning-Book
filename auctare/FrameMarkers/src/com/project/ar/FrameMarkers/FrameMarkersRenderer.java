


package com.project.ar.FrameMarkers;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;

import com.qualcomm.QCAR.QCAR;

public class FrameMarkersRenderer implements GLSurfaceView.Renderer
{
    public boolean mIsActive = false;
    public native void initRendering();
    public native void updateRendering(int width, int height);

    public void onSurfaceCreated(GL10 gl, EGLConfig config)
    {
        DebugLog.LOGD("GLRenderer::onSurfaceCreated");
        initRendering();
        QCAR.onSurfaceCreated();
    }
    
    public void onSurfaceChanged(GL10 gl, int width, int height)
    {
        DebugLog.LOGD("GLRenderer::onSurfaceChanged");
        updateRendering(width, height);
        QCAR.onSurfaceChanged(width, height);
    }    
    
    public native void renderFrame();
    public void onDrawFrame(GL10 gl)
    {
        if (!mIsActive)
            return;
        renderFrame();
    }
}
