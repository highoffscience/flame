/**
 * @author Forrest Jablonski
 */

grammar Facata;

import FacataTokens;

@header
{
package fct.vb;
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
          | Var numbersList Newline statementList End Newline          # VarStatement_
          ;
          
numbersList : numbersList Decimal # NumbersList_
            | Decimal             # SingleNumber_
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
                  | X                       # X_
                  | Y                       # Y_
                  | functionCall            # FunctionCall_
                  | pointExpression         # PrimaryPointExpression_
                  | parenthesisedExpression # PrimaryParenthesisedExpression_
                  ;
                  
functionCall : Sin LeftParen ARG=additiveExpression RightParen # Sin_
             | Cos LeftParen ARG=additiveExpression RightParen # Cos_
             | Tan LeftParen ARG=additiveExpression RightParen # Tan_
             ;
                
pointExpression : LeftBracket XCoord=additiveExpression Comma YCoord=additiveExpression RightBracket # PointExpression_
                ;

parenthesisedExpression : LeftParen additiveExpression RightParen # ParenthesisedExpression_
                        ;
