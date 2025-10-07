include mk/files.mk
include mk/variables.mk

all				: $(NAME)

$(NAME)			: $(MAIN_OBJS)
					@$(call create_executable, $^, $@)

clean			:
					@rm -rf $(MAIN_OBJS)

fclean			: clean
					@if [ -f $(NAME).a ]; then rm $(NAME).a; fi
					@rm -rf $(NAME)

re				: fclean all


.PHONY			: all clean fclean re

include mk/rules.mk
include mk/functions.mk