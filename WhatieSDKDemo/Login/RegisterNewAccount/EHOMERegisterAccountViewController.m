//
//  EHOMERegisterAccountViewController.m
//  WhatieSDKDemo
//
//  Created by IIDreams_zhouwei on 2018/6/7.
//  Copyright © 2018年 IIDreams. All rights reserved.
//

#import "EHOMERegisterAccountViewController.h"

@interface EHOMERegisterAccountViewController ()

@property (weak, nonatomic) IBOutlet UILabel *signupLabel;
@property (weak, nonatomic) IBOutlet UILabel *signupLabel1;
@property (weak, nonatomic) IBOutlet UILabel *emailLabel;
@property (weak, nonatomic) IBOutlet UILabel *pswLabel;
    
@property (weak, nonatomic) IBOutlet UITextField *emailTextField;
@property (weak, nonatomic) IBOutlet UITextField *passwordTextField;
@property (weak, nonatomic) IBOutlet UIButton *ResetBtn;

- (IBAction)registerAccount:(id)sender;

@end

@implementation EHOMERegisterAccountViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.title = NSLocalizedString(@"Register", nil);
    
    UIBarButtonItem *cancelItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedStringFromTable(@"Cancel", @"Info", nil) style:UIBarButtonItemStylePlain target:self action:@selector(dismissVC)];
    self.navigationItem.leftBarButtonItem = cancelItem;
    
    self.signupLabel.text = NSLocalizedString(@"Sign up", nil);
    self.signupLabel1.text = NSLocalizedString(@"email and password", nil);
    self.emailLabel.text = NSLocalizedStringFromTable(@"Email", @"Info", nil);
    self.pswLabel.text = NSLocalizedString(@"Password", nil);
    self.emailTextField.placeholder = NSLocalizedStringFromTable(@"Email", @"Info", nil);
    self.passwordTextField.placeholder = NSLocalizedString(@"Password", nil);
    [self.ResetBtn setTitle:NSLocalizedString(@"Register", nil) forState:UIControlStateNormal];
    self.ResetBtn.backgroundColor=THEMECOLOR;
}

-(void)dismissVC{
    
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



- (IBAction)registerAccount:(id)sender {
    
    [self.emailTextField resignFirstResponder];
    [self.passwordTextField resignFirstResponder];
    
    NSString *email = self.emailTextField.text;
    NSString *password = self.passwordTextField.text;
    
    if (email.length > 0 && [email containsString:@"@"] && password.length > 0) {
        [[EHOMEUserModel shareInstance] registerByEmail:email password:password success:^(id responseObject) {
            NSLog(@"register success");
            
            [self dismissVC];
            
        } failure:^(NSError *error) {
            NSLog(@"register failed");
        }];
    }else{
        [HUDHelper addHUDInView:sharedKeyWindow text:NSLocalizedString(@"check", nil) hideAfterDelay:1.0];
    }
    

    
}
@end
