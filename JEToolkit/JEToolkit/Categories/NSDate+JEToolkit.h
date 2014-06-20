//
//  NSDate+JEToolkit.h
//  JEToolkit
//
//  Created by John Rommel Estropia on 2013/09/14.
//  Copyright (c) 2013 John Rommel Estropia. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "JECompilerDefines.h"


@interface NSDate (JEToolkit)

#pragma mark - Conversion

/*! Extracts a date from the given value.
 @param valueOrNil The object to extract date from. Accepts nil, NSDate, a Unix timestamp NSNumber, or an ISO 8601 formatted UTC NSString
 @return valueOrNil if it is an NSDate, date representatin of a Unix timestamp NSNumber, the date from an ISO 8601 formatted UTC NSString, or nil otherwise.
 */
+ (NSDate *)dateWithValue:(id)valueOrNil;

/*! Returns an NSDate from an ISO 8601 UTC formatted date (ex: 2013-03-20T15:30:20Z), or nil if conversion fails. Note: only supports UTC
 */
+ (NSDate *)dateWithISO8601String:(NSString *)ISO8601String JE_NONNULL_ALL;

/*! Returns an NSDate from an EXIF formatted date (ex: 2013:03:20 15:30:20), or nil if conversion fails. Note: only supports UTC
 */
+ (NSDate *)dateWithEXIFString:(NSString *)EXIFString JE_NONNULL_ALL;

/*! Returns the ISO 8601 UTC date format (ex: 2013-03-20T15:30:20Z) for the receiver
 */
- (NSString *)ISO8601String;

/*! Returns the EXIF date format (ex: 2013:03:20 15:30:20) for the receiver
 */
- (NSString *)EXIFString;


@end