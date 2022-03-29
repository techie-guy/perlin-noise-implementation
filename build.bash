g++ ./src/*.cpp -std=c++17 -m64 -g -Wall -I include -o ./bin/application.exe

printf "Built Project.\n"
printf "####################"
printf "\n\n\n"

./bin/application.exe