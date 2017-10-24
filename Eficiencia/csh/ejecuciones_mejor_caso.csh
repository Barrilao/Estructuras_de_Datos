#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio
echo > mejor_caso.dat
while ( $i <= $fin )
	echo Ejecución tam = $i
	echo `./mejor_caso $i 10000` >> mejor_caso.dat
	@ i += $incremento
end
