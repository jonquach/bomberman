SRC		=	CreateMenu.cpp \
			GameEngine.cpp \
			AObject.cpp \
			Bonus.cpp \
			Bomb.cpp \
			Button.cpp \
			Camera.cpp \
			Character.cpp \
			Exception.cpp \
			Explosion.cpp \
			GameMap.cpp \
			Player.cpp \
			Sound.cpp \
			Arrow.cpp \
			LoadImg.cpp \
			Mode.cpp \
			Draw.cpp \
			Save.cpp \
			main.cpp

OBJS		=	$(SRC:.cpp=.o)

NAME		=	bomberman

CPP		=	g++

CPPFLAGS	+=	-Iinclude/ -ILibBomberman_linux_x64/includes/
CPPFLAGS	+=	-Wall -Werror -Wextra

LDFLAGS		+=	-Wl,-rpath=LibBomberman_linux_x64/libs,-rpath=lib/
LDFLAGS		+=	-LLibBomberman_linux_x64/libs -Llib/
LDFLAGS		+=	-lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -lGLU -lSDL -lfmodex64 -ldl

all	:		$(NAME)

$(NAME)	:		$(OBJS)
			$(CPP) -o $(NAME) $(OBJS) $(CPPFLAGS) $(LDFLAGS)

clean	:
			rm -f $(OBJS)

fclean :		clean
			rm -f $(NAME)

re	:		fclean all

.PHONY	:		all clean fclean re
