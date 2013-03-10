#---------
#
# CppUTest Examples Makefile
#
#----------

#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

#--- Inputs ----#
CPPUTEST_HOME = ./CppUTest

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

SRC_DIRS = \
	platform/win\
	src\
	src/Device

TEST_SRC_DIRS = \
	test\
	test/Device

INCLUDE_DIRS =\
 	.\
 	src\
	test\
	include\
 	$(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
