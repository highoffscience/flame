/**
 * @author Forrest Jablonski
 */

grammar Facata;

import FacataTokens;

@header
{
package fct.ft;
}

unit : statementList # Unit_
     ;

statementList : statementList statement # ListStatement_
              | statement               # SingleStatement_
              ;

statement : Scale  Assign pointExpression    Newline # AssignScaleStatement_
          | Trans  Assign pointExpression    Newline # AssignTransStatement_
          | Width  Assign additiveExpression Newline # AssignWidthStatement_
          | Height Assign additiveExpression Newline # AssignHeightStatement_
          | Auto OP=(On|Off) Newline                 # AssignAutoStatement_
          | Newline                                  # EmptyStatement_
          ;

additiveExpression : additiveExpression OP=(Plus|Minus) multiplicativeExpression # AdditionExpression_
                   | multiplicativeExpression                                    # AdditiveExpression_
                   ;

multiplicativeExpression : multiplicativeExpression OP=(Times|Divide) primaryExpression # MultiplicationExpression_
                         | primaryExpression                                            # MultiplicativeExpression_
                         ;

primaryExpression : Integer                 # Integer_
                  | Decimal                 # Decimal_
                  | parenthesisedExpression # PrimaryParenthesisedExpression_
                  ;

pointExpression : LeftBracket XCoord=additiveExpression Comma YCoord=additiveExpression RightBracket # PointExpression_
                ;

parenthesisedExpression : LeftParen additiveExpression RightParen # ParenthesisedExpression_
                        ;
