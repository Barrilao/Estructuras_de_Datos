#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio
echo > peor_caso.dat
while ( $i <= $fin )
	echo Ejecución tam = $i
	echo `./peor_caso $i 10000` >> peor_caso.dat
	@ i += $incremento
end
