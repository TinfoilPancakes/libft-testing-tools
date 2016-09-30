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
KANE_DIR=./kane_files
LIB_NAME=libft.a

CC = gcc -Wall -Werror -Wextra

.PHONY: mtest1 mtest2 mtestb atest qtest ytest ktest

default :
	@echo " "
	@echo "PREREQUESITES:"
	@echo "--> Please edite this makefile and point PATH_TO_LIBFT to the "
	@echo "    correct absolute path."
	@echo " "
	@echo "USAGE:"
	@echo "--> make mtest1 : runs part 1 of moulitest for libft."
	@echo "--> make mtest2 : runs part 1 & 2 of moulitest for libft."
	@echo "--> make mtestb : runs part 1, 2, & bonus of moulitest for libft."
	@echo "--> make atest: runs alevier's libft unit tests."
	@echo "--> make qtest: runs quentin's libft unit tests. [ * ]"
	@echo "--> make ytest: runs yachaka's libft unit tests."
	@echo "--> make ktest: runs kane's libft unit tests. [ * ]"
	@echo " "
	@echo "NOTES:"
	@echo " * quentin's test will always check for NULL being passed to the "
	@echo "   non-standard libc functions. If you get segfaults, don't worry. "
	@echo "   Passing null to anything that takes a pointer should usually "
	@echo "   fail."
	@echo " * kane's unit test for ft_atoi is known to be extremely rigorous."

mtest1 : moulitest_config $(LIB_NAME)
	$(MAKE) -C $(MOULITEST_DIR) libft_part1

mtest2 : moulitest_config $(LIB_NAME)
	$(MAKE) -C $(MOULITEST_DIR) libft_part2

mtestb : moulitest_config $(LIB_NAME)
	$(MAKE) -C $(MOULITEST_DIR) libft_bonus

moulitest_config :
	@echo "LIBFT_PATH = $(PATH_TO_LIBFT)" > $(MOULITEST_DIR)/config.ini

atest : $(LIB_NAME) #alevier_config
	$(MAKE) -C $(ALEVIER_DIR) f LIBFTDIR=$(PATH_TO_LIBFT) #They say this is bad practice but meh. I'm lazy.

alevier_config :
	LIBFTDIR=$(PATH_TO_LIBFT)
	export LIBFTDIR

qtest : $(LIB_NAME)
	$(CC) $(QUENTIN_DIR)/test_quentin.c -o qtest -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)
	./qtest

ytest : $(LIB_NAME)
	$(CC) $(YACHAKA_DIR)/test_yachaka.c -o ytest -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)
	./ytest

KTEST_ALL=	k_atoi \
			k_isstuff \
			k_lstdel \
			k_memccpy \
			k_memchr \
			k_memcpy \
			k_memmove \
			k_putstuff \
			k_split \
			k_strcat \
			k_strchr \
			k_strcmp \
			k_strcpy \
			k_strjoin \
			k_strlcat \
			k_strlen \
			k_strncat \
			k_strncmp \
			k_strncpy \
			k_strstr \
			k_strsub \
			k_strtrim

ktest : $(KTEST_ALL)
	./k_atoi
	./k_isstuff
	./k_lstdel
	./k_memccpy
	./k_memchr
	./k_memcpy
	./k_memmove
	./k_putstuff
	./k_split
	./k_strcat
	./k_strchr
	./k_strcmp
	./k_strcpy
	./k_strjoin
	./k_strlcat
	./k_strlen
	./k_strncat
	./k_strncmp
	./k_strncpy
	./k_strstr
	./k_strsub
	./k_strtrim

#Don't judge me you judge-a-roo. Go play your judge-ari-doo.

k_atoi : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_atoi.c -o k_atoi -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_isstuff : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_isstuff.c -o k_isstuff -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_lstdel : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_lstdel.c -o k_lstdel -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_memccpy : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_memccpy.c -o k_memccpy -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_memchr : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_memchr.c -o k_memchr -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_memcmp : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_memcmp.c -o k_memcmp -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_memcpy : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_memcpy.c -o k_memcpy -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_memmove : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_memmove.c -o k_memmove -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_putstuff : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_putstuff.c -o k_putstuff -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_split : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_split.c -o k_split -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strcat : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strcat.c -o k_strcat -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strchr : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strchr.c -o k_strchr -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strcmp : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strcmp.c -o k_strcmp -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strcpy : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strcpy.c -o k_strcpy -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strjoin : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strjoin.c -o k_strjoin -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strlcat : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strlcat.c -o k_strlcat -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strlen : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strlen.c -o k_strlen -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strncat : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strncat.c -o k_strncat -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strncmp : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strncmp.c -o k_strncmp -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strncpy : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strncpy.c -o k_strncpy -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strstr : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strstr.c -o k_strstr -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strsub : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strsub.c -o k_strsub -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

k_strtrim : $(LIB_NAME)
	$(CC) $(KANE_DIR)/test_strtrim.c -o k_strtrim -L$(PATH_TO_LIBFT) -lft -I$(PATH_TO_LIBFT)

$(LIB_NAME) :
	$(MAKE) -C $(PATH_TO_LIBFT) all

clean : 
	rm -rf $(KTEST_ALL)
	rm -rf qtest
	rm -rf ytest

fclean : clean
	$(MAKE) -C $(MOULITEST_DIR)/libft_tests clean
	$(MAKE) -C $(MOULITEST_DIR)/libft_tests fclean
	$(MAKE) -C $(ALEVIER_DIR) clean
	$(MAKE) -C $(ALEVIER_DIR) fclean
