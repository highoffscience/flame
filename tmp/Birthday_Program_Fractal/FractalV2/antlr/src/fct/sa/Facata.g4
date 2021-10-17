/**
 * @author Forrest Jablonski
 */

grammar Facata;

import FacataTokens;

@header
{
package fct.sa;
}

unit : statementList # Unit_
     ;

statementList : statementList statement # ListStatement_
              | statement               # SingleStatement_
              ;

statement : Identifier Assign additiveExpression Newline               # AssignmentStatement_
//        | If conditionalExpression Newline statementList End Newline # ConditionalStatement_
          | Newline                                                    # EmptyStatement_
          | Pre typeExpression Newline statementList End Newline       # PreStatement_
          | Post typeExpression Newline statementList End Newline      # PostStatement_
          | Matrix Assign matrixExpression Newline                     # MatrixStatement_
          ;

typeExpression : TYPE=(None|Ias|Ifs) # TypeExpression_
               ;

//matrixExpression : LeftBracket additiveExpression RightBracket # MatrixExpression_
//                 ;

matrixExpression : LeftBracket A=additiveExpression Comma
                               B=additiveExpression Comma
                               C=additiveExpression Comma
                               D=additiveExpression Comma
                               E=additiveExpression Comma
                               F=additiveExpression Comma
                               CLR=additiveExpression Comma
                               PROB=additiveExpression RightBracket # MatrixExpression_
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
                  | parenthesisedExpression # PrimaryParenthesisedExpression_
                  ;

parenthesisedExpression : LeftParen additiveExpression RightParen # ParenthesisedExpression_
                        ;
