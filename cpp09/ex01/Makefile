NAME		=	RPN

SRC_DIR		=	src
OBJ_DIR		=	obj
INCLUDE_DIR	=	include

INCLUDES	=	-I $(INCLUDE_DIR)
SRCDIRS		=	$(shell find $(SRC_DIR) -type d)
INCLUDES	+=	$(addprefix -I ,$(SRCDIRS))

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm

SRCS		=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/RPN.cpp
OBJS		=	$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS		=	$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.d)
.PHONY: $(DEPS)

TEST_NAME	=	test
TEST_OPTION	=	-Wall -Wextra -Werror -std=c++11 \
				-I$(shell brew --prefix cppunit)/include \
				-L$(shell brew --prefix cppunit)/lib \
				-lcppunit

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp
				@mkdir -p $$(dirname $@)
				$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
				$(RM) -rf $(OBJS) $(OBJ_DIR)

fclean:			clean
				$(RM) -f $(NAME) $(TEST_NAME)

re:				fclean all

test:			$(SRC_DIR)/rpn_test.cpp $(SRC_DIR)/RPN.cpp
				$(CC) $(CFLAGS) $(INCLUDES) $(TEST_OPTION) $^ -o $@
				./$(TEST_NAME)

.PHONY:			all clean fclean re test
-include $(DEPS)
