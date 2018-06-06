//
//  EHOMEAddFeedbackViewController.m
//  WhatieSDKDemo
//
//  Created by IIDreams_zhouwei on 2018/6/6.
//  Copyright © 2018年 IIDreams. All rights reserved.
//

#import "EHOMEAddFeedbackViewController.h"

@interface EHOMEAddFeedbackViewController ()

@property (weak, nonatomic) IBOutlet UITextView *textView;

@end

@implementation EHOMEAddFeedbackViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.title = @"Add Feedback";
    
    UIBarButtonItem *addFeedbackItem = [[UIBarButtonItem alloc] initWithTitle:@"Done" style:UIBarButtonItemStylePlain target:self action:@selector(addFeedback)];
    self.navigationItem.rightBarButtonItem = addFeedbackItem;
    
}

-(void)addFeedback{
    
    NSString *feedback = self.textView.text;
    
    if ([feedback isEqualToString:@"Feedback..."] || feedback.length == 0) {
        [HUDHelper addHUDInView:sharedKeyWindow text:@"Please enter feedback." hideAfterDelay:1.0];
    }else{
        [[EHOMEUserModel shareInstance] addFeedback:feedback success:^(id responseObject) {
            NSLog(@"Add feedback success. res = %@", responseObject);
            
            [HUDHelper addHUDInView:sharedKeyWindow text:@"Feedback success" hideAfterDelay:1.0];
            
            [self.navigationController popViewControllerAnimated:YES];
            
        } failure:^(NSError *error) {
            NSLog(@"Add feedback failed. error = %@", error);
        }];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



@end
