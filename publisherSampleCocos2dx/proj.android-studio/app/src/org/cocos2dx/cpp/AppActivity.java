/****************************************************************************
Copyright (c) 2015 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import android.app.Activity;
import android.os.Bundle;

import com.vungle.publisher.EventListener;
import com.vungle.publisher.VunglePub;

import org.cocos2dx.lib.Cocos2dxActivity;

public class AppActivity extends Cocos2dxActivity {
    final VunglePub vunglePub = VunglePub.getInstance();
    public static native void onAdStartCppFunction();
    public static native void onAdEndCppFunction();
    public static native void onAdPlayableChangedCppFunction(boolean isAdPlayable);
    public static native void onAdUnavailableCppFunction();
    public static Activity _activiy;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        _activiy = this;
        //初始化Vungle SDK
        final String app_id = "Test_Android";
        vunglePub.init(this, app_id);
        vunglePub.setEventListeners(vungleListener);
        System.out.println("init Vungle SDK");
    }

    @Override
    protected void onPause() {
        super.onPause();
        vunglePub.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        vunglePub.onResume();
    }
    @Override
    public void onDestroy() {
        super.onDestroy();
        vunglePub.clearEventListeners();

    };

    private final EventListener vungleListener = new EventListener(){

        @Deprecated
        @Override
        public void onVideoView(boolean isCompletedView, int watchedMillis, int videoDurationMillis) {
            // This method is deprecated and will be removed. Please do not use it.
            // Please use onAdEnd instead.
        }

        @Override
        public void onAdStart() {
            // Called before playing an ad
            System.out.println("onAdStart");
            onAdStartCppFunction();
        }

        @Override
        public void onAdEnd(boolean wasSuccessfulView, boolean wasCallToActionClicked) {
            // Called when the user leaves the ad and control is returned to your application
            // if wasSuccessfulView is true, the user watched the ad and should be rewarded
            // (if this was a rewarded ad).
            // if wasCallToActionClicked is true, the user clicked the call to action
            // button in the ad.
            System.out.println("onAdEnd");
            onAdEndCppFunction();
        }

        @Override
        public void onAdPlayableChanged(boolean isAdPlayable) {
            // Called when the playability state changes. if isAdPlayable is true, you can now
            // play an ad.
            // If false, you cannot yet play an ad.
            System.out.println("onAdPlayableChanged");
            onAdPlayableChangedCppFunction(isAdPlayable);
        }

        @Override
        public void onAdUnavailable(String reason) {
            // Called when VunglePub.playAd() was called, but no ad was available to play
            System.out.println("onAdUnavailable");
            onAdUnavailableCppFunction();
        }

    };

}
