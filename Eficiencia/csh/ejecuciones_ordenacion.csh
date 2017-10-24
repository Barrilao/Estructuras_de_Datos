#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio
echo > ordenacion.dat
while ( $i <= $fin )
	echo Ejecución tam = $i
	echo `./ordenacion $i 10000` >> ordenacion.dat
	@ i += $incremento
end
