//
//  ACRUILable.h
//  AdaptiveCards
//
//  Copyright © 2018 Microsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ACOBaseCardElement.h"

const NSInteger eACRUILabelTag = 0x1234;
const NSInteger eACRUIFactSetTag = 0x1235;
const NSInteger eACRUIImageTag = 0x1236;

@interface ACRUILabel:UITextView

@property ACRContainerStyle style;
@property BOOL isFactSetLabel;
@property BOOL isTitle;
@property BOOL isStretchable;
@property CGFloat area;
@end
