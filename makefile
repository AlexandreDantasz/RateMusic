caminhoSqlite = 'C:\Users\alexa\Documents\RateMusic\sqlite'
sqlite3 = C:\Users\alexa\Documents\RateMusic\sqlite\sqlite3.h
main: RateMusic.o 
	g++ RateMusic.o -o main -L$(caminhoSqlite) -lsqlite3
RateMusic.o: RateMusic.cpp Menu.h $(sqlite3) UsuarioControle.h MusicaControle.h
	g++ -c RateMusic.cpp -o RateMusic.o -I$(caminhoSqlite)