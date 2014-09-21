


#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <QCAR/QCAR.h>
#include <QCAR/CameraDevice.h>
#include <QCAR/Renderer.h>
#include <QCAR/VideoBackgroundConfig.h>
#include <QCAR/Trackable.h>
#include <QCAR/Tool.h>
#include <QCAR/Tracker.h>
#include <QCAR/CameraCalibration.h>
#include <QCAR/Marker.h>

#include "SampleUtils.h"
#include "Texture.h"
#include "CubeShaders.h"

#include "a.h"
#include "u.h"
#include "c.h"
#include "t.h"
#include "r.h"
#include "e.h"
#include "banana.h"
#include "Teapot.h"
#include "rhino.h"
#include "heart.h"
#include "earth.h"
#include "saturn.h"
#include "ribs.h"
#include "liver.h"




#ifdef __cplusplus
extern "C"
{
#endif

int textureCount                = 0;
Texture** textures              = 0;
unsigned int shaderProgramID    = 0;
GLint vertexHandle              = 0;
GLint normalHandle              = 0;
GLint textureCoordHandle        = 0;
GLint mvpMatrixHandle           = 0;

unsigned int screenWidth        = 0;
unsigned int screenHeight       = 0;
bool isActivityInPortraitMode   = false;
QCAR::Matrix44F projectionMatrix;






JNIEXPORT void JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkers_setActivityPortraitMode(JNIEnv *, jobject, jboolean isPortrait)
{
    isActivityInPortraitMode = isPortrait;
}


JNIEXPORT void JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkersRenderer_renderFrame(JNIEnv *, jobject)
{
    //LOG("Java_com_project_ar_FrameMarkers_GLRenderer_renderFrame");
 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    QCAR::State state = QCAR::Renderer::getInstance().begin();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    for(int tIdx = 0; tIdx < state.getNumActiveTrackables(); tIdx++)
    {
        const QCAR::Trackable* trackable = state.getActiveTrackable(tIdx);
        QCAR::Matrix44F modelViewMatrix =
            QCAR::Tool::convertPose2GLMatrix(trackable->getPose());        
        int textureIndex = 0;
        assert(trackable->getType() == QCAR::Trackable::MARKER);
        const QCAR::Marker* marker = static_cast<const QCAR::Marker*>(trackable);

        textureIndex = marker->getMarkerId();
        
        assert(textureIndex < textureCount);
        const Texture* const thisTexture = textures[textureIndex];

        const GLvoid* vertices = 0;
        const GLvoid* normals = 0;
        const GLvoid* indices = 0;
        const GLvoid* texCoords = 0;
        int numverts = 0;
        int numIndices = 0;
         float kObjectScale        = 50.0f;
                  float kObjectTranslate        = 0.0f;
         
         
         
       switch (marker->getMarkerId())
        {
        case 0:
         kObjectScale        = 50.0f;
        
            vertices = &aVerts[0];
            normals = &aNormals[0];
            numverts= 300;
            texCoords = &aTexCoords[0];
            
            break;
        case 1:
        kObjectScale        = 50.0f;
            vertices = &uVerts[0];
            normals = &uNormals[0];
            numverts= 984;
            texCoords = &uTexCoords[0];
            break;
        case 2:
       kObjectScale        = 50.0f;
            vertices = &cVerts[0];
            normals = &cNormals[0];
            numverts= 1692;
            texCoords = &cTexCoords[0];
            break;
            case 3:
           kObjectScale        = 50.0f;
            vertices = &tVerts[0];
            normals = &tNormals[0];
            numverts= 84;
            texCoords = &tTexCoords[0];
            break;
            
            case 4:
             kObjectScale        = 50.0f;
            
          
            vertices = &aVerts[0];
            normals = &aNormals[0];
            numverts= 300;
            texCoords = &aTexCoords[0];
            
            break;
            
            case 5:
          kObjectScale        = 50.0f;
            vertices = &rVerts[0];
            normals = &rNormals[0];
            numverts= 1476;
            texCoords = &rTexCoords[0];
            
            break;
            
              case 6:
          kObjectScale        = 50.0f;
            vertices = &eVerts[0];
            normals = &eNormals[0];
            numverts= 132;
            texCoords = &eTexCoords[0];
            
            break;
            
       
            case 7:
         kObjectScale        = 100.0f;
            vertices = &bananaVerts[0];
            normals = &bananaNormals[0];
            numverts= 24168;
            texCoords = &bananaTexCoords[0];
            break;
            
            
                       
            case 8:
        kObjectScale        = 3.0f;
         vertices = &teapotVertices[0];
            normals = &teapotNormals[0];
            indices = &teapotIndices[0];
            texCoords = &teapotTexCoords[0];
            numverts= 0;
            numIndices = NUM_TEAPOT_OBJECT_INDEX;
          break;
          
            case 9:
           kObjectScale = 200.0f;
            vertices = &rhinoVerts[0];
            normals = &rhinoNormals[0];
            numverts= 22362;
            texCoords = &rhinoTexCoords[0];
            numIndices=0;
            break;
          
          case 10:
           kObjectScale = 100.0f;
            vertices = &heartVerts[0];
            normals = &heartNormals[0];
            numverts= 44160;
            texCoords = &heartTexCoords[0];
            numIndices=0;
            break;
            
            case 11:
           kObjectScale = 150.0f;
           vertices = &earthVerts[0];
            normals = &earthNormals[0];
            numverts= 29400;
            texCoords = &earthTexCoords[0];
            numIndices=0;
            break;
            
            case 12:
           kObjectScale = 65.0f;
           vertices = &earthVerts[0];
            normals = &earthNormals[0];
            numverts= 29400;
            texCoords = &earthTexCoords[0];
            numIndices=0;
            break;
            
            case 13:
           kObjectScale = 50.0f;
           vertices = &earthVerts[0];
            normals = &earthNormals[0];
            numverts= 29400;
            texCoords = &earthTexCoords[0];
            numIndices=0;
            break;
      
      
      case 14:
           kObjectScale = 40.0f;
           vertices = &earthVerts[0];
            normals = &earthNormals[0];
            numverts= 29400;
            texCoords = &earthTexCoords[0];
            numIndices=0;
            break;
      
      case 15:
           kObjectScale = 30.0f;
           vertices = &earthVerts[0];
            normals = &earthNormals[0];
            numverts= 29400;
            texCoords = &earthTexCoords[0];
            numIndices=0;
            break;
            
            case 16:
           kObjectScale = 25.0f;
           vertices = &earthVerts[0];
            normals = &earthNormals[0];
            numverts= 29400;
            texCoords = &earthTexCoords[0];
            numIndices=0;
            break;
      
      case 17:
      
           kObjectScale = 20.0f;
           vertices = &earthVerts[0];
            normals = &earthNormals[0];
            numverts= 29400;
            texCoords = &earthTexCoords[0];
            numIndices=0;
            break;
            
              case 18:
      
           kObjectScale = 100.0f;
           vertices = &saturnVerts[0];
            normals = &saturnNormals[0];
            numverts= 11544;
            texCoords = &saturnTexCoords[0];
            numIndices=0;
            break;
     
      
      case 19:
      
           kObjectScale = 90.0f;
           vertices = &earthVerts[0];
            normals = &earthNormals[0];
            numverts= 29400;
            texCoords = &earthTexCoords[0];
            numIndices=0;
            break;
      
         case 20:
      
           kObjectScale = 40.0f;
           vertices = &ribsVerts[0];
           vertices = &ribsVerts[0];
            normals = &ribsNormals[0];
            numverts= 9744;
            texCoords = &ribsTexCoords[0];
            numIndices=0;
            break;
            
            
              case 21:
      
           kObjectScale = 30.0f;
           vertices = &earthVerts[0];
            normals = &earthNormals[0];
            numverts= 29400;
            texCoords = &earthTexCoords[0];
            numIndices=0;
            break;
      
      
       case 22:
      
           kObjectScale = 30.0f;
           vertices = &liverVerts[0];
            normals = &liverNormals[0];
            numverts= 16032;
            texCoords = &liverTexCoords[0];
            numIndices=0;
            break;
      
        }

       
         QCAR::Matrix44F modelViewProjection;
       
        SampleUtils::translatePoseMatrix(0.0f, 0.0f, kObjectScale,
                                         &modelViewMatrix.data[0]);
                                       
        SampleUtils::scalePoseMatrix(kObjectScale, kObjectScale, kObjectScale,
                                     &modelViewMatrix.data[0]);
        SampleUtils::multiplyMatrix(&projectionMatrix.data[0],
                                   &modelViewMatrix.data[0] , &modelViewProjection.data[0]);

        glUseProgram(shaderProgramID);
         
        glVertexAttribPointer(vertexHandle, 3, GL_FLOAT, GL_FALSE, 0,
                               vertices);
        glVertexAttribPointer(normalHandle, 3, GL_FLOAT, GL_FALSE, 0,
                               normals);
        glVertexAttribPointer(textureCoordHandle, 2, GL_FLOAT, GL_FALSE, 0,
                               texCoords);
        
        glEnableVertexAttribArray(vertexHandle);
        glEnableVertexAttribArray(normalHandle);
        glEnableVertexAttribArray(textureCoordHandle);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, thisTexture->mTextureID);
        glUniformMatrix4fv(mvpMatrixHandle, 1, GL_FALSE,
                           (GLfloat*)&modelViewProjection.data[0] );
      glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, indices);
      
      
      
      
                       glDrawArrays(GL_TRIANGLES, 0, numverts);
                       
        
        SampleUtils::checkGlError("FrameMarkers render frame");
        
        
        
       
       numIndices=0;               

        







    }

    glDisable(GL_DEPTH_TEST);
    glDisableVertexAttribArray(vertexHandle);
    glDisableVertexAttribArray(normalHandle);
    glDisableVertexAttribArray(textureCoordHandle);

    QCAR::Renderer::getInstance().end();
}


