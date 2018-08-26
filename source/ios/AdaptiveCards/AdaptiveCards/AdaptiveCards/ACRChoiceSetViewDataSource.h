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

extern NSString *checkedCheckboxReuseID;
extern NSString *uncheckedCheckboxReuseID;
extern NSString *checkedRadioButtonReuseID;
extern NSString *uncheckedRadioButtonReuseID;

@interface ACRChoiceSetCell : UITableViewCell
@property (weak) id<ACRChoiceSetResourceDelegate> acrChoiceSetResourceDelegate;
- (void) setUpCellWithReuseIdentifier:(NSString *)reuseIdentifier;
@end

@interface ACRChoiceSetViewDataSource:NSObject<UITableViewDataSource, UITableViewDelegate, ACRIBaseInputHandler>
@property NSString *id;
@property BOOL isMultiChoicesAllowed;
@property (weak) id<ACRChoiceSetResourceDelegate> acrChoiceSetResourceDelegate;

- (instancetype)initWithInputChoiceSet:(std::shared_ptr<AdaptiveCards::ChoiceSetInput> const&)choiceSet;

- (void)getDefaultInput:(NSMutableDictionary *)dictionary;

- (NSString *)getTitlesOfChoices;

@end
