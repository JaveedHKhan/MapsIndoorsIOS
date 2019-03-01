//
//  UIButton+AppButton.h
//  MIAIOS
//
//  Created by Daniel Nielsen on 26/08/15.
//  Copyright (c) 2015-2018 MapsPeople A/S. All rights reserved.
//

#import <UIKit/UIKit.h>
@import MaterialControls;

@interface UIButton (AppButton)

+ (MDButton *)appRectButtonWithTitle: (NSString*)title target: (id)target selector:(SEL)selector;
+ (MDButton *)appRectButtonWithTitle: (NSString*)title target: (id)target selector:(SEL)selector xOffset:(int)x;

@end
