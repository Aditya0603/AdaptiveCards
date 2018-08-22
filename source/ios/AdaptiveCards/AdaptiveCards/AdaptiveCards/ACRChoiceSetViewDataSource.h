//
//  ACRChoiceSetViewDataSource
//  ACRChoiceSetViewDataSource.h
//
//  Copyright © 2018 Microsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ChoiceInput.h"
#import "ChoiceSetInput.h"
#import "ACRIBaseInputHandler.h"
#import "HostConfig.h"
#import "ACRChoiceSetResourceDelegate.h"

@interface ACRChoiceSetViewDataSource:NSObject<UITableViewDataSource, UITableViewDelegate, ACRIBaseInputHandler>
@property NSString *id;
@property BOOL isMultiChoicesAllowed;
@property (weak) id<ACRChoiceSetResourceDelegate> acrChoiceSetResourceDelegate;

- (instancetype)initWithInputChoiceSet:(std::shared_ptr<AdaptiveCards::ChoiceSetInput> const&)choiceSet;

- (void)getDefaultInput:(NSMutableDictionary *)dictionary;

- (NSString *)getTitlesOfChoices;

@end
