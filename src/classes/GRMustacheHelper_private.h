// The MIT License
// 
// Copyright (c) 2012 Gwendal Roué
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "GRMustacheAvailabilityMacros_private.h"

@class GRMustacheSection;

// =============================================================================
#pragma mark - <GRMustacheHelper>

// Documented in GRMustacheHelper.h
@protocol GRMustacheHelper<NSObject>
@required

// Documented in GRMustacheHelper.h
- (NSString *)renderSection:(GRMustacheSection *)section GRMUSTACHE_API_PUBLIC;
@end


// =============================================================================
#pragma mark - GRMustacheHelper

// Documented in GRMustacheHelper.h
@interface GRMustacheHelper: NSObject<GRMustacheHelper>

#if NS_BLOCKS_AVAILABLE

// Documented in GRMustacheHelper.h
+ (id)helperWithBlock:(NSString *(^)(GRMustacheSection* section))block GRMUSTACHE_API_PUBLIC;

#endif /* if NS_BLOCKS_AVAILABLE */

@end
