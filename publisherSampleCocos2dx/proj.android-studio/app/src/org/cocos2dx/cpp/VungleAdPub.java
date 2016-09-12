package org.cocos2dx.cpp;

import com.vungle.publisher.AdConfig;
import com.vungle.publisher.Orientation;
import com.vungle.publisher.VunglePub;

/**
 * Created by vincent.yao on 9/5/16.
 */
public class VungleAdPub {


    private static boolean playAd() {
        System.out.println("________________play ad");
        VunglePub vunglePub = VunglePub.getInstance();
       //  播放广告（缓存视频需要时间，请勿初始化后直接播放视频）
        if(vunglePub.isAdPlayable()){
            System.out.println("________________got an ad to play");
            vunglePub.playAd();
            return true;
        }
        else{
            System.out.println("________________no ad cached");
            return false;
        }
    }


    private static boolean showAdWithOptions() {
        System.out.println("________________showAdWithOptions");
        VunglePub vunglePub = VunglePub.getInstance();

        // create a new AdConfig object
        final AdConfig overrideConfig = new AdConfig();
        // set any configuration options you like.
        overrideConfig.setOrientation(Orientation.matchVideo);
        overrideConfig.setSoundEnabled(false);
        overrideConfig.setBackButtonImmediatelyEnabled(false);
        overrideConfig.setPlacement("StoreFront");
        //overrideConfig.setExtra1("LaunchedFromNotification");

        //  播放广告（缓存视频需要时间，请勿初始化后直接播放视频）
        if(vunglePub.isAdPlayable()){
            System.out.println("________________got an ad to play");
            // the overrideConfig object will only affect this ad play.
            vunglePub.playAd(overrideConfig);
            return true;
        }
        else{
            System.out.println("________________no ad cached");
            return false;
        }
    }

    private static boolean showIncentivizedAd() {
        System.out.println("________________showIncentivizedAd");
        VunglePub vunglePub = VunglePub.getInstance();

        // create a new AdConfig object
        final AdConfig overrideConfig = new AdConfig();
        // set incentivized option on
        overrideConfig.setIncentivized(true);
        overrideConfig.setIncentivizedCancelDialogTitle("Careful!");
        overrideConfig.setIncentivizedCancelDialogBodyText("If the video isn't completed you won't get your reward! Are you sure you want to close early?");
        overrideConfig.setIncentivizedCancelDialogCloseButtonText("Close");
        overrideConfig.setIncentivizedCancelDialogKeepWatchingButtonText("Keep Watching");

        overrideConfig.setIncentivizedUserId("vincentAtIncentivized");

        //  播放广告（缓存视频需要时间，请勿初始化后直接播放视频）
        if(vunglePub.isAdPlayable()){
            System.out.println("________________got an ad to play");
            // the overrideConfig object will only affect this ad play.
            vunglePub.playAd(overrideConfig);
            return true;
        }
        else{
            System.out.println("________________no ad cached");
            return false;
        }
    }
}
