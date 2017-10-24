#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio
echo > burbuja2.dat
while ( $i <= $fin )
	echo Ejecución tam = $i
	echo `./burbuja2 $i 10000` >> burbuja2.dat
	@ i += $incremento
end
