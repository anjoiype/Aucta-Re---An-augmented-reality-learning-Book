
package com.project.ar.FrameMarkers;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;

import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;


public class Texture
{
    public int mWidth;     
    public int mHeight;    
    public int mChannels;   
    public byte[] mData;    
    
    public byte[] getData()
    {
        return mData;
    }    
    
    public static Texture loadTextureFromApk(String fileName,
                                                AssetManager assets)
    {
        InputStream inputStream = null;
        try
        {
            inputStream = assets.open(fileName, AssetManager.ACCESS_BUFFER);
             
            BufferedInputStream bufferedStream = new BufferedInputStream(inputStream);
            Bitmap bitMap = BitmapFactory.decodeStream(bufferedStream);
            
            int[] data = new int[bitMap.getWidth() * bitMap.getHeight()];
            bitMap.getPixels(data, 0, bitMap.getWidth(), 0, 0,
                                bitMap.getWidth(), bitMap.getHeight());
            
            
            byte[] dataBytes = new byte[bitMap.getWidth() *
                                       bitMap.getHeight() * 4];
            for (int p = 0; p < bitMap.getWidth() * bitMap.getHeight(); ++p)
            {
                int colour = data[p];
                dataBytes[p * 4]        = (byte)(colour >>> 16);    // R
                dataBytes[p * 4 + 1]    = (byte)(colour >>> 8);     // G
                dataBytes[p * 4 + 2]    = (byte) colour;            // B
                dataBytes[p * 4 + 3]    = (byte)(colour >>> 24);    // A
            }
            
            Texture texture = new Texture();
            texture.mWidth      = bitMap.getWidth();
            texture.mHeight     = bitMap.getHeight();
            texture.mChannels   = 4;
            texture.mData       = dataBytes;
            
            return texture;
        }
        catch (IOException e)
        {
            DebugLog.LOGE("Failed to log texture '" + fileName + "' from APK.");
            DebugLog.LOGI(e.getMessage());
            return null;
        }
    }

}
