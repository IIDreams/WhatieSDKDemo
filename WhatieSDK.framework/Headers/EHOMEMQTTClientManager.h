//
//  EHOMEMQTTClientManager.h
//  WhatieSDK
//
//  Created by IIDreams on 2018/4/14.
//  Copyright © 2018年 IIDreams. All rights reserved.
//



#import "EHOMEBaseObject.h"
#import "EHOMEDeviceModel.h"

@protocol MQTTDelegate <NSObject>

@optional
-(void)didRecivedMQTTData:(NSData *)data;

@end

typedef void(^MQTTBlock)(NSData *data);
typedef void(^MQTTStatusBlock)(NSString *status);

@interface EHOMEMQTTClientManager : EHOMEBaseObject

@property (nonatomic, assign) id <MQTTDelegate> delegate;


@property (nonatomic, copy) MQTTBlock mqttBlock;
@property (nonatomic, copy) MQTTStatusBlock mqttStatusBlock;

/**
 instance
 
 @return self
 */
+(EHOMEMQTTClientManager *)shareInstance;

/**
 loginMQTT
 
 MQTT Login，and subscription topic of user
 */
-(void)loginMQTT;


-(void)switchDeviceStatusWithDeviceModel:(EHOMEDeviceModel *)deviceModel
                                  status:(BOOL)status
                              startBlock:(startBlock)startblock
                            successBlock:(successBlock)successblock
                               failBlock:(failBlock)failblock;


/**
 publish
 
 publish data to topic
 */
-(void)publishAndWaitData:(NSData *)data;


/**
 close
 
 close the connection of mqttSession
 */
-(void)close;


@end