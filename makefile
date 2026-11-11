# MAKEFILE

preprocessor: mypreprocessor.o fileinclude.o comment_removal.o macro.o
        cc mypreprocessor.o fileinclude.o comment_removal.o macro.o -o preprocessor

mypreprocessor.o: mypreprocessor.c
        cc -c mypreprocessor.c

fileinclude.o: fileinclude.c
        cc -c fileinclude.c

comment_removal.o: comment_removal.c
        cc -c comment_removal.c

macro.o: macro.c
        cc -c macro.c

clear:
        @echo "cleaning up"
        @rm -v *.o
		