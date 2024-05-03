PATH_TO_TEST = ./libTester
PATH_TO_LIBS = ./myStdLibs
PATH_TO_FTEST = ./functests

all:
	$(MAKE) -C $(PATH_TO_TEST)

libs:
	$(MAKE) -C $(PATH_TO_LIBS)
	cp $(PATH_TO_LIBS)/bin/*.dll $(PATH_TO_TEST)/bin

clean:
	$(MAKE) -C $(PATH_TO_TEST) clean
	$(MAKE) -C $(PATH_TO_LIBS) clean

purge:
	$(MAKE) -C $(PATH_TO_TEST) purge
	$(MAKE) -C $(PATH_TO_LIBS) purge

test:
	$(MAKE) -C $(PATH_TO_FTEST)