Software development group project to implement 3 card games in C++ using design patterns, extensive unit tests, and code coverage. It was a lot of fun!

![alt text](https://github.com/awosoga/card_games/blob/main/dunc.PNG?raw=true)


URLs for GET ENDPOINTS
* Get the game players
  * [http://localhost:8000/game/players]
* Get the game information
  * [http://localhost:8000/game/info]

URLs for POST ENDPOINTS
* Start the game
  * [curl.exe -X POST "http://localhost:8000/game/human?name=John"]
  * [curl.exe -X POST "http://localhost:8000/game/startGame?gameChoice=CrazyEights"]
  * [curl.exe -X POST "http://localhost:8000/game/AI?gameChoice=CrazyEights&level=Easy"]