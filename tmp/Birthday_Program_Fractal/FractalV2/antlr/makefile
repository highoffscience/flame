#
# @author Forrest Jablonski
#

#
# Global variables
#

DIRS = vb/ cs/ ft/ rc/ fa/ sa/
RUN_TARGETS_STEM = VariationBlend ColorScheme Fitter Fractal Renderer StrangeAttractor

getIDFromRunTarget = $(strip $(if $(findstring VariationBlend,   $(1)), vb, \
                             $(if $(findstring ColorScheme,      $(1)), cs, \
                             $(if $(findstring Fitter,           $(1)), ft, \
                             $(if $(findstring Fractal,          $(1)), rc, \
                             $(if $(findstring Renderer,         $(1)), fa, \
                             $(if $(findstring StrangeAttractor, $(1)), sa, \
                                               $(1).UNKNOWN                )))))))

    SRC_DIR =  ./src/fct/
    BIN_DIR =  ./bin/fct/
CPP_SRC_DIR = ../fct/src/
SCRIPTS_DIR =  ./scripts/

SRC_DIRS := $(patsubst %, $(SRC_DIR)%, $(DIRS))
BIN_DIRS := $(patsubst %, $(BIN_DIR)%, $(DIRS))

ANTLR_JAR      = ./jar/antlr-4.7-complete.jar
ANTLR_GEN_ARGS = -ea -jar $(ANTLR_JAR) -visitor -no-listener
ANTLR_COM_ARGS = -g -cp ./src/:$(ANTLR_JAR) -d ./bin/
ANTLR_RUN_ARGS = -ea -cp ./bin/:$(ANTLR_JAR)
ANTLR_DOC_ARGS = -classpath ./bin/:$(ANTLR_JAR) -d ./doc/ -quiet -doctitle "Facata"
ANTLR_DBG_ARGS = -cp ./bin/:$(ANTLR_JAR) org.antlr.v4.gui.TestRig fct.Facata unit -gui

#
# Build all targets (does NOT call run)
#

all: com

#
# Generate
#

GEN_TARGETS := $(patsubst %, $(SRC_DIR)%FacataVisitor.java, $(DIRS))

gen: $(GEN_TARGETS)

$(GEN_TARGETS): %FacataVisitor.java: %Facata.g4 %FacataTokens.g4
	@echo "Generating $(strip $(patsubst $(SRC_DIR)%, %, ./$@)) from g4's..."
	@java $(ANTLR_GEN_ARGS) $<

#
# Compile
#

COM_TARGETS := $(patsubst %, $(BIN_DIR)%FacataVisitor.class, $(DIRS))

COMMON_COM_TARGETS = $(SRC_DIR)Facata.java                \
                     $(SRC_DIR)FacataCodeGenerator.java   \
                     $(SRC_DIR)SourceGeneratorHelper.java

com: $(COM_TARGETS)

$(COM_TARGETS): $(BIN_DIR)%FacataVisitor.class: $(SRC_DIR)%Main.java $(SRC_DIR)%SourceGenerator.java $(COMMON_COM_TARGETS) $(SRC_DIR)%FacataVisitor.java
	@echo "Compiling $(strip $(patsubst $(BIN_DIR)%.class, %.java, ./$@))..."
	@javac $(ANTLR_COM_ARGS) $<

#
# Execute
#

RUN_TARGETS = $(patsubst %, $(CPP_SRC_DIR)%.cpp, $(RUN_TARGETS_STEM))

run: $(RUN_TARGETS)

.SECONDEXPANSION:
$(RUN_TARGETS): $(CPP_SRC_DIR)%.cpp: $(SCRIPTS_DIR)$$(call getIDFromRunTarget, %).fct $(BIN_DIR)$$(call getIDFromRunTarget, %)/FacataVisitor.class
	@echo "Running $(strip $(patsubst $(SCRIPTS_DIR)%.fct, fct.%.Main, ./$<))..."
	@java $(ANTLR_RUN_ARGS) $(patsubst $(SCRIPTS_DIR)%.fct, fct.%.Main, ./$<)

#
# Document
#

doc:
	@javadoc $(ANTLR_DOC_ARGS) $(SRC_DIRS)*.java

#
# Debug
#

dbg:
	@java $(ANTLR_DBG_ARGS)
