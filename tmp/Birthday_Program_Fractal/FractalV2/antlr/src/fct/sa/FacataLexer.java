// Generated from src/fct/sa/Facata.g4 by ANTLR 4.7

package fct.sa;

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class FacataLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Equal=1, NotEqual=2, Plus=3, Minus=4, Times=5, Divide=6, Comma=7, Less=8, 
		Greater=9, LeftParen=10, RightParen=11, LeftBracket=12, RightBracket=13, 
		LessEqual=14, GreaterEqual=15, Assign=16, Newline=17, If=18, End=19, And=20, 
		Or=21, Pre=22, Post=23, Ias=24, Ifs=25, None=26, Matrix=27, Keyword=28, 
		Identifier=29, Integer=30, Decimal=31, Whitespace=32, Comment=33;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"Equal", "NotEqual", "Plus", "Minus", "Times", "Divide", "Comma", "Less", 
		"Greater", "LeftParen", "RightParen", "LeftBracket", "RightBracket", "LessEqual", 
		"GreaterEqual", "Assign", "Newline", "If", "End", "And", "Or", "Pre", 
		"Post", "Ias", "Ifs", "None", "Matrix", "Keyword", "Identifier", "Integer", 
		"Decimal", "Whitespace", "Comment"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'='", "'~'", "'+'", "'-'", "'*'", "'/'", "','", "'<'", "'>'", "'('", 
		"')'", "'['", "']'", "'<='", "'>='", "'<-'", null, "'If'", "'End'", "'And'", 
		"'Or'", "'Pre'", "'Post'", "'Ias'", "'Ifs'", "'None'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "Equal", "NotEqual", "Plus", "Minus", "Times", "Divide", "Comma", 
		"Less", "Greater", "LeftParen", "RightParen", "LeftBracket", "RightBracket", 
		"LessEqual", "GreaterEqual", "Assign", "Newline", "If", "End", "And", 
		"Or", "Pre", "Post", "Ias", "Ifs", "None", "Matrix", "Keyword", "Identifier", 
		"Integer", "Decimal", "Whitespace", "Comment"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public FacataLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Facata.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2#\u00c9\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3"+
		"\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\17\3\20"+
		"\3\20\3\20\3\21\3\21\3\21\3\22\3\22\3\23\3\23\3\23\3\24\3\24\3\24\3\24"+
		"\3\25\3\25\3\25\3\25\3\26\3\26\3\26\3\27\3\27\3\27\3\27\3\30\3\30\3\30"+
		"\3\30\3\30\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32\3\33\3\33\3\33\3\33"+
		"\3\33\3\34\3\34\6\34\u0091\n\34\r\34\16\34\u0092\3\35\3\35\7\35\u0097"+
		"\n\35\f\35\16\35\u009a\13\35\3\36\3\36\7\36\u009e\n\36\f\36\16\36\u00a1"+
		"\13\36\3\37\5\37\u00a4\n\37\3\37\3\37\3\37\7\37\u00a9\n\37\f\37\16\37"+
		"\u00ac\13\37\5\37\u00ae\n\37\3 \3 \3 \6 \u00b3\n \r \16 \u00b4\5 \u00b7"+
		"\n \3!\6!\u00ba\n!\r!\16!\u00bb\3!\3!\3\"\3\"\3\"\7\"\u00c3\n\"\f\"\16"+
		"\"\u00c6\13\"\3\"\3\"\2\2#\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25"+
		"\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32"+
		"\63\33\65\34\67\359\36;\37= ?!A\"C#\3\2\16\3\2\f\f\3\2OO\3\2\62;\3\2C"+
		"\\\5\2\62;C\\c|\3\2c|\6\2\62;C\\aac|\3\2\62\62\3\2\63;\3\2\60\60\5\2\13"+
		"\13\17\17\"\"\3\2\61\61\2\u00d2\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2"+
		"\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2"+
		"\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2"+
		"\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2"+
		"\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2"+
		"\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2"+
		"\2C\3\2\2\2\3E\3\2\2\2\5G\3\2\2\2\7I\3\2\2\2\tK\3\2\2\2\13M\3\2\2\2\r"+
		"O\3\2\2\2\17Q\3\2\2\2\21S\3\2\2\2\23U\3\2\2\2\25W\3\2\2\2\27Y\3\2\2\2"+
		"\31[\3\2\2\2\33]\3\2\2\2\35_\3\2\2\2\37b\3\2\2\2!e\3\2\2\2#h\3\2\2\2%"+
		"j\3\2\2\2\'m\3\2\2\2)q\3\2\2\2+u\3\2\2\2-x\3\2\2\2/|\3\2\2\2\61\u0081"+
		"\3\2\2\2\63\u0085\3\2\2\2\65\u0089\3\2\2\2\67\u008e\3\2\2\29\u0094\3\2"+
		"\2\2;\u009b\3\2\2\2=\u00a3\3\2\2\2?\u00af\3\2\2\2A\u00b9\3\2\2\2C\u00bf"+
		"\3\2\2\2EF\7?\2\2F\4\3\2\2\2GH\7\u0080\2\2H\6\3\2\2\2IJ\7-\2\2J\b\3\2"+
		"\2\2KL\7/\2\2L\n\3\2\2\2MN\7,\2\2N\f\3\2\2\2OP\7\61\2\2P\16\3\2\2\2QR"+
		"\7.\2\2R\20\3\2\2\2ST\7>\2\2T\22\3\2\2\2UV\7@\2\2V\24\3\2\2\2WX\7*\2\2"+
		"X\26\3\2\2\2YZ\7+\2\2Z\30\3\2\2\2[\\\7]\2\2\\\32\3\2\2\2]^\7_\2\2^\34"+
		"\3\2\2\2_`\7>\2\2`a\7?\2\2a\36\3\2\2\2bc\7@\2\2cd\7?\2\2d \3\2\2\2ef\7"+
		">\2\2fg\7/\2\2g\"\3\2\2\2hi\t\2\2\2i$\3\2\2\2jk\7K\2\2kl\7h\2\2l&\3\2"+
		"\2\2mn\7G\2\2no\7p\2\2op\7f\2\2p(\3\2\2\2qr\7C\2\2rs\7p\2\2st\7f\2\2t"+
		"*\3\2\2\2uv\7Q\2\2vw\7t\2\2w,\3\2\2\2xy\7R\2\2yz\7t\2\2z{\7g\2\2{.\3\2"+
		"\2\2|}\7R\2\2}~\7q\2\2~\177\7u\2\2\177\u0080\7v\2\2\u0080\60\3\2\2\2\u0081"+
		"\u0082\7K\2\2\u0082\u0083\7c\2\2\u0083\u0084\7u\2\2\u0084\62\3\2\2\2\u0085"+
		"\u0086\7K\2\2\u0086\u0087\7h\2\2\u0087\u0088\7u\2\2\u0088\64\3\2\2\2\u0089"+
		"\u008a\7P\2\2\u008a\u008b\7q\2\2\u008b\u008c\7p\2\2\u008c\u008d\7g\2\2"+
		"\u008d\66\3\2\2\2\u008e\u0090\t\3\2\2\u008f\u0091\t\4\2\2\u0090\u008f"+
		"\3\2\2\2\u0091\u0092\3\2\2\2\u0092\u0090\3\2\2\2\u0092\u0093\3\2\2\2\u0093"+
		"8\3\2\2\2\u0094\u0098\t\5\2\2\u0095\u0097\t\6\2\2\u0096\u0095\3\2\2\2"+
		"\u0097\u009a\3\2\2\2\u0098\u0096\3\2\2\2\u0098\u0099\3\2\2\2\u0099:\3"+
		"\2\2\2\u009a\u0098\3\2\2\2\u009b\u009f\t\7\2\2\u009c\u009e\t\b\2\2\u009d"+
		"\u009c\3\2\2\2\u009e\u00a1\3\2\2\2\u009f\u009d\3\2\2\2\u009f\u00a0\3\2"+
		"\2\2\u00a0<\3\2\2\2\u00a1\u009f\3\2\2\2\u00a2\u00a4\5\t\5\2\u00a3\u00a2"+
		"\3\2\2\2\u00a3\u00a4\3\2\2\2\u00a4\u00ad\3\2\2\2\u00a5\u00ae\t\t\2\2\u00a6"+
		"\u00aa\t\n\2\2\u00a7\u00a9\t\4\2\2\u00a8\u00a7\3\2\2\2\u00a9\u00ac\3\2"+
		"\2\2\u00aa\u00a8\3\2\2\2\u00aa\u00ab\3\2\2\2\u00ab\u00ae\3\2\2\2\u00ac"+
		"\u00aa\3\2\2\2\u00ad\u00a5\3\2\2\2\u00ad\u00a6\3\2\2\2\u00ae>\3\2\2\2"+
		"\u00af\u00b6\5=\37\2\u00b0\u00b2\t\13\2\2\u00b1\u00b3\t\4\2\2\u00b2\u00b1"+
		"\3\2\2\2\u00b3\u00b4\3\2\2\2\u00b4\u00b2\3\2\2\2\u00b4\u00b5\3\2\2\2\u00b5"+
		"\u00b7\3\2\2\2\u00b6\u00b0\3\2\2\2\u00b6\u00b7\3\2\2\2\u00b7@\3\2\2\2"+
		"\u00b8\u00ba\t\f\2\2\u00b9\u00b8\3\2\2\2\u00ba\u00bb\3\2\2\2\u00bb\u00b9"+
		"\3\2\2\2\u00bb\u00bc\3\2\2\2\u00bc\u00bd\3\2\2\2\u00bd\u00be\b!\2\2\u00be"+
		"B\3\2\2\2\u00bf\u00c0\t\r\2\2\u00c0\u00c4\t\r\2\2\u00c1\u00c3\n\2\2\2"+
		"\u00c2\u00c1\3\2\2\2\u00c3\u00c6\3\2\2\2\u00c4\u00c2\3\2\2\2\u00c4\u00c5"+
		"\3\2\2\2\u00c5\u00c7\3\2\2\2\u00c6\u00c4\3\2\2\2\u00c7\u00c8\b\"\2\2\u00c8"+
		"D\3\2\2\2\r\2\u0092\u0098\u009f\u00a3\u00aa\u00ad\u00b4\u00b6\u00bb\u00c4"+
		"\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}