void
configureVideoBackground()
{
    QCAR::CameraDevice& cameraDevice = QCAR::CameraDevice::getInstance();
    QCAR::VideoMode videoMode = cameraDevice.
                                getVideoMode(QCAR::CameraDevice::MODE_DEFAULT);
    QCAR::VideoBackgroundConfig config;
    config.mEnabled = true;
    config.mSynchronous = true;
    config.mPosition.data[0] = 0.0f;
    config.mPosition.data[1] = 0.0f;
    
    if (isActivityInPortraitMode)
    {
        //LOG("configureVideoBackground PORTRAIT");
        config.mSize.data[0] = videoMode.mHeight
                                * (screenHeight / (float)videoMode.mWidth);
        config.mSize.data[1] = screenHeight;
    }
    else
    {
        //LOG("configureVideoBackground LANDSCAPE");
        config.mSize.data[0] = screenWidth;
        config.mSize.data[1] = videoMode.mHeight
                            * (screenWidth / (float)videoMode.mWidth);
    }

    QCAR::Renderer::getInstance().setVideoBackgroundConfig(config);
}


JNIEXPORT void JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkers_initApplicationNative(
                            JNIEnv* env, jobject obj, jint width, jint height)
{
    LOG("Java_com_project_ar_FrameMarkers_FrameMarkers_initApplicationNative");
    screenWidth = width;
    screenHeight = height;
  
    jclass activityClass = env->GetObjectClass(obj);

    jmethodID getTextureCountMethodID = env->GetMethodID(activityClass,
                                                    "getTextureCount", "()I");
    if (getTextureCountMethodID == 0)
    {
        LOG("Function getTextureCount() not found.");
        return;
    }

    textureCount = env->CallIntMethod(obj, getTextureCountMethodID);    
    if (!textureCount)
    {
        LOG("getTextureCount() returned zero.");
        return;
    }

    textures = new Texture*[textureCount];

    jmethodID getTextureMethodID = env->GetMethodID(activityClass,
        "getTexture", "(I)Lcom/project/ar/FrameMarkers/Texture;");

    if (getTextureMethodID == 0)
    {
        LOG("Function getTexture() not found.");
        return;
    }

    for (int i = 0; i < textureCount; ++i)
    {

        jobject textureObject = env->CallObjectMethod(obj, getTextureMethodID, i); 
        if (textureObject == NULL)
        {
            LOG("GetTexture() returned zero pointer");
            return;
        }

        textures[i] = Texture::create(env, textureObject);
    }
}


