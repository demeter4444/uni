#Demeter Tamas
#dtim1806
#511/2
#lock hazi 7. feladat

#Írjunk olyan programot, amely egy n2 db. egész számot tartalmazó állománnyal #dolgozik. Az állomány bejegyzései egy n elemű M négyzetes mátrix elemei. Egy #program ismételten kiszámolja egy sor vagy egy oszlop elemeinek összegét (a sor #vagy oszlopszámot véletlenszerűen generáljuk). Az összeget a sor vagy oszlop #utolsó elemében tároljuk. Mikor egy számot felhasználtunk az összeg #kiszámításánál lenullázzuk azt, elkerülve így azt, hogy kétszer is #összeszámoljuk. Számoljuk ki M[n,n]-ben a mátrix elemeinek összegét több ilyen #program párhuzamos indításával. Azt a részt az állományból, amit a program az #összegszámolásnál használ mindig zárolni kell. A folyamatok akkor állnak le, #amikor kiszámoltuk a végső összeget. Az munkaállomány a matrix.bin nevet viseli, #amelyet a matrix.dat állományból állítunk elő.

#!/bin/bash
rm matrix.bin 2>>/dev/null
./pb
./p&
./p&
./p

