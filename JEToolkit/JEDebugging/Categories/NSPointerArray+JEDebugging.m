//
//  NSPointerArray+JEDebugging.m
//  JEToolkit
//
//  Created by John Rommel Estropia on 2013/11/26.
//  Copyright (c) 2013 John Rommel Estropia. All rights reserved.
//

#import "NSPointerArray+JEDebugging.h"

#import "NSMutableString+JEDebugging.h"


@implementation NSPointerArray (JEDebugging)

#pragma mark - NSObject+JEDebugging

- (NSMutableString *)detailedDescriptionIncludeClass:(BOOL)includeClass
                                      includeAddress:(BOOL)includeAddress
{
    NSMutableString *description = [self
                                    stringBuilderForDetailedDescriptionIncludeClass:includeClass
                                    includeAddress:includeAddress];
    NSUInteger count = [self count];
    if (count == 1)
    {
        [description appendString:@"1 entry ["];
    }
    else
    {
        [description appendFormat:@"%lu entries [", (unsigned long)count];
        
        if (count <= 0)
        {
            [description appendString:@"]"];
            return description;
        }
    }
    
    for (NSInteger idx = 0; idx < count; ++idx)
    {
        @autoreleasepool {
            
            if (idx > 0)
            {
                [description appendString:@","];
            }
            
            const void *pointer = [self pointerAtIndex:idx];
            if (pointer)
            {
                [description appendFormat:@"\n[%lu]: (void *) <%p>", (unsigned long)idx, pointer];
            }
            else
            {
                [description appendFormat:@"\n[%lu]: (void *) NULL", (unsigned long)idx];
            }
            
        }
    }
    
    [description indentByLevel:1];
    [description appendString:@"\n]"];
    
    return description;
}

@end