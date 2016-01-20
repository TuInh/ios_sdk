//
//  ADJActivityHandler.h
//  Adjust
//
//  Created by Christian Wellenbrock on 2013-07-01.
//  Copyright (c) 2013 adjust GmbH. All rights reserved.
//

#import "Adjust.h"
#import "ADJResponseData.h"

@protocol ADJActivityHandler <NSObject>

- (id)initWithConfig:(ADJConfig *)adjustConfig;

- (void)trackSubsessionStart;
- (void)trackSubsessionEnd;

- (void)trackEvent:(ADJEvent *)event;

- (void)finishedTracking:(ADJResponseData *)responseData;
- (void)launchResponseTasks:(ADJResponseData *)responseData;
- (void)launchAttributionTasks:(ADJResponseData *)responseData;
- (void)setEnabled:(BOOL)enabled;
- (BOOL)isEnabled;
- (void)appWillOpenUrl:(NSURL*)url;
- (void)setDeviceToken:(NSData *)deviceToken;

- (ADJAttribution*) attribution;
- (void)setAttribution:(ADJAttribution*)attribution;
- (void)setAskingAttribution:(BOOL)askingAttribution;

- (SEL)updateAttribution:(ADJAttribution *)attribution;
- (void)setIadDate:(NSDate*)iAdImpressionDate withPurchaseDate:(NSDate*)appPurchaseDate;
- (void)setIadDetails:(NSDictionary *)attributionDetails
                error:(NSError *)error
          retriesLeft:(int)retriesLeft;

- (void) setOfflineMode:(BOOL)offline;

@end

@interface ADJActivityHandler : NSObject <ADJActivityHandler>

+ (id<ADJActivityHandler>)handlerWithConfig:(ADJConfig *)adjustConfig;

@end
