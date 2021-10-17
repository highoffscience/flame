/**
 * @author Forrest Jablonski
 */

grammar Facata;

import FacataTokens;

@header
{
package fct.cs;
}

unit : statementList # Unit_
     ;

statementList : statementList statement # ListStatement_
              | statement               # SingleStatement_
              ;

statement : Identifier Assign additiveExpression Newline               # AssignmentStatement_
//        | If conditionalExpression Newline statementList End Newline # ConditionalStatement_
          | Return additiveExpression Newline                          # ReturnStatement_
          | Newline                                                    # EmptyStatement_
          ;

//conditionalExpression : LHS=additiveExpression OP=(Equal|NotEqual|Less|Greater|LessEqual|GreaterEqual) RHS=additiveExpression # ConditionalExpression_
//                      ;

additiveExpression : additiveExpression OP=(Plus|Minus) multiplicativeExpression # AdditionExpression_
                   | multiplicativeExpression                                    # AdditiveExpression_
                   ;

multiplicativeExpression : multiplicativeExpression OP=(Times|Divide) primaryExpression # MultiplicationExpression_
                         | primaryExpression                                            # MultiplicativeExpression_
                         ;

primaryExpression : Integer                 # Integer_
                  | Decimal                 # Decimal_
                  | Identifier              # Reference_
                  | Color                   # Color_
                  | functionCall            # FunctionCall_
                  | parenthesisedExpression # PrimaryParenthesisedExpression_
                  | pixelExpression         # PrimaryPixelExpression_
                  ;
                  
functionCall : Sin LeftParen ARG=additiveExpression RightParen # Sin_
             | Cos LeftParen ARG=additiveExpression RightParen # Cos_
             | Tan LeftParen ARG=additiveExpression RightParen # Tan_
             ;

pixelExpression : LeftBracket RED=additiveExpression Comma GREEN=additiveExpression Comma BLUE=additiveExpression RightBracket # PixelExpression_
                ;

parenthesisedExpression : LeftParen additiveExpression RightParen # ParenthesisedExpression_
                        ;
