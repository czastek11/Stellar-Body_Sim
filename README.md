# Stellar-Body_Sim
This is program used to simulate multiple body problems using newtonian mechanics

Instructions regarding running and using the program (in polish):

program do planet jest napisany obiektowo
każdy obiekt klasy reprezentuje niezafiksowany obiekt w przestrzeni kosmicznej
zawiera on w polach wskaźnik na tablice wskaźników wszystkich ciał niezafiksowanych(wspólne pole w c++ nazywa się to static)
zawiera także wektor z pozycjami i prędkościami w osi x i osi y (przechowuje cały dotychczasowy tor ciała , potrzebne do formuły 3 punktowej oraz energii i momentu pędu)
każdy obiekt ma też swoją ścieżkę do pliku w którym wypisuje dane
konstruktor tworzy nowe ciało o id(które muszą być po kolei od 1) o masie i początkowych wartościach wektora  2D położenia i prędkości
Calculate_q1 liczy pierwsze przejście układu (założenie liniowej siły)
Calculate_Step liczy nastepne przejście układu jeśli ma przynajmniej policzony jeden pkt i pkt  z warunkór początkowych
Write data wypisuje wszystkie położenia i prędkości
Calc_and_Write_E_ANGM bierze wektor z wartościami czasowymi symulacji i wypisuje go łącznie z energią i momentem pędu układu w każdej chwili

aby program w main zadziałał poprawnie należy najpierw ustalić ilość symulowanych punktów i przedział czasowy a także wielkość tablicy ciał niebieskich(może być większa niż planowana , ale nie zalecam i trzeba się upewnić że nie używane elementy tablicy są NULL)
następnie należy stworzyć potrzebne niezafiksowane ciała niebieskie w tablicy (funkcja new)
następnie należy przypisać wskaźnik (tablice)ciał niebieskich do wspólnego pola obiektów lista_ob (nazwatablicy[istniejący indeks]->lista_ob=nazwatablicy)
następnie należy użyć gotowych metod do symulacji

q1 po wszytkich obiektach

pętla:
zwykły step po wszystkich obiektach

współczyniiki ciała zafikoswanego (pozycja masa) oraz wartośc stałej grawitacyjnej znajdują się w pliku Stellra_Body.cpp

dodatkowo kod może się nie kompliwoać dla starych wersji cpp , w takim wypadku należy wejśc do pliku Stellar_Body.cpp i odkomentować kod przy którym jest komentarz że poniższa linijka może nie działać

jeśli użytkownik korzysta z code::blocks , prawdopodobne jest że program się nie skompiluje dopóki nie zepnie sie wszytkich plików w projekt code::blocks

Instructions regarding running and using the program (in english):

the planet program is written object-oriented
each object of the class represents a non-fixed object in space
it contains in fields a pointer to an array of pointers of all non-fixed bodies(a common field in c++ is called static)
it also contains a vector with x-axis and y-axis positions and velocities(it stores all the body trajectory so far , needed for 3 point formula and energy and angular momentum)
each object also has its own path to the file in which it writes out the data
constructor creates a new body with id(which must be sequentially from 1) with mass and initial 2D vector values of position and velocity
Calculate_q1 calculates the first transition of the system (assuming linear force)
Calculate_Step counts the next transition of the system if it has at least one point counted and a point from the initial conditions
Write data prints out all positions and velocities
Calc_and_Write_E_ANGM takes the vector with the simulation time values and prints it out including the energy and angular momentum of the system at each time instant

In order for the program in the main to work correctly, you must first determine the number of simulated points and time interval, as well as the size of the array of celestial bodies (it can be larger than planned, but I do not recommend it, and you need to make sure that the unused elements of the array are NULL)
then you need to create the necessary non-fixed celestial bodies in the array (function new)
then you need to assign a pointer (arrays)of celestial bodies to the common field of objects list_ob (nameatablica[existing index]->list_ob=nameatablica)
then use the ready-made methods for simulation

q1 after all objects

loop:
normal step over all objects

the coefﬁcients of the ﬁxed body (mass position) and the value of the gravitational constant can be found in the file Stellar_Body.cpp

In addition, the code may not be complie for old versions of cpp, in which case you need to access the file Stellar_Body.cpp and uncomment the code where there is a comment that the following line may not work

if you are using code::blocks, it is likely that the program will not compile until you merge all files into the code::blocks project


