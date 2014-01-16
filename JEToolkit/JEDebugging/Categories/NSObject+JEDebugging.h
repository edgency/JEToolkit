//
//  NSObject+JEDebugging.h
//  JEToolkit
//
//  Created by John Rommel Estropia on 2013/11/26.
//  Copyright (c) 2013 John Rommel Estropia. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (JEDebugging)

/*! Convenience method equivalent to [self detailedDescriptionIncludeClass:YES includeAddress:YES].
 */
- (NSMutableString *)detailedDescription;

/*! Returns a string with detailed information about the receiver. 
 The return type is @p NSMutableString so callers can freely manipulate the string if needed (for indenting, etc.).
 Subclasses may override this method directly or with categories.
 */
- (NSMutableString *)detailedDescriptionIncludeClass:(BOOL)includeClass
                                      includeAddress:(BOOL)includeAddress;

/*! Subclasses that override detailedDescriptionIncludeClass:includeAddress: may use this method to create the initial NSMutableString.
 */
- (NSMutableString *)stringBuilderForDetailedDescriptionIncludeClass:(BOOL)includeClass
                                                      includeAddress:(BOOL)includeAddress;

@end
