# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/29 07:09:36 by ppatil            #+#    #+#              #
#    Updated: 2016/09/29 08:36:35 by ppatil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# use absolute path to avoid problems.

PATH_TO_LIBFT=/nfs/2016/p/ppatil/Documents/Rubbish/libft_working
MOULITEST_DIR=./moulitest_files
ALEVIER_DIR=./alevier_files
QUENTIN_DIR=./quentin_files
YACHAKA_DIR=./yachaka_files
LIB_NAME=libft.a

CC = gcc -Wall -Werror -Wextra

.PHONY: moulitest_p1 moulitest_p2 moulitest_bonus alevier_unit_test quentin_test yachaka_test

default :
	@echo " "
	@echo "PREREQUESITES:"
	@echo "--> Please edite this makefile and point PATH_TO_LIBFT to the "
	@echo "    correct absolute path."
	@echo " "
	@echo "USAGE:"
	@echo "--> make moulitest_p1 : runs part 1 of moulitest for libft."
	@echo "--> make moulitest_p2 : runs part 1 & 2 of moulitest for libft."
	@echo "--> make moulitest_bonus : runs part 1, 2, & bonus of moulitest "
	@echo "    for libft."
	@echo "--> make alevier_unit_test: runs alevier's libft unit tests."
	@echo "--> make quentin_test: runs quentin's libft unit tests. [ * ]"
	@echo "--> make yachaka_test: runs yachaka's libft unit tests."
	@echo " "
	@echo "NOTES:"
	@echo " * quentin test will always check for NULL being passed to the "
	@echo "   non-standard libc functions. If you get segfaults, don't worry. "
	@echo "   Passing null to anything that takes a pointer should usually "
	@echo "   fail."

moulitest_p1 : moulitest_config $(LIB_NAME)
	$(MAKE) -C $(MOULITEST_DIR) libft_part1

moulitest_p2 : moulitest_config $(LIB_NAME)
	$(MAKE) -C $(MOULITEST_DIR) libft_part2

moulitest_bonus : moulitest_config $(LIB_NAME)
	$(MAKE) -C $(MOULITEST_DIR) libft_bonus

moulitest_config :
	@echo "LIBFT_PATH = $(PATH_TO_LIBFT)" > $(MOULITEST_DIR)/config.ini

alevier_unit_test : $(LIB_NAME) #alevier_config
	$(MAKE) -C $(ALEVIER_DIR) f LIBFTDIR=$(PATH_TO_LIBFT) #They say this is bad practice but meh. I'm lazy.

alevier_config :
	LIBFTDIR=$(PATH_TO_LIBFT)
	export LIBFTDIR

quentin_test : $(LIB_NAME)
	$(CC) $(QUENTIN_DIR)/test_quentin.c -o qtest -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)
	./qtest

yachaka_test : $(LIB_NAME)
	$(CC) $(YACHAKA_DIR)/test_yachaka.c -o ytest -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)
	./ytest

$(LIB_NAME) :
	$(MAKE) -C $(PATH_TO_LIBFT) all
