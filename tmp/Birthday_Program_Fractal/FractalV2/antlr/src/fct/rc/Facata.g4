/**
 * @author Forrest Jablonski
 */

grammar Facata;

import FacataTokens;

@header
{
package fct.rc;
}

unit : statementList # Unit_
     ;

statementList : statementList statement # ListStatement_
              | statement               # SingleStatement_
              ;

statement : Width  Assign additiveExpression Newline # AssignWidthStatement_
          | Height Assign additiveExpression Newline # AssignHeightStatement_
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

parenthesisedExpression : LeftParen additiveExpression RightParen # ParenthesisedExpression_
                        ;
