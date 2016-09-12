//
//  VunglePubAd.m
//  hello1
//
//  Created by Vincent.yao on 9/9/16.
//
//

#import "VunglePubAd.h"

bool VunglePubAd::isAdPlayable()
{
    // Play a Vungle ad (with default options)
    VungleSDK* sdk = [VungleSDK sharedSDK];
    return [sdk isAdPlayable];
}
void VunglePubAd::showAd()
{
    // Play a Vungle ad (with default options)
    VungleSDK* sdk = [VungleSDK sharedSDK];
    
    NSError *error;
    UIViewController *rootController=[[[[UIApplication sharedApplication]delegate] window] rootViewController];
    [sdk playAd:rootController error:&error];
    if (error) {
        NSLog(@"Error encountered playing ad: %@", error);
    }
}

// Play a Vungle ad (with customized options)
void VunglePubAd::showAdWithOptions()
{
    // Grab instance of Vungle SDK
    VungleSDK* sdk = [VungleSDK sharedSDK];
    
    // Dict to set custom ad options
    NSDictionary* options = @{VunglePlayAdOptionKeyOrientations: @(UIInterfaceOrientationMaskLandscape),
                              VunglePlayAdOptionKeyUser: @"user",
                              VunglePlayAdOptionKeyPlacement: @"StoreFront",
                              // Use this to keep track of metrics about your users
                              VunglePlayAdOptionKeyExtraInfoDictionary: @{VunglePlayAdOptionKeyExtra1: @"21",
                                                                          VunglePlayAdOptionKeyExtra2: @"Female"}};
    
    // Pass in dict of options, play ad
    NSError *error;
    UIViewController *rootController=[[[[UIApplication sharedApplication]delegate] window] rootViewController];
    [sdk playAd:rootController withOptions:options error:&error];
    if (error) {
        NSLog(@"Error encountered playing ad: %@", error);
    }
}

void VunglePubAd::showIncentivizedAd(){
    // Grab instance of Vungle SDK
    VungleSDK* sdk = [VungleSDK sharedSDK];
    
    // Dict to set custom ad options
    NSDictionary* options = @{VunglePlayAdOptionKeyIncentivized: @YES,
                              VunglePlayAdOptionKeyIncentivizedAlertBodyText : @"If the video isn't completed you won't get your reward! Are you sure you want to close early?",
                              VunglePlayAdOptionKeyIncentivizedAlertCloseButtonText : @"Close",
                              VunglePlayAdOptionKeyIncentivizedAlertContinueButtonText : @"Keep Watching",
                              VunglePlayAdOptionKeyIncentivizedAlertTitleText : @"Careful!"};
    
    // Pass in dict of options, play ad
    NSError *error;
    UIViewController *rootController=[[[[UIApplication sharedApplication]delegate] window] rootViewController];
    [sdk playAd:rootController withOptions:options error:&error];
    if (error) {
        NSLog(@"Error encountered playing ad: %@", error);
    }
}
