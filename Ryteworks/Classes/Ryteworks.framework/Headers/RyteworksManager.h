//
//  RyteworksManager.h
//  ryteworks
//
//  Created by Guruprasath on 11/11/1938 Saka.
//  Copyright © 1938 Saka Zucite. All rights reserved.
//

#import <Foundation/Foundation.h>


@class RyteworksManager;
@protocol RyteworksManagerDelegate <NSObject>
@optional
- (void)requestLog: (NSDictionary*)sentMessage;
- (void)responseLog: (NSDictionary*)receivedMessage;
@end


@interface RyteworksManager : NSObject
+ (id)sharedInstance;

- (void)setUpConfiguration;
- (void)initWithUserId: (NSString *)userId andTokenString: (NSString *)tokenString;
- (void)setUserId: (NSString *)userId;
- (void)setFCMToken: (NSString *)fcmToken;
- (void)startRyteworks;
- (void)stopRyteworks;
- (void)didReceivedNotification: (NSString *)notificationId;
- (void)didReadNotification: (NSString *)notificationId;
- (void)clearNotification;
- (void)performQRCodeScanning;
- (void)retriveListOfNotification: (NSInteger)numberOfDays successBlock: (void (^)(id responseObject))response;
- (NSDate*)lastBeaconSentTime;

- (void)awakeFromLocationService;
@property(assign, nonatomic) id<RyteworksManagerDelegate> delegate;

@property (readonly) BOOL ryteworksStatus;




@end
