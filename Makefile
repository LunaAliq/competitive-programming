MAKEFILE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

.PRECIOUS: %.o
%.o:	%.cpp
	g++ -D LOCAL $< -o $@
	chmod 755 $@

test-%:	%.o %.test
	@$(MAKEFILE_DIR)/tests $^

t-header:	header test-header
	cat header >$@-tmp.cpp
	cat test-header >>$@-tmp.cpp
	@echo "LOCAL"
	@echo "--------"
	g++ -D LOCAL $@-tmp.cpp -o $@-tmp-l.o
	./$@-tmp-l.o
	@echo "----------------"
	@echo "ACT"
	@echo "--------"
	g++ $@-tmp.cpp -o $@-tmp.o
	./$@-tmp.o
	rm $@-tmp.o $@-tmp-l.o $@-tmp.cpp
