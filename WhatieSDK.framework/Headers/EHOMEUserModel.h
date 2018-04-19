//
//  EHOMEUserModel.h
//  WhatieSDK
//
//  Created by IIDreams on 2018/4/13.
//  Copyright © 2018年 IIDreams. All rights reserved.
//

#import "EHOMEBaseObject.h"

@class EHOMEPhotoModel;

@interface EHOMEUserModel : EHOMEBaseObject

#pragma mark - Property of UserModel

/**
 The unique ID of user, called userId.
 It's very important.And it is used everywhere.
 */
@property (nonatomic, assign) int id;

/**
 The email of user,which can login in app with password together
 such as:zhouwei2015@whut.edu.cn
 */
@property (nonatomic, copy) NSString *email;

/** Gender of user. */
@property (nonatomic, copy) NSString *gender;

/** Name of user. */
@property (nonatomic, copy) NSString *name;

/** Phone Number of user. */
@property (nonatomic, copy) NSString *phone;

/**
 Portrait of user.
 Get the web image's url by portrait.path
 */
@property (nonatomic, strong) EHOMEPhotoModel *portrait;

/**
 Thumb portrait of user.
 Get the web image's url by portraitThumb.path
 */
@property (nonatomic, strong) EHOMEPhotoModel *portraitThumb;

/**
 The topic of user used in MQTT.
 Subscribe topic with this topic.
 */
@property (nonatomic, copy) NSString *topic;

/** The time of user register.such as:1522487366000 */
@property (nonatomic, assign) long long createTime;

/** The time of latest login.such as:1523599236000 */
@property (nonatomic, assign) long long updateTime;


#pragma mark - Functions

/**
 isLogin
 
 The BOOL value returns.
 If user has been logged in,return YES,else return NO.
 */
+(BOOL)isLogin;

/**
 GetCurrentUser
 
 Get current user info after login.And the data will be EHOMEUserModel.
 */
+(EHOMEUserModel *)getCurrentUser;

/**
 RemoveCurrentUser
 
 Remove the user info.
 After do this,user should login again.
 */
+(void)removeCurrentUser;

/**
 SetCurrentUser
 
 The latest user info should be updated in cache.
 
 @param userModel : mode of user info
 */
+(void)setCurrentUserWithUserModel:(EHOMEUserModel *)userModel;

/**
 SendVerifyCodeToSinUp
 
 When sign up first,It will send a PIN to user's email.
 
 @param email : eamil for signing up
 */
+(void)sendVerifyCodeToSinUpWithEmail:(NSString *)email
                           startBlock:(startBlock)startblock
                         successBlock:(successBlock)successblock
                           faileBlock:(faileBlock)faileblock;

/**
 CheckVerifyCode
 
 After key PIN,check wether it is available.
 
 @param email : email for checking PIN
 @param code : PIN for checking PIN
 */
+(void)checkVerifyCodeWithEmail:(NSString *)email
                           code:(NSString *)code
                     startBlock:(startBlock)startblock
                   successBlock:(successBlock)successblock
                     faileBlock:(faileBlock)faileblock;

/**
 SetPassword
 
 After Sign up,set the login password.
 
 @param email : email for setting password
 @param password : password for setting password
 */
+(void)setPasswordWithEmail:(NSString *)email
                   password:(NSString *)password
                 startBlock:(startBlock)startblock
               successBlock:(successBlock)successblock
                 faileBlock:(faileBlock)faileblock;

/**
 Login with Email
 
 @param email : the account to login in.
 @param password : the password to login in, it has been encrypted by MD5
 
 @blocks :
 The startblock means function has been begining,you can add some loading action here.
 The values will be returned as successblock if success.
 The error info will be also returned as faileblock if failed.
 */
+(void)loginWithEmail:(NSString *)email
             password:(NSString *)password
           startBlock:(startBlock)startblock
         successBlock:(successBlock)successblock
           faileBlock:(faileBlock)faileblock;

/**
 SendVerifyCodeToFindPassword
 
 When forget password,It will send a PIN to user's email.
 
 @param email : eamil of user
 */
+(void)sendVerifyCodeToFindPasswordWithEmail:(NSString *)email
                                  startBlock:(startBlock)startblock
                                successBlock:(successBlock)successblock
                                  faileBlock:(faileBlock)faileblock;

/**
 SetNewPasswordByOldPassword
 
 Change login password with old password if user remembers.
 
 @param email : eamil of user
 @param oldPassword : old password if user remembers
 @param newPassword : new password for signing in
 */
+(void)setNewPasswordByOldPasswordWithEmail:(NSString *)email
                                oldPassword:(NSString *)oldPassword
                                newPassword:(NSString *)newPassword
                                 startBlock:(startBlock)startblock
                               successBlock:(successBlock)successblock
                                 faileBlock:(faileBlock)faileblock;

/**
 Logout
 
 If user want to logout,do this.
 */
+(void)logoutWithStartBlock:(startBlock)startblock
               successBlock:(successBlock)successblock
                 faileBlock:(faileBlock)faileblock;


/**
 GetUserInfo
 
 If user isLogin,you can get user detail info with this way.
 */
+(void)getUserInfoWithStartBlock:(startBlock)startblock
                successBlock:(successBlock)successblock
                  faileBlock:(faileBlock)faileblock;

/**
 UpdateUserName
 
 If user want to change name,such as nickName.key new name just.
 */
+(void)updateUserNameWithName:(NSString *)name
                   startBlock:(startBlock)startblock
                 successBlock:(successBlock)successblock
                   faileBlock:(faileBlock)faileblock;

/**
 UpdateUserPortrait
 
 If user want to change portrait,do this,input an image as UIImage.
 */
+(void)updateUserPortraitWithImage:(UIImage *)image
                        startBlock:(startBlock)startblock
                      successBlock:(successBlock)successblock
                        faileBlock:(faileBlock)faileblock;


@end

@interface EHOMEPhotoModel : EHOMEBaseObject

@property (nonatomic, assign) int id;// = 237;
/** path, ex. https://files.d9lab.net/group1/M00/00/04/wKgA0lrQR4OAWKF5AASTFFSVQT4185.jpg */
@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, assign) long long createTime;

@end