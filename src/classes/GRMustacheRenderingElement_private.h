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

@class GRMustacheContext;
@class GRMustacheTemplate;

/**
 * The protocol for "rendering elements".
 * 
 * When parsing a Mustache template, GRMustacheCompiler builds a syntax
 * tree of objects representing raw text and various mustache tags.
 * 
 * This syntax tree is made of objects conforming to the
 * GRMustacheRenderingElement.
 * 
 * Their responsability is to render the data provided by the library user. This
 * data is encapsulated into GRMustacheContext objects, which represent a
 * context stack that grows when entering a Mustache {{#section}}, and shrinks
 * when leaving that same {{/section}}.
 * 
 * For instance, the template string "hello {{name}}!" would give four rendering
 * elements:
 *
 * - a GRMustacheTextElement that renders "hello ".
 * - a GRMustacheVariableElement that renders the `name` key in a context.
 * - a GRMustacheTextElement that renders "!".
 * - a GRMustacheTemplate that would contain the three previous elements, and
 *   render the concatenation of their renderings.
 * 
 * @see GRMustacheCompiler
 * @see GRMustacheContext
 */
@protocol GRMustacheRenderingElement<NSObject>
@required

/**
 * Renders a context stack.
 * 
 * @param context       A context stack.
 * @param rootTemplate  A template whose delegate methods should be called
 *                      whenever relevant.
 *
 * @return The rendering of _context_.
 */
- (NSString *)renderContext:(GRMustacheContext *)context inRootTemplate:(GRMustacheTemplate *)rootTemplate GRMUSTACHE_API_INTERNAL;
@end