JNIEXPORT void JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkers_deinitApplicationNative(
                                                        JNIEnv* env, jobject obj)
{
    LOG("Java_com_project_ar_FrameMarkers_FrameMarkers_deinitApplicationNative");

    if (textures != 0)
    {    
        for (int i = 0; i < textureCount; ++i)
        {
            delete textures[i];
            textures[i] = NULL;
        }
    
        delete[]textures;
        textures = NULL;
        
        textureCount = 0;
    }
}


JNIEXPORT void JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkers_startCamera(JNIEnv *,jobject)
{
    LOG("Java_com_project_ar_FrameMarkers_FrameMarkers_startCamera");

    if (!QCAR::CameraDevice::getInstance().init())
        return;

    configureVideoBackground();

    if (!QCAR::CameraDevice::getInstance().selectVideoMode(QCAR::CameraDevice::MODE_DEFAULT))
        return;
    if (!QCAR::CameraDevice::getInstance().start())
        return;
    QCAR::Tracker::getInstance().start();
    
    const QCAR::Tracker& tracker = QCAR::Tracker::getInstance();
    const QCAR::CameraCalibration& cameraCalibration =
                                    tracker.getCameraCalibration();
    projectionMatrix = QCAR::Tool::getProjectionGL(cameraCalibration, 2.0f,
                                            2000.0f);
}


