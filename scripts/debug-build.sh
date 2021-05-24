	# g++ -w -std=c++14 -g -c \
	# ./src/*.cpp \
	# ./src/core/*.cpp \
	# ./src/components/*.cpp \
	
	# echo "HEYA!"
	echo $(pwd)
	g++ -Wall -std=c++14 \
	./src/*.cpp ./src/core/*.cpp ./src/components/*.cpp \
	-o build/game_release \
	-I"./libs/lua" \
	-L "./libs/lua" \
	-llua \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer;