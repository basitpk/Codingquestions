# This is simple makefile for building temp.c temp2.c and temp3.c . Only will work on windows \
Also to run and generate executables use either of below commands \
make project \
make all \
make clean to remove *.exe. Use only if u have used "make project"


files := first second #variable declaration in makefile
SRC := temp.c \
       temp2.c \
       temp3.c
E = exec/
TARGETS := first \
           second \
		   third	   

EXEC := $(SRC:%.c=%.exe)
# ALL files represented in SRC for eg: temp.c with pattern matching (%.c=%.exe) the exe files should be named as temp.exe

MAKEFLAGS += --silent
# To stop printing all the commands (Look inside first second and third ) that are run

#CFLAGS=-Wall -g
.PHONY: project first second third clean
#  Chances are this isn't the case, but you may potentially have a file named clean in your main directory. 
# In such a case Make will be confused because by default the clean target would be associated with this file and Make will only run it when the 
# file doesn't appear to be up-to-date with regards to its dependencies

$(E):
	@mkdir -p $@
	@echo "Making exec directory"
first: temp.c
	@echo "Compiling temp.c"
	$(CC) $(CFLAGS) temp.c -o temp
second: temp2.c
	# touch $@.txt
	@echo "Compiling temp2.c"
	$(CC) $(CFLAGS) $< -o temp2
third: temp3.c
	@echo "Compiling temp3.c"
	$(CC) $(CFLAGS) $< -o temp3
all: ${files}
	@echo "Completed compilation for temp1 and temp2"
	@date
$(EXEC): $(TARGETS) $(E)
# This will be execute for all the three executables that are created
	@echo "Moving executable $(@) to exec/ folder"
	@mv $@ $(E)
project: $(EXEC)
	@echo "Completed targets first second and third"
	@date
clean:
	rm -rf ./exec/
	@echo "CLEANing done. Removing exec folder"