JNIEXPORT void JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkers_stopCamera(JNIEnv *,
                                                                   jobject)
{
    LOG("Java_com_project_ar_FrameMarkers_FrameMarkers_stopCamera");

    QCAR::Tracker::getInstance().stop();

    QCAR::CameraDevice::getInstance().stop();
    QCAR::CameraDevice::getInstance().deinit();
}

JNIEXPORT jboolean JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkers_toggleFlash(JNIEnv*, jobject, jboolean flash)
{
    return QCAR::CameraDevice::getInstance().setFlashTorchMode((flash==JNI_TRUE)) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkers_autofocus(JNIEnv*, jobject)
{
    return QCAR::CameraDevice::getInstance().startAutoFocus()?JNI_TRUE:JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkers_setFocusMode(JNIEnv*, jobject, jint mode)
{
    return QCAR::CameraDevice::getInstance().setFocusMode(mode)?JNI_TRUE:JNI_FALSE;
}


JNIEXPORT void JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkersRenderer_initRendering(
                                                    JNIEnv* env, jobject obj)
{
    LOG("Java_com_project_ar_FrameMarkers_FrameMarkersRenderer_initRendering");
    glClearColor(0.0f, 0.0f, 0.0f, QCAR::requiresAlpha() ? 0.0f : 1.0f);
    for (int i = 0; i < textureCount; ++i)
    {
        glGenTextures(1, &(textures[i]->mTextureID));
        glBindTexture(GL_TEXTURE_2D, textures[i]->mTextureID);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textures[i]->mWidth,
                textures[i]->mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                (GLvoid*)  textures[i]->mData);
    }
  
    shaderProgramID     = SampleUtils::createProgramFromBuffer(cubeMeshVertexShader,
                                                            cubeFragmentShader);

    vertexHandle        = glGetAttribLocation(shaderProgramID,
                                                "vertexPosition");
    normalHandle        = glGetAttribLocation(shaderProgramID,
                                                "vertexNormal");
    textureCoordHandle  = glGetAttribLocation(shaderProgramID,
                                                "vertexTexCoord");
    mvpMatrixHandle     = glGetUniformLocation(shaderProgramID,
                                                "modelViewProjectionMatrix");

}


JNIEXPORT void JNICALL
Java_com_project_ar_FrameMarkers_FrameMarkersRenderer_updateRendering(
                        JNIEnv* env, jobject obj, jint width, jint height)
{
    LOG("Java_com_project_ar_FrameMarkers_FrameMarkersRenderer_updateRendering");
    screenWidth = width;
    screenHeight = height;
    configureVideoBackground();
}


#ifdef __cplusplus
}
#endif
